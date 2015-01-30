#ifndef RESULT_H
#define RESULT_H

#include <QObject>
#include <QDate>

class Result : public QObject
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe result
     *  \param parent : Objet parent
     */
    explicit Result(QObject *parent = 0);
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe result
     *  \param int _id : id d'un result
     *  \param QString _name : name d'un result
     *  \param Qstring _description : description d'un result
     *
     */
    Result(int _id, QString _name, QDate _date, QString _description);
    
    /*!
     *  \brief GetId()
     *      Fonction qui permet de récupérer l'id d'un Result
     *  \return int
     */
    int GetId();

    /*!
     *  \brief GetName()
     *      Fonction qui permet de récupérer le nom d'un Result
     *  \return int
     */
    QString GetName();

    /*!
     *  \brief GetDate()
     *      Fonction qui permet de récupérer la Date d'un Result
     *  \return QString
     */
    QDate GetDate();

    /*!
     *  \brief GetDescription()
     *      Fonction qui permet de récupérer la description d'un Result
     *  \return QString
     */
    QString GetDescription();
    

    /*!
     *  \brief SetId()
     *      Méthode qui permet de setter l'id d'un Result
     *  \param int _id : id de la class Result
     */
    void SetId(int _id);

    /*!
     *  \brief SetName();
     *      Méthode qui permet de setter le nom d'un Result
     *  \param QString _name : name de la class Result
     */
    void SetName(QString _name);

    /*!
     *  \brief SetDate();
     *      Méthode qui permet de setter la date d'un Result
     *  \param QString _date : date de la class Result
     */
    void SetDate(QDate _date);

    /*!
     *  \brief SetDescription();
     *      Méthode qui permet de setter la description d'un Result
     *  \param QString _description : description de la class Result
     */
    void SetDescription(QString _description);
    
private:
    int id;
    QString name;
    QDate date;
    QString description;
    
signals:
    
public slots:
    
};

#endif // RESULT_H
