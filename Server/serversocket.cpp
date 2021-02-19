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



void ServerSocket::jsonReceived(const QJsonObject &data)
{
    // actions depend on the type of message
    const QJsonValue typeVal = data.value(QLatin1String("type"));
    if (typeVal.isNull() || !typeVal.isString())
        return; // a message with no type was received so we just ignore it
    if (typeVal.toString().compare(QLatin1String("login"), Qt::CaseInsensitive) == 0) { //It's a login message
        // the success field will contain the result of our attempt to login
        const QJsonValue resultVal = data.value(QLatin1String("success"));
        if (resultVal.isNull() || !resultVal.isBool())
            return; // the message had no success field so we ignore
        const bool loginSuccess = resultVal.toBool();
        if (loginSuccess) {
            // we logged in succesfully and we notify it via the loggedIn signal
            //emit loggedIn();
            return;
        }
        // the login attempt failed, we extract the reason of the failure from the JSON
        // and notify it via the loginError signal
        const QJsonValue reasonVal = data.value(QLatin1String("reason"));
        //emit userError(reasonVal.toString());
    } else if (typeVal.toString().compare(QLatin1String("message"), Qt::CaseInsensitive) == 0) { //It's a chat message
        // we extract the text field containing the chat text
        const QJsonValue textVal = data.value(QLatin1String("text"));
        // we extract the sender field containing the username of the sender
        const QJsonValue senderVal = data.value(QLatin1String("sender"));
        if (textVal.isNull() || !textVal.isString())
            return; // the text field was invalid so we ignore
        if (senderVal.isNull() || !senderVal.isString())
            return; // the sender field was invalid so we ignore
        // we notify a new message was received via the messageReceived signal
        //emit messageReceived(senderVal.toString(), textVal.toString());
    }
}



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
