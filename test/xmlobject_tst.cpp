#include "xmlobject_tst.h"

xmlobject_tst::xmlobject_tst(QObject *parent) : QObject(parent)
{

}

xmlobject_tst::~xmlobject_tst()
{

}

void xmlobject_tst::initTestCase()
{
    xml1=new XmlObject();
}

void xmlobject_tst::testId()
{
    QFETCH(int, anId);
    xml1->SetId(anId);
    QTEST(xml1->GetId(),"anId");
}

void xmlobject_tst::testId_data()
{
    QTest::addColumn<int>("anId");
    QTest::newRow("integer")<<123;
}

void xmlobject_tst::testName()
{
    QFETCH(QString,aName);
    xml1->SetName(aName);
    QTEST(xml1->GetName(),"aName");
}

void xmlobject_tst::testName_data()
{
    QTest::addColumn<QString>("aName");

    QTest::newRow("string without spaces") << "TestName";
    QTest::newRow("string with spaces") << "Test Name";
    QTest::newRow("string with special characters") << "Test Name /!%K";
}

void xmlobject_tst::testPath()
{
    QFETCH(QString,aPath);
    xml1->SetPath(aPath);
    QTEST(xml1->GetPath(),"aPath");
}

void xmlobject_tst::testPath_data()
{


}
