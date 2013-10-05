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

#include "xmlparserutil.h"

XmlParserUtil * XmlParserUtil::xml = NULL;
/*
 * private area
 * private functions
*/
XmlParserUtil::XmlParserUtil(const QString& data)
{
    domDoc  = new QDomDocument();
    domDoc->setContent(data);
}


quint32 XmlParserUtil::getErrorCode()
{
    return domDoc->elementsByTagName(ERROR_CODE_NODE).at(0).toElement().text().toInt();
}

QString XmlParserUtil::value(const QString& node)
{
    return domDoc->elementsByTagName(node).at(0).toElement().text();
}

void XmlParserUtil::updateData(const QString &data)
{
    domDoc->setContent(data);
}


/*
 * public area
 * Common instance handle
*/
XmlParserUtil * XmlParserUtil::getXmlParserUtil(const QString& data)
{
    if (xml == NULL) {
        xml = new XmlParserUtil(data);
    }else{
        xml->updateData(data);
    }
    return xml;
}

/**
 *public functions
 */
bool XmlParserUtil::isErrored()
{
    if (getErrorCode() != ERROR_CODE_SUCCESS) {
        qDebug() << getErrorCode();
       return true;
    }
    return false;
}

XmlParserUtil::~XmlParserUtil()
{
    delete xml;
}

QString XmlParserUtil::getErrorMessage()
{
    return domDoc->elementsByTagName(ERROR_MESSAGE_NODE).at(0).toElement().text();
}

OSCUser* XmlParserUtil::getOSCUser()
{
    //OSCUser
    QString uid = value(USER_UID_NODE);
    QString location = value(USER_LOCATION_NODE);
    QString name = value(USER_NAME_NODE);
    QString followers = value(USER_FOLLOWERS_NODE);
    QString fans = value(USER_FANS_NODE);
    QString score = value(USER_SCORE_NODE);
    QString portrait = value(USER_PORTRAIT_NODE);
    QHash<QString,QString> hash;
    hash.insert(USER_UID_NODE,uid);
    hash.insert(USER_LOCATION_NODE,location);
    hash.insert(USER_NAME_NODE,name);
    hash.insert(USER_FOLLOWERS_NODE,followers);
    hash.insert(USER_FANS_NODE,fans);
    hash.insert(USER_SCORE_NODE,score);
    hash.insert(USER_PORTRAIT_NODE,portrait);
    return (new OSCUser(hash));
}
