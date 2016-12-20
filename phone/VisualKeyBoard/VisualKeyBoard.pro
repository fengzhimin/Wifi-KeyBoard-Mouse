#-------------------------------------------------
#
# Project created by QtCreator 2016-12-04T13:22:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisualKeyBoard
TEMPLATE = app


SOURCES += main.cpp\
        keyboard.cpp \
    num_keyboard.cpp \
    mainwindow.cpp \
    tcpsocket.cpp

HEADERS  += keyboard.h \
    num_keyboard.h \
    mainwindow.h \
    tcpsocket.h

FORMS    += keyboard.ui \
    num_keyboard.ui \
    mainwindow.ui

CONFIG += mobility
MOBILITY = 

QT += network

RESOURCES += \
    stylesheet.qrc

DISTFILES += \
    style.qss \
    ../../../Downloads/login.jpg

