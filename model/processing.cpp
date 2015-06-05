#include "processing.h"

//Processing::Processing(QObject *parent) :
//    QObject(parent)
//{
//}

Processing::Processing(VideoCapture _cap) {
    this->cap = _cap;
}

void Processing::run()
{
    double count = this->cap.get(CV_CAP_PROP_FRAME_COUNT);
    Mat frame;
    for(int i=0;i<(int)count;i+=10){
        this->cap.set(CV_CAP_PROP_POS_FRAMES, i);
        this->cap >> frame;
    }
    qDebug() <<"Thread finish";
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

void Processing::SetResult(Result* _result) {
    this->result = _result;
}
