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
    QPoint m_startPoint;

    //chat
    void display_message(QHash<QString,QString> message);
    void modify_message(int index, QHash<QString,QString> message);
    QString cur_time();

    // Added for resizing window
    QPoint mpos; //For dragging, relative mouse position to upper left
    QPoint global_mpos; //For resizing, global mouse position at mouse click
    QPoint rs_mpos; //for resizing
    int storeWidth; //fix window size at mouseclick for resizing
    int storeHeight;

    //utility functions
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void remove(QLayout* layout);
    QPixmap PixmapToRound(const QPixmap &src, int radius);


signals:

private slots:
    //connect
    void connected();
    void serverError(QAbstractSocket::SocketError socketError);

    //login
    void loginError(const QString &reason);
    void loggedIn();
    void startApplication();
    void on_signout_clicked();

    //profile
    void profileChanged();
    void profileError(const QString &reason);
    void on_settingbutton_clicked();
    void on_changeProfile_clicked();
    void on_changeprofilepic_clicked();

    //chat
    void on_pushButton_clicked(); //send button
    void on_user_list_clicked(const QModelIndex &index);
    void on_info_butt_clicked();
    void on_pushButton_2_clicked(); //back to chat buttonn
    void messageReceived(QHash<QString,QString> &message);

    //ui
    void on_dictionary_2_clicked();
    void on_new_conversation_clicked();
    void on_maximize_butt_clicked();
    void on_minimize_butt_clicked();
};


#endif // MAINWINDOW_H
