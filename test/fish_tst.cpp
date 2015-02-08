#include "fish_tst.h"

FishTest::FishTest(QObject *parent) :
    QObject(parent)
{
}

void FishTest::initTestCase()
{
    f1 = new Fish();
    f2 = new Fish(666, "Red", 16.23);
}

void FishTest::testId()
{
    f1->SetId(1337);
    QVERIFY(f1->GetId() == 1337);
    QVERIFY(f2->GetId() == 666);
}

void FishTest::testName()
{
    f1->SetName("Nemo");
    QVERIFY(f1->GetName() == QString("Nemo"));
    QVERIFY(f2->GetName() == QString("Red"));
}

void FishTest::testSize()
{
    f1->SetSize(52.35);
    QVERIFY(f1->GetSize() == 52.35);
    QVERIFY(f2->GetSize() == 16.23);
}

void FishTest::cleanupTestCase()
{
    delete f1;
    delete f2;
}
