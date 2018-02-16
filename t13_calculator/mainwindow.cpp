#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool userIsTypingSecondNum = false;


/* Window Lifecycle Functions *************************************************/

/* Constructor */
MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  /* Initialize  ui object */
  ui->setupUi( this );

  connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digits_pressed()));
  connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digits_pressed()));
  connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digits_pressed()));
  connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digits_pressed()));
  connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digits_pressed()));
  connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digits_pressed()));
  connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digits_pressed()));
  connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digits_pressed()));
  connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digits_pressed()));
  connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digits_pressed()));

  connect(ui->pushButton_plusMinus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
  connect(ui->pushButton_percent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

  connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
  connect(ui->pushButton_subtract,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
  connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
  connect(ui->pushButton_division,SIGNAL(released()),this,SLOT(binary_operation_pressed()));


  ui->pushButton_add->setCheckable(true);
  ui->pushButton_subtract->setCheckable(true);
  ui->pushButton_multiply->setCheckable(true);
  ui->pushButton_division->setCheckable(true);

}

/* Destructor */
MainWindow::~MainWindow()
{
  delete ui;
}



//* Slots **********************************************************************/

void MainWindow::digits_pressed()
{
  QPushButton * button = (QPushButton*)sender();

  double labelNumber;
  QString newLabel;

  if((ui->pushButton_add->isChecked() || ui->pushButton_subtract->isChecked() ||
     ui->pushButton_multiply->isChecked() || ui->pushButton_division->isChecked()) && (!userIsTypingSecondNum))
  {
      labelNumber = button->text().toDouble();
      userIsTypingSecondNum = true;
      newLabel = QString::number(labelNumber,'g',15);
  }
  else
  {
      if(ui->label->text().contains(".") && button->text() == "0")
      {
          newLabel =ui->label->text() + button->text();
      }
      else
      {
           labelNumber = (ui->label->text() + button->text()).toDouble();
           newLabel = QString::number(labelNumber,'g',15);
      }
  }


  ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_decimal_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;

    if(button->text() == "+/-")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }


    if(button->text() == "%")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * .01;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }

}




void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_subtract->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_division->setChecked(false);

    userIsTypingSecondNum = false;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum =ui->label->text().toDouble();

    if(ui->pushButton_add->isChecked())
    {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_add->setChecked(false);
    }
    else if(ui->pushButton_subtract->isChecked())
    {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_subtract->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_division->isChecked())
    {
        labelNumber = firstNum / secondNum;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label->setText(newLabel);
        ui->pushButton_division->setChecked(false);
    }

    userIsTypingSecondNum = false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);
}
