#include "server.h"

#include <QDebug>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

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

    //load registered users
    QFile file("../Server/registered_users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument data = QJsonDocument::fromJson(file.readAll());
    file.close();
    QJsonObject users = data.object();
    foreach(const QString& key, users.keys()) {
        QJsonObject user_json = users.value(key).toObject();
        QHash<QString,QString> user;
        foreach(const QString& key2, user_json.keys()) {
            user.insert(key2,user_json.value(key2).toString());
        }
        registered_users.insert(key,user);
    }
}

Server::~Server(){

}

void Server::attemptSignup(ServerSocket *client,const QString &username,const QString &password){
    if(username.compare("")==0){
            client->loginError("Username is empty");
    }else if(registered_users.contains(username)){
        client->loginError("Username already taken");
    }else if(password.compare("")==0){
        client->loginError("Password is empty");
    }else{
        client->loginSuccessful();

        //initialize and save client info
        QHash<QString,QString> user;
        user.insert("username",username);
        user.insert("password",password);
        registered_users.insert(username,user);
        QJsonObject user_json;
        user_json.insert("username",username);
        user_json.insert("password",password);

        //save to json file
        QFile file("../Server/registered_users.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QJsonDocument data = QJsonDocument::fromJson(file.readAll());
        file.close();
        QJsonObject users = data.object();
        users.insert(username,user_json);
        data.setObject(users);
        file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
        file.write(data.toJson());
        file.close();
        client->sendPersonalInfo(user);

        //initialize and save message info

    }
}

void Server::attemptLogin(ServerSocket *client,const QString &username,const QString &password){
    if(registered_users.contains(username)){
        if(registered_users[username]["password"].compare(password)==0){
            client->loginSuccessful();
            //get client info and send
            client->sendPersonalInfo(registered_users[username]);
            //get message info and send

            qDebug() << username << "loggedin";
        }else{
            client->loginError("Incorrect password");
        }
    }else{
        client->loginError("Username does not exist");
    }
}

void Server::newConnection(){
    ServerSocket *client = new ServerSocket(this);
    client->setSocket(server->nextPendingConnection());
    connect(client, &ServerSocket::connectionError, this,
            std::bind(&Server::userConnectionError, this, client, std::placeholders::_1));
    connect(client, &ServerSocket::attemptLogin, this,
            std::bind(&Server::attemptLogin, this, client, std::placeholders::_1, std::placeholders::_2));
    connect(client, &ServerSocket::attemptSignup, this,
            std::bind(&Server::attemptSignup, this, client, std::placeholders::_1, std::placeholders::_2));
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
