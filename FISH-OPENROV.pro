#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T14:23:23
#
#-------------------------------------------------

QT       += core gui xml
QT       += testlib


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FISH-OPENROV
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    model/xmlobject.cpp \
    model/fish.cpp \
    model/place.cpp \
    model/webservice.cpp \
    model/library.cpp \
    model/processing.cpp \
    model/result.cpp \
    model/frame.cpp \
    model/video.cpp \
    test/fish_tst.cpp \
    test/frame_tst.cpp \
    test/video_tst.cpp

HEADERS  += mainwindow.h \
    model/xmlobject.h \
    model/fish.h \
    model/place.h \
    model/webservice.h \
    model/library.h \
    model/processing.h \
    model/result.h \
    model/frame.h \
    model/video.h

FORMS    += mainwindow.ui
