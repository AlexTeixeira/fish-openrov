#include "place.h"

Place::Place(QObject *parent) :
    QObject(parent)
{
}

Place::Place(int _id, QString _name)
{
    this->id = _id;
    this->name = _name;
    
    //this->listFish = new QList<Fish>();
}

Place::Place(QMap<QString, QString> qMap) {
    QMapIterator<QString, QString> i(qMap);
    while(i.hasNext()) {
        i.next();
        Setter(i.key(), i.value());
    }
}

int Place::GetId() {
    return this->id;
}

QString Place::GetName() {
    return this->name;
}

QList<Fish*>* Place::GetListFish() {
    return this->listFish;
}

void Place::SetId(int _id) {
    this->id = _id;
}

void Place::SetName(QString _name) {
   this->name = _name;
}

void Place::SetListFish(QList<Fish *> *_listFish) {
    this->listFish = _listFish;
}

void Place::Setter(QString keyToSet, QString valueToSet) {
    if (keyToSet == "id") {
        SetId(valueToSet.toInt(false, 10));
    } else if (keyToSet == "name") {
        SetName(valueToSet);
    }
}

void Place::AddFish(Fish *_fish) {
    this->listFish->append(_fish);
}

void Place::UpdateFish(Fish *_fish, int pos) {
    this->listFish->insert(pos, _fish);
}

void Place::DeleteFish(Fish *_fish) {
    int pos = this->GetPosByFish(_fish);
    if (pos > -1) {
        this->listFish->removeAt(pos);   
    }
}

int Place::GetPosByFish(Fish *_fish) {
    for (int i = 0; i < this->listFish->size(); i++) {
        if((this->listFish->at(i))->GetId() == _fish->GetId()) {
            return i;
        }
    }
    return -1;
}
