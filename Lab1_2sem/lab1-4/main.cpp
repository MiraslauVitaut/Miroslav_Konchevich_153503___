#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Receipts");
    w.show();
    return a.exec();
}
