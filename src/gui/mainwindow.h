#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>

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
    void showResult(QString result);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
