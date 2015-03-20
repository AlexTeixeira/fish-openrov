#include "library_tst.h"

LibraryTest::LibraryTest(QObject *parent) :
    QObject(parent)
{

}

void LibraryTest::initTestCase()
{
    l1 = new Library();
}

void LibraryTest::testId()
{
    // Pattern Unit Test
    QFETCH(int, anId);
    l1->SetId(anId);
    QTEST(l1->GetId(), "anId");
}

void LibraryTest::testId_data()
{
    QTest::addColumn<int>("anId");
    QTest::newRow("integer") << 154;
}

void LibraryTest::testName()
{
    QFETCH(QString, aString);
    l1->SetName(aString);
    QTEST(l1->GetName(), "aString");
}

void LibraryTest::testName_data()
{
    QTest::addColumn<QString>("aString");
    QTest::newRow("string without spaces") << "TestName";
    QTest::newRow("string with spaces") << "Test Name";
    QTest::newRow("string with special characters") << "Test Name /!%K";
}

void LibraryTest::testXmlDirPath()
{
    QFETCH(QString, aPath);
    l1->SetName(aPath);
    QTEST(l1->GetName(), "aPath");
}

void LibraryTest::testXmlDirPath_data()
{
    QTest::addColumn<QString>("aString");
    QTest::newRow("string without spaces") << "TestName";
    QTest::newRow("string with spaces") << "Test Name";
    QTest::newRow("string with special characters") << "Test Name /!%K";

}

void LibraryTest::testLoadXmlLibrary()
{
    QList<XmlObject*> xmlLibrary_tst;

    QFETCH(int, anID);
    QFETCH(QString, aName);
    QFETCH(QString, aPath);

    XmlObject xml1 = new XmlObject(anID, aName, aPath);

    xmlLibrary_tst.append(xml1);

    l1->LoadXmlLibrary(xmlLibrary_tst);
}

void LibraryTest::testLoadXmlLibrary_data()
{
    QTest::addColumn<int>("anID");
    QTest::addColumn<QString>("aName");
    QTest::addColumn<QString>("aPath");

    QTest::newRow("ListTest")<<123<<"myXmlLibrary";
}
