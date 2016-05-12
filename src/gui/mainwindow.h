#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

private slots:
    void onTabChanged(int index);
    void onComboBoxChanged(int index);
    void onCheckBoxChecked(bool checked);
    void showResult(QString result);

    void randGenerate();
    void tempGenerate();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
