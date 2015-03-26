#include "webservice_tst.h"

WebService_tst::WebService_tst(QObject *parent) : QObject(parent)
{

}

void WebService_tst::initTestCase()
{
 webservice=new WebService();
}
void WebService_tst::testId()
{
       QFETCH(int,anId);
       webservice->SetId(anId);
       QTEST(webservice->GetId(),"anId");
}


void WebService_tst::testId_data()
{
    QTest::addColumn<int>("anId");
    QTest::newRow("integer")<<1234;
}

void WebService_tst::cleanupTestCase()
{
    delete webservice;
}


