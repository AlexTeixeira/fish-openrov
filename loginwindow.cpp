#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "principal.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    connect(ui->connexionButton, SIGNAL(clicked()), this, SLOT(checkLogin()));
    connect(ui->annulerButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->AutoLoginButton, SIGNAL(clicked()), this, SLOT(AutoLogin()));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::checkLogin(){
    if(ui->lineEdit->text() == adminUsername && ui->lineEdit_2->text() == adminUsername){
        this->close();
        ShowMainWindow("admin");
    } else if(ui->lineEdit->text() == studentUsername && ui->lineEdit_2->text() == studentPassword){
        this->close();
        ShowMainWindow("student");
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
