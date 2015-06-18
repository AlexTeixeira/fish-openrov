#include "principal.h"
#include "ui_principal.h"

principal::principal(QString windowType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);

    this->windowType = windowType;

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

    if(this->windowType == "student"){
        ui->btn_ajoutPoisson->setEnabled(false);
    }

}

principal::~principal()
{
    delete ui;
}

void principal::onClick_showAnalyser(){

    deletItem(ui->layoutContenu);

    this->nom = new QLineEdit;
    this->date = new QLineEdit;
    this->lieu = new QLineEdit;
    this->vidima = new QLineEdit;

    this->vidima->setDisabled(true);
    ui->layoutContenu->addRow("Nom", nom);
    ui->layoutContenu->addRow("Date", date);
    ui->layoutContenu->addRow("Lieu", lieu);
    ui->layoutContenu->addRow("Video images", vidima);

    QPushButton *parcourir = new QPushButton("Parcourir");
    connect(parcourir, SIGNAL(clicked()), this, SLOT(onClick_selectSourcePath()));
    ui->layoutContenu->addRow(parcourir);

    QPushButton *boutonAnalyser = new QPushButton("Valider");
    connect(boutonAnalyser, SIGNAL(clicked()), this, SLOT(onClick_validAnalysis()));
    ui->layoutContenu->addRow(boutonAnalyser);

    ui->TitleLabel->setText("Analyser");
}

void principal::onClick_showAjouterPoisson(){

    deletItem(ui->layoutContenu);

    this->poisson = new QLineEdit;
    this->lieu2 = new QLineEdit;
    this->image = new QListWidget;

    ui->layoutContenu->addRow("Poisson", poisson);
    ui->layoutContenu->addRow("Lieu", lieu2);
    ui->layoutContenu->addRow("Image", image);

    QPushButton *parcourir = new QPushButton("Parcourir");
    connect(parcourir, SIGNAL(clicked()), this, SLOT(onClick_selectSourcePathImage()));
    ui->layoutContenu->addRow(parcourir);

    QPushButton *boutonAnalyser = new QPushButton("Valider");
    connect(boutonAnalyser, SIGNAL(clicked()), this, SLOT(onClick_validAjoutPoisson()));
    ui->layoutContenu->addRow(boutonAnalyser);

    ui->TitleLabel->setText("Ajout de poissons");
}

void principal::onClick_validAjoutPoisson(){
    QStringList *ImageList = new QStringList();
    if(!this->poisson->text().trimmed().isEmpty() && !this->lieu2->text().trimmed().isEmpty()){
        ImageList->append(this->poisson->text());
        ImageList->append(this->lieu2->text());
    }
    for(int i = 0; i < image->count(); ++i)
    {
        QListWidgetItem* item = image->item(i);
        ImageList->append(item->text());
    }
    qDebug()<<*ImageList;
    // Création de l'Arborescence //
    QString currentPath = QCoreApplication::applicationDirPath();
    qDebug()<<currentPath;
}

void principal::onClick_showTelechargerPoisson(){

    deletItem(ui->layoutContenu);

    QLineEdit *Lieu3 = new QLineEdit;

    ui->layoutContenu->addRow("Lieu", Lieu3);

    QPushButton *boutonAnalyser = new QPushButton("Valider");
    ui->layoutContenu->addRow(boutonAnalyser);

    ui->TitleLabel->setText("Télécharger bibliothèque de poissons");

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
    QString filename = QFileDialog::getOpenFileName(this, tr("Ouvrir Image/Vidéo"), "C:/", tr("Fichiers Vidéo (*.mp4 *.avi *.m4v);;Fichiers Image (*.png *.jpg *.bmp *.tiff *.ppm)"));
    this->vidima->setText(filename);
}

void principal::onClick_selectSourcePathImage(){
    QString *filename = new QString;
    *filename = QFileDialog::getOpenFileName(this, tr("Ouvrir Image/Vidéo"), "C:/", tr("Fichiers Image (*.png *.jpg *.bmp *.tiff *.ppm);;Fichiers Vidéo (*.mp4 *.avi *.m4v)"));
    this->image->addItem(new QListWidgetItem(*filename));
    qDebug()<<*filename;
}

void principal::onClick_validAnalysis(){
     bool valid = false;
     QStringList *FormList = new QStringList();
     if(!this->nom->text().trimmed().isEmpty() && !this->date->text().trimmed().isEmpty() && !this->lieu->text().trimmed().isEmpty() && !this->vidima->text().trimmed().isEmpty()){
         FormList->append(this->nom->text());
         FormList->append(this->date->text());
         FormList->append(this->lieu->text());

         valid = true;
     }
     if(valid){
         Player* player = new Player(0,this->vidima->text(), FormList);
         QFileInfo video(this->vidima->text());
         if(video.exists()){
            const string path = this->vidima->text().toLocal8Bit().constData();
            VideoCapture cap(path);
             if(!cap.isOpened()){
                 qDebug() <<"Cannot open file";
             }else{
                Processing *proc = new Processing(cap);
                proc->start();
             }
         }
     }
     //player.addToPlaylist(this->filename);
}
