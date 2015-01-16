#ifndef WEBSERVICE_H
#define WEBSERVICE_H

#include <QObject>

class WebService : public QObject
{
public:
    WebService(){}
    WebService(int _id);
    
    int GetId();
    void SetId(int _id);
    
    void Connect();
    void Send();
    void Receive();
    
private:
    int id;
};

#endif // WEBSERVICE_H
