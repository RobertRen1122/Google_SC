#ifndef SERVER_H
#define SERVER_H

#include "serversocket.h"
#include "user.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHash>

class Server : public QObject{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
private:
    QTcpServer* server;
    QVector<ServerSocket*> clients;
    QHash<QString,QHash<QString,QString>> registered_users;
    QHash<QString,QHash<QString,QString>> active_users;

signals:

private slots:
    void newConnection();
    void userConnectionError(ServerSocket* client, QAbstractSocket::SocketError socketError);

    void attemptLogin(ServerSocket* client, const QString &username, const QString &password);
    void attemptSignup(ServerSocket* client, const QString &username, const QString &password);
};

#endif // SERVER_H
