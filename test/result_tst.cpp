#include "result_tst.h"

ResultTest::ResultTest(QObject *parent) :
    QObject(parent)
{
}

void ResultTest::initTestCase()
{
    r1 = new Result();
    r2 = new Result(123, "Antibes-Salis", QDate(2015, 2, 8), "Observation 1");
}

void ResultTest::testId()
{
    r1->SetId(456);
    QVERIFY(r1->GetId() == 456);
    QVERIFY(r2->GetId() == 123);
}

void ResultTest::testName()
{
    r1->SetName("New Result 025");
    QVERIFY(r1->GetName() == QString("New Result 025"));
    QVERIFY(r2->GetName() == QString("Antibes-Salis"));
}

void ResultTest::testDate()
{
    QDate date( 2002, 5, 16 );
    r1->SetDate(date);
    QVERIFY(r1->GetDate().isValid());
    QVERIFY(r2->GetDate().isValid());
    QCOMPARE(r1->GetDate().day(), 16);
    QCOMPARE(r2->GetDate().day(), 8);
    QCOMPARE(r1->GetDate().month(), 5);
    QCOMPARE(r2->GetDate().month(), 2);
    QCOMPARE(r1->GetDate().year(), 2002);
    QCOMPARE(r2->GetDate().year(), 2015);
}

void ResultTest::testDescription()
{
    r1->SetDescription("New Observation 345");
    QVERIFY(r1->GetDescription() == QString("New Observation 345"));
    QVERIFY(r2->GetDescription() == QString("Observation 1"));
}

void ResultTest::cleanupTestCase()
{
    delete r1;
    delete r2;
}
