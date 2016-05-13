#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QErrorMessage>
#include <QClipboard>
#include <QProcess>

namespace Ui {
class MainWindow;
}

enum Tabs
{
    RANDOM_TAB = 0,
    TEMPLATE_TAB = 1
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void printError(QString);

private slots:
    void onTabChanged(int index);
    void onComboBoxChanged(int index);
    void onSpinBoxSizeChanged(int value);
    void onCheckBoxChecked(bool checked);
    void onLineEditTemplateChanged(QString string);

    void onProcessError(QProcess::ProcessError error);

    void showAbout(bool trigered);
    void showResult(QString result);

    void randGenerate();
    void tempGenerate();

private:
    Ui::MainWindow *ui;
    QErrorMessage *err_dialog;
};

#endif // MAINWINDOW_H
