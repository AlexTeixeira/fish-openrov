#include "xmlobject.h"

XmlObject::XmlObject(int _id, QString _name, QString _path)
{
    this->id = _id;
    this->name = _name;
    this->path = _path;
}

int XmlObject::GetId() {
    return this->id;
}

void XmlObject::SetId(int _id) {
    this->id = _id;
}

QString XmlObject::GetName() {
    return this->name;
}

void XmlObject::SetName(QString _name) {
    this->name = _name;
}

QString XmlObject::GetPath() {
    return this->path;
}

void XmlObject::SetPath(QString _path) {
    this->path = _path;
}

void XmlObject::Load() {
    this->domDoc = new QDomDocument(this->name);
    this->file = new QFile(this->file);
    
    if (!this->file->open(QIODevice::ReadOnly)) {
        qDebug() << "XmlObject - Load : Immpossible d'ouvrir le fichier en lecture seule.";
        return;
    } else {
        if (!domDoc->setContent(this->file)) {
            this->file->close();
            qDebug() << "XmlObject - Load : Immpossible de setter le domDoc.";
            return;
        }
    }
    this->file->close();
}

QList<QMap<QString, QString> > XmlObject::ReadAllFish() {
    // Liste à retourner
    QList<QMap<QString, QString> > listOfList;
    
    // Racine pointe sur l'élément "library" du xml
    QDomElement racine = this->domDoc->documentElement();
    
    // On pointe maintenant sur le fils de la racine, "place"
    racine = racine.firstChildElement();
    
    // Parcours depuis "place"
    while(!racine.isNull()) {
        // On vérifie que le fils est bien "place"
        if (racine.tagName() == "place") {
            // Récupération de son premier fils "fish"
            QDomElement element = racine.firstChildElement();
            // Parcours tant qu'il y a des éléments
            while (!element.isNull()) {
                // On vérifie que le tagName soit bien "fish"
                if (element.tagName() == "fish") {
                    // Pour chaque élément on créé un objet QMap
                    QMap<QString, QString> map;
                    // Récupération du premier fils de fish
                    QDomElement elementFish = element.firstChildElement();
                    // Parcours pour chaque fils
                    while (!elementFish.isNull()) {
                        // Récupération du tagName et de sa valeur que l'on insert dans l'objet QMap
                        map.insert(elementFish.tagName(), elementFish.text());
                        // On passe à l'élément suivant
                        elementFish = elementFish.nextSiblingElement();
                    }
                    // Insertion de l'objet QMap dans la liste
                    listOfList.append(map);
                }
                // On passe à l'élément suivant
                element = element.nextSiblingElement();
            }
        }
        // On passe à l'élément suivant
        racine = racine.nextSiblingElement();
	}
    return listOfList;
}

void Update() {
    
}

void Delete() {
    
}
