#include "library.h"

Library::Library(QObject *parent) :
    QObject(parent)
{
}

Library::Library(int _id, QString _name) {
    this->id = _id;
    this->name = _name;
}

int Library::GetId() {
    return this->id;
}

QString Library::GetName() {
    return this->name;
}

QString Library::GetXmlDirPath() {
    return this->xmlDirPath;
}

void Library::SetId(int _id) {
    this->id = _id;
}

void Library::SetName(QString _name) {
    this->name = _name;
}

void Library::SetXmlDirPath(QString _xmlDirPath) {
    this->xmlDirPath = _xmlDirPath;
}

QList<XmlObject>* Library::LoadXmlLibrary() {
    return this->xmlLibrary;
}

void Library::UpdateXmlLibrary() {
    
}
