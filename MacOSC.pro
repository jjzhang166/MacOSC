#-------------------------------------------------
#
# Project created by BruceZCQ 2013-10-01T08:14:36
#
#-------------------------------------------------

###
# fix fellow warning to add 'cache()' in pro file
#warning: No .qmake.cache is present.
# This significantly slows down qmake
# with this makespec. warning: Call 'cache()'
# in the top-level project file to rectify this problem.
###
cache()
QT       += core gui
#network setting
QT       += network
# xml
QT       += xml

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
# MacOSC Sources
SOURCES += main.cpp\
    Classes/oscloginwindow.cpp \
    Utils/xmlparserutil.cpp \
    Models/oscuser.cpp
# MacOSC Headers
HEADERS  += \
    Classes/oscloginwindow.h \
    Common/common.h \
    Common/conststrings.h \
    Common/headers.h \
    Common/urls.h \
    Utils/xmlparserutil.h \
    Common/xmlnodenames.h \
    Models/oscuser.h
# Forms
FORMS    += Classes/oscloginwindow.ui
# images and config files
OTHER_FILES += \
    README.md \
    Info.plist \
    winosc.rc \
    LICENSE
# resources qrc file
RESOURCES += \
    osc.qrc
