#include "oscloginwindow.h"
#include "ui_oscloginwindow.h"

OSCLoginWindow::OSCLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OSCLoginWindow)
{
    ui->setupUi(this);
//    QLabel *l = new QLabel();
//    l->setMinimumSize(100,100);
//    l->setText("<a href=\"http://zhucongqi.cn/\">Click Here!</a>");
//    l->setTextFormat(Qt::RichText);
//    l->setTextInteractionFlags(Qt::TextBrowserInteraction);
//    l->setOpenExternalLinks(true);
//    l->show();
    initLoginWindow();
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

void OSCLoginWindow::initLoginWindow()
{
    //init register button
    ui->registerButton->setText(REGISTER_TEXT);
    ui->registerButton->setTextFormat(Qt::RichText);
    ui->registerButton->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->registerButton->setOpenExternalLinks(true);
    //init forget password button
    ui->forgetPassword->setText(FORGETPASSWORD_TEXT);
    ui->forgetPassword->setTextFormat(Qt::RichText);
    ui->forgetPassword->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->forgetPassword->setOpenExternalLinks(true);
}

void OSCLoginWindow::aboutMacOSCAction()
{
    qDebug() << "about";
}
