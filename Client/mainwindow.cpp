#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    loading(new LoadingWindow()),
    login(new LoginWindow()),
    client(new Client(this))
{
    //connections
    //login window
    //connect(login,&LoginWindow::attemptLogin, client,&Client::attemptLogin);
    //connect(login,&LoginWindow::attemptSignup, client,&Client::attemptSignup);

    //client from QTcpSocket
    connect(client,&Client::connected, this,&MainWindow::connected);
    connect(client,&Client::serverError, this,&MainWindow::serverError);

    //client

    //initialization
    ui->setupUi(this);
    this->hide();
    login->hide();
    loading->show();
    client->connectToServer();
}

MainWindow::~MainWindow()
{
    delete loading;
    delete login;
    delete ui;
}






void MainWindow::connected(){
    loading->hide();
    login->show();
}

void MainWindow::serverError(QAbstractSocket::SocketError socketError){
    switch (socketError) {
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The host refused the connection"));
        break;
    case QAbstractSocket::RemoteHostClosedError:
        QMessageBox::critical(this, tr("Error"), tr("The host closed the connection"));
        break;
    case QAbstractSocket::ProxyConnectionRefusedError:
        QMessageBox::critical(this, tr("Error"), tr("The proxy refused the connection"));
        break;
    case QAbstractSocket::ProxyNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the proxy"));
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::critical(this, tr("Error"), tr("Could not find the server"));
        break;
    case QAbstractSocket::SocketAccessError:
        QMessageBox::critical(this, tr("Error"), tr("You don't have permissions to execute this operation"));
        break;
    case QAbstractSocket::SocketResourceError:
        QMessageBox::critical(this, tr("Error"), tr("Too many connections opened"));
        break;
    case QAbstractSocket::ProxyConnectionTimeoutError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy timed out"));
        break;
    case QAbstractSocket::NetworkError:
        QMessageBox::critical(this, tr("Error"), tr("Unable to reach the network"));
        break;
    case QAbstractSocket::UnsupportedSocketOperationError:
        QMessageBox::critical(this, tr("Error"), tr("Operation not supported"));
        break;
    case QAbstractSocket::ProxyAuthenticationRequiredError:
        QMessageBox::critical(this, tr("Error"), tr("Your proxy requires authentication"));
        break;
    case QAbstractSocket::ProxyProtocolError:
        QMessageBox::critical(this, tr("Error"), tr("Proxy comunication failed"));
        break;
    case QAbstractSocket::SocketTimeoutError:
        QMessageBox::warning(this, tr("Error"), tr("Operation timed out"));
        return;
    case QAbstractSocket::TemporaryError:
        QMessageBox::warning(this, tr("Error"), tr("A temporary error occured"));
        return;
    case QAbstractSocket::OperationError:
        QMessageBox::warning(this, tr("Error"), tr("Operation failed, please try again"));
        return;
    default:
        QMessageBox::critical(this, tr("Error"), tr("An unknown error occured"));
    }
    loading->hide();
    login->hide();
    this->close();
}
