#include "server.h"

#include <QDebug>

Server::Server(QObject *parent) :
    QObject(parent),
    server(new QTcpServer(this))
{
    connect(server, &QTcpServer::newConnection, this, &Server::newConnection);

    if (!server->listen(QHostAddress::Any, 8080)){
        qDebug() << "Server could not start";
    }else{
        qDebug() << "Server started";
    }
}

Server::~Server(){

}

void Server::newConnection(){
    ServerSocket *client = new ServerSocket(this);
    client->setSocket(server->nextPendingConnection());
    connect(client, &ServerSocket::connectionError, this,
            std::bind(&Server::userConnectionError, this, client, std::placeholders::_1));
    clients.append(client);
    qDebug() << "New client Connected";
}



void Server::userConnectionError(ServerSocket *client, QAbstractSocket::SocketError socketError){
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        qDebug() << "The client closed the connection";
        break;
    case QAbstractSocket::SocketTimeoutError:
        qDebug() << "Operation timed out";
        return;
    case QAbstractSocket::TemporaryError:
        qDebug() << "A Temporary error occured";
        return;
    case QAbstractSocket::OperationError:
        qDebug() << "Operation failed, please try again";
        return;
    default:
        qDebug() << "An unknown error occured";
    }
    clients.removeAll(client);
    client->deleteLater();
}
