#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

class Client : public QObject{
    Q_OBJECT

public:
    explicit Client(QObject *parent = nullptr);
    void connectToServer();
    void signout();

    QString ID;
    QHash<QString,QString> profile;
    void updateProfile();

    QHash<QString,QVector<QHash<QString,QString>>> friend_messages;
    QHash<QString,QHash<QString,QString>> friend_profiles;

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
    void informationReceived();
    void profileChanged();
    void profileError(const QString &reason);
    void messageReceived(QHash<QString,QString> &message);

public slots:
    void attemptLogin(const QString &username,const QString &password);
    void attemptSignup(const QString &email,const QString &username,const QString &password);

    //void newConversation();
    void sendMessage(QHash<QString,QString> &message);

private slots:
    void onReadyRead();

};

#endif // CLIENT_H
