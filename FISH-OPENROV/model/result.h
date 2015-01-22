#ifndef RESULT_H
#define RESULT_H

#include <QObject>
#include <QDate>

class Result : public QObject
{
    Q_OBJECT
public:
    explicit Result(QObject *parent = 0);
    Result(int _id, QString _name, QDate _date, QString _description);
    
    int GetId();
    QString GetName();
    QDate GetDate();
    QString GetDescription();
    
    void SetId(int _id);
    void SetName(QString _name);
    void SetDate(QDate _date);
    void SetDescription(QString _description);
    
private:
    int id;
    QString name;
    QDate date;
    QString description;
    
signals:
    
public slots:
    
};

#endif // RESULT_H
