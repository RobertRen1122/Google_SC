#ifndef SERVER_H
#define SERVER_H

#include "serversocket.h"
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class Server : public QObject{
    Q_OBJECT

public:
    explicit Server(QObject *parent = nullptr);
    ~Server();
private:
    QTcpServer* server;
    QVector<ServerSocket*> clients;

signals:

private slots:
    void newConnection();
    void userConnectionError(ServerSocket* client,QAbstractSocket::SocketError socketError);
};

#endif // SERVER_H
