#include "principal.h"
#include <QApplication>

#include <QDebug>
#include "model/library.h"
#include "model/fish.h"
#include "model/place.h"
#include "model/library.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Library *lib = new Library(01, "libTest");  
    lib->SetXmlDirPath("C:/temp");   
    lib->LoadXmlLibrary();  
    lib->LoadXmlContent();
    
    QList<Place*> *places = new QList<Place*>(*lib->GetListPlace());
    
    for (int var = 0; var < places->size(); ++var) {
        qDebug() << "Fishier chargé n°" << var;
        qDebug() << places->at(var)->GetId();
        qDebug() << places->at(var)->GetName();
        
        QList<Fish*> *fishes = new QList<Fish*>(*places->at(var)->GetListFish());
        for (int var2 = 0; var2 < fishes->size(); ++var2) {
            qDebug() << "    ---" << fishes->at(var2)->GetId();
            qDebug() << "    ---" << fishes->at(var2)->GetName();
            qDebug() << "    ---" << fishes->at(var2)->GetSize();
            qDebug() << "";
        }
    }
    
    principal w;
    w.show();
    
    return a.exec();
}
