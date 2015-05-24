#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <QObject>
#include <QCryptographicHash>
#include <QDebug>

class Cryptography : public QObject
{
    Q_OBJECT
public:
    explicit Cryptography(QObject *parent = 0);
    ~Cryptography();

    static QString hash(QString string);

signals:

public slots:
};

#endif // CRYPTOGRAPHY_H
