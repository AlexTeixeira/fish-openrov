#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSignalMapper"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSignalMapper* signalMapper = new QSignalMapper (this) ;

    connect (ui->analyseButton, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->ajouterPoissonBoutton, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (ui->telechargerPoissonButton, SIGNAL(clicked()), signalMapper, SLOT(map())) ;

    signalMapper -> setMapping (ui->analyseButton, 0) ;
    signalMapper -> setMapping (ui->ajouterPoissonBoutton, 1) ;
    signalMapper -> setMapping (ui->telechargerPoissonButton, 2) ;

    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(switchMainWidget(int))) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchMainWidget(int i ){
    ui->mainWidget->setCurrentIndex(i);
}
