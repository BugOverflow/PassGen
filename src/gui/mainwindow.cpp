#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAbout(bool)));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));

    connect(ui->pushButtonRandomGen, SIGNAL(pressed()), this, SLOT(randGenerate()));
    connect(ui->pushButtonTemplateGen, SIGNAL(pressed()), this, SLOT(tempGenerate()));

    connect(ui->spinBoxSize, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxSizeChanged(int)));
    connect(ui->checkBoxUseSymb, SIGNAL(toggled(bool)), this, SLOT(onCheckBoxChecked(bool)));
    connect(ui->comboBoxStrength, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));

    connect(ui->lineEditTemplate, SIGNAL(returnPressed()), ui->pushButtonTemplateGen, SLOT(click()));
    connect(ui->lineEditTemplate, SIGNAL(textChanged(QString)), this, SLOT(onLineEditTemplateChanged(QString)));

    ui->comboBoxStrength->addItem("Easy", 1);
    ui->comboBoxStrength->addItem("Medium", 2);
    ui->comboBoxStrength->addItem("Hard", 3);
    ui->comboBoxStrength->addItem("Paranoid", 4);

    ui->lineEditResult->setDisabled(true);
    ui->pushButtonRandomGen->setDisabled(true);
    ui->pushButtonTemplateGen->setDisabled(true);

    err_dialog = new QErrorMessage(this);
    connect(this, SIGNAL(printError(QString)), err_dialog, SLOT(showMessage(QString)));
}

MainWindow::~MainWindow()
{
    delete err_dialog;
    delete ui;
}

void MainWindow::onTabChanged(int index)
{
    switch (index)
    {
        case RANDOM_TAB:
            ui->statusBar->showMessage("Choose strength and size, and ready to go!", 5000);
            break;
        case TEMPLATE_TAB:
            ui->statusBar->showMessage("Enter your template, and go on!", 5000);
            break;
    }
    ui->lineEditResult->clear();
    ui->lineEditResult->setDisabled(true);
}

void MainWindow::onComboBoxChanged(int index)
{
    if (index < 3)
        ui->checkBoxUseSymb->setChecked(false);
    else
        ui->checkBoxUseSymb->setChecked(true);
}

void MainWindow::onSpinBoxSizeChanged(int value)
{
    if (value > 0)
        ui->pushButtonRandomGen->setEnabled(true);
    else
        ui->pushButtonRandomGen->setDisabled(true);
}

void MainWindow::onCheckBoxChecked(bool checked)
{
    if (checked)
        ui->comboBoxStrength->setCurrentIndex(3);
}

void MainWindow::onLineEditTemplateChanged(QString string)
{
    if (string.size() > 0)
        ui->pushButtonTemplateGen->setEnabled(true);
    else
        ui->pushButtonTemplateGen->setDisabled(true);
}

void MainWindow::onProcessError(QProcess::ProcessError error)
{
    QString error_string = QString("Err:").append(" %1 ").arg((int)error);
    switch (error)
    {
    case QProcess::Crashed:
        error_string.append("\"Crashed\"");
        break;
    case QProcess::Timedout:
        error_string.append("\"Timeout\"");
        break;
    case QProcess::FailedToStart:
        error_string.append("\"Failed to start PassGen\"");
        break;
    case QProcess::ReadError:
        error_string.append("\"Failed to read pipe\"");
        break;
    case QProcess::WriteError:
    case QProcess::UnknownError:
        break;
    }

    emit printError(error_string);
}

void MainWindow::showAbout(bool trigered)
{
    trigered = trigered;
    QMessageBox::information(this, tr("QPassGen About"),
                          tr("QPassGen 1.0.\n\n"
                          "Copyright 2016 BugOverflow, Inc."));
}

void MainWindow::showResult(QString result)
{
    ui->lineEditResult->setEnabled(true);
    ui->lineEditResult->setText(result);
    if (ui->actionCopy_to_Clipboard->isChecked())
        QApplication::clipboard()->setText(result);
}

void MainWindow::randGenerate()
{
    int size = ui->spinBoxSize->value();
    int stren = ui->comboBoxStrength->currentData().toInt();

    QProcess run;
    connect(&run, SIGNAL(error(QProcess::ProcessError)), this, SLOT(onProcessError(QProcess::ProcessError)));
    run.start(QString("./PassGen -d -c%1 -s%2").arg(size).arg(stren), QIODevice::ReadOnly);
    run.waitForFinished();
    QString err = run.readAllStandardError();
    if (!err.isEmpty())
    {
        emit printError(err);
        return;
    }
    if (run.error() == 5)
        showResult(run.readAllStandardOutput());
}

void MainWindow::tempGenerate()
{
    QString templ = ui->lineEditTemplate->text();

    QProcess run;
    connect(&run, SIGNAL(error(QProcess::ProcessError)), this, SLOT(onProcessError(QProcess::ProcessError)));
    run.start(QString("./PassGen -t %1").arg(templ), QIODevice::ReadOnly);
    run.waitForFinished();
    QString err = run.readAllStandardError();
    if (!err.isEmpty())
    {
        emit printError(err);
        return;
    }
    if (run.error() == 5)
        showResult(run.readAllStandardOutput());
}
