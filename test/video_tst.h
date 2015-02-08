#ifndef VIDEO_TST_H
#define VIDEO_TST_H
#include <QObject>
#include <QtTest/QtTest>
#include <QString>
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
    void testName();
    void testListFrame();
    void cleanupTestCase();

};
#endif // VIDEO_TST_H
