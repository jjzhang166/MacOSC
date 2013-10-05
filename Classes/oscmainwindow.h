#ifndef OSCMAINWINDOW_H
#define OSCMAINWINDOW_H

#include <QMainWindow>
#include "Common/common.h"

namespace Ui {
class OSCMainWindow;
}

class OSCMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OSCMainWindow(QWidget *parent = 0);
    ~OSCMainWindow();

private:
    Ui::OSCMainWindow *ui;
};

#endif // OSCMAINWINDOW_H
