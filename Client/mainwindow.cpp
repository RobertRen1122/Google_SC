
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QCloseEvent>
#include <QStyledItemDelegate>
#include <QGraphicsDropShadowEffect>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    loading(new LoadingWindow()),
    login(new LoginWindow()),
    client(new Client(this))
{
    //connect to server
    connect(client,&Client::connected, this,&MainWindow::connected);
    connect(client,&Client::serverError, this,&MainWindow::serverError);
    //login
    connect(login,&LoginWindow::attemptLogin, client,&Client::attemptLogin);
    connect(login,&LoginWindow::attemptSignup, client,&Client::attemptSignup);
    connect(client,&Client::loggedIn, this,&MainWindow::loggedIn);
    connect(client,&Client::loggedIn, login,&LoginWindow::loggedIn);
    connect(client,&Client::loginError, this,&MainWindow::loginError);
    //profile
    connect(client,&Client::informationRecieved, this,&MainWindow::startApplication);
    connect(client,&Client::profileChanged, this,&MainWindow::profileChanged);
    connect(client,&Client::profileError, this,&MainWindow::profileError);

    //initialization
    ui->setupUi(this);
    this->hide();
    login->hide();
    loading->show();
    //title bar buttons
    connect(ui->close_butt, SIGNAL(clicked()), SLOT(close()));
    connect(ui->minimize_butt, SIGNAL(clicked()), SLOT(showMinimized()));

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);

    /* stack widget
    QHBoxLayout *layout = new QHBoxLayout(this);
    QStackedWidget *stack = new QStackedWidget(this);
    connect(sidebar, &Sidebar::show_profile,
            stack, std::bind(&QStackedWidget::setCurrentIndex, stack, 0));
    connect(sidebar, &Sidebar::show_chat,
            stack, std::bind(&QStackedWidget::setCurrentIndex, stack, 1));
    stack->addWidget(profile);
    stack->addWidget(chat);
    layout->addWidget(sidebar);
    layout->addWidget(stack);
    this->setLayout(layout);
    */

    QGraphicsDropShadowEffect* shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setColor(QColor(0,0,0,120));
    shadowEffect->setBlurRadius(25);
    shadowEffect->setOffset(3, 3);
    (ui->user_pic)->setGraphicsEffect(shadowEffect);

    QGraphicsDropShadowEffect* shadowEffect1 = new QGraphicsDropShadowEffect(this);
    shadowEffect1->setColor(QColor(0,0,0,120));
    shadowEffect1->setBlurRadius(25);
    shadowEffect1->setOffset(0, 3);
    (ui->new_conversation)->setGraphicsEffect(shadowEffect1);

    QGraphicsDropShadowEffect* shadowEffect2 = new QGraphicsDropShadowEffect(this);
    shadowEffect2->setColor(QColor(0,0,0,120));
    shadowEffect2->setBlurRadius(25);
    shadowEffect2->setOffset(0, 3);
    (ui->dictionary_2)->setGraphicsEffect(shadowEffect2);

    QGraphicsDropShadowEffect* shadowEffect3 = new QGraphicsDropShadowEffect(this);
    shadowEffect3->setColor(QColor(0,0,0,120));
    shadowEffect3->setBlurRadius(25);
    shadowEffect3->setOffset(0, 3);
    (ui->widget)->setGraphicsEffect(shadowEffect3);

    QGraphicsDropShadowEffect* shadowEffect4 = new QGraphicsDropShadowEffect(this);
    shadowEffect4->setColor(QColor(0,0,0,120));
    shadowEffect4->setBlurRadius(25);
    shadowEffect4->setOffset(0, 3);
    (ui->stackedWidget)->setGraphicsEffect(shadowEffect4);

    QPalette palette3 = (ui->username_enter)->palette();
    palette3.setColor(QPalette::PlaceholderText, QColor(255,255,255,255));
    (ui->username_enter)->setPalette(palette3);

    QPalette palette4 = (ui->textEdit)->palette();
    palette4.setColor(QPalette::PlaceholderText, QColor(255,255,255,255));
    (ui->textEdit)->setPalette(palette4);

    QPalette palette5 = (ui->enter_email)->palette();
    palette5.setColor(QPalette::PlaceholderText, QColor(255,255,255,255));
    (ui->enter_email)->setPalette(palette5);

    ui->pro_comboBox->view()->window()->setWindowFlags(Qt::Popup|Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint);
    ui->pro_comboBox->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    ui->language_1st_com->view()->window()->setWindowFlags(Qt::Popup|Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint);
    ui->language_1st_com->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    ui->language_2nd_com->view()->window()->setWindowFlags(Qt::Popup|Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint);
    ui->language_2nd_com->view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    ui->language_3rd_com->view()->window()->setWindowFlags(Qt::Popup|Qt::FramelessWindowHint|Qt::NoDropShadowWindowHint);
    ui->language_3rd_com->view()->window()->setAttribute(Qt::WA_TranslucentBackground);

    client->connectToServer();
    for(int i = 0; i < ui->user_list->count(); ++i)
    {
        QListWidgetItem* item = ui->user_list->item(i);
        item->setTextAlignment(Qt::AlignCenter);
    }
}
MainWindow::~MainWindow()
{
    delete loading;
    delete login;
    delete ui;
}

void MainWindow::startApplication(){
    loading->hide();
    this->show();
    //put all info on screen

}

void MainWindow::profileError(const QString &reason){
    ui->profileError->setText(reason);
}

void MainWindow::profileChanged(){
    ui->profileError->setText("Profile changed!");
}

void MainWindow::on_changeProfile_clicked(){
    if(ui->username_enter->text()==""){
        ui->profileError->setText("username is not empty");
    }else if(!login->validate_email(ui->enter_email->text())){
        ui->profileError->setText("Email is not valid");
    }else{
        client->profile["username"]=ui->username_enter->text();
        client->profile["email"]=ui->enter_email->text();
        client->profile["intro"]=ui->textEdit->toPlainText();
        client->profile["pronoun"]=ui->pro_comboBox->currentText();
        client->profile["language1"]=ui->language_1st_com->currentText();
        client->profile["language2"]=ui->language_2nd_com->currentText();
        client->profile["language3"]=ui->language_3rd_com->currentText();
        client->updateProfile();
    }
}

void MainWindow::loginError(const QString &reason){
    login->displayError(reason);
}

void MainWindow::loggedIn(){
    login->hide();
    loading->show();
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

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton){
        m_startPoint = frameGeometry().topLeft() - event->globalPos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() + m_startPoint);
}

void MainWindow::on_settingbutton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->Profile);

    ui->profileError->setText("");
    ui->username_enter->setText(client->profile["username"]);
    ui->enter_email->setText(client->profile["email"]);
    ui->textEdit->setText(client->profile["intro"]);
    ui->pro_comboBox->setCurrentIndex(ui->pro_comboBox->findText(client->profile["pronoun"]));
    ui->language_1st_com->setCurrentIndex(ui->language_1st_com->findText(client->profile["language1"]));
    ui->language_2nd_com->setCurrentIndex(ui->language_2nd_com->findText(client->profile["language2"]));
    ui->language_3rd_com->setCurrentIndex(ui->language_3rd_com->findText(client->profile["language3"]));
}

void MainWindow::on_dictionary_2_clicked()
{
   ui->stackedWidget->setCurrentWidget(ui->dictionary);
}
