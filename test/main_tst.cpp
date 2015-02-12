#include <QtTest/QtTest>
#include <QDebug>
#include "fish_tst.h"
#include "frame_tst.h"
#include "result_tst.h"
#include "video_tst.h"
#include "place_tst.h"
#include "processing_tst.h"

int main()
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
}
