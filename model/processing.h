#ifndef PROCESSING_H
#define PROCESSING_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include <QThread>
#include <QList>
#include <QDebug>
#include "model/result.h"

using namespace cv;

class Processing : public QThread
{
    Q_OBJECT
public:
//    /*!
//     *  \brief Constructeur
//     *      Constructeur de la classe Processing
//     *  \param parent : Objet parent
//     */
//    explicit Processing(QObject *parent = 0);

    /*!
     *  \brief Constructeur
     *      Constructeur de la classe Processing
     *  \param int _id : id d'un Processing
     */
    Processing(VideoCapture _cap);

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

    void MatchingMethod( int, void*, Mat img);
    
private:
    int id;
    VideoCapture cap;
    Result *result;
    QList<Mat> *frameList;

protected:
     void run();
     
signals:
    
public slots:
    
};

#endif // PROCESSING_H
