#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->signup->hide();
}

LoginWindow::~LoginWindow(){
    delete ui;
}

void LoginWindow::on_login_clicked(){
    ui->error->setText("");
    QString username = ui->username->text();
    QString password = ui->password->text();
    qDebug()<<username<<" "<<password<<"\n";
    emit attemptLogin(username,password);
}

void LoginWindow::on_goto_signup_clicked(){
    ui->error->setText("");
    ui->username->setText("");
    ui->password->setText("");
    ui->login->hide();
    ui->goto_signup->hide();
    ui->signup->show();
}

void LoginWindow::on_signup_clicked(){
    ui->error->setText("");
    QString username = ui->username->text();
    QString password = ui->password->text();
    qDebug()<<username<<" "<<password<<"\n";
    emit attemptSignup(username,password);
}

void LoginWindow::display_error(const QString &error){
    ui->error->setText(error);
}
