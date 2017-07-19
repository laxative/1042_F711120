#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T19:27:33
#
#-------------------------------------------------

QT       += core gui  multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    basic.cpp \
    Item.cpp \
    result.cpp

HEADERS  += mainwindow.h \
    basic.h \
    Item.h \
    result.h

FORMS    += mainwindow.ui \
    result.ui \
    basic.ui

RESOURCES += \
    resources.qrc \
    bgm.qrc
