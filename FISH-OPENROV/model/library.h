#ifndef LIBRARY_H
#define LIBRARY_H

#include <QObject>
#include <QList>
#include "xmlobject.h"

class Library : public QObject
{
    Q_OBJECT
public:
    explicit Library(QObject *parent = 0);
    Library(int _id, QString _name);
    
    int GetId();
    QString GetName();
    QString GetXmlDirPath();
    
    void SetId(int _id);
    void SetName(QString _name);
    void SetXmlDirPath(QString _xmlDirPath);
    
    QList<XmlObject> *LoadXmlLibrary();
    void UpdateXmlLibrary();
    
private:
    int id;
    QString name;
    QString xmlDirPath;
    QList<XmlObject> *xmlLibrary;
    
signals:
    
public slots:
    
};

#endif // LIBRARY_H
