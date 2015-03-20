#include "iabstractclass.h"

IAbstractClass::IAbstractClass()
{
}

int IAbstractClass::GetId() {
    return this->id;
}

void IAbstractClass::SetId(int _id) {
    this->id = _id;
}
