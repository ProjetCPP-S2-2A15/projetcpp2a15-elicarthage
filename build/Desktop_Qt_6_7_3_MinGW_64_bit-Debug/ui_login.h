/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *mot_de_passe_oublie;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QPushButton *btnquestion;
    QPushButton *btnLogin;
    QLineEdit *lineEdit_5;
    QLabel *question;
    QWidget *widgetRei;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QPushButton *bntReinitialiser;
    QPushButton *btnLogin_2;
    QLineEdit *lineEdit_4;
    QWidget *widget_logo;
    QLabel *label_2;
    QLabel *label;
    QWidget *loginWidget;
    QLineEdit *lineEditEmail;
    QPushButton *btnConnecter;
    QLineEdit *lineEditPassword;
    QPushButton *btnMotDePasse;
    QLabel *labelImage;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(865, 499);
        mot_de_passe_oublie = new QWidget(login);
        mot_de_passe_oublie->setObjectName("mot_de_passe_oublie");
        mot_de_passe_oublie->setGeometry(QRect(760, 60, 361, 341));
        mot_de_passe_oublie->setStyleSheet(QString::fromUtf8(""));
        lineEdit_2 = new QLineEdit(mot_de_passe_oublie);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(10, 210, 311, 40));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        label_3 = new QLabel(mot_de_passe_oublie);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 140, 351, 71));
        btnquestion = new QPushButton(mot_de_passe_oublie);
        btnquestion->setObjectName("btnquestion");
        btnquestion->setGeometry(QRect(10, 300, 311, 31));
        QFont font;
        font.setBold(false);
        btnquestion->setFont(font);
        btnquestion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"\n"
""));
        btnLogin = new QPushButton(mot_de_passe_oublie);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(148, 432, 91, 31));
        QFont font1;
        font1.setUnderline(true);
        btnLogin->setFont(font1);
        btnLogin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;  /* Fond transparent */\n"
"    border: none;\n"
"    color: #222d52;  /* Couleur du texte */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    font-weight: bold;\n"
"    color: #1a2439;  /* Couleur du texte l\303\251g\303\250rement plus sombre quand le bouton est press\303\251 */\n"
"}"));
        lineEdit_5 = new QLineEdit(mot_de_passe_oublie);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(10, 50, 311, 40));
        lineEdit_5->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        question = new QLabel(mot_de_passe_oublie);
        question->setObjectName("question");
        question->setGeometry(QRect(10, 105, 311, 31));
        widgetRei = new QWidget(login);
        widgetRei->setObjectName("widgetRei");
        widgetRei->setGeometry(QRect(540, 450, 351, 351));
        widgetRei->setStyleSheet(QString::fromUtf8(""));
        lineEdit_3 = new QLineEdit(widgetRei);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(10, 150, 311, 40));
        lineEdit_3->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        label_4 = new QLabel(widgetRei);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 30, 201, 71));
        bntReinitialiser = new QPushButton(widgetRei);
        bntReinitialiser->setObjectName("bntReinitialiser");
        bntReinitialiser->setGeometry(QRect(10, 320, 311, 31));
        bntReinitialiser->setFont(font);
        bntReinitialiser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"\n"
""));
        btnLogin_2 = new QPushButton(widgetRei);
        btnLogin_2->setObjectName("btnLogin_2");
        btnLogin_2->setGeometry(QRect(148, 432, 91, 31));
        btnLogin_2->setFont(font1);
        btnLogin_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;  /* Fond transparent */\n"
"    border: none;\n"
"    color: #222d52;  /* Couleur du texte */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    font-weight: bold;\n"
"    color: #1a2439;  /* Couleur du texte l\303\251g\303\250rement plus sombre quand le bouton est press\303\251 */\n"
"}"));
        lineEdit_4 = new QLineEdit(widgetRei);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(10, 240, 311, 40));
        lineEdit_4->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        widget_logo = new QWidget(login);
        widget_logo->setObjectName("widget_logo");
        widget_logo->setGeometry(QRect(-20, 0, 361, 361));
        label_2 = new QLabel(widget_logo);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 60, 211, 161));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(\"C:/Users/Admin/Desktop/projet/images/logo.png\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
""));
        label = new QLabel(widget_logo);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 210, 291, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Goudy Stout")});
        font2.setPointSize(15);
        font2.setBold(true);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white; /* Texte en blanc */\n"
" font-family: 'Goudy Stout', sans-serif;\n"
"}\n"
"\n"
""));
        loginWidget = new QWidget(login);
        loginWidget->setObjectName("loginWidget");
        loginWidget->setGeometry(QRect(390, -20, 351, 441));
        loginWidget->setStyleSheet(QString::fromUtf8(""));
        lineEditEmail = new QLineEdit(loginWidget);
        lineEditEmail->setObjectName("lineEditEmail");
        lineEditEmail->setGeometry(QRect(10, 120, 301, 40));
        lineEditEmail->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        btnConnecter = new QPushButton(loginWidget);
        btnConnecter->setObjectName("btnConnecter");
        btnConnecter->setEnabled(true);
        btnConnecter->setGeometry(QRect(10, 290, 311, 31));
        btnConnecter->setFont(font);
        btnConnecter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"\n"
""));
        lineEditPassword = new QLineEdit(loginWidget);
        lineEditPassword->setObjectName("lineEditPassword");
        lineEditPassword->setGeometry(QRect(10, 200, 301, 40));
        QFont font3;
        font3.setPointSize(9);
        lineEditPassword->setFont(font3);
        lineEditPassword->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        lineEditPassword->setEchoMode(QLineEdit::EchoMode::Password);
        btnMotDePasse = new QPushButton(loginWidget);
        btnMotDePasse->setObjectName("btnMotDePasse");
        btnMotDePasse->setGeometry(QRect(190, 250, 151, 24));
        btnMotDePasse->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
" \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    font-weight: bold;\n"
"}\n"
""));
        labelImage = new QLabel(loginWidget);
        labelImage->setObjectName("labelImage");
        labelImage->setGeometry(QRect(200, 0, 161, 101));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Form", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("login", "r\303\251ponse", nullptr));
        label_3->setText(QCoreApplication::translate("login", "<html><head/><body><p><span style=\" font-weight:700;\">R\303\251pondez \303\240 cette question personnelle pour r\303\251initialiser </span></p><p><span style=\" font-weight:700;\">votre mot de passe.</span></p></body></html>", nullptr));
        btnquestion->setText(QCoreApplication::translate("login", "R\303\251pondre \303\240 la question", nullptr));
        btnLogin->setText(QString());
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("login", "email", nullptr));
        question->setText(QCoreApplication::translate("login", "TextLabel", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("login", "Nouveau mot de passe", nullptr));
        label_4->setText(QCoreApplication::translate("login", "<html><head/><body><p><span style=\" font-weight:700;\">R\303\251initialiser le mot de passe</span></p></body></html>", nullptr));
        bntReinitialiser->setText(QCoreApplication::translate("login", "R\303\251initialiser le mot de passe", nullptr));
        btnLogin_2->setText(QString());
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("login", "Confirmer le nouveau mot de passe", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("login", "ELICARTHAGE", nullptr));
        lineEditEmail->setPlaceholderText(QCoreApplication::translate("login", "email", nullptr));
        btnConnecter->setText(QCoreApplication::translate("login", "se connecter", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("login", "mot de passe", nullptr));
        btnMotDePasse->setText(QCoreApplication::translate("login", "Mot de passe oubli\303\251?", nullptr));
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
