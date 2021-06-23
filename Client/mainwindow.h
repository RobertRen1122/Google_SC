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
    // Added for resizing window
    QPoint mpos; //For dragging, relative mouse position to upper left
    QPoint global_mpos; //For resizing, global mouse position at mouse click
    QPoint rs_mpos; //for resizing
    int storeWidth; //fix window size at mouseclick for resizing
    int storeHeight;

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
    void on_maximize_butt_clicked();
    void on_minimize_butt_clicked();
};


#endif // MAINWINDOW_H
