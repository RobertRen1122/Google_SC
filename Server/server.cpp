#include "server.h"

#include <QDebug>
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <time.h>
#include <sys/timeb.h>

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

    //manually add friends or remove users here
}

Server::~Server(){

}

void Server::remove_user(const QString &ID){
    //active
    //force signout the user
    //remove from all_users, registered_emails, and registered_usernames
    //notify and remove from all active friends

    //permanent
    //remove from all_users.json
    QFile file("../Server/all_users.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument data = QJsonDocument::fromJson(file.readAll());
    file.close();
    QJsonObject users = data.object();
    users.remove(ID);
    data.setObject(users);
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    file.write(data.toJson());
    file.close();
    //remove from all friend folders
    QDir dir("../Server/messages/"+ID);
    QStringList files = dir.entryList(QStringList() << "*.json", QDir::Files);
    foreach(const QString& friend_ID, files) {
        QFile friend_message("../Server/messages/"+friend_ID.split('.')[0]+"/"+ID+".json");
        friend_message.remove();
    }
    //remove folder from messages
    dir.removeRecursively();
}

void Server::make_friend(const QString &ID1,const QString &ID2){
    //create message json file for ID1
    QFile file("../Server/messages/"+ID1+"/"+ID2+".json");
    file.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    QJsonArray jsonArray;

    QJsonDocument jsonDoc;
    jsonDoc.setArray(jsonArray);
    file.write(jsonDoc.toJson());
    file.close();
    //create message json file for ID2
    QFile file2("../Server/messages/"+ID2+"/"+ID1+".json");
    file2.open(QFile::WriteOnly | QFile::Text | QFile::Truncate);
    QJsonArray jsonArray2;

    QJsonDocument jsonDoc2;
    jsonDoc2.setArray(jsonArray2);
    file2.write(jsonDoc2.toJson());
    file2.close();
}

//CHANGE STUFF HERE
QString Server::new_ID(){
    QString id_;
    int length = 32;
    QString strTmp = "abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    struct timeb timer;
    ftime(&timer);
    srand(timer.time * 1000 + timer.millitm);

    for(int i = 0; i < length; i++ )
    {
    int j = rand()%61;
    id_ += strTmp.at(j);
    }
    qDebug() << id_;
    if(all_users.contains(id_)==0){
        return id_;
    }else{
        qDebug()<<"something went wrong";
        return new_ID();
    }
    return "error";
}

void Server::attemptSignup(ServerSocket *client,const QString &email,const QString &username,const QString &password){
    if(registered_emails.contains(email)){
        client->loginError("Email already taken");
    }else if(registered_usernames.contains(username)){
        client->loginError("Username already taken");
    }else{
        QString ID = new_ID();
        client->loginSuccessful(ID);
        active_users.append(ID);

        //initialize and save client info
        QHash<QString,QString> user;
        user.insert("username",username);
        user.insert("password",password);
        user.insert("email",email);
        user.insert("intro","This is your intro.");
        user.insert("pronoun","");
        user.insert("language1","");
        user.insert("language2","");
        user.insert("language3","");
        user.insert("profile_pic_path", ":/images/pic/profile.png");
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

        //initialize and save messages info
        QDir().mkdir("../Server/messages/"+ID);

        //send info to client
        client->sendPersonalInfo(user);
        client->sendMessageInfo(ID);
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
            client->sendMessageInfo(registered_usernames[username]);

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
            client->sendMessageInfo(registered_emails[username]);

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

void Server::signout(const QString &ID){
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
