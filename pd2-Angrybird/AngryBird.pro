#-------------------------------------------------
#
# Project created by QtCreator 2016-06-12T16:57:19
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AngryBird
TEMPLATE = app
LIBS += -lBox2D


SOURCES += main.cpp\
        mainwindow.cpp \
    item.cpp \
    bird.cpp \
    land.cpp \
    transpoint.cpp \
    obstacle.cpp \
    contactlistener.cpp \
    pig.cpp \
    blackbird.cpp \
    redbird.cpp \
    whitebird.cpp \
    yellowbird.cpp \
    resultdialog.cpp

HEADERS  += mainwindow.h \
    item.h \
    bird.h \
    land.h \
    transpoint.h \
    obstacle.h \
    contactlistener.h \
    pig.h \
    blackbird.h \
    redbird.h \
    whitebird.h \
    yellowbird.h \
    resultdialog.h

FORMS    += mainwindow.ui \
    resultdialog.ui

RESOURCES += \
    resources.qrc
