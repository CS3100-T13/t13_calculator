#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
/*
private slots:
    void change_text_press_released();
    */

private slots:
    void digits_pressed();
    void on_pushButton_decimal_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_pushButton_equals_released();
    void binary_operation_pressed();
};

#endif // MAINWINDOW_H
