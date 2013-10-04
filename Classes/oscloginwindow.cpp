#include "oscloginwindow.h"
#include "ui_oscloginwindow.h"

OSCLoginWindow::OSCLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OSCLoginWindow)
{
    ui->setupUi(this);

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
    delete manager;
}

void OSCLoginWindow::createActions()
{
    //about item action
    connect(ui->actionAbout,SIGNAL(triggered()),
            this,SLOT(aboutMacOSCAction()));
    //login button action
    connect(ui->loginButton,SIGNAL(clicked()),
            this,SLOT(loginMacOSCAction()));
    //network signal and slot
    connect(manager,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(onResult(QNetworkReply*)));
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
    //init prompt
    ui->prompt->setText(CLEAR_TEXT);
    ui->prompt->setTextFormat(Qt::RichText);
    //init network manager
    manager = new QNetworkAccessManager(this);
}

void OSCLoginWindow::aboutMacOSCAction()
{
    qDebug() << "about";
}

void OSCLoginWindow::loginMacOSCAction()
{
    ui->prompt->setText(RICH_TEXT("green","1233"));
    if (ui->loginname->text().length() == 0
            || ui->password->text().length() ==0){
        return;
    }
    QNetworkRequest request(QUrl(OSC_LOGIN_URL));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QString params = QString("username=").append(ui->loginname->text()).append("&pwd=").append(ui->password->text());
    manager->post(request,QByteArray(params.toStdString().c_str()));
    ui->loginname->setEnabled(false);
    ui->password->setEnabled(false);
    ui->rememberPassword->setEnabled(false);
    ui->loginButton->setEnabled(false);

    QMovie *loadingMovie = new QMovie(":/login/loading");
    ui->prompt->setMovie(loadingMovie);
     loadingMovie->start();

    qDebug() << "login action";
}
