#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <notificationcenter.h>

#include "dummymodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public NotificationSubscriber
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void notificationRecieved( const NotificationID notificationName );

    void updateDisplayLabel();

private:
    Ui::MainWindow *ui;
    DummyModel dummyModel;

private slots:
    void hsliderSizeValueChanged( const int newValue );
    void charButtonReleased();
};

#endif // MAINWINDOW_H
