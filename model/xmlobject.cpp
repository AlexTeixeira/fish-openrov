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

QString XmlObject::GetName() {
    return this->name;
}

QString XmlObject::GetPath() {
    return this->path;
}

QDomDocument* XmlObject::GetDomDoc() {
    return this->domDoc;
}

void XmlObject::SetId(int _id) {
    this->id = _id;
}

void XmlObject::SetPath(QString _path) {
    this->path = _path;
}

void XmlObject::SetName(QString _name) {
    this->name = _name;
}

void XmlObject::Load() {
    this->domDoc = new QDomDocument(this->name);
    this->file = new QFile(this->path);
    
    if (!this->file->open(QIODevice::ReadOnly)) {
        qDebug() << "XmlObject - Load : Immpossible d'ouvrir le fichier en lecture seule.";
        return;
    } else {
        if (!domDoc->setContent(this->file)) {
            this->file->close();
            qDebug() << "XmlObject - Load : Immpossible de setter le domDoc.";
            return;
        } else {
            //qDebug() << this->path << "loaded ! ";
        }
    }
    this->file->close();
}

QList<QMap<QString, QString> > XmlObject::GetAllElementValues() {
    // Liste à retourner
    QList<QMap<QString, QString> > listOfList;
    
    // Racine pointe sur l'élément "library" du xml
    QDomElement racine = this->domDoc->documentElement();
    
    // On pointe maintenant sur le fils de la racine, "place"
    racine = racine.firstChildElement();
    
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

QList<QMap<QString, QString> *> *XmlObject::GetElementAttributesValue(QDomNode node, QString tagName) {
    // Liste de tableau associatif qui doit être retournée
    QList<QMap<QString, QString> *> *returnList = new QList<QMap<QString, QString> *>();
    
    // On pointe sur le premier noeud
    QDomNode domNode = node.firstChild();
    
    // Parcours du noeud
    while (!(domNode.isNull())) {
        // Si l'élément est celui que l'on recherche on récupère ses attributs
        if (domNode.toElement().tagName() == tagName) {
            // Création du tableau associatif
            QMap<QString, QString> *loadMap = new QMap<QString, QString>();
            // Vérification de l'existance des attributs du noeud
            if (domNode.hasAttributes()) {
                // Récupération des attributs dans le tableau associatif
                GetAttributesValue(domNode, loadMap);
                // Ajout du tableau dans la liste
                returnList->append(loadMap);
            }
        }
        // On fait la même chose avec e noeud suivant (récursivité)
        GetElementAttributesValue(domNode, tagName);
        // On passe au noeud suivant du même niveau
        domNode = domNode.nextSibling();
    }
    return returnList;
}

QList<QMap<QString, QString> *> *XmlObject::GetElementValues(QDomNode node, QString tagName) {
    QList<QMap<QString, QString> *> *returnList = new QList<QMap<QString, QString> *>();
    GetElementValues(node, tagName, returnList);
    return returnList;
}

void XmlObject::GetElementValues(QDomNode node, QString tagName, QList<QMap<QString, QString> *> *list) {
    QDomNode domNode = node.firstChild();   
    while (!(domNode.isNull())) {
        if (domNode.parentNode().toElement().tagName() == tagName) {
            QMap<QString, QString> *loadMap = new QMap<QString, QString>();
            GetElementValue(domNode.parentNode(), loadMap);
            list->append(loadMap);
        }
        GetElementValues(domNode, tagName, list);
        domNode = domNode.nextSibling();
    }
}

QList<QMap<QString, QString> *> *XmlObject::GetChildElementValues(QDomNode node, QString parentTagName) {
    QList<QMap<QString, QString>* > *returnList = new QList<QMap<QString, QString> *>();
    GetChildElementValues(node, parentTagName, returnList);
    return returnList;
}

void XmlObject::GetChildElementValues(QDomNode node, QString parentTagName, QList<QMap<QString, QString>* > *list) {
    QDomNode domNode = node.firstChild();
    while (!(domNode.isNull())) {
        QMap<QString, QString> *loadMap = new QMap<QString, QString>();
        if (domNode.toElement().tagName() == parentTagName) {
            QDomNodeList nodeList = domNode.childNodes();
            if (!nodeList.isEmpty()) {
                for (int var = 0; var < nodeList.size(); ++var) {
                    GetElementValue(nodeList.at(var), loadMap);
                }
                list->append(loadMap);
            }
        }
        GetChildElementValues(domNode, parentTagName, list);
        domNode = domNode.nextSibling();  
    }
}

void XmlObject::GetAttributesValue(QDomNode node, QMap<QString, QString> *returnMap) {
    if (node.isElement()) {
        QDomElement dom = node.toElement();
        QDomNamedNodeMap nma = dom.attributes();
        for(  int i=0; i < nma.length(); i++ ) {
          QDomAttr tempa = nma.item(i).toAttr();
          returnMap->insert(tempa.name(), tempa.value());
        }
    }
}

void XmlObject::GetElementValue(QDomNode node, QMap<QString, QString> *returnMap) {
    QDomElement element = node.toElement();
    if (!(element.isNull())) {
        QString text = element.text();
        if (!text.isNull()) {
            returnMap->insert(element.tagName(), text);
        }
    }
}

void Update() {
    
}

void Delete() {
    
}
