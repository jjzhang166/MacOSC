#include "Classes/oscloginwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OSCLoginWindow w;
    w.show();

    return a.exec();
}
