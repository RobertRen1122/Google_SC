#include "serversocket.h"
#include <QTcpSocket>
#include <QDataStream>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

ServerSocket::ServerSocket(QObject *parent) :
    QObject(parent)
{

}

void ServerSocket::setSocket(QTcpSocket *clientSocket){
    socket = clientSocket;
    //connect to signals
    connect(socket, &QAbstractSocket::errorOccurred, this, &ServerSocket::connectionError);
    //connect to slots
    connect(socket, &QTcpSocket::readyRead, this, &ServerSocket::onReadyRead);
}

ServerSocket::~ServerSocket(){
    delete socket;
}


void ServerSocket::sendPersonalInfo(QHash<QString,QString> &user){
    QDataStream clientStream(socket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    // Create the JSON we want to send
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("profile information");
    for(QHash<QString,QString>::iterator i=user.begin(); i!=user.end(); ++i)
    {
        message[i.key()] = i.value();
    }
    // send the JSON using QDataStream
    clientStream << QJsonDocument(message).toJson();
}



void ServerSocket::loginError(const QString &reason){
    QDataStream clientStream(socket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    // Create the JSON we want to send
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("login");
    message[QStringLiteral("success")] = false;
    message[QStringLiteral("reason")] = reason;
    // send the JSON using QDataStream
    clientStream << QJsonDocument(message).toJson();
}

void ServerSocket::loginSuccessful(){
    QDataStream clientStream(socket);
    clientStream.setVersion(QDataStream::Qt_5_7);
    // Create the JSON we want to send
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("login");
    message[QStringLiteral("success")] = true;
    // send the JSON using QDataStream
    clientStream << QJsonDocument(message).toJson();
}


void ServerSocket::jsonReceived(const QJsonObject &data)
{
    const QJsonValue typeVal = data.value(QLatin1String("type"));
    // message regarding login
    if (typeVal.toString().compare(QLatin1String("login"))==0) {
        const QJsonValue usernameVal = data.value(QLatin1String("username"));
        const QString username = usernameVal.toString();
        const QJsonValue passwordVal = data.value(QLatin1String("password"));
        const QString password = passwordVal.toString();
        emit attemptLogin(username,password);
    }else if (typeVal.toString().compare(QLatin1String("signup"))==0) {
        const QJsonValue usernameVal = data.value(QLatin1String("username"));
        const QString username = usernameVal.toString();
        const QJsonValue passwordVal = data.value(QLatin1String("password"));
        const QString password = passwordVal.toString();
        emit attemptSignup(username,password);
    }
}


// ------------------------------ helper functions ------------------------------

void ServerSocket::onReadyRead()
{
    // a container to hold the UTF-8 encoded JSON we receive from the socket
    QByteArray jsonData;
    // a QDataStream operating on the socket
    QDataStream socketStream(socket);
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
