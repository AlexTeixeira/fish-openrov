#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSignalMapper"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QSignalMapper* signalMapper = new QSignalMapper (this) ;

//    connect (ui->analyseButton, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
//    connect (ui->ajouterPoissonBoutton, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
//    connect (ui->telechargerPoissonButton, SIGNAL(clicked()), signalMapper, SLOT(map())) ;

//    signalMapper -> setMapping (ui->analyseButton, 0) ;
//    signalMapper -> setMapping (ui->ajouterPoissonBoutton, 1) ;
//    signalMapper -> setMapping (ui->telechargerPoissonButton, 2) ;

//    connect (signalMapper, SIGNAL(mapped(int)), this, SLOT(switchMainWidget(int))) ;

    // Je connecte le bouton "Analyser(btn_analyser)" à la méthode "onClick_showAnalyser()"
    connect(ui->btn_analyser, SIGNAL(clicked()), this, SLOT(onClick_showAnalyser()));

    // Je connecte le bouton "Ajouter un poisson(btn_ajoutPoisson)" à la méthode "onClick_showAjouterPoisson()"
    connect(ui->btn_ajoutPoisson, SIGNAL(clicked()), this, SLOT(onClick_showAjouterPoisson()));

    // Je connecte le bouton "Télécharger librairie(btn_telechargerPoisson" à la méthode "onClick_showTelechargerPoisson()"
    connect(ui->btn_telechargerPoisson, SIGNAL(clicked()), this, SLOT(onClick_showTelechargerPoisson()));

    QSize *size = new QSize();
    size->setHeight(150);
    size->setWidth(150);

    ui->btn_analyser->setMaximumSize(*size);
    ui->btn_ajoutPoisson->setMaximumSize(*size);
    ui->btn_telechargerPoisson->setMaximumSize(*size);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onClick_showAnalyser(){

    deletItem(ui->layoutContenu);

    QLineEdit *nom = new QLineEdit;
    QLineEdit *date = new QLineEdit;
    QLineEdit *lieu = new QLineEdit;
    QLineEdit *vidima = new QLineEdit;

    ui->layoutContenu->addRow("Nom", nom);
    ui->layoutContenu->addRow("Date", date);
    ui->layoutContenu->addRow("Lieu", lieu);
    ui->layoutContenu->addRow("Video images", vidima);


    QPushButton *parcourir = new QPushButton("Parcourir");
    connect(parcourir, SIGNAL(clicked()), this, SLOT(onClick_selectSourcePath()));
    ui->layoutContenu->addRow(parcourir);
    //ui->parcourir.setGeometry(60, 50, 260, 70);

    QPushButton *boutonAnalyser = new QPushButton("Valider");
    ui->layoutContenu->addRow(boutonAnalyser);


}

void MainWindow::onClick_showAjouterPoisson(){

    deletItem(ui->layoutContenu);

    QLineEdit *poisson = new QLineEdit;
    QLineEdit *lieu2 = new QLineEdit;
    QLineEdit *image = new QLineEdit;

    ui->layoutContenu->addRow("Poisson", poisson);
    ui->layoutContenu->addRow("Lieu", lieu2);
    ui->layoutContenu->addRow("Image", image);

    QPushButton *boutonAnalyser = new QPushButton("Valider");
    ui->layoutContenu->addRow(boutonAnalyser);
}

void MainWindow::onClick_showTelechargerPoisson(){

    deletItem(ui->layoutContenu);

    QLineEdit *Lieu3 = new QLineEdit;

    ui->layoutContenu->addRow("Lieu", Lieu3);

    QPushButton *boutonAnalyser = new QPushButton("Valider");
    ui->layoutContenu->addRow(boutonAnalyser);
}



void MainWindow::deletItem(QFormLayout *layoutContenu){
    QLayoutItem *item;
    while (!layoutContenu->isEmpty()) {
            item = layoutContenu->takeAt(0);
            delete item->widget();
            delete item;
    }
}

void MainWindow::onClick_selectSourcePath(){
    QString *filename = new QString;
    *filename = QFileDialog::getOpenFileName(this, tr("Ouvrir Image/Vidéo"), "C:/", tr("Fichiers Image (*.png *.jpg *.bmp *.tiff *.ppm);;Fichiers Vidéo (*.mp4 *.avi *.m4v)"));
    qDebug()<<*filename;
}
