#include "fish.h"

Fish::Fish() {
}

Fish::Fish(int _id, QString _name, double _size)
{
    this->id = _id;
    this->name = _name;
    this->size = _size;
}

Fish::Fish(QMap<QString, QString> qMap) {
    QMapIterator<QString, QString> i(qMap);
    while(i.hasNext()) {
        i.next();
        Setter(i.key(), i.value());
    }
}

int Fish::GetId() {
    return this->id;
}

QString Fish::GetName() {
    return this->name;
}

double Fish::GetSize() {
    return this->size;
}

void Fish::SetId(int _id) {
    this->id = _id;
}

void Fish::SetName(QString _name) {
    this->name = _name;
}

void Fish::SetSize(double _size) {
    this->size = _size;
}

void Fish::Setter(QString keyToSet, QString valueToSet) {
    if (keyToSet == "id") {
        SetId(valueToSet.toInt(false, 10));
    } else if (keyToSet == "name") {
        SetName(valueToSet);
    } else if (keyToSet == "size") {
        SetSize(valueToSet.toDouble(false));
    }
}
