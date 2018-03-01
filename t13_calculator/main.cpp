#include "mainwindow.h"
#include "model.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    /*
     wstring divBy0 = L"3/0";

     MUP_STRING_TYPE mathString;
     mathString = divBy0;

     string toPrint = model::parse_string(mathString);
     cout << toPrint << endl;
    */

    return a.exec();
}
