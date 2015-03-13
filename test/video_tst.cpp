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
    QList<Frame*> frList;

    Frame *fr1 = new Frame();

    QFETCH(int, anId);
    fr1->SetId(anId);

    QFETCH(QString,aString);
    fr1->SetName(aString);

    frList.append(fr1);

    v1->SetListFrame(frList);

    QTEST(v1->GetListFrame().at(0)->GetId(), "anId");
    QTEST(v1->GetListFrame().at(0)->GetName(), "aString");

}
void VideoTest::testListFrame_data()
{
    QTest::addColumn<int>("anId");
    QTest::addColumn<QString>("aString");

    QTest::newRow("ListTest")<<123<<"myFrame";
}

void VideoTest::cleanupTestCase()
{
    delete v1;
}
