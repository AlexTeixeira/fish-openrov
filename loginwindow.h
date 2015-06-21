#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
        void LoginWindow::ShowMainWindow(QString windowType);


private:
    Ui::LoginWindow *ui;
//    QString adminUsername = "admin";
//    QString adminPassword = "admin";
//    QString studentUsername = "user";
//    QString studentPassword = "user";

signals:


public slots:

    void checkLogin();
    void AutoLogin();


};

#endif // LOGINWINDOW_H
