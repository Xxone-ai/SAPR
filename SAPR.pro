#-------------------------------------------------
#
# Project created by QtCreator 2016-11-17T16:43:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SAPR
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rod.cpp \
    rodcreator.cpp \
    vertexforcecreator.cpp \
    resulttable.cpp \
    rodtable.cpp

HEADERS  += mainwindow.h \
    rod.h \
    rodcreator.h \
    vertexforcecreator.h \
    resulttable.h \
    rodtable.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
