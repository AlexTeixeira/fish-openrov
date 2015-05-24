#include "cryptography.h"
#include <QMessageBox>

Cryptography::Cryptography(QObject *parent) : QObject(parent)
{

}

Cryptography::~Cryptography()
{

}

QString Cryptography::hash(QString string){
    QByteArray byteArry = QCryptographicHash::hash(string.toUtf8(), QCryptographicHash::Sha1);
    return byteArry.toHex();
}

