#-------------------------------------------------
#
# Project created by BruceZCQ 2013-10-01T08:14:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MacOSC
TEMPLATE = app


SOURCES += main.cpp\
    Classes/oscloginwindow.cpp

HEADERS  += \
    Classes/oscloginwindow.h

FORMS    += Classes/oscloginwindow.ui

OTHER_FILES += \
    README.md \
    icon.png
