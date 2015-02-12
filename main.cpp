#include "mainwindow.h"
#include <QApplication>

#include <QDebug>
#include "model/library.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    MainWindow w;
    w.show();
    
    return a.exec();
}
