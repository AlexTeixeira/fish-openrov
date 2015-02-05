#include <QString>
#include <QtTest>
#include "../model/fish.h"

class FishTest : public QObject
{
    Q_OBJECT

public:
    FishTest();

private Q_SLOTS:
    void testId();
    void testName();
    void testSize();
    void testConstructor();
};

void FishTest::testId()
{
    Fish *f= new Fish();
    f->SetId(1337);
    QVERIFY(f->GetId() == 1337);
}

void FishTest::testName()
{
    Fish *f= new Fish();
    f->SetName("Nemo");
    QVERIFY(f->GetName() == QString("Nemo"));
}

void FishTest::testSize()
{
    Fish *f= new Fish();
    f->SetSize(52.35);
    QVERIFY(f->GetSize() == 52.35);
}

void FishTest::testConstructor()
{
    Fish *f= new Fish(1337,"Nemo",52.35);
    QVERIFY(f->GetId() == 1337);
    QVERIFY(f->GetName() == QString("Nemo"));
    QVERIFY(f->GetSize() == 52.35);
}
