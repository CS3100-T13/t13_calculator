#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dummyModel()
{
    ui->setupUi(this);

    /* Subscribe for notifications */
    dummyModel.getNotificationCenter()->subscribe( STRING_UPDATED, this );

    /* Connect Signals and Slots */
    connect(
      ui->hslider_size,
      SIGNAL( valueChanged(int) ),
      this,
      SLOT( hsliderSizeValueChanged(int) )
    );

    connect(
      ui->btn_pound,
      SIGNAL( released() ),
      this,
      SLOT( charButtonReleased() )
    );

    connect(
      ui->btn_star,
      SIGNAL( released() ),
      this,
      SLOT( charButtonReleased() )
    );

    /* Update display label */
    updateDisplayLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::notificationRecieved( const NotificationID notificationName ) {

  if( notificationName == STRING_UPDATED ) {
    updateDisplayLabel();
  }

}

void MainWindow::updateDisplayLabel() {
  ui->lbl_display->setText( dummyModel.getString() );
}

void MainWindow::hsliderSizeValueChanged( const int newValue ) {
  dummyModel.updateSize( ( size_t ) newValue );
}


void MainWindow::charButtonReleased() {

  QPushButton *btn = ( QPushButton * ) sender();
  QString text = btn->text();
  char c = text.toLatin1().data()[ 0 ];

  dummyModel.updateChar( c );

}
