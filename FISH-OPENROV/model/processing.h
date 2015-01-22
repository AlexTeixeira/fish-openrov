#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>

#include "result.h"

class Processing : public QObject
{
    Q_OBJECT
public:
    explicit Processing(QObject *parent = 0);
    Processing(int _id);
    
    int GetId();
    Result *GetResult();
    
    void SetId(int _id);
    void SetResult(Result *_result);
    
private:
    int id;
    Result *result;
     
signals:
    
public slots:
    
};

#endif // PROCESSING_H
