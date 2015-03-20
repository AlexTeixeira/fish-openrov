#ifndef LIBRARY_TST_H
#define LIBRARY_TST_H

#include <QObject>
#include <QtTest/QtTest>
#include <QString>
#include "../model/library.h"

class LibraryTest : public QObject
{
    Q_OBJECT
public:
    explicit LibraryTest(QObject *parent = 0);

private:
    Library *l1;
private slots:

    void initTestCase();
    void testId();
    void testId_data();
    void testName();
    void testName_data();
    void testXmlDirPath();
    void testXmlDirPath_data();
    void testLoadXmlLibrary();
    void testLoadXmlLibrary_data();
};

#endif // LIBRARY_TST_H
