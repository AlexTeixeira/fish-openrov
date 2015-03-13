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
    QFETCH(int, anId);
    f1->SetId(anId);
    QTEST(f1->GetId(), "anId");

}

void FrameTest::testId_data()
{
    QTest::addColumn<int>("anId");
    QTest::newRow("integer") << 4587;
}

void FrameTest::testName()
{
    QFETCH(QString, aString);
    f1->SetName(aString);
    QTEST(f1->GetName(), "aString");
}

void FrameTest::testName_data(){
    QTest::addColumn<QString>("aString");
    QTest::newRow("QString") << "nameFrame";
}

void FrameTest::cleanupTestCase()
{
    delete f1;
    delete f2;
}
