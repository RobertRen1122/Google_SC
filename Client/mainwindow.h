#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "loadingwindow.h"
#include "loginwindow.h"
#include "client.h"

namespace Ui {class MainWindow;}

class MainWindow : public QWidget{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    LoadingWindow* loading;
    LoginWindow* login;
    Client* client;

signals:

private slots:
    void connected();
    void serverError(QAbstractSocket::SocketError socketError);

};

#endif // MAINWINDOW_H
