#include <QtTest/QtTest>
#include <fish_tst.h>
#include <frame_tst.h>
#include <video_tst.h>

int main()
{
    FishTest fit;
    QTest::qExec(&fit);
    FrameTest frt;
    QTest::qExec(&frt);
    VideoTest vit;
    QTest::qExec(&vit);
}
