#ifndef PLACETEST_H
#define PLACETEST_H
#include <../model/place.h>
#include <QtTest/QtTest>

#include <QObject>

class PlaceTest : public QObject
{
    Q_OBJECT
public:
    explicit PlaceTest(QObject *parent = 0);

private:

    Place *p1;
    Place *p2;

private slots:

    void initTestCase();
    void testId();
    void testId_data();
    void testName();
    void testName_data();
    void testListFish();
    void testListFish_data();
    void cleanupTestCase();

};


#endif // PLACETEST_H
