#ifndef PLACE_H
#define PLACE_H

#include <QObject>
#include <QList>

#include "fish.h"

class Place : public QObject
{
    Q_OBJECT
public:

    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Place
     *  \param parent : Objet parent
     */
    explicit Place(QObject *parent = 0);
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Place
     *  \param int _id : id de la Place
     *  \param QString _name : nom de la Place
     */
    Place(int _id, QString _name);
    
    /*!
     *  \brief GetId()
     *      Fonction qui permet de récupérer l'id d'un lieu
     *  \return int
     */
    int GetId();
    /*!
     *  \brief GetName()
     *      Fonction qui permet de récupérer le nom d'un lieu
     *  \return Qstring
     */
    QString GetName();

    /*!
     *  \brief GetListFish()
     *      Fonction qui permet de récupérer une liste de poisson
     *  \return QList<Fish>
     */
    QList<Fish> *GetListFish();
    
    /*!
     *  \brief SetId()
     *      Méthode qui permet de setter l'id d'un lieu
     *  \param int _id : id de la framme
     */
    void SetId(int _id);

    /*!
     *  \brief SetName()
     *      Méthode qui permet de setter l'id d'un lieu
     *  \param Qstring _name : id d'un lieu
     */
    void SetName(QString _name);

    /*!
     *  \brief SetListFish();
     *      Méthode qui permet de setter une liste de poisson
     *  \param QList<Fish>* _listFish : liste de poisson
     */
    void SetListFish(QList<Fish>* _listFish);
    

    /*!
     *  \brief AddFish();
     *      Méthode qui permet d'ajouter un poisson à la liste de poisson
     *  \param Fish _fish : un poisson
     */
    void AddFish(Fish _fish);

    /*!
     *  \brief UpdateFish();
     *      Méthode qui permet de mettre à un poisson dans la liste de poisson
     *  \param Fish _fish : un poisson
     *  \param int pos : La position du poisson dans la liste
     */
    void UpdateFish(Fish _fish, int pos);

    /*!
     *  \brief DeleteFish();
     *      Méthode qui permet de supprimer un poisson de la liste de poisson
     *  \param Fish _fish : un poisson
     */
    void DeleteFish(Fish _fish);
    
private:
    int id;
    QString name;
    QList<Fish> *listFish;
    
signals:
    
public slots:
    
};

#endif // PLACE_H
