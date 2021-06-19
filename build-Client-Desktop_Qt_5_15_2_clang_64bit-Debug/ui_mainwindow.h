/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *background;
    QVBoxLayout *verticalLayout;
    QWidget *title;
    QPushButton *close_butt;
    QPushButton *minimize_butt;
    QWidget *body;
    QHBoxLayout *horizontalLayout;
    QWidget *left_panel;
    QVBoxLayout *verticalLayout_4;
    QWidget *buttons;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QLabel *user_pic;
    QLabel *username;
    QPushButton *settingbutton;
    QPushButton *new_conversation;
    QPushButton *dictionary_2;
    QLabel *contact_label;
    QListWidget *user_list;
    QStackedWidget *stackedWidget;
    QWidget *Profile;
    QVBoxLayout *verticalLayout_8;
    QWidget *profile_container;
    QVBoxLayout *verticalLayout_5;
    QWidget *profile_entrance;
    QVBoxLayout *verticalLayout_7;
    QWidget *title_container;
    QVBoxLayout *verticalLayout_6;
    QLabel *title_profile;
    QFrame *line;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_4;
    QLabel *displayprofile;
    QPushButton *changeprofilepic;
    QPushButton *signout;
    QPushButton *changeProfile;
    QLabel *profileError;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_11;
    QWidget *username_wid;
    QVBoxLayout *verticalLayout_10;
    QLabel *username_ti;
    QLineEdit *username_enter;
    QWidget *intro;
    QVBoxLayout *verticalLayout_17;
    QLabel *intro_ti;
    QTextEdit *textEdit;
    QWidget *preferred_pro_wid;
    QVBoxLayout *verticalLayout_13;
    QLabel *perferred_pro;
    QComboBox *pro_comboBox;
    QWidget *language_1st;
    QVBoxLayout *verticalLayout_14;
    QLabel *language_1st_til;
    QComboBox *language_1st_com;
    QWidget *language_2nd;
    QVBoxLayout *verticalLayout_15;
    QLabel *language_2nd_til;
    QComboBox *language_2nd_com;
    QWidget *language_3rd;
    QVBoxLayout *verticalLayout_16;
    QLabel *language_3rd_til;
    QComboBox *language_3rd_com;
    QLabel *title_security;
    QWidget *Security_block;
    QVBoxLayout *verticalLayout_18;
    QLabel *enter_email_title;
    QLineEdit *enter_email;
    QWidget *dictionary;
    QLabel *label;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1250, 950);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(MainWindow);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        background = new QWidget(MainWindow);
        background->setObjectName(QString::fromUtf8("background"));
        background->setStyleSheet(QString::fromUtf8("QWidget#background{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(175, 197, 247, 230), stop:1 rgba(223, 233, 255, 230));\n"
"border-radius: 20px;\n"
"}"));
        verticalLayout = new QVBoxLayout(background);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        title = new QWidget(background);
        title->setObjectName(QString::fromUtf8("title"));
        close_butt = new QPushButton(title);
        close_butt->setObjectName(QString::fromUtf8("close_butt"));
        close_butt->setGeometry(QRect(1181, 10, 24, 24));
        QFont font;
        font.setFamily(QString::fromUtf8("Poppins"));
        font.setBold(true);
        font.setWeight(75);
        close_butt->setFont(font);
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
        minimize_butt = new QPushButton(title);
        minimize_butt->setObjectName(QString::fromUtf8("minimize_butt"));
        minimize_butt->setGeometry(QRect(1150, 10, 24, 24));
        minimize_butt->setFont(font);
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

        verticalLayout->addWidget(title);

        body = new QWidget(background);
        body->setObjectName(QString::fromUtf8("body"));
        body->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(body);
        horizontalLayout->setSpacing(25);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 9, -1, -1);
        left_panel = new QWidget(body);
        left_panel->setObjectName(QString::fromUtf8("left_panel"));
        left_panel->setStyleSheet(QString::fromUtf8("QWidget#left_panel{\n"
"border-radius: 30px;\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(100, 127, 194, 255), stop:1 rgba(123, 149, 216, 87));\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(left_panel);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        buttons = new QWidget(left_panel);
        buttons->setObjectName(QString::fromUtf8("buttons"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttons->sizePolicy().hasHeightForWidth());
        buttons->setSizePolicy(sizePolicy1);
        buttons->setCursor(QCursor(Qt::PointingHandCursor));
        buttons->setFocusPolicy(Qt::ClickFocus);
        verticalLayout_2 = new QVBoxLayout(buttons);
        verticalLayout_2->setSpacing(14);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 9);
        widget = new QWidget(buttons);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 120));
        user_pic = new QLabel(widget);
        user_pic->setObjectName(QString::fromUtf8("user_pic"));
        user_pic->setGeometry(QRect(10, 10, 100, 100));
        user_pic->setStyleSheet(QString::fromUtf8("border-radius: 50px;"));
        user_pic->setPixmap(QPixmap(QString::fromUtf8(":/images/pic/profile.png")));
        user_pic->setScaledContents(true);
        username = new QLabel(widget);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(140, 30, 61, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Poppins"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        username->setFont(font1);
        username->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: white;\n"
"}"));
        settingbutton = new QPushButton(widget);
        settingbutton->setObjectName(QString::fromUtf8("settingbutton"));
        settingbutton->setGeometry(QRect(200, 90, 25, 25));
        settingbutton->setStyleSheet(QString::fromUtf8("QPushButton#settingbutton{\n"
"	background-color: none;\n"
"	border-radius:7px;\n"
"}\n"
"\n"
"QPushButton#settingbutton:hover{\n"
"	background-color: none;\n"
"	border: 1.5px solid #E1EAFE;\n"
"	border-radius:7px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/pic/settings (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        settingbutton->setIcon(icon);

        verticalLayout_2->addWidget(widget);

        new_conversation = new QPushButton(buttons);
        new_conversation->setObjectName(QString::fromUtf8("new_conversation"));
        sizePolicy.setHeightForWidth(new_conversation->sizePolicy().hasHeightForWidth());
        new_conversation->setSizePolicy(sizePolicy);
        new_conversation->setMinimumSize(QSize(0, 50));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Poppins"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        new_conversation->setFont(font2);
        new_conversation->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #E1EAFE;\n"
"border-radius: 25px;\n"
"color: #647FC2;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: rgb(81, 111, 194);\n"
"border-radius: 25px;\n"
"color: #E1EAFE;\n"
"}"));

        verticalLayout_2->addWidget(new_conversation);

        dictionary_2 = new QPushButton(buttons);
        dictionary_2->setObjectName(QString::fromUtf8("dictionary_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dictionary_2->sizePolicy().hasHeightForWidth());
        dictionary_2->setSizePolicy(sizePolicy2);
        dictionary_2->setMinimumSize(QSize(0, 50));
        dictionary_2->setFont(font2);
        dictionary_2->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #E1EAFE;\n"
"border-radius: 25px;\n"
"color: #647FC2;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: rgb(81, 111, 194);\n"
"border-radius: 25px;\n"
"color: #E1EAFE;\n"
"}"));

        verticalLayout_2->addWidget(dictionary_2);

        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        verticalLayout_4->addWidget(buttons);

        contact_label = new QLabel(left_panel);
        contact_label->setObjectName(QString::fromUtf8("contact_label"));
        contact_label->setFont(font1);
        contact_label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:rgba(225, 234, 254, 255);\n"
"}"));
        contact_label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(contact_label);

        user_list = new QListWidget(left_panel);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        new QListWidgetItem(user_list);
        user_list->setObjectName(QString::fromUtf8("user_list"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(user_list->sizePolicy().hasHeightForWidth());
        user_list->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Poppins"));
        font3.setPointSize(12);
        user_list->setFont(font3);
        user_list->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        user_list->setFocusPolicy(Qt::ClickFocus);
        user_list->setStyleSheet(QString::fromUtf8("QListView{\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(225, 234, 254, 255), stop:1 rgba(222, 232, 252, 33));\n"
"\n"
"	border-radius: 25px;\n"
"}\n"
"\n"
"QListView::item{\n"
"color: rgba(100, 127, 194, 255);\n"
"height: 35px;\n"
"	border-bottom: 1px solid rgba(100, 127, 194, 120);\n"
"border-top: 1px solid rgba(100, 127, 194, 0);\n"
"border-left: 1px solid rgba(100, 127, 194, 0);\n"
"border-right: 1px solid rgba(100, 127, 194, 0);\n"
"\n"
"	border-radius: 25px;\n"
"}\n"
"\n"
"QListView::item:focus{\n"
"color: white;\n"
"height: 35px;\n"
"	border-bottom: 1px solid rgba(100, 127, 194, 120);\n"
"border-left: 1px solid rgba(100, 127, 194, 0);\n"
"border-right: 1px solid rgba(100, 127, 194, 0);\n"
"\n"
"	border-radius: 25px;\n"
"}\n"
"\n"
"\n"
"\n"
"QScrollArea{\n"
"border: none;\n"
"background-color: none;\n"
"}\n"
"\n"
"    QScrollBar {\n"
"        background-color: #7B95D8;\n"
"        border-radius: 5px;\n"
"    }\n"
"\n"
"    QScrollBar:horizontal {\n"
"        heigh"
                        "t: 13px;\n"
"    }\n"
"\n"
"    QScrollBar:vertical {\n"
"        width: 13px;\n"
"    }\n"
"\n"
"    QScrollBar::handle {\n"
"        background: #E1EAFE;\n"
"        border-radius: 5px;\n"
"    }\n"
"\n"
"    QScrollBar::handle:horizontal {\n"
"        height: 25px;\n"
"        min-width: 10px;\n"
"    }\n"
"\n"
"    QScrollBar::handle:vertical {\n"
"        width: 25px;\n"
"        min-height: 10px;\n"
"    }\n"
"\n"
"    QScrollBar::add-line {\n"
"        border: none;\n"
"        background: none;\n"
"    }\n"
"\n"
"    QScrollBar::sub-line {\n"
"        border: none;\n"
"        background: none;\n"
"    }\n"
""));
        user_list->setFrameShadow(QFrame::Plain);
        user_list->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        user_list->setAutoScroll(false);
        user_list->setTabKeyNavigation(true);
        user_list->setProperty("showDropIndicator", QVariant(false));
        user_list->setAlternatingRowColors(false);
        user_list->setMovement(QListView::Snap);
        user_list->setFlow(QListView::TopToBottom);
        user_list->setProperty("isWrapping", QVariant(false));
        user_list->setResizeMode(QListView::Adjust);
        user_list->setLayoutMode(QListView::SinglePass);
        user_list->setSpacing(0);
        user_list->setUniformItemSizes(false);
        user_list->setSelectionRectVisible(false);
        user_list->setItemAlignment(Qt::AlignAbsolute|Qt::AlignCenter|Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_4->addWidget(user_list);

        verticalLayout_4->setStretch(0, 2);
        verticalLayout_4->setStretch(2, 7);

        horizontalLayout->addWidget(left_panel);

        stackedWidget = new QStackedWidget(body);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        Profile = new QWidget();
        Profile->setObjectName(QString::fromUtf8("Profile"));
        Profile->setStyleSheet(QString::fromUtf8("QWidget#Profile{\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(212, 227, 255, 255), stop:1 rgba(212, 227, 255, 253));\n"
"	border-radius: 30px;\n"
"	\n"
"}"));
        verticalLayout_8 = new QVBoxLayout(Profile);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        profile_container = new QWidget(Profile);
        profile_container->setObjectName(QString::fromUtf8("profile_container"));
        verticalLayout_5 = new QVBoxLayout(profile_container);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        profile_entrance = new QWidget(profile_container);
        profile_entrance->setObjectName(QString::fromUtf8("profile_entrance"));
        verticalLayout_7 = new QVBoxLayout(profile_entrance);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        title_container = new QWidget(profile_entrance);
        title_container->setObjectName(QString::fromUtf8("title_container"));
        verticalLayout_6 = new QVBoxLayout(title_container);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        title_profile = new QLabel(title_container);
        title_profile->setObjectName(QString::fromUtf8("title_profile"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(title_profile->sizePolicy().hasHeightForWidth());
        title_profile->setSizePolicy(sizePolicy4);
        QFont font4;
        font4.setFamily(QString::fromUtf8("Poppins"));
        font4.setPointSize(20);
        font4.setBold(true);
        font4.setWeight(75);
        title_profile->setFont(font4);
        title_profile->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: rgb(255, 255, 255);\n"
"}"));
        title_profile->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(title_profile);

        line = new QFrame(title_container);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("color:white;"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line);


        verticalLayout_7->addWidget(title_container);

        widget_3 = new QWidget(profile_entrance);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: none;"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_5 = new QWidget(widget_3);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: none;"));
        verticalLayout_9 = new QVBoxLayout(widget_5);
        verticalLayout_9->setSpacing(9);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(-1, -1, -1, 318);
        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("color: #FFFFFF;"));
        displayprofile = new QLabel(widget_4);
        displayprofile->setObjectName(QString::fromUtf8("displayprofile"));
        displayprofile->setGeometry(QRect(40, 20, 150, 150));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(displayprofile->sizePolicy().hasHeightForWidth());
        displayprofile->setSizePolicy(sizePolicy5);
        displayprofile->setStyleSheet(QString::fromUtf8(""));
        displayprofile->setPixmap(QPixmap(QString::fromUtf8(":/images/pic/profile.png")));
        displayprofile->setScaledContents(true);
        changeprofilepic = new QPushButton(widget_4);
        changeprofilepic->setObjectName(QString::fromUtf8("changeprofilepic"));
        changeprofilepic->setGeometry(QRect(150, 20, 36, 36));
        changeprofilepic->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: white;\n"
"border-radius: 18px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"background-color: white;\n"
"border-radius: 18px;\n"
"border: 1px solid black;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/pic/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        changeprofilepic->setIcon(icon1);
        signout = new QPushButton(widget_4);
        signout->setObjectName(QString::fromUtf8("signout"));
        signout->setGeometry(QRect(40, 190, 150, 54));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(signout->sizePolicy().hasHeightForWidth());
        signout->setSizePolicy(sizePolicy6);
        signout->setMinimumSize(QSize(100, 15));
        signout->setMaximumSize(QSize(150, 16777215));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Poppins"));
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setWeight(75);
        signout->setFont(font5);
        signout->setStyleSheet(QString::fromUtf8("QPushButton#signout{\n"
"	background-color: rgba(235, 49, 49,150);\n"
"	border-radius: 15px;\n"
"}\n"
"\n"
"QPushButton#signout:hover{\n"
"	background-color: rgba(235, 49, 49,1);\n"
"}"));
        changeProfile = new QPushButton(widget_4);
        changeProfile->setObjectName(QString::fromUtf8("changeProfile"));
        changeProfile->setGeometry(QRect(0, 310, 216, 21));
        profileError = new QLabel(widget_4);
        profileError->setObjectName(QString::fromUtf8("profileError"));
        profileError->setGeometry(QRect(90, 280, 47, 13));

        verticalLayout_9->addWidget(widget_4);

        verticalLayout_9->setStretch(0, 6);

        horizontalLayout_2->addWidget(widget_5);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy7);
        widget_2->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: none;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(60, -1, 30, -1);
        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("QAbstractScrollArea #scrollAreaWidgetContents{\n"
"     border: none;\n"
"\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(212, 227, 255, 255), stop:1 rgba(212, 227, 255, 253));\n"
"    }\n"
"QScrollArea{\n"
"border: none;\n"
"background-color: none;\n"
"}\n"
"\n"
"    QScrollBar {\n"
"        background-color: #7B95D8;\n"
"        border-radius: 5px;\n"
"    }\n"
"\n"
"    QScrollBar:horizontal {\n"
"        height: 13px;\n"
"    }\n"
"\n"
"    QScrollBar:vertical {\n"
"        width: 13px;\n"
"    }\n"
"\n"
"    QScrollBar::handle {\n"
"        background: #E1EAFE;\n"
"        border-radius: 5px;\n"
"    }\n"
"\n"
"    QScrollBar::handle:horizontal {\n"
"        height: 25px;\n"
"        min-width: 10px;\n"
"    }\n"
"\n"
"    QScrollBar::handle:vertical {\n"
"        width: 25px;\n"
"        min-height: 10px;\n"
"    }\n"
"\n"
"    QScrollBar::add-line {\n"
"        border: none;\n"
"        background: none;\n"
"    }\n"
"\n"
"    QScrollBar::sub-line {\n"
"        bo"
                        "rder: none;\n"
"        background: none;\n"
"    }\n"
""));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 482, 794));
        verticalLayout_11 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_11->setSpacing(23);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, -1, 39, -1);
        username_wid = new QWidget(scrollAreaWidgetContents);
        username_wid->setObjectName(QString::fromUtf8("username_wid"));
        QSizePolicy sizePolicy8(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(username_wid->sizePolicy().hasHeightForWidth());
        username_wid->setSizePolicy(sizePolicy8);
        username_wid->setMinimumSize(QSize(300, 0));
        username_wid->setStyleSheet(QString::fromUtf8("QWidget#username_wid\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(100, 127, 194, 255), stop:1 rgba(123, 149, 216, 87));\n"
"border-radius: 20px\n"
"}"));
        verticalLayout_10 = new QVBoxLayout(username_wid);
        verticalLayout_10->setSpacing(3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(25, -1, 25, 12);
        username_ti = new QLabel(username_wid);
        username_ti->setObjectName(QString::fromUtf8("username_ti"));
        username_ti->setStyleSheet(QString::fromUtf8("QLabel#username_ti{\n"
"background-color: none;\n"
"	font: 8pt \"Poppins\";\n"
"color: white;\n"
"}"));

        verticalLayout_10->addWidget(username_ti);

        username_enter = new QLineEdit(username_wid);
        username_enter->setObjectName(QString::fromUtf8("username_enter"));
        username_enter->setStyleSheet(QString::fromUtf8("QLineEdit#username_enter{\n"
"background-color:rgba(255, 255, 255, 0);\n"
"border:none;\n"
"border-bottom:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"	font: 12pt \"Poppins\";\n"
"}"));

        verticalLayout_10->addWidget(username_enter);


        verticalLayout_11->addWidget(username_wid);

        intro = new QWidget(scrollAreaWidgetContents);
        intro->setObjectName(QString::fromUtf8("intro"));
        sizePolicy8.setHeightForWidth(intro->sizePolicy().hasHeightForWidth());
        intro->setSizePolicy(sizePolicy8);
        intro->setMinimumSize(QSize(300, 0));
        intro->setStyleSheet(QString::fromUtf8("QWidget#intro\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(100, 127, 194, 255), stop:1 rgba(123, 149, 216, 87));\n"
"border-radius: 20px\n"
"}"));
        verticalLayout_17 = new QVBoxLayout(intro);
        verticalLayout_17->setSpacing(3);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(25, -1, 25, 12);
        intro_ti = new QLabel(intro);
        intro_ti->setObjectName(QString::fromUtf8("intro_ti"));
        intro_ti->setStyleSheet(QString::fromUtf8("QLabel#intro_ti{\n"
"background-color: none;\n"
"	font: 8pt \"Poppins\";\n"
"color: white;\n"
"}"));

        verticalLayout_17->addWidget(intro_ti);

        textEdit = new QTextEdit(intro);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"background-color:rgba(255, 255, 255, 0);\n"
"border:none;\n"
"border-bottom:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"	font: 12pt \"Poppins\";\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"QScrollArea {\n"
"        border: none;\n"
"    }\n"
"\n"
"    QScrollBar {\n"
"        background: #7B95D8;\n"
"        border-radius: 5px;\n"
"    }\n"
"\n"
"    QScrollBar:horizontal {\n"
"        height: 13px;\n"
"    }\n"
"\n"
"    QScrollBar:vertical {\n"
"        width: 13px;\n"
"    }\n"
"\n"
"    QScrollBar::handle {\n"
"        background: #E1EAFE;\n"
"        border-radius: 5px;\n"
"    }\n"
"\n"
"    QScrollBar::handle:horizontal {\n"
"        height: 25px;\n"
"        min-width: 10px;\n"
"    }\n"
"\n"
"    QScrollBar::handle:vertical {\n"
"        width: 25px;\n"
"        min-height: 10px;\n"
"    }\n"
"\n"
"    QScrollBar::add-line {\n"
"        border: none;\n"
"        background: none;\n"
"    }\n"
"\n"
"    QScrollBar::sub-line {\n"
"        border: none;\n"
"        background: none;\n"
""
                        "    }"));

        verticalLayout_17->addWidget(textEdit);


        verticalLayout_11->addWidget(intro);

        preferred_pro_wid = new QWidget(scrollAreaWidgetContents);
        preferred_pro_wid->setObjectName(QString::fromUtf8("preferred_pro_wid"));
        sizePolicy8.setHeightForWidth(preferred_pro_wid->sizePolicy().hasHeightForWidth());
        preferred_pro_wid->setSizePolicy(sizePolicy8);
        preferred_pro_wid->setMinimumSize(QSize(300, 0));
        preferred_pro_wid->setStyleSheet(QString::fromUtf8("QWidget#preferred_pro_wid\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(100, 127, 194, 255), stop:1 rgba(123, 149, 216, 87));\n"
"border-radius: 20px\n"
"}"));
        verticalLayout_13 = new QVBoxLayout(preferred_pro_wid);
        verticalLayout_13->setSpacing(3);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(25, -1, 25, 12);
        perferred_pro = new QLabel(preferred_pro_wid);
        perferred_pro->setObjectName(QString::fromUtf8("perferred_pro"));
        perferred_pro->setStyleSheet(QString::fromUtf8("QLabel#perferred_pro\n"
"{\n"
"background-color: none;\n"
"	font: 8pt \"Poppins\";\n"
"color: white;\n"
"}"));

        verticalLayout_13->addWidget(perferred_pro);

        pro_comboBox = new QComboBox(preferred_pro_wid);
        pro_comboBox->addItem(QString());
        pro_comboBox->addItem(QString());
        pro_comboBox->addItem(QString());
        pro_comboBox->setObjectName(QString::fromUtf8("pro_comboBox"));
        pro_comboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"background-color:rgba(255, 255, 255, 0);\n"
"border:none;\n"
"border-bottom:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"font: 12pt \"Poppins\";\n"
"}\n"
"\n"
"QComboBox QAbstractItemView{\n"
"background-color:#BBC8EA;\n"
"border:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"	font: 12pt \"Poppins\";\n"
"border-radius: 10px;\n"
"}"));

        verticalLayout_13->addWidget(pro_comboBox);


        verticalLayout_11->addWidget(preferred_pro_wid);

        language_1st = new QWidget(scrollAreaWidgetContents);
        language_1st->setObjectName(QString::fromUtf8("language_1st"));
        sizePolicy8.setHeightForWidth(language_1st->sizePolicy().hasHeightForWidth());
        language_1st->setSizePolicy(sizePolicy8);
        language_1st->setMinimumSize(QSize(300, 0));
        language_1st->setStyleSheet(QString::fromUtf8("QWidget#language_1st\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(100, 127, 194, 255), stop:1 rgba(123, 149, 216, 87));\n"
"border-radius: 20px\n"
"}"));
        verticalLayout_14 = new QVBoxLayout(language_1st);
        verticalLayout_14->setSpacing(3);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(25, -1, 25, 12);
        language_1st_til = new QLabel(language_1st);
        language_1st_til->setObjectName(QString::fromUtf8("language_1st_til"));
        language_1st_til->setStyleSheet(QString::fromUtf8("QLabel#language_1st_til\n"
"{\n"
"background-color: none;\n"
"	font: 8pt \"Poppins\";\n"
"color: white;\n"
"}"));

        verticalLayout_14->addWidget(language_1st_til);

        language_1st_com = new QComboBox(language_1st);
        language_1st_com->addItem(QString());
        language_1st_com->addItem(QString());
        language_1st_com->addItem(QString());
        language_1st_com->addItem(QString());
        language_1st_com->addItem(QString());
        language_1st_com->addItem(QString());
        language_1st_com->addItem(QString());
        language_1st_com->addItem(QString());
        language_1st_com->addItem(QString());
        language_1st_com->setObjectName(QString::fromUtf8("language_1st_com"));
        language_1st_com->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"background-color:rgba(255, 255, 255, 0);\n"
"border:none;\n"
"border-bottom:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"font: 12pt \"Poppins\";\n"
"}\n"
"\n"
"QComboBox QAbstractItemView{\n"
"background-color:#BBC8EA;\n"
"border:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"	font: 12pt \"Poppins\";\n"
"border-radius: 10px;\n"
"}"));

        verticalLayout_14->addWidget(language_1st_com);


        verticalLayout_11->addWidget(language_1st);

        language_2nd = new QWidget(scrollAreaWidgetContents);
        language_2nd->setObjectName(QString::fromUtf8("language_2nd"));
        sizePolicy8.setHeightForWidth(language_2nd->sizePolicy().hasHeightForWidth());
        language_2nd->setSizePolicy(sizePolicy8);
        language_2nd->setMinimumSize(QSize(300, 0));
        language_2nd->setStyleSheet(QString::fromUtf8("QWidget#language_2nd\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(100, 127, 194, 255), stop:1 rgba(123, 149, 216, 87));\n"
"border-radius: 20px\n"
"}"));
        verticalLayout_15 = new QVBoxLayout(language_2nd);
        verticalLayout_15->setSpacing(3);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(25, -1, 25, 12);
        language_2nd_til = new QLabel(language_2nd);
        language_2nd_til->setObjectName(QString::fromUtf8("language_2nd_til"));
        language_2nd_til->setStyleSheet(QString::fromUtf8("QLabel#language_2nd_til\n"
"{\n"
"background-color: none;\n"
"	font: 8pt \"Poppins\";\n"
"color: white;\n"
"}"));

        verticalLayout_15->addWidget(language_2nd_til);

        language_2nd_com = new QComboBox(language_2nd);
        language_2nd_com->addItem(QString());
        language_2nd_com->addItem(QString());
        language_2nd_com->addItem(QString());
        language_2nd_com->addItem(QString());
        language_2nd_com->addItem(QString());
        language_2nd_com->addItem(QString());
        language_2nd_com->addItem(QString());
        language_2nd_com->addItem(QString());
        language_2nd_com->addItem(QString());
        language_2nd_com->setObjectName(QString::fromUtf8("language_2nd_com"));
        language_2nd_com->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"background-color:rgba(255, 255, 255, 0);\n"
"border:none;\n"
"border-bottom:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"font: 12pt \"Poppins\";\n"
"}\n"
"\n"
"QComboBox QAbstractItemView{\n"
"background-color:#BBC8EA;\n"
"border:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"	font: 12pt \"Poppins\";\n"
"border-radius: 10px;\n"
"}"));

        verticalLayout_15->addWidget(language_2nd_com);


        verticalLayout_11->addWidget(language_2nd);

        language_3rd = new QWidget(scrollAreaWidgetContents);
        language_3rd->setObjectName(QString::fromUtf8("language_3rd"));
        sizePolicy8.setHeightForWidth(language_3rd->sizePolicy().hasHeightForWidth());
        language_3rd->setSizePolicy(sizePolicy8);
        language_3rd->setMinimumSize(QSize(300, 0));
        language_3rd->setStyleSheet(QString::fromUtf8("QWidget#language_3rd\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(100, 127, 194, 255), stop:1 rgba(123, 149, 216, 87));\n"
"border-radius: 20px\n"
"}"));
        verticalLayout_16 = new QVBoxLayout(language_3rd);
        verticalLayout_16->setSpacing(3);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(25, -1, 25, 12);
        language_3rd_til = new QLabel(language_3rd);
        language_3rd_til->setObjectName(QString::fromUtf8("language_3rd_til"));
        language_3rd_til->setStyleSheet(QString::fromUtf8("QLabel#language_3rd_til\n"
"{\n"
"background-color: none;\n"
"	font: 8pt \"Poppins\";\n"
"color: white;\n"
"}"));

        verticalLayout_16->addWidget(language_3rd_til);

        language_3rd_com = new QComboBox(language_3rd);
        language_3rd_com->addItem(QString());
        language_3rd_com->addItem(QString());
        language_3rd_com->addItem(QString());
        language_3rd_com->addItem(QString());
        language_3rd_com->addItem(QString());
        language_3rd_com->addItem(QString());
        language_3rd_com->addItem(QString());
        language_3rd_com->addItem(QString());
        language_3rd_com->addItem(QString());
        language_3rd_com->setObjectName(QString::fromUtf8("language_3rd_com"));
        language_3rd_com->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"background-color:rgba(255, 255, 255, 0);\n"
"border:none;\n"
"border-bottom:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"font: 12pt \"Poppins\";\n"
"}\n"
"\n"
"QComboBox QAbstractItemView{\n"
"background-color:#BBC8EA;\n"
"border:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"	font: 12pt \"Poppins\";\n"
"border-radius: 10px;\n"
"}"));

        verticalLayout_16->addWidget(language_3rd_com);


        verticalLayout_11->addWidget(language_3rd);

        title_security = new QLabel(scrollAreaWidgetContents);
        title_security->setObjectName(QString::fromUtf8("title_security"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Poppins"));
        font6.setPointSize(12);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        title_security->setFont(font6);
        title_security->setStyleSheet(QString::fromUtf8("QLabel#title_security{\n"
"border: white;\n"
"	border-bottom: 1px solid rgb(255, 255, 255);\n"
"background-color: none;\n"
"color: white;\n"
"}"));
        title_security->setAlignment(Qt::AlignCenter);
        title_security->setMargin(3);

        verticalLayout_11->addWidget(title_security);

        Security_block = new QWidget(scrollAreaWidgetContents);
        Security_block->setObjectName(QString::fromUtf8("Security_block"));
        sizePolicy8.setHeightForWidth(Security_block->sizePolicy().hasHeightForWidth());
        Security_block->setSizePolicy(sizePolicy8);
        Security_block->setMinimumSize(QSize(300, 0));
        Security_block->setStyleSheet(QString::fromUtf8("QWidget#Security_block\n"
"{\n"
"background-color: qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(163, 182, 234, 255), stop:1 rgba(163, 182, 234, 87));\n"
"border-radius: 20px\n"
"}"));
        verticalLayout_18 = new QVBoxLayout(Security_block);
        verticalLayout_18->setSpacing(9);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(25, -1, 25, 12);
        enter_email_title = new QLabel(Security_block);
        enter_email_title->setObjectName(QString::fromUtf8("enter_email_title"));
        enter_email_title->setStyleSheet(QString::fromUtf8("QLabel#enter_email_title{\n"
"background-color: none;\n"
"	font: 8pt \"Poppins\";\n"
"color: white;\n"
"}"));

        verticalLayout_18->addWidget(enter_email_title);

        enter_email = new QLineEdit(Security_block);
        enter_email->setObjectName(QString::fromUtf8("enter_email"));
        enter_email->setStyleSheet(QString::fromUtf8("QLineEdit#enter_email{\n"
"background-color:rgba(255, 255, 255, 0);\n"
"border:none;\n"
"border-bottom:1px solid rgba(101, 128, 195, 120);\n"
"color: white;\n"
"	font: 12pt \"Poppins\";\n"
"}"));

        verticalLayout_18->addWidget(enter_email);


        verticalLayout_11->addWidget(Security_block);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_3->addWidget(scrollArea);


        horizontalLayout_2->addWidget(widget_2);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 5);

        verticalLayout_7->addWidget(widget_3);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 23);

        verticalLayout_5->addWidget(profile_entrance);


        verticalLayout_8->addWidget(profile_container);

        stackedWidget->addWidget(Profile);
        dictionary = new QWidget();
        dictionary->setObjectName(QString::fromUtf8("dictionary"));
        label = new QLabel(dictionary);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 140, 521, 101));
        stackedWidget->addWidget(dictionary);

        horizontalLayout->addWidget(stackedWidget);


        verticalLayout->addWidget(body);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 25);

        verticalLayout_3->addWidget(background);


        retranslateUi(MainWindow);

        user_list->setCurrentRow(-1);
        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        close_butt->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        minimize_butt->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        user_pic->setText(QString());
        username->setText(QCoreApplication::translate("MainWindow", "Bot", nullptr));
        settingbutton->setText(QString());
        new_conversation->setText(QCoreApplication::translate("MainWindow", "New Conversation", nullptr));
        dictionary_2->setText(QCoreApplication::translate("MainWindow", "Dictionary", nullptr));
        contact_label->setText(QCoreApplication::translate("MainWindow", "Contacts", nullptr));

        const bool __sortingEnabled = user_list->isSortingEnabled();
        user_list->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = user_list->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "HiBot", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = user_list->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Lindy", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = user_list->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Robert", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = user_list->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "Serena", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = user_list->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "Cathy", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = user_list->item(5);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("MainWindow", "User_1", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = user_list->item(6);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("MainWindow", "User_2", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = user_list->item(7);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("MainWindow", "User_3", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = user_list->item(8);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("MainWindow", "User_4", nullptr));
        QListWidgetItem *___qlistwidgetitem9 = user_list->item(9);
        ___qlistwidgetitem9->setText(QCoreApplication::translate("MainWindow", "User_5", nullptr));
        QListWidgetItem *___qlistwidgetitem10 = user_list->item(10);
        ___qlistwidgetitem10->setText(QCoreApplication::translate("MainWindow", "User_6", nullptr));
        QListWidgetItem *___qlistwidgetitem11 = user_list->item(11);
        ___qlistwidgetitem11->setText(QCoreApplication::translate("MainWindow", "User_7", nullptr));
        QListWidgetItem *___qlistwidgetitem12 = user_list->item(12);
        ___qlistwidgetitem12->setText(QCoreApplication::translate("MainWindow", "User_8", nullptr));
        QListWidgetItem *___qlistwidgetitem13 = user_list->item(13);
        ___qlistwidgetitem13->setText(QCoreApplication::translate("MainWindow", "user_9", nullptr));
        QListWidgetItem *___qlistwidgetitem14 = user_list->item(14);
        ___qlistwidgetitem14->setText(QCoreApplication::translate("MainWindow", "user_10", nullptr));
        QListWidgetItem *___qlistwidgetitem15 = user_list->item(15);
        ___qlistwidgetitem15->setText(QCoreApplication::translate("MainWindow", "user_11", nullptr));
        QListWidgetItem *___qlistwidgetitem16 = user_list->item(16);
        ___qlistwidgetitem16->setText(QCoreApplication::translate("MainWindow", "user_12", nullptr));
        QListWidgetItem *___qlistwidgetitem17 = user_list->item(17);
        ___qlistwidgetitem17->setText(QCoreApplication::translate("MainWindow", "user_13", nullptr));
        user_list->setSortingEnabled(__sortingEnabled);

        title_profile->setText(QCoreApplication::translate("MainWindow", "Personal Profile", nullptr));
        displayprofile->setText(QString());
        changeprofilepic->setText(QString());
        signout->setText(QCoreApplication::translate("MainWindow", "Sign Out", nullptr));
        changeProfile->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        profileError->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        username_ti->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        username_enter->setPlaceholderText(QCoreApplication::translate("MainWindow", "Bot", nullptr));
        intro_ti->setText(QCoreApplication::translate("MainWindow", "Intro", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "I am the queen. Be confident. ", nullptr));
        perferred_pro->setText(QCoreApplication::translate("MainWindow", "Preferred Pronoun", nullptr));
        pro_comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "They/ Them/ Their", nullptr));
        pro_comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "She/ Her/ Hers", nullptr));
        pro_comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "He/ Him/ His ", nullptr));

        language_1st_til->setText(QCoreApplication::translate("MainWindow", "First Language", nullptr));
        language_1st_com->setItemText(0, QCoreApplication::translate("MainWindow", "English (Canada)", nullptr));
        language_1st_com->setItemText(1, QCoreApplication::translate("MainWindow", "English (US)", nullptr));
        language_1st_com->setItemText(2, QCoreApplication::translate("MainWindow", "French", nullptr));
        language_1st_com->setItemText(3, QCoreApplication::translate("MainWindow", "German", nullptr));
        language_1st_com->setItemText(4, QCoreApplication::translate("MainWindow", "Chinese (Simplified)", nullptr));
        language_1st_com->setItemText(5, QCoreApplication::translate("MainWindow", "Chinese (Traditional)", nullptr));
        language_1st_com->setItemText(6, QCoreApplication::translate("MainWindow", "Spanish", nullptr));
        language_1st_com->setItemText(7, QCoreApplication::translate("MainWindow", "Japanese", nullptr));
        language_1st_com->setItemText(8, QCoreApplication::translate("MainWindow", "Korean", nullptr));

        language_2nd_til->setText(QCoreApplication::translate("MainWindow", "Second Language", nullptr));
        language_2nd_com->setItemText(0, QCoreApplication::translate("MainWindow", "English (Canada)", nullptr));
        language_2nd_com->setItemText(1, QCoreApplication::translate("MainWindow", "English (US)", nullptr));
        language_2nd_com->setItemText(2, QCoreApplication::translate("MainWindow", "French", nullptr));
        language_2nd_com->setItemText(3, QCoreApplication::translate("MainWindow", "German", nullptr));
        language_2nd_com->setItemText(4, QCoreApplication::translate("MainWindow", "Chinese (Simplified)", nullptr));
        language_2nd_com->setItemText(5, QCoreApplication::translate("MainWindow", "Chinese (Traditional)", nullptr));
        language_2nd_com->setItemText(6, QCoreApplication::translate("MainWindow", "Spanish", nullptr));
        language_2nd_com->setItemText(7, QCoreApplication::translate("MainWindow", "Japanese", nullptr));
        language_2nd_com->setItemText(8, QCoreApplication::translate("MainWindow", "Korean", nullptr));

        language_3rd_til->setText(QCoreApplication::translate("MainWindow", "Thrid Language", nullptr));
        language_3rd_com->setItemText(0, QCoreApplication::translate("MainWindow", "English (Canada)", nullptr));
        language_3rd_com->setItemText(1, QCoreApplication::translate("MainWindow", "English (US)", nullptr));
        language_3rd_com->setItemText(2, QCoreApplication::translate("MainWindow", "French", nullptr));
        language_3rd_com->setItemText(3, QCoreApplication::translate("MainWindow", "German", nullptr));
        language_3rd_com->setItemText(4, QCoreApplication::translate("MainWindow", "Chinese (Simplified)", nullptr));
        language_3rd_com->setItemText(5, QCoreApplication::translate("MainWindow", "Chinese (Traditional)", nullptr));
        language_3rd_com->setItemText(6, QCoreApplication::translate("MainWindow", "Spanish", nullptr));
        language_3rd_com->setItemText(7, QCoreApplication::translate("MainWindow", "Japanese", nullptr));
        language_3rd_com->setItemText(8, QCoreApplication::translate("MainWindow", "Korean", nullptr));

        title_security->setText(QCoreApplication::translate("MainWindow", "Security", nullptr));
        enter_email_title->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        enter_email->setText(QCoreApplication::translate("MainWindow", "BOT@gmail.com", nullptr));
        enter_email->setPlaceholderText(QCoreApplication::translate("MainWindow", "Bot", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "This is supposed to be the dictionary page??? Not sure how to structure it yet so I left it like this.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
