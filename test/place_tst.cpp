#include "place_tst.h"
#include "../model/fish.h"

PlaceTest::PlaceTest(QObject *parent) : QObject(parent)
{

}

void PlaceTest::initTestCase()
{

        p1 = new Place();
        p2 = new Place(13,"new place");

        //f1 = new Fish (3,"video name");
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
        QFETCH(QString, aName);
        p1->SetName(aName);
        QTEST(p1->GetName(), "aName");
}

void PlaceTest::testName_data()
{
    QTest::addColumn<QString>("aName");
    QTest::newRow("string without spaces") << "FishDeListe";
    QTest::newRow("string with spaces") << "Fish De Liste";
    QTest::newRow("string with special characters") << "F15h de l1%^57e /!%K";
}


void PlaceTest::testListFish()
{
    /*QFETCH(QString, aNameFish);
    Fish * f2= new Fish(4,"FishDeListe",74.3);
    p2->AddFish(f2);
    QTEST(p2->GetListFish().takeFirst()->GetName(),"aNameFish");*/
}

void PlaceTest::testListFish_data()
{


}

void PlaceTest::cleanupTestCase()

{
    delete p1;
    delete p2;
}
