#include "fish_tst.h"

FishTest::FishTest(QObject *parent) :
    QObject(parent)
{
}

void FishTest::initTestCase()
{
    f1 = new Fish();
}

void FishTest::testId()
{
    // Pattern Unit Test
    QFETCH(int, anId);
    f1->SetId(anId);
    QTEST(f1->GetId(), "anId");
}

void FishTest::testId_data()
{
    QTest::addColumn<int>("anId");
    QTest::newRow("integer") << 154;
}

void FishTest::testName()
{
    QFETCH(QString, aString);
    f1->SetName(aString);
    QTEST(f1->GetName(), "aString");
}

void FishTest::testName_data()
{
    QTest::addColumn<QString>("aString");
    QTest::newRow("string without spaces") << "TestName";
    QTest::newRow("string with spaces") << "Test Name";
    QTest::newRow("string with special characters") << "Test Name /!%K";
}

void FishTest::testSize()
{
    QFETCH(double, aDouble);
    f1->SetSize(aDouble);
    QTEST(f1->GetSize(), "aDouble");
}

void FishTest::testSize_data()
{
    QTest::addColumn<double>("aDouble");
    QTest::newRow("double") << 154.05;
}

void FishTest::cleanupTestCase()
{
    delete f1;
}
