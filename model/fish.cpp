#include "fish.h"

Fish::Fish(int _id, QString _name, double _size)
{
    this->id = _id;
    this->name = _name;
    this->size = _size;
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
