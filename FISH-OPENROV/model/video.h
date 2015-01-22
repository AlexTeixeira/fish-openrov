#ifndef VIDEO_H
#define VIDEO_H

#include <QObject>

#include "frame.h"

class Video : public QObject
{
    Q_OBJECT
public:
    explicit Video(QObject *parent = 0);
    Video(int _id, QString _name);
    
    int GetId();
    QString GetName();
    QList<Frame> *GetListFrame();
    
    void SetId(int _id);
    void SetName(QString _name);
    void SetListFrame(QList<Frame>* _listFrame);
    
    void AddFrame(Frame _frame);
    void UpdateFrame(Frame _frame);
    void DeleteFrame(Frame _frame);
    
private:
    int id;
    QString name;
    QList<Frame> *listFrame;
    
signals:
    
public slots:
    
};

#endif // VIDEO_H
