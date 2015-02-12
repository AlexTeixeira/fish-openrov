#include "video_tst.h"

VideoTest::VideoTest(QObject *parent) :
    QObject(parent)
{
}

void VideoTest::initTestCase()
{
    v1 = new Video();
    v2 = new Video (3,"video name");
}

void VideoTest::testId()
{
    v1->SetId(4579);
    QVERIFY(v1->GetId()==4579);
    QVERIFY(v2->GetId()==3);
}

void VideoTest::testName()
{
    v1->SetName("v1");
    QVERIFY(v1->GetName()=="v1");
    QVERIFY(v2->GetName()=="video name");
}

void VideoTest::testListFrame()
{

    Frame *f3 = new Frame(3,"name fish");
    v1->SetListFrame(new QList<Frame>());
            //v1->AddFrame(f3);
}

void VideoTest::cleanupTestCase()
{
    delete v1;
    delete v2;
}
