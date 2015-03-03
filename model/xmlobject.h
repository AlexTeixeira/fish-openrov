#ifndef XMLOBJECT_H
#define XMLOBJECT_H

/*! 
 * \file xmlobject.h
 */

#include <QtXml>

/*! 
 * \class XmlObject xmlobject.h
 * \brief Classe retprésentant un xml
 */

class XmlObject
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
     *  \brief GetPath()
     *      Fonction qui permet de récupérer le domDocument d'un xml chargé
     *  \return QDomDocument
     */
    QDomDocument *GetDomDoc();

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
     *  \param QString _path : chemin du xml
     */
    void SetPath(QString _path);
    
    /*!
     *  \brief Load()
     *      Méthode qui permet de charger un Xml
     *  \param QString _path : chemin du xml
     */
    void Load();
    
    /*!
     *  \brief ReadElement()
     *      Fonction qui permet de récupérer toutes les informations d'un element dans
     *      un fichier xml.
     *      // ! \\ La recherche se fait de façon non récursive avec une structure xml
     *      en dure et non dynamique. Si la structure change, le code change.
     *  \return QList<QMap<QString, QString> > retourne une liste de tableau associatif
     *  contenant les attributs et les valeurs du xml
     */
    QList<QMap<QString, QString> > GetAllElementValues();
    
    /////////////////////////////////////////////:::
    
    /*!
     *  \brief GetElementAttributesValue()
     *      Fonction qui permet de récupérer les noms et valeurs des attributs dans un
     *      fichier xml en fonction d'un nom d'élément passé en paramètre. 
     *      // ! \\ La recherche se fait de façon récursive dans tout le documen xml. 
     *  \param QDomNode node : noeud dans le lequel extraire les valeurs des attributs
     *  \param QString tagName : le nom de l'attribut que l'on souhaite parser
     *  \return QList<QMap<QString, QString> *>* retourne un pointer sur une liste de pointer sur
     *  un tableau associatif contenant les attributs et les valeurs du xml
     */
    QList<QMap<QString, QString> *> *GetElementAttributesValue(QDomNode node, QString tagName);
    
    /*!
     *  \brief GetElementValues()
     *      Fonction qui récupère la ou les valeurs d'un élément spécifique contenu
     *      dans un fichier xml et place ces informations dans un tableau associatif (QMap)
     *      en fonction d'un nom en paramètre.
     *      // ! \\ La recherche se fait de façon récursive dans tout le documen xml à
     *      l'aide de la méthode GetElementValues.
     *  \param QDomNode node : noeud dans le lequel extraire les valeurs des éléments
     *  \param QString tagName : le nom de l'élément que l'on souhaite parser
     *  \return QMap<QString, QString> *returnMap: pointer sur un tableau associatif
     *  permettant de stoquer les informations recueillies
     */
    QList<QMap<QString, QString> *> *GetElementValues(QDomNode node, QString tagName);
    
    /*!
     *  \brief GetElementValue()
            Méthode qui récupère la ou les valeurs d'un élément spécifique contenu
     *      dans un fichier xml et place ces informations dans un tableau associatif (QMap)
     *      en fonction d'un nom en paramètre.
     *      // ! \\ Fonction récursive qui est appellée par la fonction GetElementValues
     *      // ! \\ Ne pas utiliser directement.
     *  \param QDomNode node : noeud dans le lequel extraire les valeurs des attributs
     *  \param QString tagName : le nom de l'élément que l'on souhaite parser
     *  \param QList<QMap<QString, QString> *> *list: un pointer sur une liste de pointer
     *  de tableau associatif contenant les attributs et les valeurs du xml
     */
    void GetElementValues(QDomNode node, QString tagName, QList<QMap<QString, QString> *> *list);
    
    /*!
     *  \brief GetChildElementValues()
     *      Fonction qui récupère la ou les valeurs des enfants d'un élément spécifique contenu
     *      dans un fichier xml et place ces informations dans un tableau associatif (QMap)
     *      en fonction d'un nom en paramètre.
     *      // ! \\ La recherche se fait de façon récursive dans tout le documen xml à
     *      l'aide de la méthode GetChildElementValues.
     *  \param QDomNode _node : noeud dans le lequel extraire les valeurs des attributs
     *  \param QString parentTagName : le nom de l'élément parent que l'on souhaite parser
     *  \return QList<QMap<QString, QString>* > * : pointer sur un tableau associatif
     *  permettant de stoquer les informations recueillies
     */
    QList<QMap<QString, QString>* > *GetChildElementValues(QDomNode node, QString parentTagName);
    
    /*!
     *  \brief GetChildElementValues()
            Méthode qui récupère la ou les valeurs des enfants d'un élément spécifique contenu
     *      dans un fichier xml et place ces informations dans un tableau associatif (QMap)
     *      en fonction d'un nom en paramètre.
     *      // ! \\ Fonction récursive qui est appellée par la fonction GetChildElementValues
     *      // ! \\ Ne pas utiliser directement.
     *  \param QDomNode node : noeud dans le lequel extraire les valeurs des enfants de l'élement
     *  \param QString parentTagName : le nom de l'élément parent que l'on souhaite parser
     *  \param QList<QMap<QString, QString> *> *list: pointer sur un tableau associatif
     *  permettant de stoquer les informations recueillies
     */
    void GetChildElementValues(QDomNode node, QString parentTagName, QList<QMap<QString, QString> *> *list);
    
    /*!
     *  \brief GetAttributesValue()
     *      Récupère la valeur des attrivuts d'un element contenu dans un fichier xml et
     *      place ces informations dans un tableau associatif (QMap)
     *  \param QDomNode _node : noeud dans le lequel extraire les valeurs des attributs
     *  \param QMap<QString, QString> *returnMap: pointer sur un tableau associatif
     *  permettant de stoquer les informations recueillies
     */
    void GetAttributesValue(QDomNode node, QMap<QString, QString> *returnMap);
    
    /*!
     *  \brief GetElementValue()
     *      Récupère la ou les valeurs de l'élément contenu dans un fichier xml et
     *      place ces informations dans un tableau associatif (QMap)
     *  \param QDomNode _node : noeud dans le lequel extraire les valeurs des attributs
     *  \param QMap<QString, QString> *returnMap: pointer sur un tableau associatif
     *  permettant de stoquer les informations recueillies
     */
    void GetElementValue(QDomNode node, QMap<QString, QString> *returnMap);
    
    ///////////////////////////////////////////////////
    
    void Update();
    void Delete();
    
private:
    int id;
    QString name;
    QString path;
    
    QDomDocument *domDoc;
    QFile *file;
    //QList<QMap<QString, QString>* > *listMap;
};

#endif // XMLOBJECT_H
