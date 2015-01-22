#include "processing.h"

Processing::Processing(QObject *parent) :
    QObject(parent)
{
}

Processing::Processing(int _id) {
    this->id = _id;
    //this->result = new Result();
}

int Processing::GetId() {
    return this->id;
}

Result* Processing::GetResult() {
    return this->result;
}

void Processing::SetId(int _id) {
    this->id = _id;
}

void Processing::SetResult(Result _result) {
    this->result = _result;
}
