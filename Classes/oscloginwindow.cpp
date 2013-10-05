#include "oscloginwindow.h"
#include "ui_oscloginwindow.h"

OSCLoginWindow::OSCLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OSCLoginWindow)
{
    ui->setupUi(this);
//  init login window
    initLoginWindow();
// connect signals and slots
    createActions();
}

// mem clear
OSCLoginWindow::~OSCLoginWindow()
{
    delete ui;
    delete manager;
}

void OSCLoginWindow::createActions()
{
    //about item action
    connect(ui->actionAbout,SIGNAL(triggered()),
            this,SLOT(onAboutMacOSCAction()));
    //login button action
    connect(ui->loginButton,SIGNAL(clicked()),
            this,SLOT(onLoginMacOSCAction()));
    //network signal and slot
    connect(manager,SIGNAL(finished(QNetworkReply*)),
            this,SLOT(onLoginRequestResult(QNetworkReply*)));
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

void OSCLoginWindow::changeState(bool state)
{
    ui->loginname->setEnabled(state);
    ui->password->setEnabled(state);
    ui->rememberPassword->setEnabled(state);
    ui->loginButton->setEnabled(state);
}

void OSCLoginWindow::onAboutMacOSCAction()
{
    qDebug() << "about";
}

void OSCLoginWindow::onLoginMacOSCAction()
{
    if (ui->loginname->text().length() == 0
            || ui->password->text().length() ==0){
        ui->prompt->setText(RICH_TEXT(RED_COLOR,EMPTY_TEXT));
        return;
    }
    QNetworkRequest request(OSC_HTTPS_LOGIN_URL);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    QString params = QString("username=")
                        .append(ui->loginname->text())
                        .append("&pwd=")
                        .append(ui->password->text());
    manager->post(request,QByteArray(CONVERT_TO_C_CHAR(params)));
    changeState(false);
}

void OSCLoginWindow::onLoginRequestResult(QNetworkReply* reply)
{
    QMovie *loadingMovie = new QMovie(":/login/loading");
    ui->prompt->setMovie(loadingMovie);
    loadingMovie->start();
    QString data = (QString) reply->readAll();
    qDebug() << data;
    changeState();
}
