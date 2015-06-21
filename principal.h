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
#include "usermanagement.h"

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
    void createFolder(QString *currentPath, QString name);
    QString windowType;
    QListWidget* image;
    QLineEdit *vidima;
    QLineEdit *nom;
    QLineEdit *date;
    QLineEdit *lieu;
    QThread *thread;
    QLineEdit *poisson;
    QLineEdit *lieu2;

public slots:

    void onClick_showAnalyser();
    void onClick_showAjouterPoisson();
    void onClick_showTelechargerPoisson();
    void onClick_selectSourcePath();
    void onClick_selectSourcePathImage();
    void onClick_validAnalysis();
    void onClick_validAjoutPoisson();
    void openUserManagement();
};

#endif // PRINCIPAL_H
