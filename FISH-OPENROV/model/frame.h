#ifndef FRAME_H
#define FRAME_H

#include <QObject>

class Frame : public QObject
{
    Q_OBJECT
public:
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Frame
     *  \param parent : Objet parent
     */
    explicit Frame(QObject *parent = 0);
    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Frame
     *  \param int _id : id de la frame
     *  \param QString _name : nom de la frame
     */
    Frame(int _id, QString _name);
    

    /*!
     *  \brief GetId()
     *      Fonction qui permet de récupérer l'id d'une frame
     *  \return int
     */
    int GetId();

    /*!
     *  \brief GetName()
     *      Fonction qui permet de récupérer le nom d'une frame
     *  \return QString
     */
    QString GetName();
    


    /*!
     *  \brief SetId()
     *      Méthode qui permet de setter l'id d'une frame
     *  \param int _id : id de la framme
     */
    void SetId(int _id);


    /*!
     *  \brief SetFrame()
     *      Méthode qui permet de setter le nom d'une frame
     *  \param String _name : name de la frame
     */
    void SetName(QString _name);
    
private:
    int id;
    QString name;
    
signals:
    
public slots:
    
};

#endif // FRAME_H
