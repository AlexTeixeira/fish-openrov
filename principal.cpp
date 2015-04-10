#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);

    // Je connecte le bouton "Analyser(btn_analyser)" à la méthode "onClick_showAnalyser()"
    connect(ui->btn_analyser, SIGNAL(clicked()), this, SLOT(onClick_showAnalyser()));

    // Je connecte le bouton "Ajouter un poisson(btn_ajoutPoisson)" à la méthode "onClick_showAjouterPoisson()"
    connect(ui->btn_ajoutPoisson, SIGNAL(clicked()), this, SLOT(onClick_showAjouterPoisson()));

    // Je connecte le bouton "Télécharger librairie(btn_telechargerPoisson" à la méthode "onClick_showTelechargerPoisson()"
    connect(ui->btn_telechargerPoisson, SIGNAL(clicked()), this, SLOT(onClick_showTelechargerPoisson()));

    //couleur layout menu
    QColor *backgroundColour = new QColor();
    backgroundColour->setRgb(91,155,213); //example colour, I could later manage to utilize this variable with a QColorDialog

    QPalette p(palette());
    p.setColor(QPalette::Background, backgroundColour->rgb());

    ui->widgetMenu->setAutoFillBackground(true);
    ui->widgetMenu->setPalette(p);

    //couleur button menu
    ui->btn_analyser->setStyleSheet("background-color : rgb(91,155,213);");
    ui->btn_analyser->setFlat(true);

    ui->btn_ajoutPoisson->setStyleSheet("background-color : rgb(91,155,213);");
    ui->btn_ajoutPoisson->setFlat(true);

    ui->btn_telechargerPoisson->setStyleSheet("background-color : rgb(91,155,213);");
    ui->btn_telechargerPoisson->setFlat(true);
}

principal::~principal()
{
    delete ui;
}

void principal::onClick_showAnalyser(){

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

void principal::onClick_showAjouterPoisson(){

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

void principal::onClick_showTelechargerPoisson(){

    deletItem(ui->layoutContenu);

    QLineEdit *Lieu3 = new QLineEdit;

    ui->layoutContenu->addRow("Lieu", Lieu3);

    QPushButton *boutonAnalyser = new QPushButton("Valider");
    ui->layoutContenu->addRow(boutonAnalyser);
}



void principal::deletItem(QFormLayout *layoutContenu){
    QLayoutItem *item;
    while (!layoutContenu->isEmpty()) {
            item = layoutContenu->takeAt(0);
            delete item->widget();
            delete item;
    }
}

void principal::onClick_selectSourcePath(){
    QString *filename = new QString;
    *filename = QFileDialog::getOpenFileName(this, tr("Ouvrir Image/Vidéo"), "C:/", tr("Fichiers Image (*.png *.jpg *.bmp *.tiff *.ppm);;Fichiers Vidéo (*.mp4 *.avi *.m4v)"));
    qDebug()<<*filename;
}

