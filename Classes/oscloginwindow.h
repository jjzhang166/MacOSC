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

class OSCLoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OSCLoginWindow(QWidget *parent = 0);
    ~OSCLoginWindow();

private:
    Ui::OSCLoginWindow *ui;
    QNetworkAccessManager *manager;
   // QMovie *loadingMovie;
    void createActions();
    void initLoginWindow();
private slots:
    void aboutMacOSCAction();
    void loginMacOSCAction();
    void onResult(QNetworkReply* reply);
};

#endif // OSCLOGINWINDOW_H
