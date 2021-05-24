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
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    LoadingWindow* loading;
    LoginWindow* login;
    Client* client;
    QPoint m_startPoint;

signals:

private slots:
    void connected();
    void serverError(QAbstractSocket::SocketError socketError);

    void loginError(const QString &reason);
    void loggedIn();
    void startApplication();

    void profileChanged();
    void profileError(const QString &reason);

    void on_settingbutton_clicked();
    void on_dictionary_2_clicked();
    void on_changeProfile_clicked();
    void on_signout_clicked();
};


#endif // MAINWINDOW_H
