#include "adduser.h"
#include "ui_adduser.h"
#include "model/user.h"
#include "QtSql"
#include "model/database/sqlconnection.h"
#include "qmessagebox.h"

AddUser::AddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);

    connect(ui->addButton, SIGNAL(clicked(bool)), this, SLOT(UserAdd()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), this, SLOT(close()));
    connect( this, SIGNAL(refresh()), parentWidget(), SLOT(fillUserList()) );

}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::UserAdd(){

    SQLConnection *sqlConnection = new SQLConnection(this);
    sqlConnection->getSQLInstance(QCoreApplication::applicationDirPath()+"/fish.db");
    QSqlQuery query;
    if(ui->userNamefield->text().count()<50){
        if(ui->passwordField->text().count()<50){
            if(ui->passwordField->text() == ui->confirmField->text()){
                if(ui->isAdminCheckbox->isChecked()){
                    query.exec("INSERT INTO users (username, password, isadmin) VALUES ('"+ ui->userNamefield->text()+"','"+Cryptography::hash(ui->passwordField->text())+"','1')");
                } else {
                    query.exec("INSERT INTO users (username, password, isadmin) VALUES ('"+ ui->userNamefield->text()+"','"+Cryptography::hash(ui->passwordField->text())+"','0')");
                }
            } else {
                QMessageBox messageBox;
                messageBox.critical(0,"Erreur","Les deux champs mot de passe ne sont pas identiques");
                messageBox.setFixedSize(500,200);
            }

        } else {
            QMessageBox messageBox;
            messageBox.critical(0,"Erreur","Le mot de passe doit compter moins de 50 caractères");
            messageBox.setFixedSize(500,200);
        }

    } else {
        QMessageBox messageBox;
        messageBox.critical(0,"Erreur","Le nom d'utilisateur doit compter moins de 50 caractères");
        messageBox.setFixedSize(500,200);

    }


    emit refresh();
    this->close();
}

