#include "oscmainwindow.h"
#include "ui_oscmainwindow.h"

OSCMainWindow::OSCMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OSCMainWindow)
{
    ui->setupUi(this);
    OSCDbUtil *d  = OSCDbUtil::getDbHelper();
}

OSCMainWindow::~OSCMainWindow()
{
    delete ui;
}
