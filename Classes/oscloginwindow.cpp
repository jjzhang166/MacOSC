#include "oscloginwindow.h"
#include "ui_oscloginwindow.h"

OSCLoginWindow::OSCLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OSCLoginWindow)
{
    ui->setupUi(this);
    createActions();
}

OSCLoginWindow::~OSCLoginWindow()
{
    delete ui;
}

void OSCLoginWindow::createActions()
{
    connect(ui->actionAbout,SIGNAL(triggered()),
            this,SLOT(aboutMacOSCAction()));
}

void OSCLoginWindow::aboutMacOSCAction()
{
    qDebug() << "about";
}
