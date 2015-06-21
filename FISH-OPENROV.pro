#-------------------------------------------------
#
# Project created by QtCreator 2015-01-16T14:23:23
#
#-------------------------------------------------

QT       += core gui xml
QT       += sql

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
    loginwindow.cpp \
    model/security/cryptography.cpp \
    model/database/sqlconnection.cpp \
    #User Manangement #
    usermanagement.cpp \
    usermanagement/adduser.cpp \
    usermanagement/confirm.cpp \
    usermanagement/edituser.cpp \

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
    loginwindow.h \
    model/security/cryptography.h \
    model/database/sqlconnection.h \
    #User Manangement #
    usermanagement.h \
    usermanagement/adduser.h \
    usermanagement/confirm.h \
    usermanagement/edituser.h

maemo* {
    DEFINES += PLAYER_NO_COLOROPTIONS
}

FORMS += principal.ui \
        loginwindow.ui \
        #User Manangement #
        usermanagement.ui \
        usermanagement/adduser.ui \
        usermanagement/confirm.ui \
        usermanagement/edituser.ui

INCLUDEPATH += C:/opencv/build/include

CONFIG( debug, debug|release ) {

LIBS += -LC:/opencv/build/x86/vc12/lib \
    -lopencv_calib3d2411d \
    -lopencv_contrib2411d \
    -lopencv_core2411d \
    -lopencv_features2d2411d \
    -lopencv_flann2411d \
    -lopencv_gpu2411d \
    -lopencv_highgui2411d \
    -lopencv_imgproc2411d \
    -lopencv_legacy2411d \
    -lopencv_ml2411d \
    -lopencv_nonfree2411d \
    -lopencv_objdetect2411d \
    -lopencv_ocl2411d \
    -lopencv_photo2411d \
    -lopencv_stitching2411d \
    -lopencv_superres2411d \
    -lopencv_ts2411d \
    -lopencv_video2411d \
    -lopencv_videostab2411d
}

else {

LIBS += -LC:/opencv/build/x86/vc12/lib \
    -lopencv_calib3d2411 \
    -lopencv_contrib2411 \
    -lopencv_core2411 \
    -lopencv_features2d2411 \
    -lopencv_flann2411 \
    -lopencv_gpu2411 \
    -lopencv_highgui2411 \
    -lopencv_imgproc2411 \
    -lopencv_legacy2411 \
    -lopencv_ml2411 \
    -lopencv_nonfree2411 \
    -lopencv_objdetect2411 \
    -lopencv_ocl2411 \
    -lopencv_photo2411 \
    -lopencv_stitching2411 \
    -lopencv_superres2411 \
    -lopencv_ts2411 \
    -lopencv_video2411 \
    -lopencv_videostab2411
}

RESOURCES += resources.qrc
