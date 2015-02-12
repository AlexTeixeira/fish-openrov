#include "processing_tst.h"

ProcessingTest::ProcessingTest(QObject *parent) :
    QObject(parent)
{
}

void ProcessingTest::initTestCase()
{
    p1 = new Processing();
}

void ProcessingTest::testId()
{
    QFETCH(int, anId);
    p1->SetId(anId);
    QTEST(p1->GetId(), "anId");
}

void ProcessingTest::testId_data()
{
    QTest::addColumn<int>("anId");
    QTest::newRow("integer") << 4587;
}

void ProcessingTest::testResult()
{
    Result *r1 = new Result(123, "Antibes-Salis", QDate(2013, 2, 8), "Observation 1");
    p1->SetResult(r1);
    QVERIFY(p1->GetResult()->GetId() == 123);
    QVERIFY(p1->GetResult()->GetName() == QString("Antibes-Salis"));
    QVERIFY(p1->GetResult()->GetDate().isValid());
    QCOMPARE(p1->GetResult()->GetDate().day(), 8);
    QCOMPARE(p1->GetResult()->GetDate().month(), 2);
    QCOMPARE(p1->GetResult()->GetDate().year(), 2013);
    QVERIFY(p1->GetResult()->GetDescription() == QString("Observation 1"));
}

void ProcessingTest::testResult_data()
{
    //Result *r1 = new Result(123, "Antibes-Salis", QDate(2013, 2, 8), "Observation 1");
    QTest::addColumn<Result>("r1");
    Result r1;
}

void ProcessingTest::cleanupTestCase()
{
    delete p1;
}
