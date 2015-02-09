#ifndef PROCESSING_TST_H
#define PROCESSING_TST_H
#include <QObject>
#include <QtTest/QtTest>
#include <QString>
#include <QDate>
#include "../model/processing.h"
#include "../model/result.h"

class ProcessingTest : public QObject
{
    Q_OBJECT

public:

    explicit ProcessingTest(QObject *parent = 0);

private:

    Processing *p1;
    Processing *p2;

private slots:

    void initTestCase();
    void testId();
    void testResult();
    void cleanupTestCase();

};

#endif // PROCESSING_TST_H
