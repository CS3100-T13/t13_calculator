#include "mainwindow.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MUP_STRING_TYPE mathString;

    mathString = _T("6/0");

    model::parse_string(mathString);

    return a.exec();
}
