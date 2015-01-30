#ifndef WEBSERVICE_H
#define WEBSERVICE_H

#include <QObject>

class WebService : public QObject
{
public:
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe WebService
     */
    WebService(){}

    /*!
     *  \brief Constructeur
     *      Constructeur de la classe WebService
     *  \param int _id : id d'un WebService
     *
     */
    WebService(int _id);
    
    /*!
     *  \brief GetId()
     *      Fonction qui permet de récupérer l'id d'une WB
     *  \return int
     */
    int GetId();

    /*!
     *  \brief GetId()
     *      Fonction qui permet de récupérer l'id d'une WB
     *  \param int _id : id du WB
     */
    void SetId(int _id);
    
    /*!
     *  \brief Connect()
     *      Permet de ce connecter au WB
     */
    void Connect();

    /*!
     *  \brief Connect()
     *      Permet d'envoyer des données au WB
     */
    void Send();


    /*!
     *  \brief Connect()
     *      Permet de recevoir des données du WB
     */
    void Receive();
    
private:
    int id;
};

#endif // WEBSERVICE_H
