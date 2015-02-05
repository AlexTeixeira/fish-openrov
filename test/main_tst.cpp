#include <QtTest/QtTest>
#include <fish_tst.h>
#include <frame_tst.h>

int main()
{
    FishTest fit;
    QTest::qExec(&fit);
    FrameTest frt;
    QTest::qExec(&frt);
}
