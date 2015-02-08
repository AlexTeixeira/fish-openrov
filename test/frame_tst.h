#ifndef FRAME_TST_H
#define FRAME_TST_H
#include <QObject>
#include <QtTest/QtTest>
#include <QString>
#include "../model/frame.h"

class FrameTest : public QObject
{
    Q_OBJECT

public:

    explicit FrameTest(QObject *parent = 0);

private:

    Frame *f1;
    Frame *f2;

private slots:

    void initTestCase();
    void testId();
    void testName();
    void cleanupTestCase();

};
#endif // FRAME_TST_H
