#include "place_tst.h"

PlaceTest::PlaceTest(QObject *parent) : QObject(parent)
{

}

void PlaceTest::initTestCase()
{
    p1 = new Place();
}

void PlaceTest::testId()
{
    QFETCH(int, anId);
    p1->SetId(anId);
    QTEST(p1->GetId(), "anId");
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
    QList<Fish*> fList;

    Fish *f1 = new Fish();

    QFETCH(int, anId);
    f1->SetId(anId);

    QFETCH(QString, aString);
    f1->SetName(aString);

    QFETCH(double, aDouble);
    f1->SetSize(aDouble);

    fList.append(f1);

    p1->SetListFish(fList);

    QTEST(p1->GetListFish().at(0)->GetId(), "anId");
    QTEST(p1->GetListFish().at(0)->GetName(), "aString");
    QTEST(p1->GetListFish().at(0)->GetSize(), "aDouble");
}

void PlaceTest::testListFish_data()
{
    QTest::addColumn<int>("anId");
    QTest::addColumn<QString>("aString");
    QTest::addColumn<double>("aDouble");

    QTest::newRow("ListTest") << 1 << "Sardine" << 1.23;
}

void PlaceTest::cleanupTestCase()
{
    delete p1;
}
