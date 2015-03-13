#include "video.h"

Video::Video(QObject *parent) :
    QObject(parent)
{
}

Video::Video(int _id, QString _name) {
    this->id = _id;
    this->name = _name; 
}

int Video::GetId() {
    return this->id;
}

QString Video::GetName() {
    return this->name;
}

QList<Frame*> Video::GetListFrame() {
    return this->listFrame;
}

void Video::SetId(int _id) {
    this->id = _id;
}

void Video::SetName(QString _name) {
    this->name = _name;
}

void Video::SetListFrame(QList<Frame*>_listFrame) {
    this->listFrame = _listFrame;
}

void Video::AddFrame(Frame * _frame) {
    
}

void Video::UpdateFrame(Frame _frame) {
    
}

void Video::DeleteFrame(Frame _frame) {
    
}
