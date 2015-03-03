#include "mainwindow.h"
#include <QApplication>

#include <QDebug>
#include "model/library.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    Library *lib = new Library(01, "libTest");
    lib->SetXmlDirPath("C:/temp");
    lib->LoadXmlLibrary();
    
    lib->LoadXmlContent();
    
    
    MainWindow w;
    w.show();
    
    return a.exec();
}
