#-------------------------------------------------
#
# Project created by QtCreator 2015-02-08T18:49:33
#
#-------------------------------------------------

QT       += testlib
QT       -= gui

TARGET = TEST-OPENROV
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main_tst.cpp \
        fish_tst.cpp \
        ../model/fish.cpp

HEADERS  += fish_tst.h \
        ../model/fish.h
