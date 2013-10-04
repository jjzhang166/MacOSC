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

    manager = new QNetworkAccessManager(this);
    //新建QNetworkAccessManager对象
    connect(manager,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(onResult(QNetworkReply*)));
    //发送请求


    initLoginWindow();
    createActions();
}


void OSCLoginWindow::onResult(QNetworkReply* reply)
{
    QString data = (QString) reply->readAll();
    qDebug() << data;
}

OSCLoginWindow::~OSCLoginWindow()
{
    delete ui;
}

void OSCLoginWindow::createActions()
{
    //about item action
    connect(ui->actionAbout,SIGNAL(triggered()),
            this,SLOT(aboutMacOSCAction()));
    //login button action
    connect(ui->loginButton,SIGNAL(clicked()),
            this,SLOT(loginMacOSCAction()));
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

void OSCLoginWindow::loginMacOSCAction()
{
    if (ui->loginname->text().length() == 0
            || ui->password->text().length() ==0){
        return;
    }
    QNetworkRequest request(QUrl(OSC_LOGIN_URL));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QString params = QString("username=").append(ui->loginname->text()).append("&pwd=").append(ui->password->text());
    manager->post(request,QByteArray(params.toStdString().c_str()));

    qDebug() << "login action";
}
