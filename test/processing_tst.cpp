#include "processing_tst.h"

ProcessingTest::ProcessingTest(QObject *parent) :
    QObject(parent)
{
}

void ProcessingTest::initTestCase()
{
    p1 = new Processing();
    p2 = new Processing();
}

void ProcessingTest::testId()
{
}

void ProcessingTest::cleanupTestCase()
{
    delete p1;
    delete p2;
}
