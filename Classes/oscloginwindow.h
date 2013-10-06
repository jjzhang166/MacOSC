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

/*
 *  开源中国MacOSC
 *  OSCLoginWindow created by BruceZCQ 2013-10-01T08:14:36
 */

#ifndef OSCLOGINWINDOW_H
#define OSCLOGINWINDOW_H

#include <QMainWindow>

#include "Common/common.h"

namespace Ui {
class OSCLoginWindow;
}

class XmlParserUtil;
class OSCDbUtil;

class OSCLoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OSCLoginWindow(QWidget *parent = 0);
    ~OSCLoginWindow();

private:
    Ui::OSCLoginWindow *ui;
    QNetworkAccessManager *manager;
    XmlParserUtil *xml;
    OSCDbUtil *db;
    bool loginSuccess;
    void createActions();
    void initLoginWindow();
    void changeState(bool state=true);
private slots:
    void onAboutMacOSCAction();
    void onLoginMacOSCAction();
    void onLoginRequestResult(QNetworkReply* reply);
    void onClearText();
};

#endif // OSCLOGINWINDOW_H
