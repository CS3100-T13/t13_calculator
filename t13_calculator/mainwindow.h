#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public NotificationSubscriber
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void notificationRecieved( const NotificationID name );

private:
    Ui::MainWindow *ui;
    model mdl;
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
