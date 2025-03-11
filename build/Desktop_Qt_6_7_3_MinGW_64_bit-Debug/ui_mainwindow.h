/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QWidget *widget_2;
    QPushButton *projet;
    QPushButton *client;
    QPushButton *ressources;
    QPushButton *formations;
    QPushButton *tache;
    QPushButton *architecte;
    QPushButton *deconnecter;
    QPushButton *logo;
    QWidget *widget_3;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_role;
    QLineEdit *lineEdit_mail;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *annulerEvent;
    QLabel *label_12;
    QLineEdit *lineEdit_motDePasse;
    QComboBox *comboBox_question;
    QLineEdit *lineEdit_response;
    QPushButton *btnAjouter;
    QLabel *label_14;
    QPushButton *exportProjet;
    QPushButton *BouttonRechProjet;
    QLineEdit *taperRech;
    QPushButton *tri;
    QLabel *label;
    QWidget *widget_4;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QTableView *tableView;
    QLineEdit *lineEdit_IDS;
    QPushButton *btnsupprimer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1250, 618);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-10, 0, 1251, 600));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgba(240, 240, 240, 1); /* Gris tr\303\250s clair */\n"
"}\n"
""));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 140, 580));
        widget_2->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QGroupBox */\n"
"QWidget { \n"
"    border: none; /* Supprime le cadre du groupe */\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, \n"
"        stop:0 rgba(34, 32, 82, 255), \n"
"        stop:1 rgba(0, 0, 0, 255)); /* D\303\251grad\303\251 */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    padding: 10px; /* Espace int\303\251rieur */\n"
"}\n"
"\n"
"/* Style des boutons */\n"
"QPushButton {\n"
"    background-color: transparent; /* Fond transparent par d\303\251faut */\n"
"    color: white; /* Texte blanc */\n"
"    border: none;\n"
"    padding: 10px;\n"
"    font-size: 16px;\n"
"    min-width: 120px; /* Largeur minimale du bouton */\n"
"    min-height: 40px; /* Hauteur minimale du bouton */\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 0.1); /* L\303\251ger fond blanc transparent au survol */\n"
"}\n"
"\n"
"/* Effet quand le bouton est press\303\251 */\n"
"QPushButton:pressed"
                        " {\n"
"    background-color: white; /* Fond blanc */\n"
"    color: black; /* Texte noir */\n"
"}\n"
"\n"
"/* Quand le bouton est coch\303\251, il reste en blanc */\n"
"QPushButton:checked {\n"
"    background-color: white; /* Fond blanc apr\303\250s clic */\n"
"    color: black; /* Texte noir apr\303\250s clic */\n"
"}\n"
"\n"
"/* Style du QLabel */\n"
"QLabel {\n"
"    color: white; /* Texte en blanc */\n"
"    font-family: Arial, sans-serif; /* Police Arial */\n"
"    font-size: 16px; /* Taille de la police */\n"
"    font-weight: bold; /* Police en gras */\n"
"    padding: 5px; /* Espace autour du texte */\n"
"}\n"
"QPushButton#architecte {\n"
"    qproperty-icon: url(C:/Users/Admin/Desktop/projet/images/engineer.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#projet {\n"
"    qproperty-icon: url(C:/Users/Admin/Desktop/projet/images/dossier.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#tache {\n"
"    qproperty-icon: url(C:/Users/Admin/Desktop/projet/images"
                        "/taches.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#client {\n"
"    qproperty-icon:url(C:/Users/Admin/Desktop/projet/images/user.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#formations {\n"
"    qproperty-icon:url(C:/Users/Admin/Desktop/projet/images/learning.png);\n"
"  qproperty-iconSize: 24px 24px;\n"
"}\n"
"QPushButton#ressources {\n"
"    qproperty-icon:url(C:/Users/Admin/Desktop/projet/images/loan.png);\n"
"  qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#deconnecter {\n"
"    qproperty-icon:url(C:/Users/Admin/Desktop/projet/images/deconnexion.png);\n"
"  qproperty-iconSize: 24px 24px;\n"
"}\n"
"QPushButton#logo {\n"
"    qproperty-icon: url(C:/Users/Admin/Desktop/projet/images/logo.png);\n"
"    qproperty-iconSize: 70px 70px; /* Taille augment\303\251e */\n"
"}\n"
"\n"
"\n"
"\n"
""));
        projet = new QPushButton(widget_2);
        projet->setObjectName("projet");
        projet->setGeometry(QRect(0, 135, 141, 60));
        client = new QPushButton(widget_2);
        client->setObjectName("client");
        client->setGeometry(QRect(0, 255, 141, 60));
        ressources = new QPushButton(widget_2);
        ressources->setObjectName("ressources");
        ressources->setGeometry(QRect(0, 315, 141, 60));
        formations = new QPushButton(widget_2);
        formations->setObjectName("formations");
        formations->setGeometry(QRect(0, 375, 141, 60));
        tache = new QPushButton(widget_2);
        tache->setObjectName("tache");
        tache->setGeometry(QRect(0, 195, 141, 60));
        architecte = new QPushButton(widget_2);
        architecte->setObjectName("architecte");
        architecte->setGeometry(QRect(0, 75, 142, 62));
        architecte->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:  #ffffff;\n"
"\n"
"    color: black;  /* D\303\251finir la couleur du texte en noir */\n"
"    border: 1px solid black;  /* Optionnel : pour ajouter une bordure noire */\n"
"}\n"
""));
        deconnecter = new QPushButton(widget_2);
        deconnecter->setObjectName("deconnecter");
        deconnecter->setGeometry(QRect(0, 480, 141, 62));
        deconnecter->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0)"));
        logo = new QPushButton(widget_2);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 10, 140, 60));
        logo->setStyleSheet(QString::fromUtf8("QPushButton#logo {\n"
"    qproperty-icon: url(C:/Users/Admin/Desktop/projet/images/logo.png);\n"
"    qproperty-iconSize: 70px 70px; /* Taille augment\303\251e */\n"
"    background-color: transparent; /* Fond transparent */\n"
"    border: none; /* Supprime la bordure */\n"
"}\n"
"\n"
"/* Pas d'effet au survol */\n"
"QPushButton#logo:hover {\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"/* Pas d'effet au clic */\n"
"QPushButton#logo:pressed {\n"
"    background-color: transparent;\n"
"}\n"
""));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(150, 30, 231, 531));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #eee5d3; \n"
"    border: 1px solid black;   /* Cadre noir fin (1px) */\n"
"      border-radius: 20px; /* Coins arrondis */      /* Coins arrondis */\n"
"}\n"
"\n"
"QWidget > * {\n"
"    border: none;              /* D\303\251sactive la bordure pour les \303\251l\303\251ments enfants */\n"
"}\n"
""));
        lineEdit_nom = new QLineEdit(widget_3);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(10, 50, 141, 31));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;    /* Fond blanc pour une bonne lisibilit\303\251 */\n"
"    color: #2C3E50;               /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;    /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;           /* Coins arrondis */\n"
"    padding: 6px;                 /* Espacement int\303\251rieur */\n"
"    font-size: 13px;              /* Taille de la police \303\251quilibr\303\251e */\n"
"    selection-background-color: #5DADE2; /* Bleu clair pour la s\303\251lection du texte */\n"
"    selection-color: white;       /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        lineEdit_prenom = new QLineEdit(widget_3);
        lineEdit_prenom->setObjectName("lineEdit_prenom");
        lineEdit_prenom->setGeometry(QRect(10, 110, 141, 31));
        lineEdit_prenom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;    /* Fond blanc pour une bonne lisibilit\303\251 */\n"
"    color: #2C3E50;               /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;    /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;           /* Coins arrondis */\n"
"    padding: 6px;                 /* Espacement int\303\251rieur */\n"
"    font-size: 13px;              /* Taille de la police \303\251quilibr\303\251e */\n"
"    selection-background-color: #5DADE2; /* Bleu clair pour la s\303\251lection du texte */\n"
"    selection-color: white;       /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        lineEdit_role = new QLineEdit(widget_3);
        lineEdit_role->setObjectName("lineEdit_role");
        lineEdit_role->setGeometry(QRect(10, 170, 141, 31));
        lineEdit_role->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;    /* Fond blanc pour une bonne lisibilit\303\251 */\n"
"    color: #2C3E50;               /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;    /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;           /* Coins arrondis */\n"
"    padding: 6px;                 /* Espacement int\303\251rieur */\n"
"    font-size: 13px;              /* Taille de la police \303\251quilibr\303\251e */\n"
"    selection-background-color: #5DADE2; /* Bleu clair pour la s\303\251lection du texte */\n"
"    selection-color: white;       /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        lineEdit_mail = new QLineEdit(widget_3);
        lineEdit_mail->setObjectName("lineEdit_mail");
        lineEdit_mail->setGeometry(QRect(10, 230, 141, 31));
        lineEdit_mail->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;    /* Fond blanc pour une bonne lisibilit\303\251 */\n"
"    color: #2C3E50;               /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;    /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;           /* Coins arrondis */\n"
"    padding: 6px;                 /* Espacement int\303\251rieur */\n"
"    font-size: 13px;              /* Taille de la police \303\251quilibr\303\251e */\n"
"    selection-background-color: #5DADE2; /* Bleu clair pour la s\303\251lection du texte */\n"
"    selection-color: white;       /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 20, 31, 16));
        QFont font;
        font.setBold(true);
        label_2->setFont(font);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 51, 16));
        label_3->setFont(font);
        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 210, 31, 16));
        label_4->setFont(font);
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 150, 31, 16));
        label_5->setFont(font);
        annulerEvent = new QPushButton(widget_3);
        annulerEvent->setObjectName("annulerEvent");
        annulerEvent->setGeometry(QRect(110, 490, 80, 31));
        annulerEvent->setStyleSheet(QString::fromUtf8("QPushButton#annulerEvent {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton#annulerEvent:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton#annulerEvent:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"QPushButton#annulerEvent:dis"
                        "abled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        label_12 = new QLabel(widget_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 270, 81, 16));
        label_12->setFont(font);
        lineEdit_motDePasse = new QLineEdit(widget_3);
        lineEdit_motDePasse->setObjectName("lineEdit_motDePasse");
        lineEdit_motDePasse->setGeometry(QRect(10, 300, 141, 31));
        lineEdit_motDePasse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;    /* Fond blanc pour une bonne lisibilit\303\251 */\n"
"    color: #2C3E50;               /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;    /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;           /* Coins arrondis */\n"
"    padding: 6px;                 /* Espacement int\303\251rieur */\n"
"    font-size: 13px;              /* Taille de la police \303\251quilibr\303\251e */\n"
"    selection-background-color: #5DADE2; /* Bleu clair pour la s\303\251lection du texte */\n"
"    selection-color: white;       /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        lineEdit_motDePasse->setEchoMode(QLineEdit::EchoMode::Password);
        comboBox_question = new QComboBox(widget_3);
        comboBox_question->addItem(QString::fromUtf8("Quel est le nom de votre premier animal ?"));
        comboBox_question->addItem(QString());
        comboBox_question->addItem(QString());
        comboBox_question->setObjectName("comboBox_question");
        comboBox_question->setGeometry(QRect(0, 350, 221, 21));
        comboBox_question->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    font-weight: bold;      /* Texte en gras */\n"
"    font-size: 10.5px;      /* Taille de la police dans la zone de saisie */\n"
"    color: #2C3E50;         /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    font-size: 5px;         /* Taille de la police tr\303\250s petite dans la liste d\303\251roulante */\n"
"    font-weight: bold;      /* Texte en gras dans la liste d\303\251roulante */\n"
"}\n"
"\n"
""));
        lineEdit_response = new QLineEdit(widget_3);
        lineEdit_response->setObjectName("lineEdit_response");
        lineEdit_response->setGeometry(QRect(10, 420, 141, 31));
        lineEdit_response->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;    /* Fond blanc pour une bonne lisibilit\303\251 */\n"
"    color: #2C3E50;               /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;    /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;           /* Coins arrondis */\n"
"    padding: 6px;                 /* Espacement int\303\251rieur */\n"
"    font-size: 13px;              /* Taille de la police \303\251quilibr\303\251e */\n"
"    selection-background-color: #5DADE2; /* Bleu clair pour la s\303\251lection du texte */\n"
"    selection-color: white;       /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        btnAjouter = new QPushButton(widget_3);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(10, 490, 80, 31));
        btnAjouter->setStyleSheet(QString::fromUtf8("QPushButton#btnAjouter {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton#btnAjouter:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton#btnAjouter:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"QPushButton#btnAjouter:disabled {\n"
""
                        "    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        label_14 = new QLabel(widget_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(0, 390, 221, 16));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(false);
        label_14->setFont(font1);
        exportProjet = new QPushButton(widget);
        exportProjet->setObjectName("exportProjet");
        exportProjet->setGeometry(QRect(390, 30, 131, 31));
        exportProjet->setStyleSheet(QString::fromUtf8("QPushButton#exportProjet {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton#exportProjet:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton#exportProjet:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"QPushButton#exportProjet:dis"
                        "abled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        BouttonRechProjet = new QPushButton(widget);
        BouttonRechProjet->setObjectName("BouttonRechProjet");
        BouttonRechProjet->setGeometry(QRect(870, 30, 141, 31));
        BouttonRechProjet->setStyleSheet(QString::fromUtf8("QPushButton#BouttonRechProjet {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton#BouttonRechProjet:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton#BouttonRechProjet:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"QPushButton#B"
                        "outtonRechProjet:disabled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        taperRech = new QLineEdit(widget);
        taperRech->setObjectName("taperRech");
        taperRech->setGeometry(QRect(650, 30, 191, 31));
        taperRech->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;    /* Fond blanc pour une bonne lisibilit\303\251 */\n"
"    color: #2C3E50;               /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;    /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;           /* Coins arrondis */\n"
"    padding: 6px;                 /* Espacement int\303\251rieur */\n"
"    font-size: 13px;              /* Taille de la police \303\251quilibr\303\251e */\n"
"    selection-background-color: #5DADE2; /* Bleu clair pour la s\303\251lection du texte */\n"
"    selection-color: white;       /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"\n"
"    \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        tri = new QPushButton(widget);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(1190, 30, 31, 41));
        tri->setStyleSheet(QString::fromUtf8("QPushButton#tri {\n"
"    qproperty-icon: url(C:/Users/Admin/Desktop/projet/images/tri.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QPushButton#tri:pressed {\n"
"    qproperty-iconSize: 32px 32px; /* Agrandit l'ic\303\264ne */\n"
"    padding: 5px; /* R\303\251duit l\342\200\231espace autour pour l\342\200\231effet d\342\200\231agrandissement */\n"
"    margin: -5px; /* Compense pour \303\251viter le d\303\251placement */\n"
"}\n"
""));
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 10, 181, 31));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #E8DDC8; /* Couleur de fond */\n"
"    color: white; /* Texte en blanc pour contraste */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    padding: 8px 15px; /* Espacement int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(490, 420, 751, 141));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #E0E0E0;  /* Fond gris plus clair */\n"
"    border: 1px solid black;    /* Cadre noir fin (1px) */\n"
"    border-radius: 20px;        /* Coins arrondis */\n"
"}\n"
"\n"
"QWidget > * {\n"
"    border: none;               /* D\303\251sactive la bordure pour les \303\251l\303\251ments enfants */\n"
"}\n"
""));
        label_6 = new QLabel(widget_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 20, 621, 131));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-image: url(\"C:/Users/Admin/Desktop/projet/images/stat.png\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
""));
        label_7 = new QLabel(widget_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 10, 331, 16));
        label_7->setFont(font);
        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(450, 34, 111, 16));
        label_9 = new QLabel(widget_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(450, 110, 111, 16));
        label_10 = new QLabel(widget_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(450, 72, 111, 16));
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(1100, 43, 93, 16));
        label_11->setFont(font);
        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(420, 80, 831, 261));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #F8F9FA;   /* Fond gris tr\303\250s clair */\n"
"    color: #1B2631;              /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;   /* Bordure ext\303\251rieure */\n"
"    gridline-color: #5D6D7E;     \n"
"    font-size: 12px;  /* R\303\251duction de la taille de police */\n"
"    selection-background-color: #D6EAF8;\n"
"    selection-color: #1B2631;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 1px; /* R\303\251duction maximale du padding */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #D6EAF8;\n"
"    color: #1B2631;\n"
"}\n"
"\n"
"/* En-t\303\252te de colonne */\n"
"QHeaderView::section {\n"
"    background-color: #1F4E78;\n"
"    color: white;\n"
"    padding: 1px;  /* R\303\251duction maximale du padding */\n"
"    font-weight: bold;\n"
"    border: 1px solid #154360;\n"
"    border-left: none;\n"
"    border-right: none;\n"
"    min-width: 10px;  /* Colonnes encore plus petites */\n"
"    max-width: 40px;  /* R\303\251du"
                        "ction encore plus prononc\303\251e */\n"
"    font-size: 11px;  /* Diminution suppl\303\251mentaire de la taille du texte */\n"
"}\n"
"\n"
"/* Supprimer la bordure gauche de la premi\303\250re colonne */\n"
"QHeaderView::section:first {\n"
"    border-left: 1px solid #154360;\n"
"}\n"
"\n"
"/* Supprimer la bordure droite de la derni\303\250re colonne */\n"
"QHeaderView::section:last {\n"
"    border-right: 1px solid #154360;\n"
"}\n"
"\n"
"/* Effet au survol */\n"
"QHeaderView::section:hover {\n"
"    background-color: #154360;\n"
"}\n"
"\n"
"/* Supprimer la num\303\251rotation des lignes */\n"
"QTableView QHeaderView::section:vertical {\n"
"    background: transparent;\n"
"    border: none;\n"
"    min-width: 0px;\n"
"    max-width: 0px;\n"
"    width: 0px;\n"
"}\n"
"\n"
"/* Bouton de coin */\n"
"QTableCornerButton::section {\n"
"    background-color: #1F4E78;\n"
"    border: 1px solid #154360;\n"
"}\n"
""));
        lineEdit_IDS = new QLineEdit(widget);
        lineEdit_IDS->setObjectName("lineEdit_IDS");
        lineEdit_IDS->setGeometry(QRect(990, 360, 113, 31));
        lineEdit_IDS->setStyleSheet(QString::fromUtf8("/* Style par d\303\251faut du QLineEdit */\n"
"QLineEdit {\n"
"    background-color: #FFFFFF;    /* Fond blanc pour une bonne lisibilit\303\251 */\n"
"    color: #2C3E50;               /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;    /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;           /* Coins arrondis */\n"
"    padding: 6px;                 /* Espacement int\303\251rieur */\n"
"    font-size: 13px;              /* Taille de la police \303\251quilibr\303\251e */\n"
"    selection-background-color: #5DADE2; /* Bleu clair pour la s\303\251lection du texte */\n"
"    selection-color: white;       /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"/* Style lorsque le QLineEdit est en focus */\n"
"QLineEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
"\n"
"/* Style d'erreur : bordure rouge */\n"
"QLineEdit.error {\n"
"    border: 2px solid "
                        "red;  /* Bordure rouge en cas d'erreur */\n"
"}\n"
""));
        btnsupprimer = new QPushButton(widget);
        btnsupprimer->setObjectName("btnsupprimer");
        btnsupprimer->setGeometry(QRect(1120, 360, 101, 31));
        btnsupprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"/* Lorsque le bouton est survol\303\251 */\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"/* Lorsque le bouton est press\303\251 */\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on"
                        " clique */\n"
"}\n"
"\n"
"/* Lorsque le bouton est d\303\251sactiv\303\251 */\n"
"QPushButton:disabled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;  /* Bordure gris clair pour l'inactivit\303\251 */\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1250, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        projet->setText(QCoreApplication::translate("MainWindow", "Projects", nullptr));
        client->setText(QCoreApplication::translate("MainWindow", "Clients", nullptr));
        ressources->setText(QCoreApplication::translate("MainWindow", "Ressources", nullptr));
        formations->setText(QCoreApplication::translate("MainWindow", "Formations", nullptr));
        tache->setText(QCoreApplication::translate("MainWindow", "T\303\242che", nullptr));
        architecte->setText(QCoreApplication::translate("MainWindow", "Architecte", nullptr));
        deconnecter->setText(QCoreApplication::translate("MainWindow", "D\303\251connecter", nullptr));
        logo->setText(QString());
        lineEdit_nom->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "R\303\264le", nullptr));
        annulerEvent->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        comboBox_question->setItemText(1, QCoreApplication::translate("MainWindow", "Dans quelle ville \303\252tes-vous n\303\251(e) ?", nullptr));
        comboBox_question->setItemText(2, QCoreApplication::translate("MainWindow", "Quel est le nom de votre meilleur ami ?", nullptr));

        lineEdit_response->setPlaceholderText(QCoreApplication::translate("MainWindow", "reponse", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Choisissez une question et r\303\251pondez-y", nullptr));
        exportProjet->setText(QCoreApplication::translate("MainWindow", "Exporter pdf", nullptr));
        BouttonRechProjet->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        taperRech->setText(QString());
        taperRech->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez un nom ou un pr\303\251nom", nullptr));
        tri->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Ajouter un architecte", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Statistiques sur les heures suppl\303\251mentaires des architectes", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "plus de 50 heures", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "entre 20 et 50 heures", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", " moins de 20 heures", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#222d52;\">Trier par Nom:</span></p></body></html>", nullptr));
        lineEdit_IDS->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        btnsupprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
