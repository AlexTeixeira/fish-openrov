#include "library.h"

Library::Library(QObject *parent) :
    QObject(parent)
{
}

Library::Library(int _id, QString _name) {
    this->id = _id;
    this->name = _name;
    
    this->listPlace = new QList<Place*>();
}

int Library::GetId() {
    return this->id;
}

QString Library::GetName() {
    return this->name;
}

QString Library::GetXmlDirPath() {
    return this->xmlDirPath;
}

QList<QString> Library::GetListFullPath() {
    return this->listFullPath;
}

QList<Place*> *Library::GetListPlace() {
    return this->listPlace;
}

void Library::SetId(int _id) {
    this->id = _id;
}

void Library::SetName(QString _name) {
    this->name = _name;
}

void Library::SetXmlDirPath(QString _xmlDirPath) {
    this->xmlDirPath = _xmlDirPath;
}

void Library::LoadXmlLibrary() {
    // Récupération des chemins vers les fichiers xml à charger
    // Modification directe de la variable listFullPath
    GetFullPathFiles(this->xmlDirPath, "xml");
   
    // Parcours des fichiers à loader
    for (int var = 0; var < this->listFullPath.size(); ++var) {        
        // Création de l'objet XmlObject
        XmlObject *xmlToLoad = new XmlObject(var, (this->listFullPath[var]).split("/")[(this->listFullPath[var]).split("/").size()-1], this->listFullPath[var]);
        // Loading du fichier et
        xmlToLoad->Load();
        this->xmlLibrary.append(xmlToLoad);
    }
}

void Library::LoadXmlContent() {
    // Parcours de la librairyXml
    for (int var = 0; var < this->xmlLibrary.size(); ++var) {
        QList<QMap<QString, QString> *> *currentListPlace = this->xmlLibrary.at(var)->GetElementAttributesValue(this->xmlLibrary.at(var)->GetDomDoc()->firstChild(), "place");
        // Envoi de la QList dans la factory afin de créer les PLACE
        if (currentListPlace->size() > 0) {
            for (int var2 = 0; var2 < currentListPlace->size(); ++var2) {        
                // Création de la classe courrante Place
                Place *currentPlace = new Place(*currentListPlace->at(var2));
                this->listPlace->append(currentPlace);
                
                // Pour chaque place trouvée, on recherche le ou les fish
                QList<QMap<QString, QString> *> *currentListFish = this->xmlLibrary.at(var)->GetChildElementValues(this->xmlLibrary.at(var)->GetDomDoc()->firstChild(), "fish");
                // Envoi de la QList dans la factory afin de créer les FISH
                if (currentListFish->size() > 0) {
                    QList<Fish*> *listFish = new QList<Fish*>();
                    for (int var2 = 0; var2 < currentListFish->size(); ++var2) {
                        Fish *currentFish = new Fish(*currentListFish->at(var2));
                        listFish->append(currentFish);
                    }
                    currentPlace->SetListFish(listFish);
                }
            }
        }
    }    
}

void Library::GetFullPathFiles(QDir rootDir, QString extension) {
    // FICHIERS
    // Filtrage des fichiers uniquement
    rootDir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    // Liste des fichiers
    QStringList fileList = rootDir.entryList();
    // Parcours des fichiers trouvés
    for (int i = 0; i < fileList.count(); i++) {
        // On vérifie l'extension du fichier trouvé
        if (fileList[i].endsWith(extension)) {
            // Construction du full path pour chaque fichier
            QString fullPath = rootDir.absolutePath()+"/"+fileList[i];
            this->listFullPath.append(fullPath);
        }
    }
    
    // DOSSIERS
    // Filtrage des dossiers uniquement
    rootDir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    // Liste des dossiers
    QStringList dirList = rootDir.entryList();
    // Parcours des dossiers
    for (int j = 0; j < dirList.size(); j++) {
        // Construction du full path du dossier parcouru
        QString newPath = QString("%1/%2").arg(rootDir.absolutePath()).arg(dirList.at(j));
        // Exécution en recursif sur le nouveau dossier
        GetFullPathFiles(QDir(newPath), extension);
    }
}

void Library::UpdateXmlLibrary() {
    
}
