#include "oscloginwindow.h"
#include "ui_oscloginwindow.h"

OSCLoginWindow::OSCLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OSCLoginWindow)
{
    ui->setupUi(this);
}

OSCLoginWindow::~OSCLoginWindow()
{
    delete ui;
}
