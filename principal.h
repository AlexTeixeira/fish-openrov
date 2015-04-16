#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QMainWindow>
#include <QDebug>
#include <QLineEdit>
#include <QFormLayout>
#include <QFileDialog>
#include <QColor>
#include "model/player.h"

namespace Ui {
class principal;
}

class principal : public QWidget
{
    Q_OBJECT

public:
    explicit principal(QWidget *parent = 0);
    ~principal();

private:
    Ui::principal *ui;
    void deletItem(QFormLayout *layoutContenu);


public slots:

    void onClick_showAnalyser();
    void onClick_showAjouterPoisson();
    void onClick_showTelechargerPoisson();
    void onClick_selectSourcePath();
    void onClick_validAnalysis();
};

#endif // PRINCIPAL_H
