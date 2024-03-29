#ifndef LIBRARY_H
#define LIBRARY_H

#include <QObject>
#include <QList>
#include "xmlobject.h"

class Library : public QObject
{
    Q_OBJECT
public:

    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Library
     *  \param parent : Objet parent
     */
    explicit Library(QObject *parent = 0);

    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Library
     *  \param int _id : id de la Library
     *  \param QString _name : nom de la Library
     */
    Library(int _id, QString _name);
    
    /*!
     *
     * \brief GetId()
     *      Function qui retourne l'id d'une Library
     * \return int
     *
     */
    int GetId();


    /*!
     *
     * \brief GetName()
     *      Function qui retourne le nom d'une Library
     * \return Qstring
     *
     */
    QString GetName();

    /*!
     *
     * \brief GetXmlDirPath()
     *      Function qui retourne le path des XML
     * \return Qstring
     *
     */
    QString GetXmlDirPath();
    
    /*!
     *  \brief SetId()
     *      Méthode qui permet de setter l'id d'une library
     *  \param int _id : id de la library
     */
    void SetId(int _id);

    /*!
     *  \brief SetName();
     *      Méthode qui permet de setter le nom d'une library
     *  \param Qstring _name : nom de la library
     */
    void SetName(QString _name);

    /*!
     *  \brief SetXmlDirPath();
     *      Méthode qui permet de setter le path des xml
     *  \param Qstring _xmlDirPath : path des xml
     */
    void SetXmlDirPath(QString _xmlDirPath);
    
    /*!
     *  \brief LoadXmlLibrary();
     *     ??
     *  \return QList<XmlObject>
     */
    QList<XmlObject> *LoadXmlLibrary();


    /*!
     *  \brief UpdateXmlLibrary();
     *     ??
     */
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
