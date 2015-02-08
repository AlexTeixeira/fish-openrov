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
    Fish *f2;

private slots:

    void initTestCase();
    void testId();
    void testName();
    void testSize();
    void cleanupTestCase();

};
#endif // FISH_TST
