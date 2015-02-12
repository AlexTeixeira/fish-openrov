#include "place_tst.h"
#include "../model/fish.h"

PlaceTest::PlaceTest(QObject *parent) : QObject(parent)
{

}

void PlaceTest::initTestCase()
{

        p1 = new Place();
        p2 = new Place (3,"video name");
}

void PlaceTest::testId()
{
        p1->SetId(4579);
        QVERIFY(p1->GetId()==4579);
        QVERIFY(p2->GetId()==3);
}

void PlaceTest::testName()
{
        p1->SetName("p1");
        QVERIFY(p1->GetName()=="p1");
        QVERIFY(p2->GetName()=="video name");
}



void PlaceTest::testListFish()
{

    Fish *f3 = new Fish(3,"name fish",54.32);
    p1->SetListFish(new QList<Fish>());
           p1->AddFish(f3);
}

void PlaceTest::cleanupTestCase()

{
    delete p1;
    delete p2;
}
