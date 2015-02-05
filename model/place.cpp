#include "place.h"

Place::Place(QObject *parent) :
    QObject(parent)
{
    
}

Place::Place(int _id, QString _name)
{
    this->id = _id;
    this->name = _name;
    
    this->listFish = new QList<Fish>();
}

int Place::GetId() {
    return this->id;
}

QString Place::GetName() {
    return this->name;
}

QList<Fish>* Place::GetListFish() {
    return this->listFish;
}

void Place::SetId(int _id) {
    this->id = _id;
}

void Place::SetName(QString _name) {
   this->name = _name;
}

void Place::SetListFish(QList<Fish>* _listFish) {
    this->listFish = _listFish;
}

void Place::AddFish(Fish _fish) {
    this->listFish->append(_fish);
}

void Place::UpdateFish(Fish _fish, int pos) {
    this->listFish->at(pos) = _fish;
}

void Place::DeleteFish(Fish _fish) {
    this->listFish->removeAt(this->listFish->indexOf(_fish));
}
