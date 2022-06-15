#include "myfirst.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graphic_Scene w;
    w.resize(1100,850);


    w.show();
    return a.exec();
}
