#-------------------------------------------------
#
# Project created by QtCreator 2015-02-08T18:49:33
#
#-------------------------------------------------

QT       += testlib
QT       += xml
QT       -= gui

TARGET = TEST-OPENROV
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main_tst.cpp \
        fish_tst.cpp \
        frame_tst.cpp \
        result_tst.cpp \
        ../model/fish.cpp \
        ../model/place.cpp \
        ../model/processing.cpp \
        ../model/library.cpp \
        ../model/video.cpp \
        ../model/result.cpp \
        ../model/webservice.cpp \
        ../model/xmlobject.cpp \
        ../model/frame.cpp \
    video_tst.cpp \
    place_tst.cpp

HEADERS  += fish_tst.h \
        frame_tst.h \
        result_tst.h \
        ../model/fish.h \
        ../model/place.h \
        ../model/processing.h \
        ../model/library.h \
        ../model/video.h \
        ../model/result.h \
        ../model/webservice.h \
        ../model/xmlobject.h \
        ../model/frame.h \
    video_tst.h \
    place_tst.h
