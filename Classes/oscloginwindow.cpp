/*****************************************************************************************
 ** The MIT License (MIT)

 ** Copyright (c) 2013 BruceZCQ
 ** http://zhucongqi.cn
 ** Contact: brucezcq@gmail.com

 ** Permission is hereby granted, free of charge, to any person obtaining a copy of
 ** this software and associated documentation files (the "Software"), to deal in
 ** the Software without restriction, including without limitation the rights to
 ** use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 ** the Software, and to permit persons to whom the Software is furnished to do so,
 ** subject to the following conditions:

 ** The above copyright notice and this permission notice shall be included in all
 ** copies or substantial portions of the Software.

 ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 ** FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 ** COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 ** IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 ** CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *****************************************************************************************/

#include "oscloginwindow.h"
#include "ui_oscloginwindow.h"

OSCLoginWindow::OSCLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OSCLoginWindow)
{
    ui->setupUi(this);


    //testing data
    ui->loginname->setText("brucezcq@gmail.com");

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
    delete xml;
    delete db;
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
    //return
    connect(ui->loginname,SIGNAL(returnPressed()),
            this,SLOT(onLoginMacOSCAction()));
    connect(ui->password,SIGNAL(returnPressed()),
            this,SLOT(onLoginMacOSCAction()));
    //text changed
    connect(ui->loginname,SIGNAL(textChanged(QString)),
            this,SLOT(onClearText()));
    connect(ui->password,SIGNAL(textChanged(QString)),
            this,SLOT(onClearText()));
}

void OSCLoginWindow::initLoginWindow()
{
    //init tools
    xml = XmlParserUtil::getXmlParserUtil();
    db = OSCDbUtil::getDbHelper();

    //login flag
    loginSuccess = false;

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

    //setting focus state
    if (ui->loginname->text().length() == 0) {
        ui->loginname->setFocus();
    }else{
        ui->password->setFocus();
    }
}

void OSCLoginWindow::changeState(bool state)
{
    ui->loginname->setEnabled(state);
    ui->password->setEnabled(state);
    ui->rememberPassword->setEnabled(state);
    ui->loginButton->setEnabled(state);
}

void OSCLoginWindow::onClearText()
{
    if (!loginSuccess && ui->prompt->text().length() != 0) {
        ui->prompt->setText(CLEAR_TEXT);
    }
}

void OSCLoginWindow::onAboutMacOSCAction()
{
    qDebug() << "about";
}

void OSCLoginWindow::onLoginMacOSCAction()
{
//    OSCMainWindow *oscMainWin = new OSCMainWindow;
//    this->close();
//    oscMainWin->show();
//    return;
    if (ui->loginname->text().length() == 0
            || ui->password->text().length() ==0){
        ui->prompt->setText(RICH_TEXT(RED_COLOR,EMPTY_TEXT));
        return;
    }
    QNetworkRequest request(OSC_HTTP_LOGIN_URL);
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
    if (reply->error() != QNetworkReply::NoError) {
        ui->prompt->setText(RICH_TEXT(RED_COLOR,"貌似红薯又爆菊了"));
        return;
    }

    QString data = (QString) reply->readAll();
    if (OSC_HTTPS_LOGIN_URL == reply->url()) {
        //parse xml
        xml->setData(data);
        if (xml->isErrored()) {
            ui->prompt->setText(RICH_TEXT(RED_COLOR,CONVERT_TO_C_CHAR(xml->getErrorMessage())));
            //reopen
            changeState();
            //update focus
            ui->loginname->setFocus();
            return;
        }
        this->hide();
        //login success and update the login flag
        loginSuccess = true;
        QMovie *loadingMovie = new QMovie(":/login/loading");
        ui->prompt->setMovie(loadingMovie);
        loadingMovie->start();
       OSCUser* user = xml->getOSCUser();

       QWebView *web = new QWebView;
       web->load(QUrl(user->getPortrait()));
       web->show();
       manager->get(QNetworkRequest(QUrl("http://farm5.static.flickr.com/4101/4798839454_725882374d_b.jpg")));
    }else{
        qDebug() << "get avatar";
        QPixmap currentPicture;
        currentPicture.loadFromData(reply->readAll());
        QDateTime now;
        QString filename = now.currentDateTime().toString("yyMMddhhmmss.jpg");
        currentPicture.save(QString("/Users/BruceZCQ/Downloads/").append(filename));
        QLabel *ImageLabel = new QLabel();
//        QMovie *move = new QMovie(filename);
//        ImageLabel->setMovie(move);
//        move->start();

        ImageLabel->setPixmap(currentPicture);
        ImageLabel->show();
    }
}
