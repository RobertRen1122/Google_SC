#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject{
    Q_OBJECT

public:
    explicit Client(QObject *parent = nullptr);
    void connectToServer();

private:
    QTcpSocket* socket;
    void jsonReceived(const QJsonObject &data);

signals:
    //QTcpSocket signals
    void connected();
    void serverError(QAbstractSocket::SocketError socketError);
    //signals fired after analyzing message from the server
    //void userError(const QString &reason);
    //void loggedIn();
    //void messageReceived(const QString &sender, const QString &text);

public slots:
    //void attemptSignup(const QString &username,const QString &password);
    //void attemptLogin(const QString &username,const QString &password);

    //void updateProfile();
    //void newConversation();
    //void sendMessage();

private slots:
    void onReadyRead();


};

#endif // CLIENT_H
