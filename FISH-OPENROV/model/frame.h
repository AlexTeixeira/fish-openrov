#ifndef FRAME_H
#define FRAME_H

#include <QObject>

class Frame : public QObject
{
    Q_OBJECT
public:
    explicit Frame(QObject *parent = 0);
    Frame(int _id, QString _name);
    
    int GetId();
    QString GetName();
    
    void SetId(int _id);
    void SetName(QString _name);
    
private:
    int id;
    QString name;
    
signals:
    
public slots:
    
};

#endif // FRAME_H
