#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QLineEdit>
#include <QFormLayout>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void deletItem(QFormLayout *layoutContenu);


public slots:

    void onClick_showAnalyser();
    void onClick_showAjouterPoisson();
    void onClick_showTelechargerPoisson();
    void onClick_selectSourcePath();

};

#endif // MAINWINDOW_H
