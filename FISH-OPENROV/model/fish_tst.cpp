#include <QString>
#include <QtTest>
#include "fish.h"

class MyFirstUnitTest : public QObject
{
    Q_OBJECT

public:
    MyFirstUnitTest();

    // les slots à utiliser pendant les tests
private Q_SLOTS:
    void testCase1_data();
    void testCase1();
};



MyFirstUnitTest::MyFirstUnitTest()
{
}



// les données pour le test

void MyFirstUnitTest::testCase1_data()
{
    QTest::addColumn<int>("first");
    QTest::addColumn<int>("second");
    QTest::addColumn<int>("expected");

    QTest::newRow("compare01") << 0 << 0 << 0;
    QTest::newRow("compare02") << 5 << 10 << -1;
    QTest::newRow("compare03") << 10 << 5 << 1;
    QTest::newRow("compare04") << -5 << -10 << 1;
    QTest::newRow("compare05") << -10 << -5 << -1;
    QTest::newRow("compare06") << 5 << -10 << 1;
    QTest::newRow("compare07") << -5 << 10 << -1;
    QTest::newRow("compare08") << 2000000000 << 10 << 1;
    QTest::newRow("compare09") << -10 << 2000000000 << -1;
    QTest::newRow("compare10") << 10 << -2000000000 << 1;
}


// fonction qui fait les testes
void MyFirstUnitTest::testCase1()
{
    // changer le classe de l'objet classAtester
    MyClass classAtester;


    // modifier les variables dans le tableau
    QFETCH(int, first);
    QFETCH(int, second);
    QFETCH(int, expected);


    int actual = classAtester.compare(first, second); // la fonction à tester de classAtester
    QCOMPARE(actual, expected); // comparaison de resultat de teste avec resultat attendu

}

QTEST_APPLESS_MAIN(MyFirstUnitTest)

#include "tst_myfirstunittest.moc"

