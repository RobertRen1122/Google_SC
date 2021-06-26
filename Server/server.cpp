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
    QFile file("../Server/all_users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument data = QJsonDocument::fromJson(file.readAll());
    file.close();
    QJsonObject users = data.object();
    foreach(const QString& ID, users.keys()) {
        QJsonObject user_json = users.value(ID).toObject();
        QHash<QString,QString> user;
        foreach(const QString& key, user_json.keys()) {
            user.insert(key,user_json.value(key).toString());
        }
        all_users.insert(ID,user);
        registered_usernames.insert(user["username"],ID);
        registered_emails.insert(user["email"],ID);
    }
}

Server::~Server(){

}

//CHANGE STUFF HERE
QString Server::new_ID(){
    for(int i=0;i<10;i++){
        if (all_users.contains(QString::number(i))==0){
            return QString::number(i);
        }
    }
    qDebug()<<"Something went wrong or >10 users";
    return "error";
}

void Server::attemptSignup(ServerSocket *client,const QString &email,const QString &username,const QString &password){
    if(registered_emails.contains(email)){
        client->loginError("Email already taken");
    }else if(registered_usernames.contains(username)){
        client->loginError("Username already taken");
    }else{
        QString ID=new_ID();
        client->loginSuccessful(ID);
        active_users.append(ID);

        //initialize and save client info
        QHash<QString,QString> user;
        user.insert("username",username);
        user.insert("password",password);
        user.insert("email",email);
        user.insert("intro","This is your intro.");
        user.insert("pronoun","none");
        user.insert("language1","none");
        user.insert("language2","none");
        user.insert("language3","none");
        user.insert("profile_pic_path", "../Client/pic/profile.png");
        all_users.insert(ID,user);
        registered_usernames.insert(username,ID);
        registered_emails.insert(email,ID);

        //save to json file
        QFile file("../Server/all_users.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QJsonDocument data = QJsonDocument::fromJson(file.readAll());
        file.close();
        QJsonObject users = data.object();
        QJsonObject user_json;
        foreach(const QString& key, user.keys()) {
            user_json.insert(key,user[key]);
        }
        users.insert(ID,user_json);
        data.setObject(users);
        file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
        file.write(data.toJson());
        file.close();
        client->sendPersonalInfo(user);

        //initialize and save message info

    }
}

void Server::attemptLogin(ServerSocket *client,const QString &username,const QString &password){
    if(registered_usernames.contains(username)){
        if(all_users[registered_usernames[username]]["password"].compare(password)==0){
            client->loginSuccessful(registered_usernames[username]);
            active_users.append(registered_usernames[username]);
            //get client info and send
            client->sendPersonalInfo(all_users[registered_usernames[username]]);
            //get message info and send

            qDebug()<<"Current users:";
            foreach(const QString& ID, active_users) {
                qDebug()<<ID<<": "<<all_users[ID]["username"];
            }
            qDebug()<<"";
        }else{
            client->loginError("Incorrect password");
        }
    }else if(registered_emails.contains(username)){
        if(all_users[registered_emails[username]]["password"].compare(password)==0){
            client->loginSuccessful(registered_emails[username]);
            active_users.append(registered_emails[username]);
            //get client info and send
            client->sendPersonalInfo(all_users[registered_emails[username]]);
            //get message info and send

            qDebug()<<"Current users:";
            foreach(const QString& ID, active_users) {
                qDebug()<<ID<<": "<<all_users[ID]["username"];
            }
            qDebug()<<"";
        }else{
            client->loginError("Incorrect password");
        }
    }else{
        client->loginError("Username does not exist");
    }
}

void Server::changeProfile(ServerSocket* client, QHash<QString,QString> profile){
    //if username changed
    if(profile["username"]!=all_users[client->ID]["username"]){
        qDebug()<<profile["username"]<<" vs "<<all_users[client->ID]["username"];
        if (registered_usernames.contains(profile["username"])){
            client->changeProfileError("username is already taken",all_users[client->ID]);
            return;
        }
    }
    //if email changed
    if(profile["email"]!=all_users[client->ID]["email"]){
        if (registered_emails.contains(profile["email"])){
            client->changeProfileError("email is already taken",all_users[client->ID]);
            return;
        }
    }
    //approve change
    client->changeProfileSuccess();

    registered_usernames.remove(all_users[client->ID]["username"]);
    registered_usernames.insert(profile["username"],client->ID);
    registered_emails.remove(all_users[client->ID]["email"]);
    registered_emails.insert(profile["email"],client->ID);
    all_users[client->ID]=profile;

    //save to json
    QFile file("../Server/all_users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument data = QJsonDocument::fromJson(file.readAll());
    file.close();
    QJsonObject users = data.object();
    QJsonObject profile_json;
    foreach(const QString& key, profile.keys()) {
        profile_json.insert(key,profile[key]);
    }
    users[client->ID]=profile_json;
    data.setObject(users);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(data.toJson());
    file.close();
}

void Server::newConnection(){
    ServerSocket *client = new ServerSocket(this);
    client->setSocket(server->nextPendingConnection());
    connect(client, &ServerSocket::connectionError, this,
            std::bind(&Server::userConnectionError, this, client, std::placeholders::_1));
    connect(client, &ServerSocket::attemptLogin, this,
            std::bind(&Server::attemptLogin, this, client, std::placeholders::_1, std::placeholders::_2));
    connect(client, &ServerSocket::attemptSignup, this,
            std::bind(&Server::attemptSignup, this, client, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    connect(client, &ServerSocket::changeProfile, this,
            std::bind(&Server::changeProfile, this, client, std::placeholders::_1));
    connect(client, &ServerSocket::signout, this, &Server::signout);
    clients.append(client);
    qDebug() << "New client Connected";
}

void Server::signout(QString &ID){
    active_users.removeOne(ID);

    qDebug()<<"Current users:";
    foreach(const QString& ID, active_users) {
        qDebug()<<ID<<": "<<all_users[ID]["username"];
    }
    qDebug()<<"";
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
    active_users.removeOne(client->ID);
    client->deleteLater();

    qDebug()<<"Current users:";
    foreach(const QString& ID, active_users) {
        qDebug()<<ID<<": "<<all_users[ID]["username"];
    }
    qDebug()<<"";
}
