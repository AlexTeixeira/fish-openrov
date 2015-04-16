#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T14:23:23
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
                                        multimedia \
                                        multimediawidgets \
                                        network

TARGET = FISH-OPENROV
TEMPLATE = app

SOURCES += main.cpp \
    model/xmlobject.cpp \
    model/fish.cpp \
    model/place.cpp \
    model/webservice.cpp \
    model/library.cpp \
    model/processing.cpp \
    model/result.cpp \
    model/frame.cpp \
    model/video.cpp \
    principal.cpp \
    # Model Media Player #
    model/histogramwidget.cpp \
    model/player.cpp \
    model/playercontrols.cpp \
    model/playlistmodel.cpp \
    model/videowidget.cpp   \
    loginwindow.cpp

HEADERS += model/xmlobject.h \
    model/fish.h \
    model/place.h \
    model/webservice.h \
    model/library.h \
    model/processing.h \
    model/result.h \
    model/frame.h \
    model/video.h \
    principal.h \
    # Source Media Player #
    model/histogramwidget.h \
    model/player.h \
    model/playercontrols.h \
    model/playlistmodel.h \
    model/videowidget.h \
    loginwindow.h

maemo* {
    DEFINES += PLAYER_NO_COLOROPTIONS
}

FORMS += principal.ui \
        loginwindow.ui

RESOURCES += resources.qrc
