#ifndef WEBSERVICE_TST_H
#define WEBSERVICE_TST_H
#include "../model/webservice.h"
#include <QtTest/QtTest>
#include <QObject>

class WebService_tst : public QObject
{

private:

    Q_OBJECT
    WebService *webservice;

public:
    explicit WebService_tst(QObject *parent = 0);

signals:

private slots:

    void initTestCase();
    void testId();
    void testId_data();
    void cleanupTestCase();

};

#endif // WEBSERVICE_TST_H
