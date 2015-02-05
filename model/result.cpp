#include "result.h"

Result::Result(QObject *parent) :
    QObject(parent)
{
}

Result::Result(int _id, QString _name, QDate _date, QString _description) {
    this->id = _id;
    this->name = _name;
    this->date = _date;
    this->description = _description;
}

int Result::GetId() {
    return this->id;
}

QString Result::GetName() {
    return this->name;
}

QDate Result::GetDate() {
    return this->date;
}

QString Result::GetDescription() {
    return this->description;
}

void Result::SetId(int _id) {
    this->id = _id;
}

void Result::SetName(QString _name) {
    this->name = _name;
}

void Result::SetDate(QDate _date) {
    this->date = _date;
}

void Result::SetDescription(QString _description) {
    this->description = _description;
}
