#ifndef RESULT_TST_H
#define RESULT_TST_H
#include <QObject>
#include <QtTest/QtTest>
#include <QString>
#include <QDate>
#include "../model/result.h"

class ResultTest : public QObject
{
    Q_OBJECT

public:

    explicit ResultTest(QObject *parent = 0);

private:

    Result *r1;
    Result *r2;

private slots:

    void initTestCase();
    void testId();
    void testName();
    void testDate();
    void testDescription();
    void cleanupTestCase();

};

#endif // RESULT_TST_H
