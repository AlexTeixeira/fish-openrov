#ifndef VIDEO_H
#define VIDEO_H

#include <QObject>

#include "frame.h"

class Video : public QObject
{
    Q_OBJECT
public:

    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Video
     *  \param parent : Objet parent
     */
    explicit Video(QObject *parent = 0);

    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Video
     *  \param int _id : id d'une Video
     *  \param QString _name : name d'une Video
     *
     */
    Video(int _id, QString _name);
    
    /*!
     *  \brief GetId()
     *      Fonction qui permet de récupérer l'id d'une Video
     *  \return int
     */
    int GetId();

    /*!
     *  \brief GetName()
     *      Fonction qui permet de récupérer le nom d'une Video
     *  \return QString
     */
    QString GetName();

    /*!
     *  \brief GetListFrame()
     *      Fonction qui permet de récupérer une liste de frame
     *  \return QList<Frame>
     */
    QList<Frame> *GetListFrame();
    
    /*!
     *  \brief SetId()
     *      Méthode qui permet de setter l'id d'une Video
     *  \param int _id : id de la class Video
     */
    void SetId(int _id);

    /*!
     *  \brief SetName();
     *      Méthode qui permet de setter le nom d'une Video
     *  \param QString _name : name de la class Video
     */
    void SetName(QString _name);

    /*!
     *  \brief SetListFrame();
     *      Méthode qui permet de setter une liste de frame
     *  \param QList<Frame>* _listFrame : liste de frame
     */
    void SetListFrame(QList<Frame>* _listFrame);
    
    /*!
     *  \brief AddFrame();
     *      Méthode qui permet d'ajouter une frame à la liste de frame
     *  \param Frame _frame : une frame
     */
    void AddFrame(Frame _frame);

    /*!
     *  \brief UpdateFrame();
     *      Méthode qui permet de mettre à jour une frame de la liste de frame
     *  \param Frame _frame : une frame
     */
    void UpdateFrame(Frame _frame);

    /*!
     *  \brief DeleteFrame();
     *      Méthode qui permet de supprimer une frame de la liste de frame
     *  \param Frame _frame : une frame
     */
    void DeleteFrame(Frame _frame);
    
private:
    int id;
    QString name;
    QList<Frame> *listFrame;
    
signals:
    
public slots:
    
};

#endif // VIDEO_H
