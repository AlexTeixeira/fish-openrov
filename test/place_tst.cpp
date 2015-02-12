#include "place_tst.h"
#include "../model/fish.h"

PlaceTest::PlaceTest(QObject *parent) : QObject(parent)
{

}

void PlaceTest::initTestCase()
{

        p1 = new Place();
    //    p2 = new Place (3,"video name");
}

void PlaceTest::testId()
{
        QFETCH(int, anId);
        p1->SetId(anId);
        QTEST(p1->GetId(), "anId");

        /* ancien version
        p1->SetId(4579);
        QVERIFY(p1->GetId()==4579);
        QVERIFY(p2->GetId()==3);*/
}

void PlaceTest::testId_data()
{
        QTest::addColumn<int>("anId");
        QTest::newRow("integer") << 154;
}
void PlaceTest::testName()
{
        QFETCH(QString, aString);
        p1->SetName(aString);
        QTEST(p1->GetName(), "aString");
}



void PlaceTest::testListFish()
{

<<<<<<< HEAD
    Fish *f3 = new Fish(3,"name fish",54.32);
    p1->SetListFish(new QList<Fish>());
           //p1->AddFish(f3);
=======
   // Fish *f3 = new Fish(3,"name fish",54.32);
   // p1->SetListFish(new QList<Fish>());
   //        p1->AddFish(f3);
>>>>>>> f96e79913c3699b43beb758a1cfd930c2f713c74
}

void PlaceTest::cleanupTestCase()

{
    delete p1;
}
