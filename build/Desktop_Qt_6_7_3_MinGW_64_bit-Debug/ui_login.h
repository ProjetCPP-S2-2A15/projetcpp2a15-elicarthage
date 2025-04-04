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
    QPushButton *btnLogin;
    QLineEdit *lineEditemailR;
    QPushButton *btnValider;
    QPushButton *btnRetour;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *widgetRei;
    QLineEdit *nvPass;
    QLabel *label_4;
    QPushButton *btnReinitialiser;
    QPushButton *btnLogin_2;
    QLineEdit *confirmPass;
    QLabel *labelErreur;
    QWidget *loginWidget;
    QLineEdit *lineEditEmail;
    QPushButton *btnConnecter;
    QLineEdit *lineEditPassword;
    QPushButton *btnMotDePasse;
    QLabel *labelImage;
    QWidget *widgetQuestion;
    QLabel *question;
    QLabel *label_3;
    QLineEdit *lineEditReponse;
    QPushButton *btnquestion;
    QWidget *widget_logo;
    QLabel *label_2;
    QLabel *label;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(865, 499);
        mot_de_passe_oublie = new QWidget(login);
        mot_de_passe_oublie->setObjectName("mot_de_passe_oublie");
        mot_de_passe_oublie->setGeometry(QRect(20, 80, 381, 401));
        mot_de_passe_oublie->setStyleSheet(QString::fromUtf8(""));
        btnLogin = new QPushButton(mot_de_passe_oublie);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(148, 432, 91, 31));
        QFont font;
        font.setUnderline(true);
        btnLogin->setFont(font);
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
        lineEditemailR = new QLineEdit(mot_de_passe_oublie);
        lineEditemailR->setObjectName("lineEditemailR");
        lineEditemailR->setGeometry(QRect(20, 240, 311, 40));
        lineEditemailR->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        btnValider = new QPushButton(mot_de_passe_oublie);
        btnValider->setObjectName("btnValider");
        btnValider->setGeometry(QRect(80, 320, 181, 31));
        btnValider->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnRetour = new QPushButton(mot_de_passe_oublie);
        btnRetour->setObjectName("btnRetour");
        btnRetour->setGeometry(QRect(80, 360, 181, 24));
        btnRetour->setFont(font);
        btnRetour->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
" \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    font-weight: bold;\n"
"}\n"
""));
        label_5 = new QLabel(mot_de_passe_oublie);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 20, 151, 20));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setItalic(false);
        label_5->setFont(font1);
        label_6 = new QLabel(mot_de_passe_oublie);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 70, 351, 141));
        QFont font2;
        font2.setPointSize(8);
        label_6->setFont(font2);
        widgetRei = new QWidget(login);
        widgetRei->setObjectName("widgetRei");
        widgetRei->setGeometry(QRect(410, 60, 351, 351));
        widgetRei->setStyleSheet(QString::fromUtf8(""));
        nvPass = new QLineEdit(widgetRei);
        nvPass->setObjectName("nvPass");
        nvPass->setGeometry(QRect(10, 150, 311, 40));
        nvPass->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        nvPass->setEchoMode(QLineEdit::EchoMode::Password);
        label_4 = new QLabel(widgetRei);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 30, 201, 71));
        btnReinitialiser = new QPushButton(widgetRei);
        btnReinitialiser->setObjectName("btnReinitialiser");
        btnReinitialiser->setGeometry(QRect(10, 320, 311, 31));
        QFont font3;
        font3.setBold(false);
        btnReinitialiser->setFont(font3);
        btnReinitialiser->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnLogin_2->setFont(font);
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
        confirmPass = new QLineEdit(widgetRei);
        confirmPass->setObjectName("confirmPass");
        confirmPass->setGeometry(QRect(10, 240, 311, 40));
        confirmPass->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        confirmPass->setEchoMode(QLineEdit::EchoMode::Password);
        labelErreur = new QLabel(widgetRei);
        labelErreur->setObjectName("labelErreur");
        labelErreur->setGeometry(QRect(40, 200, 281, 16));
        loginWidget = new QWidget(login);
        loginWidget->setObjectName("loginWidget");
        loginWidget->setGeometry(QRect(390, 430, 351, 441));
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
        btnConnecter->setFont(font3);
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
        QFont font4;
        font4.setPointSize(9);
        lineEditPassword->setFont(font4);
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
        widgetQuestion = new QWidget(login);
        widgetQuestion->setObjectName("widgetQuestion");
        widgetQuestion->setGeometry(QRect(820, 30, 331, 331));
        question = new QLabel(widgetQuestion);
        question->setObjectName("question");
        question->setGeometry(QRect(10, 110, 281, 31));
        label_3 = new QLabel(widgetQuestion);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 311, 71));
        QFont font5;
        font5.setBold(true);
        label_3->setFont(font5);
        lineEditReponse = new QLineEdit(widgetQuestion);
        lineEditReponse->setObjectName("lineEditReponse");
        lineEditReponse->setGeometry(QRect(10, 170, 301, 40));
        lineEditReponse->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,0);\n"
"border:2px solid rgba(0,0,0,0);\n"
"border-bottom-color:rgba(46,82,101,200);\n"
"color:rgb(0,0,0);\n"
"padding-bottom:7px;"));
        btnquestion = new QPushButton(widgetQuestion);
        btnquestion->setObjectName("btnquestion");
        btnquestion->setGeometry(QRect(0, 280, 311, 31));
        btnquestion->setFont(font3);
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
        widget_logo = new QWidget(login);
        widget_logo->setObjectName("widget_logo");
        widget_logo->setGeometry(QRect(40, -210, 311, 281));
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
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Goudy Stout")});
        font6.setPointSize(15);
        font6.setBold(true);
        label->setFont(font6);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: white; /* Texte en blanc */\n"
" font-family: 'Goudy Stout', sans-serif;\n"
"}\n"
"\n"
""));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Form", nullptr));
        btnLogin->setText(QString());
        lineEditemailR->setPlaceholderText(QCoreApplication::translate("login", "email", nullptr));
        btnValider->setText(QCoreApplication::translate("login", "Valider", nullptr));
        btnRetour->setText(QCoreApplication::translate("login", "retour \303\240 la page de connexion", nullptr));
        label_5->setText(QCoreApplication::translate("login", "Mot de passe oubli\303\251 ?", nullptr));
        label_6->setText(QCoreApplication::translate("login", "<html><head/><body><p>Pour r\303\251initialiser votre mot de passe, veuillez saisir l'adresse</p><p>e-mail associ\303\251e \303\240 votre compte. Une fois l'e-mail valid\303\251, </p><p>votre question secr\303\250te personnelle s'affichera. Vous devrez</p><p>alors y r\303\251pondre.Si votre r\303\251ponse est correcte, vous pourrez</p><p>ensuite saisir un nouveau mot de passe s\303\251curis\303\251.</p></body></html>", nullptr));
        nvPass->setPlaceholderText(QCoreApplication::translate("login", "Nouveau mot de passe", nullptr));
        label_4->setText(QCoreApplication::translate("login", "<html><head/><body><p><span style=\" font-weight:700;\">R\303\251initialiser le mot de passe</span></p></body></html>", nullptr));
        btnReinitialiser->setText(QCoreApplication::translate("login", "R\303\251initialiser le mot de passe", nullptr));
        btnLogin_2->setText(QString());
        confirmPass->setPlaceholderText(QCoreApplication::translate("login", "Confirmer le nouveau mot de passe", nullptr));
        labelErreur->setText(QString());
        lineEditEmail->setPlaceholderText(QCoreApplication::translate("login", "email", nullptr));
        btnConnecter->setText(QCoreApplication::translate("login", "se connecter", nullptr));
        lineEditPassword->setPlaceholderText(QCoreApplication::translate("login", "mot de passe", nullptr));
        btnMotDePasse->setText(QCoreApplication::translate("login", "Mot de passe oubli\303\251?", nullptr));
        labelImage->setText(QString());
        question->setText(QString());
        label_3->setText(QCoreApplication::translate("login", "<html><head/><body><p>Veuillez r\303\251pondre \303\240 votre question secr\303\250te ci-dessous</p></body></html>", nullptr));
        lineEditReponse->setPlaceholderText(QCoreApplication::translate("login", "r\303\251ponse", nullptr));
        btnquestion->setText(QCoreApplication::translate("login", "R\303\251pondre \303\240 la question", nullptr));
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("login", "ELICARTHAGE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
