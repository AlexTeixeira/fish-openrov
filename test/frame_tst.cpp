//#include <QString>
//#include <QtTest>
//#include "../model/frame.h"

//class MyFirstUnitTest : public QObject
//{
//    Q_OBJECT

//public:
//    MyFirstUnitTest();

//    // les slots à utiliser pendant les tests
//private Q_SLOTS:
//    void testCase1_data();
//    void testCase1();
//};



//MyFirstUnitTest::MyFirstUnitTest()
//{
//}



//// les données pour le test

//void MyFirstUnitTest::testCase1_data()
//{
//    QTest::addColumn<int>("first");
//    QTest::addColumn<string>("second");
//    //QTest::addColumn<int>("expected");

//    QTest::newRow("compare01") << 0 << "premier";
//    QTest::newRow("compare02") << -5 << "second";
//    QTest::newRow("compare03") << 10 << "tertiaire";
//}


//// fonction qui fait les testes
//void MyFirstUnitTest::testCase1()
//{
//    // changer le classe de l'objet classAtester
//    Frame classAtester = new Frame();


//    // modifier les variables dans le tableau
//    QFETCH(int, first);
//    QFETCH(string, second);
//  //  QFETCH(int, expected);


//    int actual = classAtester(first,second); // la fonction à tester de classAtester

//    //QCOMPARE(actual, expected); // comparaison de resultat de teste avec resultat attendu

//}
//void MyFirstUnitTest::testCase1()
//{

//}

//QTEST_APPLESS_MAIN(MyFirstUnitTest)

//#include "tst_myfirstunittest.moc"


