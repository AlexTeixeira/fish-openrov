#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "principal.h"
#include <QtSql>
#include "model/security/cryptography.h"
#include "model/database/SQLConnection.h"
#include "QMessageBox"
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    connect(ui->connexionButton, SIGNAL(clicked()), this, SLOT(checkLogin()));
    connect(ui->annulerButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->AutoLoginButton, SIGNAL(clicked()), this, SLOT(AutoLogin()));

    //REMPLACE LES CHARACTERES PAR DES ASTERISQUES
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::checkLogin(){
    SQLConnection *sqlConnection = new SQLConnection(this);
    QString path = QDir::currentPath();
    sqlConnection->getSQLInstance(QDir::currentPath()+"/debug/fish.db");
    QSqlQuery query;
    if(query.exec("SELECT username, password, isAdmin FROM users WHERE username=='"+ui->lineEdit->text()+"' AND password=='"+Cryptography::hash(ui->lineEdit_2->text())+"'")){
        principal *_principal;
       if (query.next()){
                //ON VERIFIE LE TYPE DU COMPTE (0/1) DANS LA BASE DE DONNEES
                if(query.value(2)==1){
                    _principal = new principal("admin");
                } else {
                    _principal = new principal("student");
                }
                this->close();
               _principal->show();

        }   else {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Nom d'utilisateur/mot de passe incorrect");
            messageBox.setFixedSize(500,200);
        }

    }
}

void LoginWindow::ShowMainWindow(QString windowType){
    principal *_principal = new principal(windowType);
    _principal->show();
}

void LoginWindow::AutoLogin(){
    this->close();
    principal *_principal = new principal("admin");
    _principal->show();
}
