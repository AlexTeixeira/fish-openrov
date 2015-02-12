#include "video_tst.h"

VideoTest::VideoTest(QObject *parent) :
    QObject(parent)
{
}

void VideoTest::initTestCase()
{
    v1 = new Video();
}

void VideoTest::testId()
{
    QFETCH(int, anId);
    v1->SetId(anId);
    QTEST(v1->GetId(), "anId");
}

void VideoTest::testId_data()
{
    QTest::addColumn<int>("anId");
    QTest::newRow("integer") << 154;
}

void VideoTest::testName()
{
    QFETCH(QString, aName);
    v1->SetName(aName);
    QTEST(v1->GetName(), "aName");
}
void VideoTest::testName_data()
{
    QTest::addColumn<QString>("aName");

    QTest::newRow("string without spaces") << "TestName";
    QTest::newRow("string with spaces") << "Test Name";
    QTest::newRow("string with special characters") << "Test Name /!%K";

}

void VideoTest::testListFrame()
{

    //QFETCH(QList<Frame>, aFish);
    //v1->SetListFrame(new QList<Frame>());
    //v1->AddFrame(aFish);
}
void VideoTest::testListFrame_data()
{
    /*QList<Frame> ListFrame;
    v1->SetListFrame(new QList<Frame>());
    QTest::addColumn<Frame>("aFish");
   //QTest::newRow("string without spaces") << new Frame(3,"name fish");*/

}

void VideoTest::cleanupTestCase()
{
    delete v1;
}
