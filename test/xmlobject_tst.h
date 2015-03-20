#ifndef XMLOBJECT_TST_H
#define XMLOBJECT_TST_H

#include <QObject>

class xmlobject_tst : public QObject
{
    Q_OBJECT
public:
    explicit xmlobject_tst(QObject *parent = 0);
    ~xmlobject_tst();

signals:

public slots:
};

#endif // XMLOBJECT_TST_H
