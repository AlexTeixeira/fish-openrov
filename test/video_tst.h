#ifndef VIDEO_TST_H
#define VIDEO_TST_H
#include <QObject>
#include <QtTest/QtTest>
#include <QString>
#include <QList>
#include "../model/frame.h"
#include "../model/video.h"

class VideoTest : public QObject
{
    Q_OBJECT

public:
    
    explicit VideoTest(QObject *parent = 0);

private:

    Video *v1;
    Video *v2;

private slots:

    void initTestCase();
    void testId();
    void testId_data();
    void testName();
    void testName_data();
    void testListFrame();
    void testListFrame_data();
    void cleanupTestCase();

};
#endif // VIDEO_TST_H
