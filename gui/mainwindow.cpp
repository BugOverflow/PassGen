#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionExit, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));

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
}

void MainWindow::showResult(QString result)
{
    ui->lineEditResult->setEnabled(true);
    ui->lineEditResult->setText(result);
    if (ui->actionCopy_to_Clipboard->isChecked())
        QApplication::clipboard()->setText(result);
}
