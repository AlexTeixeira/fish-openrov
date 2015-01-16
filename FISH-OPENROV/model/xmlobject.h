#ifndef XMLOBJECT_H
#define XMLOBJECT_H

#include <QObject>

class XmlObject : public QObject
{
public:
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
};

#endif // XMLOBJECT_H
