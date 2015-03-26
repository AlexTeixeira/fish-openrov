#ifndef XMLOBJECT_TST_H
#define XMLOBJECT_TST_H

#include <QObject>
#include <QtTest/QtTest>
#include <QString>
//#include <QList>
//#include <QtXml>
#include "../model/xmlobject.h"



class XmlObject_tst : public QObject
{
    Q_OBJECT
public:
    explicit XmlObject_tst(QObject *parent = 0);


private:
    XmlObject *xml1;


signals:

private slots:


    void initTestCase();
    void initTestCase_data();
    void cleanupTestCase();


    void testId();
    void testId_data();
    void testName();
    void testName_data();
    void testPath();
    void testPath_data();


};

#endif // XMLOBJECT_TST_H






