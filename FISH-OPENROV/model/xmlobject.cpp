#include "xmlobject.h"

XmlObject::XmlObject(QObject *parent) :
    QObject(parent)
{
}

XmlObject::XmlObject(int _id, QString _name, QString _path)
{
    this->id = _id;
    this->name = _name;
    this->path = _path;
}

int XmlObject::GetId() {
    return this->id;
}

void XmlObject::SetId(int _id) {
    this->id = _id;
}

QString XmlObject::GetName() {
    return this->name;
}

void XmlObject::SetName(QString _name) {
    this->name = _name;
}

QString XmlObject::GetPath() {
    return this->path;
}

void XmlObject::SetPath(QString _path) {
    this->path = _path;
}

void Load() {
    
}

void Read() {
    
}

void Update() {
    
}

void Delete() {
    
}
