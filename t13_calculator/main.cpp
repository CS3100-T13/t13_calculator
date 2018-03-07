#include "mainwindow.h"
#include "model.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    string divBy0 = "3*(+4)";
    string toPrint = model::parse_string(divBy0);
    cout << toPrint << endl;


    return a.exec();
}
