#ifndef URLS_H
#define URLS_H

//protocols
#define HTTP_PROTOCOL tr("http://")
#define HTTPS_PROTOCOL tr("http://")
//base url
#define OSC_HTTP_BASE_URL \
        QString(HTTP_PROTOCOL).append(tr("www.oschina.net/"))
#define OSC_HTTPS_BASE_URL \
    QString(HTTPS_PROTOCOL).append(tr("www.oschina.net/"))
//login url
#define OSC_HTTP_LOGIN_URL \
        QUrl(QString(OSC_HTTP_BASE_URL) \
            .append(tr("action/api/login_validate")))
#define OSC_HTTPS_LOGIN_URL \
        QUrl(QString(OSC_HTTPS_BASE_URL) \
            .append(tr("action/api/login_validate")))


#endif // URLS_H
