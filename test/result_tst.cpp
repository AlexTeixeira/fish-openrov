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
    QFETCH(int, anId);
    r1->SetId(anId);
    QTEST(r1->GetId(), "anId");
}

void ResultTest::testId_data()
{
    QTest::addColumn<int>("anId");
    QTest::newRow("integer") << 4587;
}


void ResultTest::testName()
{
    QFETCH(QString, aString);
    r1->SetName(aString);
    QTEST(r1->GetName(), "aString");
}

void ResultTest::testName_data()
{
    QTest::addColumn<QString>("aString");
    QTest::newRow("QString") << "Observation 1";
}

void ResultTest::testDate()
{
    QFETCH(QDate, aDate);
    r1->SetDate(aDate);
    QTEST(r1->GetDate(), "aDate");
}

void ResultTest::testDate_data(){
    QTest::addColumn<QDate>("aDate");
    QTest::newRow("QDate") << QDate(2015, 2, 8);
}

void ResultTest::testDescription()
{
    QFETCH(QString, aString);
    r1->SetName(aString);
    QTEST(r1->GetName(), "aString");
}

void ResultTest::testDescription_data(){
    QTest::addColumn<QString>("aString");
    QTest::newRow("QString") << "Jours Pluvieux";
}

void ResultTest::cleanupTestCase()
{
    delete r1;
    delete r2;
}
