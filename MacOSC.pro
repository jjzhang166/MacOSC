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
    Common/common.h

FORMS    += Classes/oscloginwindow.ui

OTHER_FILES += \
    README.md \
    icon.png \
    icon.icns \
    Info.plist \
    icon.ico \
    winosc.rc \
    LICENSE
