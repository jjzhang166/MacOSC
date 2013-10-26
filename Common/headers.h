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

#ifndef HEADERS_H
#define HEADERS_H

//c or std headers
#include <stdio.h>
//Qt headers
//#include <QDebug>
//#include <QLabel>
//#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QtXml>
//network
#include <QMovie>
#include <QPushButton>
#include <QUrl>
#include <QUrlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtWebKit>
#include <QtWebKitWidgets/QWebView>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
//custom headers
#include "Common/urls.h"
#include "conststrings.h"
#include "Common/xmlnodenames.h"
#include "Common/dbconfig.h"
//models
#include "Models/oscuser.h"
#include "Utils/xmlparserutil.h"
#include "Utils/oscdbutil.h"
// windows
#include "Classes/oscloginwindow.h"
#include "Classes/oscmainwindow.h"

#endif // HEADERS_H
