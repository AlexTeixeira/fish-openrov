#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>

#include "result.h"

class Processing : public QObject
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Processing
     *  \param parent : Objet parent
     */
    explicit Processing(QObject *parent = 0);

    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Processing
     *  \param int _id : id d'un Processing
     */
    Processing(int _id);

    /*!
     *  \brief GetId()
     *      Fonction qui permet de récupérer l'id d'un Processing
     *  \return int
     */
    int GetId();

    /*!
     *  \brief GetResult()
     *      Fonction qui permet de récupérer la class résultat
     *  \return int
     */
    Result *GetResult();
    
    /*!
     *  \brief SetId()
     *      Méthode qui permet de setter l'id d'un Processing
     *  \param int _id : id de la class Processing
     */
    void SetId(int _id);

    /*!
     *  \brief SetResult();
     *      Méthode qui permet de setter un résultat
     *  \param Result *_result : resultat
     */
    void SetResult(Result *_result);
    
private:
    int id;
    Result *result;
     
signals:
    
public slots:
    
};

#endif // PROCESSING_H
