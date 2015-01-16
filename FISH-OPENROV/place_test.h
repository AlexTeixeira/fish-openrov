#ifndef PLACE_TEST_H
#define PLACE_TEST_H

#include <QString>
#include "model/fish.h"

class Place_Test
{
public:
    //Place(){}
    Place_Test();
    
    int GetId();
    void SetId(int _id);
    QString GetName();
    void SetName(QString _name);
    
    QList<Fish> getListFish();
    void AddFish(Fish _fish);
    void UpdateFish(Fish _fish);
    void DeleteFish(Fish _fish);
    
private:
    int id;
    QString name;
    QList<Fish> listFish;
};

#endif // PLACE_TEST_H
