#include "client.h"
#include <QTcpSocket>
#include <QDataStream>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

Client::Client(QObject *parent):
    QObject(parent),
    socket(new QTcpSocket(this))
{
    //connect to signals
    connect(socket, &QTcpSocket::connected, this, &Client::connected);
    connect(socket, &QAbstractSocket::errorOccurred, this,  &Client::serverError);
    //connect to slots
    connect(socket, &QTcpSocket::readyRead, this, &Client::onReadyRead);
}

// ------------------------------ message from server ------------------------------

void Client::jsonReceived(const QJsonObject &data)
{
    qDebug()<<"message";
    foreach(const QString& key, data.keys()){
        qDebug()<<key<<"->"<<data.value(key).toString();
    }
    qDebug()<<"";

    const QJsonValue typeVal = data.value(QLatin1String("type"));
    // message regarding login
    if (typeVal.toString().compare(QLatin1String("login"))==0) {
        const QJsonValue resultVal = data.value(QLatin1String("success"));
        const bool loginSuccess = resultVal.toBool();
        if (loginSuccess) {
            emit loggedIn();
            return;
        }
        const QJsonValue reasonVal = data.value(QLatin1String("reason"));
        emit loginError(reasonVal.toString());
    // message regarding profile
    }else if(typeVal.toString().compare(QLatin1String("profile information"))==0) {
        foreach(const QString& key, data.keys()) {
            if (key!="type"){
                QJsonValue value = data.value(key);
                profile[key]=value.toString();
            }
        }
        emit informationRecieved();
    }else if(typeVal.toString().compare(QLatin1String("profile change"))==0) {
        const QJsonValue resultVal = data.value(QLatin1String("success"));
        const bool loginSuccess = resultVal.toBool();
        if (loginSuccess) {
            emit profileChanged();
            return;
        }
        const QJsonValue reasonVal = data.value(QLatin1String("reason"));
        foreach(const QString& key, data.keys()){
            if(key!="type" and key!="success" and key!="reason"){
                QJsonValue value = data.value(key);
                profile[key]=value.toString();
            }
        }
        emit profileError(reasonVal.toString());
    }
    // message regarding contacts
}

// ------------------------------ message to server ------------------------------

void Client::updateProfile(){
    QDataStream clientStream(socket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("profile change");
    foreach(const QString& key, profile.keys()) {
        message[key] = profile[key];
    }
    clientStream << QJsonDocument(message).toJson();
}

void Client::attemptLogin(const QString &username,const QString &password){
    QDataStream clientStream(socket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    // Create the JSON we want to send
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("login");
    message[QStringLiteral("username")] = username;
    message[QStringLiteral("password")] = password;
    // send the JSON using QDataStream
    clientStream << QJsonDocument(message).toJson();
}

void Client::attemptSignup(const QString &email,const QString &username,const QString &password){
    QDataStream clientStream(socket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    // Create the JSON we want to send
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("signup");
    message[QStringLiteral("email")] = email;
    message[QStringLiteral("username")] = username;
    message[QStringLiteral("password")] = password;
    // send the JSON using QDataStream
    clientStream << QJsonDocument(message).toJson();
}

// ------------------------------ helper functions ------------------------------

void Client::onReadyRead()
{
    // a container to hold the UTF-8 encoded JSON we receive from the socket
    QByteArray jsonData;
    // a QDataStream operating on the socket
    QDataStream socketStream(socket);
    socketStream.setVersion(QDataStream::Qt_5_7);
    while(1) {
        // start a transaction so we can revert to the previous state
        // in case we try to read more data than is available on the socket
        socketStream.startTransaction();
        socketStream >> jsonData;
        if (socketStream.commitTransaction()) {
            QJsonParseError parseError;
            const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
            // if the data is valid JSON
            if (parseError.error == QJsonParseError::NoError) {
                // if the data is JSON object
                if (jsonDoc.isObject()){
                    jsonReceived(jsonDoc.object());
                }
            }
        } else {
            // the read failed
            // the socket goes automatically back to the state it was in before the transaction started
            // exit the loop and wait for more data to become available
            break;
        }
    }
}

void Client::connectToServer()
{
    socket->connectToHost("127.0.0.1",8080);
}
