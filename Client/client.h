#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject{
    Q_OBJECT

public:
    explicit Client(QObject *parent = nullptr);
    void connectToServer();

    QHash<QString,QString> profile;
    void updateProfile();

private:
    QTcpSocket* socket;
    void jsonReceived(const QJsonObject &data);

signals:
    //QTcpSocket signals
    void connected();
    void serverError(QAbstractSocket::SocketError socketError);
    //signals fired after analyzing message from the server
    void loginError(const QString &reason);
    void loggedIn();
    void informationRecieved();
    //void messageReceived(const QString &sender, const QString &text);
    void profileChanged();
    void profileError(const QString &reason);

public slots:
    void attemptLogin(const QString &username,const QString &password);
    void attemptSignup(const QString &email,const QString &username,const QString &password);

    //void newConversation();
    //void sendMessage();

private slots:
    void onReadyRead();


};

#endif // CLIENT_H
