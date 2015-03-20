#ifndef XMLOBJECT_TST_H
#define XMLOBJECT_TST_H

#include <QObject>
#include <QtTest/QtTest>
#include <QString>
#include <QList>
#include <QtXml>
#include "../model/xmlobject.h"



class xmlobject_tst : public QObject
{
    Q_OBJECT
public:
    explicit xmlobject_tst(QObject *parent = 0);
    ~xmlobject_tst();


private:
    XmlObject *xml1;


signals:

private slots:

    void initTestCase();
    void testId();
    void testId_data();
    void testName();
    void testName_data();
    void testPath();
    void testPath_data();
    void cleanupTestCase();


};

#endif // XMLOBJECT_TST_H
