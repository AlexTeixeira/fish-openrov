#include <QtTest/QtTest>
#include <QDebug>
#include <QApplication>
#include "fish_tst.h"
#include "frame_tst.h"
#include "result_tst.h"
#include "video_tst.h"
#include "place_tst.h"
#include "processing_tst.h"
#include "xmlobject_tst.h"
#include "webservice_tst.h"
#include "../mainwindow.h"

int main(int argc, char *argv[])
{
    FishTest fit;
    QTest::qExec(&fit);
    FrameTest frt;
    QTest::qExec(&frt);
    ResultTest rst;
    QTest::qExec(&rst);
    VideoTest vit;
    QTest::qExec(&vit);
    PlaceTest plt;
    QTest::qExec(&plt);
    ProcessingTest prt;
    QTest::qExec(&prt);
    XmlObject_tst xmt;
    QTest::qExec(&xmt);
    WebService wbt;
    QTest::qExec(&wbt);

    // Lancement de l'application //
    QApplication a(argc, argv);

    // Lancement de l'interface //
    MainWindow w;
    w.show();

    return a.exec();
}
