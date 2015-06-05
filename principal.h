#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QMainWindow>
#include <QDebug>
#include <QLineEdit>
#include <QFormLayout>
#include <QFileDialog>
#include <QColor>
#include <QListWidget>
#include <QListWidgetItem>
#include "model/player.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv/cv.h>
#include "model/processing.h"

using namespace cv;
using namespace std;

namespace Ui {
class principal;
}

class principal : public QWidget
{
    Q_OBJECT

public:
    explicit principal(QString windowType, QWidget *parent = 0);
    ~principal();

private:
    Ui::principal *ui;
    void deletItem(QFormLayout *layoutContenu);
    QString windowType;
    QListWidget* image;
    QLineEdit *vidima;
    QLineEdit *nom;
    QLineEdit *date;
    QLineEdit *lieu;
    QThread *thread;

public slots:

    void onClick_showAnalyser();
    void onClick_showAjouterPoisson();
    void onClick_showTelechargerPoisson();
    void onClick_selectSourcePath();
    void onClick_selectSourcePathImage();
    void onClick_validAnalysis();
};

#endif // PRINCIPAL_H
