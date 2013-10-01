#-------------------------------------------------
#
# Project created by BruceZCQ 2013-10-01T08:14:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MacOSC
TEMPLATE = app
#config in macx platform
macx{
    ICON = icon.icns
}
#config in win32 platform
win32{
    RC_ICONS = icon.ico
    RC_FILE = winosc.rc
}

SOURCES += main.cpp\
    Classes/oscloginwindow.cpp

HEADERS  += \
    Classes/oscloginwindow.h \
    Common/common.h \
    Common/conststrings.h

FORMS    += Classes/oscloginwindow.ui

OTHER_FILES += \
    README.md \
    icon.png \
    icon.icns \
    Info.plist \
    icon.ico \
    winosc.rc \
    LICENSE \
    Resouces/woman.png \
    Resouces/software@2x.png \
    Resouces/share@2x.png \
    Resouces/share_tencent.png \
    Resouces/share_sina.png \
    Resouces/man.png \
    Resouces/Default.png \
    Resouces/Default-568h@2x.png \
    Resouces/aboutbg1136.jpg

RESOURCES += \
    osc.qrc
