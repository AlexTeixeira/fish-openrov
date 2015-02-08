#include "frame_tst.h"

FrameTest::FrameTest(QObject *parent) :
    QObject(parent)
{
}

void FrameTest::initTestCase()
{
    f1 = new Frame();
    f2 = new Frame(42, "FishFrame");
}

void FrameTest::testId()
{
    f1->SetId(1337);
    QVERIFY(f1->GetId() == 1337);
    QVERIFY(f2->GetId() == 42);
}

void FrameTest::testName()
{
    f1->SetName("TestFrame");
    QVERIFY(f1->GetName() == QString("TestFrame"));
    QVERIFY(f2->GetName() == QString("FishFrame"));
}

void FrameTest::cleanupTestCase()
{
    delete f1;
    delete f2;
}
