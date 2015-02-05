#include "frame.h"

Frame::Frame(QObject *parent) :
    QObject(parent)
{
}

Frame::Frame(int _id, QString _name) {
    this->id = _id;
    this->name = _name;
}

int Frame::GetId() {
    return this->id;
}

QString Frame::GetName() {
    return this->name;
}

void Frame::SetId(int _id) {
    this->id = _id;
}

void Frame::SetName(QString _name) {
    this->name = _name;
}
