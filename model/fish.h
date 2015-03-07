#ifndef FISH_H
#define FISH_H

/*! 
 * \file fish.h
 */

#include <QString>
#include <QMap>

/*! 
 * \class Fish fish.h
 * \brief Classe retprésentant un poisson(fish)
 */

class Fish
{

public:
    
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Fish
     */
    Fish();
    
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Fish
     *  \param int _id : id du poisson
     *  \param QString _name : nom du poisson
     *  \param double _size : taille du poisson
     */
    Fish(int _id, QString _name, double _size);
    
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Fish
     *  \param QMap<QString, QString> qMap : Tableau associatif
     *  contenat les propriétés de la classe Fish
     */
    Fish(QMap<QString, QString> qMap);
    
    /*!
     *  \brief GetId()
     *      Fonction qui permet de récupérer l'id d'une IAbstractClass
     *  \return int
     */
    int GetId();
    
    /*!
     *  \brief GetName()
     *      Fonction qui permet de récupérer le nom d'un poisson
     *  \return QString
     */
    QString GetName();
    
    /*!
     *  \brief GetSize()
     *      Fonction qui permet de récupérer la taille d'un poisson
     *  \return double
     */
    double GetSize();
    
    /*!
     *  \brief SetId()
     *      Méthode qui permet de setter l'id d'un lieu
     *  \param int _id : id de la framme
     */
    void SetId(int _id);
    
    /*!
     *  \brief SetName()
     *      Méthode qui permet de setter le nom d'un poisson
     *  \param QString _name : nom du poisson
     */
    void SetName(QString _name);
    
    /*!
     *  \brief SetSize()
     *      Méthode qui permet de setter la taille d'un poisson
     *  \param double _size : taille du poisson
     */
    void SetSize(double _size);
    
    /*!
     *  \brief Setter();
     *      Méthode qui permet de setter une des propriétés de Fish
     *      // !! \\ Doit être mise à jour après chaque modification
     *      sur les propriétés de la classe
     *  \param QString keyToSet : propriété à setter
     *  \param QString valueToSet : valeur à setter
     */
    void Setter(QString keyToSet, QString valueToSet);
    
private:
    int id;
    QString name;
    double size;
};

#endif // FISH_H
