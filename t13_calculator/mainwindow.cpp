#include "mainwindow.h"
#include "ui_mainwindow.h"

/* Window Lifecycle Functions *************************************************/

const char * const DISPLAY_TEXT_OPTIONS[] = {
  "Hi",
  "Bye"
};

/* Window Lifecycle Functions *************************************************/

/* Constructor */
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  /* Initialize  ui object */
  ui->setupUi( this );

  /* Initialize UI elements */
  ui->label_display->setText( DISPLAY_TEXT_OPTIONS[ 0 ] );

  /* Connect Signals to Slots */
  connect(
    ui->button_changeText,
    SIGNAL(released()),
    this, SLOT(change_text_press_released() )
  );
}

/* Destructor */
MainWindow::~MainWindow()
{
  delete ui;
}

/* Slots **********************************************************************/

/* Called when button is pressed */
void MainWindow::change_text_press_released() {

  /* Convienience variables */
  QString currentDisplayText = ui->label_display->text();
  QString displayOption0 = DISPLAY_TEXT_OPTIONS[ 0 ];
  int compareValue;

  /* Determine if the current display text is equal to the 0th option */
  compareValue = QString::compare(
    currentDisplayText,
    displayOption0,
    Qt::CaseInsensitive
  );

  /* If the current display text is equal to the 0th option... */
  if( compareValue == 0 ) {

    /* ...change the display text to the 1st option. */
    ui->label_display->setText( DISPLAY_TEXT_OPTIONS[ 1 ] );

  } else {

    /* ...change the display text to the 0th option. */
    ui->label_display->setText( DISPLAY_TEXT_OPTIONS[ 0 ] );
  }

}
