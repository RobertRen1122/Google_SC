#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <QObject>
#include <QTcpSocket>

class ServerSocket : public QObject{
    Q_OBJECT

public:
    explicit ServerSocket(QObject *parent = nullptr);
    ~ServerSocket();

    void setSocket(QTcpSocket *socket);
    void disconnectFromClient();
private:
    QTcpSocket *socket;
    void jsonReceived(const QJsonObject &data);

signals:
    //QTcpSocket signals
    void connectionError(QAbstractSocket::SocketError socketError);
    //signals fired after analyzing message from the client
    //void attemptLogin();
    //void changeProfile();
    //void newConversation();

public slots:
    //void loginSuccess(const QString &username,const QString &password);
    //void userError(const QString &username,const QString &password);

    //void profileInformation();
    //void matchFound();
    //void messageRecieved();

private slots:
    void onReadyRead();

};

#endif // SERVERSOCKET_H
