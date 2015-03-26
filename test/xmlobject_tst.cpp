#include "xmlobject_tst.h"

XmlObject_tst::XmlObject_tst(QObject *parent) : QObject(parent)
{

}

void XmlObject_tst::initTestCase()
{
//    QFETCH(int, anID);
//    QFETCH(QString, aName);
//    QFETCH(QString, aPath);


    xml1=new XmlObject(123,"aName","aPath");
/*
    QTEST(xml1->GetId(),"anID");
    QTEST(xml1->GetName(),"aName");
    QTEST(xml1->GetPath(),"aPath");
*/
}

void XmlObject_tst::initTestCase_data()
{
    QTest::addColumn<int>("anID");
    QTest::addColumn<QString>("aName");
    QTest::addColumn<QString>("aPath");
    QTest::newRow("XmlObjectTest")<<123<<"XmlObject"<<"c:\\ProgramData\\FishRov\\xmlobject.xml";
}

void XmlObject_tst::testId()
{
    QFETCH(int, anId1);
    xml1->SetId(anId1);
    QTEST(xml1->GetId(),"anId1");
}

void XmlObject_tst::testId_data()
{
    QTest::addColumn<int>("anId1");
    QTest::newRow("integer")<<123;
}

void XmlObject_tst::testName()
{
    QFETCH(QString,aName1);
    xml1->SetName(aName1);
    QTEST(xml1->GetName(),"aName1");
}

void XmlObject_tst::testName_data()
{
    QTest::addColumn<QString>("aName1");

    QTest::newRow("string without spaces") << "TestName";
    QTest::newRow("string with spaces") << "Test Name";
    QTest::newRow("string with special characters") << "Test Name /!%K";
}

void XmlObject_tst::testPath()
{
    QFETCH(QString,aPath1);
    xml1->SetPath(aPath1);
    QTEST(xml1->GetPath(),"aPath1");
}

void XmlObject_tst::testPath_data()
{
    QTest::addColumn<QString>("aPath1");

    QTest::newRow("path Windows") << "C:\\ProgramData\\FishRov\\xmlobject.xml";
    QTest::newRow("path Unix") << "\\home\\FishRov\\xmlobject.xml";
}

void XmlObject_tst::cleanupTestCase()
{
    delete xml1;
}

