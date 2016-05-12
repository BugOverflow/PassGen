#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));

    connect(ui->pushButtonRandomGen, SIGNAL(pressed()), this, SLOT(randGenerate()));
    connect(ui->pushButtonTemplateGen, SIGNAL(pressed()), this, SLOT(tempGenerate()));

    connect(ui->checkBoxUseSymb, SIGNAL(toggled(bool)), this, SLOT(onCheckBoxChecked(bool)));
    connect(ui->comboBoxStrength, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));

    ui->comboBoxStrength->addItem("Easy", 1);
    ui->comboBoxStrength->addItem("Medium", 2);
    ui->comboBoxStrength->addItem("Hard", 3);
    ui->comboBoxStrength->addItem("Paranoid", 4);

    ui->lineEditResult->setDisabled(true);
}

MainWindow::~MainWindow()
{
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

void MainWindow::onCheckBoxChecked(bool checked)
{
    if (checked)
        ui->comboBoxStrength->setCurrentIndex(3);
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
    run.start(QString("./PassGen -d -c%1 -s%2").arg(size).arg(stren), QIODevice::ReadOnly);
    run.waitForFinished();
    showResult(run.readAllStandardOutput());
}

void MainWindow::tempGenerate()
{
    QString templ = ui->lineEditTemplate->text();

    QProcess run;
    run.start(QString("./PassGen -t %1").arg(templ), QIODevice::ReadOnly);
    run.waitForFinished();
    showResult(run.readAllStandardOutput());
}
