#ifndef FISH_TST
#define FISH_TST
#include <QObject>
#include <QtTest/QtTest>
#include <QString>
#include "../model/fish.h"

class FishTest : public QObject
{
    Q_OBJECT

public:

    explicit FishTest(QObject *parent = 0);

private:

    Fish *f1;

private slots:

    void initTestCase();
    void testId();
    void testId_data();
    void testName();
    void testName_data();
    void testSize();
    void testSize_data();
    void cleanupTestCase();

};
#endif // FISH_TST
