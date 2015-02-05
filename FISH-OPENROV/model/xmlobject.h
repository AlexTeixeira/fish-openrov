#ifndef XMLOBJECT_H
#define XMLOBJECT_H

/*! 
 * \file xmlobject.h
 */

#include <QObject>

/*! 
 * \class XmlObject xmlobject.h
 * \brief Classe retprésentant un xml
 */

class XmlObject : public QObject
{
public:
    
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe XmlObject
     *  \param int _id : id du xml
     *  \param QString _name : nom du xml
     *  \param QString _path : chemin vers le xml
     */
    XmlObject(int _id, QString _name, QString _path);
    
    /*!
     *  \brief GetId()
     *      Fonction qui permet de récupérer l'id d'un xml
     *  \return int
     */
    int GetId();
    
    /*!
     *  \brief GetName()
     *      Fonction qui permet de récupérer le nom d'un xml
     *  \return QString
     */
    QString GetName();
    
    /*!
     *  \brief GetPath()
     *      Fonction qui permet de récupérer le chemin d'un xml
     *  \return QString
     */
    QString GetPath();

    /*!
     *  \brief SetId()
     *      Méthode qui permet de setter la taille d'un poisson
     *  \param int _id : id du xml
     */
    void SetId(int _id);
    
    /*!
     *  \brief SetName()
     *      Méthode qui permet de setter le nom d'un xml
     *  \param QString _name : nom du xml
     */
    void SetName(QString _name);
    
    /*!
     *  \brief SetPath()
     *      Méthode qui permet de setter le chemin d'un xml
     *  \param QString _name : chemin du xml
     */
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
