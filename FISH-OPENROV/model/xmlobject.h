#ifndef XMLOBJECT_H
#define XMLOBJECT_H

#include <QObject>

class XmlObject : public QObject
{
    Q_OBJECT
public:
    explicit XmlObject(QObject *parent = 0);
    XmlObject(int _id, QString _name, QString _path);
    
    int GetId();
    QString GetName();
    QString GetPath();
    void SetId(int _id);
    void SetName(QString _name);
    void SetPath(QString _path);
    
    void Load();
    void Read();
    void Update();
    void Delete();
    
private:
    int id;
    QString name;
    QString path;
    
signals:
    
public slots:
    
};

#endif // XMLOBJECT_H
