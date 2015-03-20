#include "iabstractclass.h"

IAbstractClass::IAbstractClass()
{
}

int IAbstractClass::getId() {
    return this->id;
}

void IAbstractClass::setId(int _id) {
    this->id = _id;
}
