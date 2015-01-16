#ifndef PLACE_H
#define PLACE_H

#include <QObject>
#include <QList>

#include "fish.h"

class Place : public QObject
{
    Q_OBJECT
public:
    explicit Place(QObject *parent = 0);
    Place(int _id, QString _name);
    
    int GetId();
    QString GetName();
    QList<Fish> *GetListFish();
    void SetId(int _id);
    void SetName(QString _name);
    
    void AddFish(Fish _fish);
    void UpdateFish(Fish _fish);
    void DeleteFish(Fish _fish);
    
private:
    int id;
    QString name;
    QList<Fish> *listFish;
    
signals:
    
public slots:
    
};

#endif // PLACE_H
