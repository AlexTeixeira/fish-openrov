#include "place_test.h"

Place_Test::Place_Test()
{
}

int Place_Test::GetId() {
    return this->id;
}

void Place_Test::SetId(int _id) {
    this->id = _id;
}

QString Place_Test::GetName() {
    return this->name;
}

void Place_Test::SetName(QString _name) {
   this->name = _name;
}

QList<Fish> Place_Test::getListFish() {
    
}

void Place_Test::AddFish(Fish _fish) {
    
}

void Place_Test::UpdateFish(Fish _fish) {
    
}

void Place_Test::DeleteFish(Fish _fish) {
    
}
