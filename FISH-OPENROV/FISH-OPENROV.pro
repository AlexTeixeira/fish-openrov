#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T14:23:23
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FISH-OPENROV
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    model/xmlobject.cpp \
    model/fish.cpp \
    model/place.cpp \

HEADERS  += mainwindow.h \
    model/xmlobject.h \
    model/fish.h \
    model/place.h

FORMS    += mainwindow.ui
