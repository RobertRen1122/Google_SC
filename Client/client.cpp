#include "client.h"
#include <QTcpSocket>
#include <QDataStream>
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

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

/*
 * void ChatClient::sendMessage(const QString &text)
{
    if (text.isEmpty())
        return; // We don't send empty messages
    // create a QDataStream operating on the socket
    QDataStream clientStream(m_clientSocket);
    // set the version so that programs compiled with different versions of Qt can agree on how to serialise
    clientStream.setVersion(QDataStream::Qt_5_7);
    // Create the JSON we want to send
    QJsonObject message;
    message[QStringLiteral("type")] = QStringLiteral("message");
    message[QStringLiteral("text")] = text;
    // send the JSON using QDataStream
    clientStream << QJsonDocument(message).toJson();
}*/

void Client::jsonReceived(const QJsonObject &data)
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







void Client::onReadyRead()
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


void Client::connectToServer()
{
    socket->connectToHost("127.0.0.1",8080);
}
