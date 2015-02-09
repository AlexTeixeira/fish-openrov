#include "processing_tst.h"

ProcessingTest::ProcessingTest(QObject *parent) :
    QObject(parent)
{
}

void ProcessingTest::initTestCase()
{
    p1 = new Processing();
    p2 = new Processing(456);
}

void ProcessingTest::testId()
{
    p1->SetId(753);
    QVERIFY(p1->GetId() == 753);
    QVERIFY(p2->GetId() == 456);
}

void ProcessingTest::testResult()
{
    Result *r1 = new Result(123, "Antibes-Salis", QDate(2013, 2, 8), "Observation 1");
    Result *r2 = new Result(951, "Antibes-Gravette", QDate(2015, 6, 21), "Observation N°754");
    p1->SetResult(r1);
    p2->SetResult(r2);
    QVERIFY(p1->GetResult()->GetId() == 123);
    QVERIFY(p2->GetResult()->GetId() == 951);
    QVERIFY(p1->GetResult()->GetName() == QString("Antibes-Salis"));
    QVERIFY(p2->GetResult()->GetName() == QString("Antibes-Gravette"));
    QVERIFY(p1->GetResult()->GetDate().isValid());
    QVERIFY(p2->GetResult()->GetDate().isValid());
    QCOMPARE(p1->GetResult()->GetDate().day(), 8);
    QCOMPARE(p2->GetResult()->GetDate().day(), 21);
    QCOMPARE(p1->GetResult()->GetDate().month(), 2);
    QCOMPARE(p2->GetResult()->GetDate().month(), 6);
    QCOMPARE(p1->GetResult()->GetDate().year(), 2013);
    QCOMPARE(p2->GetResult()->GetDate().year(), 2015);
    QVERIFY(p1->GetResult()->GetDescription() == QString("Observation 1"));
    QVERIFY(p2->GetResult()->GetDescription() == QString("Observation N°754"));
}

void ProcessingTest::cleanupTestCase()
{
    delete p1;
    delete p2;
}
