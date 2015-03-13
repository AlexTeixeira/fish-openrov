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
    Result *result = new Result();

    QFETCH(int, anId);
    result->SetId(anId);

    QFETCH(QString, aString);
    result->SetName(aString);

    QFETCH(QDate, aDate);
    result->SetDate(aDate);

    QFETCH(QString, aString2);
    result->SetDescription(aString2);

    p1->SetResult(result);

    QTEST(p1->GetResult()->GetId(), "anId");
    QTEST(p1->GetResult()->GetName(), "aString");
    QTEST(p1->GetResult()->GetDate(), "aDate");
    QTEST(p1->GetResult()->GetDescription(), "aString2");

}

void ProcessingTest::testResult_data()
{
    QTest::addColumn<int>("anId");
    //QTest::newRow("integer") << 4587;
    QTest::addColumn<QString>("aString");
    //QTest::newRow("QString") << "Antibes-Salis";
    QTest::addColumn<QDate>("aDate");
   // QTest::newRow("QDate") << QDate(2013, 2, 8);
    QTest::addColumn<QString>("aString2");
    //QTest::newRow("QString") << "Observation 1";

   QTest::newRow("ResultTest") << 1 << "Antibes-Salis" << QDate(2013, 2, 8) << "Observation 1";
}

void ProcessingTest::cleanupTestCase()
{
    delete p1;
}
