#ifndef FISH_H
#define FISH_H

#include <QObject>

class Fish : public QObject
{
    Q_OBJECT
public:
    explicit Fish(QObject *parent = 0);
    Fish(int _id, QString _name, double _size);
    
    int GetId();
    QString GetName();
    double GetSize();
    void SetId (int _id);
    void SetName(QString _name);
    void SetSize(double _size);
    
private:
    int id;
    QString name;
    double size;
    
signals:
    
public slots:
    
};

#endif // FISH_H
