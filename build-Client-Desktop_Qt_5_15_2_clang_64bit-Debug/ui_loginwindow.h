/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QToolButton *toolButton_3;
    QLabel *WELCOME;
    QPushButton *minimize_butt;
    QLineEdit *username;
    QLabel *error;
    QPushButton *signup;
    QPushButton *close_butt;
    QLabel *_or_text;
    QRadioButton *Keep_me;
    QPushButton *login;
    QPushButton *google;
    QPushButton *back;
    QPushButton *forgot_password;
    QLineEdit *password;
    QPushButton *goto_signup;
    QToolButton *toolButton_4;
    QLabel *background;
    QToolButton *email_logo;
    QLineEdit *email;
    QLineEdit *pwd_confirmation;
    QToolButton *reconfirm_logo;
    QLabel *_or_text_signup;
    QPushButton *google_signup;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(509, 573);
        LoginWindow->setWindowOpacity(1.000000000000000);
        LoginWindow->setStyleSheet(QString::fromUtf8("Qlabel{\n"
"border-radius: 25px;\n"
"}"));
        toolButton_3 = new QToolButton(LoginWindow);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setGeometry(QRect(86, 183, 30, 30));
        toolButton_3->setAutoFillBackground(false);
        toolButton_3->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: None;\n"
"border: None;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/pic/profile.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon);
        toolButton_3->setIconSize(QSize(35, 35));
        WELCOME = new QLabel(LoginWindow);
        WELCOME->setObjectName(QString::fromUtf8("WELCOME"));
        WELCOME->setGeometry(QRect(102, 91, 241, 56));
        QFont font;
        font.setFamily(QString::fromUtf8("Poppins"));
        font.setPointSize(36);
        WELCOME->setFont(font);
        WELCOME->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: #F5F5F5;\n"
"}"));
        WELCOME->setTextFormat(Qt::PlainText);
        minimize_butt = new QPushButton(LoginWindow);
        minimize_butt->setObjectName(QString::fromUtf8("minimize_butt"));
        minimize_butt->setGeometry(QRect(352, 40, 24, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Poppins"));
        font1.setBold(true);
        font1.setWeight(75);
        minimize_butt->setFont(font1);
        minimize_butt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid #707070;\n"
"border-radius: 10px;\n"
"background:#FFFBDB;\n"
"color: #707070;\n"
"}\n"
"QPushButton:hover{\n"
"border: 1px solid #535249;\n"
"border-radius: 10px;\n"
"background:#535249;\n"
"color: #FFFBDB;\n"
"}"));
        username = new QLineEdit(LoginWindow);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(80, 172, 287, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Poppins"));
        font2.setPointSize(12);
        username->setFont(font2);
        username->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius:20px;\n"
"background-color:#DEE6FF;\n"
"border: 1px solid #707070;\n"
"padding-left:40px;\n"
"}\n"
"QLineEdit:focus{\n"
"color: #000000;\n"
"background-color:#FDFBFB;\n"
"padding-left:40px;\n"
"}\n"
"\n"
"\n"
""));
        username->setFrame(false);
        username->setClearButtonEnabled(true);
        error = new QLabel(LoginWindow);
        error->setObjectName(QString::fromUtf8("error"));
        error->setGeometry(QRect(130, 440, 181, 16));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Poppins"));
        error->setFont(font3);
        error->setFocusPolicy(Qt::StrongFocus);
        error->setStyleSheet(QString::fromUtf8("QLabel{\n"
"border: None;\n"
"color: #CD4F8A;\n"
"alignment: center;\n"
"}"));
        error->setFrameShape(QFrame::Box);
        signup = new QPushButton(LoginWindow);
        signup->setObjectName(QString::fromUtf8("signup"));
        signup->setGeometry(QRect(180, 460, 88, 37));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Poppins"));
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        signup->setFont(font4);
        signup->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius: 15px;\n"
"background-color: #7DA3FD;\n"
"border:2px solid #DBD9D9;\n"
"color: #DBD9D9\n"
"}\n"
"QPushButton:hover{\n"
"background-color: #566FA7;\n"
"border:2px solid #DBD9D9;\n"
"color: #FFFFFF\n"
"}"));
        close_butt = new QPushButton(LoginWindow);
        close_butt->setObjectName(QString::fromUtf8("close_butt"));
        close_butt->setGeometry(QRect(383, 40, 24, 24));
        close_butt->setFont(font1);
        close_butt->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border: 1px solid #707070;\n"
"border-radius: 10px;\n"
"background:#DD6243;\n"
"color: #707070;\n"
"}\n"
"QPushButton:hover{\n"
"border: 1px solid #E8907A;\n"
"border-radius: 10px;\n"
"background:#E8907A;\n"
"color: #FFFBDB;\n"
"}"));
        _or_text = new QLabel(LoginWindow);
        _or_text->setObjectName(QString::fromUtf8("_or_text"));
        _or_text->setGeometry(QRect(203, 370, 41, 20));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Poppins"));
        font5.setBold(false);
        font5.setWeight(50);
        _or_text->setFont(font5);
        _or_text->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: #F5F5F5;\n"
"}"));
        Keep_me = new QRadioButton(LoginWindow);
        Keep_me->setObjectName(QString::fromUtf8("Keep_me"));
        Keep_me->setGeometry(QRect(90, 330, 131, 20));
        Keep_me->setFont(font3);
        Keep_me->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"color: #F5F5F5;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked{\n"
"border: 1px solid #F5F5F5;\n"
"border-radius: 5px;\n"
"}\n"
"QRadioButton::indicator::checked{\n"
"background-color:#7DA3FD;\n"
"border: 4px solid #F5F5F5;\n"
"border-radius: 5px;\n"
"}"));
        login = new QPushButton(LoginWindow);
        login->setObjectName(QString::fromUtf8("login"));
        login->setGeometry(QRect(180, 460, 88, 37));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Poppins"));
        font6.setPointSize(16);
        font6.setBold(true);
        font6.setWeight(75);
        login->setFont(font6);
        login->setStyleSheet(QString::fromUtf8("QPushButton#login{\n"
"border-radius: 15px;\n"
"background-color: #7DA3FD;\n"
"border:2px solid #DBD9D9;\n"
"color: #DBD9D9\n"
"}\n"
"QPushButton#login:hover{\n"
"background-color: #566FA7;\n"
"border:2px solid #DBD9D9;\n"
"color: #FFFFFF\n"
"}"));
        google = new QPushButton(LoginWindow);
        google->setObjectName(QString::fromUtf8("google"));
        google->setGeometry(QRect(203, 390, 41, 41));
        google->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: None;\n"
"border: None;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: None;\n"
"border: 1px solid #F5F5F5;\n"
"border-radius: 17px;\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/pic/google.png"), QSize(), QIcon::Normal, QIcon::Off);
        google->setIcon(icon1);
        google->setIconSize(QSize(35, 35));
        google->setCheckable(false);
        back = new QPushButton(LoginWindow);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(40, 460, 31, 41));
        back->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background: none;\n"
"border:none;\n"
"icon: url(:/images/pic/left-arrow1.png);\n"
"}\n"
"QPushButton:hover{\n"
"background: none;\n"
"border:none;\n"
"icon: url(:/images/pic/left-arrow.png);\n"
"}"));
        back->setIconSize(QSize(32, 32));
        forgot_password = new QPushButton(LoginWindow);
        forgot_password->setObjectName(QString::fromUtf8("forgot_password"));
        forgot_password->setGeometry(QRect(250, 327, 111, 25));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Poppins"));
        font7.setUnderline(true);
        forgot_password->setFont(font7);
        forgot_password->setCursor(QCursor(Qt::PointingHandCursor));
        forgot_password->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: #C7D2EE;\n"
"border: None;\n"
"background-color: None;\n"
"}\n"
"QPushButton:hover{\n"
"color: #F5F5F5;\n"
"border: None;\n"
"background-color: None;\n"
"}"));
        password = new QLineEdit(LoginWindow);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(80, 248, 287, 49));
        password->setFont(font2);
        password->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius:20px;\n"
"background-color:#DEE6FF;\n"
"border: 1px solid #707070;\n"
"padding-left:40px;\n"
"}\n"
"QLineEdit:focus{\n"
"color: #000000;\n"
"background-color:#FDFBFB;\n"
"padding-left:40px;\n"
"}\n"
"\n"
"\n"
""));
        password->setClearButtonEnabled(true);
        goto_signup = new QPushButton(LoginWindow);
        goto_signup->setObjectName(QString::fromUtf8("goto_signup"));
        goto_signup->setGeometry(QRect(120, 510, 208, 27));
        goto_signup->setFont(font7);
        goto_signup->setCursor(QCursor(Qt::PointingHandCursor));
        goto_signup->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color: #C7D2EE;\n"
"border: None;\n"
"background-color: None;\n"
"}\n"
"QPushButton:hover{\n"
"color: #F5F5F5;\n"
"border: None;\n"
"background-color: None;\n"
"}"));
        toolButton_4 = new QToolButton(LoginWindow);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setGeometry(QRect(88, 257, 30, 30));
        toolButton_4->setAutoFillBackground(false);
        toolButton_4->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: None;\n"
"border: None;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/pic/padlock.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon2);
        toolButton_4->setIconSize(QSize(30, 30));
        background = new QLabel(LoginWindow);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(21, 22, 408, 527));
        background->setStyleSheet(QString::fromUtf8("QLabel#background{\n"
"border-radius: 10px;\n"
"background: #7DA3FD;\n"
"border: 3px solid;\n"
"border-color: #DBD9D9;\n"
"\n"
"}"));
        email_logo = new QToolButton(LoginWindow);
        email_logo->setObjectName(QString::fromUtf8("email_logo"));
        email_logo->setGeometry(QRect(86, 106, 30, 30));
        email_logo->setAutoFillBackground(false);
        email_logo->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: None;\n"
"border: None;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/pic/fingerprint.png"), QSize(), QIcon::Normal, QIcon::Off);
        email_logo->setIcon(icon3);
        email_logo->setIconSize(QSize(35, 35));
        email = new QLineEdit(LoginWindow);
        email->setObjectName(QString::fromUtf8("email"));
        email->setGeometry(QRect(80, 96, 287, 51));
        email->setFont(font2);
        email->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius:20px;\n"
"background-color:#DEE6FF;\n"
"border: 1px solid #707070;\n"
"padding-left:40px;\n"
"}\n"
"QLineEdit:focus{\n"
"color: #000000;\n"
"background-color:#FDFBFB;\n"
"padding-left:40px;\n"
"}\n"
"\n"
"\n"
""));
        email->setFrame(false);
        email->setClearButtonEnabled(true);
        pwd_confirmation = new QLineEdit(LoginWindow);
        pwd_confirmation->setObjectName(QString::fromUtf8("pwd_confirmation"));
        pwd_confirmation->setGeometry(QRect(80, 321, 287, 49));
        pwd_confirmation->setFont(font2);
        pwd_confirmation->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border-radius:20px;\n"
"background-color:#DEE6FF;\n"
"border: 1px solid #707070;\n"
"padding-left:40px;\n"
"}\n"
"QLineEdit:focus{\n"
"color: #000000;\n"
"background-color:#FDFBFB;\n"
"padding-left:40px;\n"
"}\n"
"\n"
"\n"
""));
        pwd_confirmation->setClearButtonEnabled(true);
        reconfirm_logo = new QToolButton(LoginWindow);
        reconfirm_logo->setObjectName(QString::fromUtf8("reconfirm_logo"));
        reconfirm_logo->setGeometry(QRect(88, 330, 30, 30));
        reconfirm_logo->setAutoFillBackground(false);
        reconfirm_logo->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"background-color: None;\n"
"border: None;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/pic/thumb-up.png"), QSize(), QIcon::Normal, QIcon::Off);
        reconfirm_logo->setIcon(icon4);
        reconfirm_logo->setIconSize(QSize(30, 30));
        _or_text_signup = new QLabel(LoginWindow);
        _or_text_signup->setObjectName(QString::fromUtf8("_or_text_signup"));
        _or_text_signup->setGeometry(QRect(200, 380, 41, 20));
        _or_text_signup->setFont(font5);
        _or_text_signup->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: #F5F5F5;\n"
"}"));
        google_signup = new QPushButton(LoginWindow);
        google_signup->setObjectName(QString::fromUtf8("google_signup"));
        google_signup->setGeometry(QRect(200, 400, 41, 41));
        google_signup->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: None;\n"
"border: None;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: None;\n"
"border: 1px solid #F5F5F5;\n"
"border-radius: 17px;\n"
"}\n"
""));
        google_signup->setIcon(icon1);
        google_signup->setIconSize(QSize(35, 35));
        google_signup->setCheckable(false);
        background->raise();
        WELCOME->raise();
        minimize_butt->raise();
        username->raise();
        error->raise();
        signup->raise();
        close_butt->raise();
        _or_text->raise();
        Keep_me->raise();
        login->raise();
        google->raise();
        back->raise();
        forgot_password->raise();
        password->raise();
        goto_signup->raise();
        toolButton_4->raise();
        toolButton_3->raise();
        email->raise();
        email_logo->raise();
        pwd_confirmation->raise();
        reconfirm_logo->raise();
        _or_text_signup->raise();
        google_signup->raise();

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Form", nullptr));
        toolButton_3->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        WELCOME->setText(QCoreApplication::translate("LoginWindow", "WELCOME", nullptr));
        minimize_butt->setText(QCoreApplication::translate("LoginWindow", "-", nullptr));
        username->setInputMask(QString());
        username->setText(QString());
        username->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter Username", nullptr));
        error->setText(QString());
        signup->setText(QCoreApplication::translate("LoginWindow", "SIGN UP", nullptr));
        close_butt->setText(QCoreApplication::translate("LoginWindow", "x", nullptr));
        _or_text->setText(QCoreApplication::translate("LoginWindow", "\342\200\224  or  \342\200\224", nullptr));
        Keep_me->setText(QCoreApplication::translate("LoginWindow", "Keep me signed in.", nullptr));
        login->setText(QCoreApplication::translate("LoginWindow", "LOG IN", nullptr));
        google->setText(QString());
        back->setText(QString());
        forgot_password->setText(QCoreApplication::translate("LoginWindow", "Forgot password?", nullptr));
        password->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter Password", nullptr));
        goto_signup->setText(QCoreApplication::translate("LoginWindow", "New user? Click here to sign up. ", nullptr));
        toolButton_4->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        background->setText(QString());
        email_logo->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        email->setInputMask(QString());
        email->setText(QString());
        email->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Enter Email", nullptr));
        pwd_confirmation->setPlaceholderText(QCoreApplication::translate("LoginWindow", "Confirm Password", nullptr));
        reconfirm_logo->setText(QCoreApplication::translate("LoginWindow", "...", nullptr));
        _or_text_signup->setText(QCoreApplication::translate("LoginWindow", "\342\200\224  or  \342\200\224", nullptr));
        google_signup->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
