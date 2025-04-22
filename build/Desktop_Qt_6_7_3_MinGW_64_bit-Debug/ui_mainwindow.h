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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
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
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_nom;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *pushButtonajouter;
    QPushButton *pushButton_modifier;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineEdit_description;
    QDateEdit *dateEdit_finDate;
    QDateEdit *dateEdit_debutDate;
    QComboBox *comboBox_etat;
    QLineEdit *lineEdit_IDS;
    QPushButton *btnsupprimer;
    QPushButton *pushButton_micro;
    QPushButton *pushButton_exportPDF;
    QPushButton *BouttonRechProjet;
    QLineEdit *lineEdit_recherche;
    QPushButton *tri;
    QLabel *label;
    QWidget *widget_4;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton_statistique;
    QFrame *Statistiques;
    QCalendarWidget *calendarWidget;
    QTextEdit *taskDetails;
    QLabel *label_11;
    QPushButton *pushButton;
    QPushButton *exportProjet_2;
    QTableView *tableView;
    QLineEdit *lineEdit_debutDatee;
    QLineEdit *lineEdit_finDatee;
    QLineEdit *lineEdit_etat;
    QComboBox *comboBox_tri;
    QPushButton *pushButton_stats;
    QLabel *Afficher_statistiques;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1260, 662);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1251, 600));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgba(240, 240, 240, 1); /* Gris tr\303\250s clair */\n"
"    background-image: url(\"back.jpg\"); /* Ton image de fond */\n"
"    background-repeat: no-repeat; /* Evite la r\303\251p\303\251tition de l'image */\n"
"    background-position: center; /* Centre l'image */\n"
"    background-size: cover; /* Couvre toute la surface du widget */\n"
"}\n"
""));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 140, 580));
        widget_2->setStyleSheet(QString::fromUtf8("/* Style g\303\251n\303\251ral du QGroupBox */\n"
"QWidget {\n"
"    border: none; /* Supprime le cadre du groupe */\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1,\n"
"        stop:0 rgba(34, 32, 82, 255),\n"
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
"QPushButton:pressed {\n"
""
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
"    qproperty-icon: url(C:/Users/user/OneDrive/Documents/archi/engineer.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#projet {\n"
"    qproperty-icon: url(C:/Users/user/OneDrive/Documents/archi/dossier.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#tache {\n"
"    qproperty-icon: url(C:/Users/user/OneDrive/Documents/archi/"
                        "taches.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#client {\n"
"    qproperty-icon:url(C:/Users/user/OneDrive/Documents/archi/user.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#formations {\n"
"    qproperty-icon:url(C:/Users/user/OneDrive/Documents/archi/learning.png);\n"
"  qproperty-iconSize: 24px 24px;\n"
"}\n"
"QPushButton#ressources {\n"
"    qproperty-icon:url(C:/Users/user/OneDrive/Documents/archi/loan.png);\n"
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
        tache->setGeometry(QRect(0, 195, 142, 62));
        tache->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:  #ffffff;\n"
"\n"
"    color: black;  /* D\303\251finir la couleur du texte en noir */\n"
"    border: 1px solid black;  /* Optionnel : pour ajouter une bordure noire */\n"
"}\n"
""));
        architecte = new QPushButton(widget_2);
        architecte->setObjectName("architecte");
        architecte->setGeometry(QRect(0, 75, 142, 62));
        architecte->setStyleSheet(QString::fromUtf8(""));
        deconnecter = new QPushButton(widget_2);
        deconnecter->setObjectName("deconnecter");
        deconnecter->setGeometry(QRect(0, 480, 141, 62));
        deconnecter->setStyleSheet(QString::fromUtf8("color:rgb(170, 0, 0)"));
        logo = new QPushButton(widget_2);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 10, 140, 81));
        logo->setStyleSheet(QString::fromUtf8("QPushButton#logo {\n"
"    qproperty-icon: url(C:/Users/user/OneDrive/Documents/archi/logo.png);\n"
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
        widget_3->setGeometry(QRect(150, 20, 251, 411));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #eee5d3;\n"
"    border: 1px solid black;   /* Cadre noir fin (1px) */\n"
"      border-radius: 20px; /* Coins arrondis */      /* Coins arrondis */\n"
"}\n"
"\n"
"QWidget > * {\n"
"    border: none;              /* D\303\251sactive la bordure pour les \303\251l\303\251ments enfants */\n"
"}\n"
""));
        lineEdit_ID = new QLineEdit(widget_3);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(90, 50, 151, 31));
        lineEdit_ID->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_nom = new QLineEdit(widget_3);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(90, 90, 151, 31));
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
        label_2 = new QLabel(widget_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 50, 61, 31));
        QFont font;
        font.setBold(true);
        label_2->setFont(font);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 130, 81, 31));
        label_3->setFont(font);
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 260, 61, 16));
        label_5->setFont(font);
        pushButtonajouter = new QPushButton(widget_3);
        pushButtonajouter->setObjectName("pushButtonajouter");
        pushButtonajouter->setGeometry(QRect(20, 360, 80, 31));
        pushButtonajouter->setStyleSheet(QString::fromUtf8("QPushButton#pushButtonajouter {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton#pushButtonajouter:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton#pushButtonajouter:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"QPushButton#p"
                        "ushButtonajouter:disabled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        pushButton_modifier = new QPushButton(widget_3);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(120, 360, 80, 31));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_modifier {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton#pushButton_modifier:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton#pushButton_modifier:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"QPushBu"
                        "tton#pushButton_modifier:disabled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        label_12 = new QLabel(widget_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(10, 90, 81, 31));
        label_12->setFont(font);
        label_13 = new QLabel(widget_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 180, 61, 16));
        label_13->setFont(font);
        label_14 = new QLabel(widget_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 220, 81, 16));
        label_14->setFont(font);
        lineEdit_description = new QLineEdit(widget_3);
        lineEdit_description->setObjectName("lineEdit_description");
        lineEdit_description->setGeometry(QRect(90, 130, 151, 31));
        lineEdit_description->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        dateEdit_finDate = new QDateEdit(widget_3);
        dateEdit_finDate->setObjectName("dateEdit_finDate");
        dateEdit_finDate->setGeometry(QRect(90, 250, 151, 31));
        dateEdit_finDate->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
"QDateEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        dateEdit_debutDate = new QDateEdit(widget_3);
        dateEdit_debutDate->setObjectName("dateEdit_debutDate");
        dateEdit_debutDate->setGeometry(QRect(90, 210, 151, 31));
        dateEdit_debutDate->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
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
"QDateEdit:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        comboBox_etat = new QComboBox(widget_3);
        comboBox_etat->setObjectName("comboBox_etat");
        comboBox_etat->setGeometry(QRect(80, 170, 161, 31));
        comboBox_etat->setStyleSheet(QString::fromUtf8("QComboBox{\n"
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
"QComboBox:focus {\n"
"    border: 2px solid #222D52;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        lineEdit_IDS = new QLineEdit(widget_3);
        lineEdit_IDS->setObjectName("lineEdit_IDS");
        lineEdit_IDS->setGeometry(QRect(20, 390, 113, 26));
        btnsupprimer = new QPushButton(widget_3);
        btnsupprimer->setObjectName("btnsupprimer");
        btnsupprimer->setGeometry(QRect(150, 390, 93, 29));
        pushButton_micro = new QPushButton(widget_3);
        pushButton_micro->setObjectName("pushButton_micro");
        pushButton_micro->setGeometry(QRect(110, 320, 93, 29));
        pushButton_exportPDF = new QPushButton(widget);
        pushButton_exportPDF->setObjectName("pushButton_exportPDF");
        pushButton_exportPDF->setGeometry(QRect(410, 30, 131, 31));
        pushButton_exportPDF->setStyleSheet(QString::fromUtf8("QPushButton#exportProjet {\n"
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
        lineEdit_recherche = new QLineEdit(widget);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(650, 30, 191, 31));
        lineEdit_recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;    /* Fond blanc pour une bonne lisibilit\303\251 */\n"
"    color: #2C3E50;               /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;    /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;           /* Coins arrondis */\n"
"    padding: 6px;                 /* Espacement int\303\251rieur */\n"
"    font-size: 13px;              /* Taille de la police \303\251quilibr\303\251e */\n"
"    selection-background-color: #5DADE2; /* Bleu clair pour la s\303\251lection du texte */\n"
"    selection-color: white;       /* Texte blanc quand s\303\251lectionn\303\251 */\n"
"\n"
"\n"
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
        label->setGeometry(QRect(170, 20, 181, 31));
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
        widget_4->setGeometry(QRect(410, 360, 821, 231));
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
"    background-image: url(\"C:/Users/user/OneDrive/Documents/archi/stat.png\");\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"}\n"
""));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 10, 261, 16));
        label_4->setFont(font);
        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(640, 50, 71, 16));
        label_9 = new QLabel(widget_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(640, 90, 71, 16));
        label_10 = new QLabel(widget_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(640, 70, 61, 16));
        pushButton_statistique = new QPushButton(widget_4);
        pushButton_statistique->setObjectName("pushButton_statistique");
        pushButton_statistique->setGeometry(QRect(630, 10, 93, 29));
        pushButton_statistique->setStyleSheet(QString::fromUtf8("\n"
"QPushButton#pushButton_statistique {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton#pushButton_statistique:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton#pushButton_modifier:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
""
                        "QPushButton#pushButton_statistique:disabled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        Statistiques = new QFrame(widget_4);
        Statistiques->setObjectName("Statistiques");
        Statistiques->setGeometry(QRect(370, 30, 241, 131));
        Statistiques->setFrameShape(QFrame::Shape::StyledPanel);
        Statistiques->setFrameShadow(QFrame::Shadow::Raised);
        calendarWidget = new QCalendarWidget(widget_4);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(20, 10, 321, 211));
        taskDetails = new QTextEdit(widget_4);
        taskDetails->setObjectName("taskDetails");
        taskDetails->setGeometry(QRect(360, 150, 104, 75));
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(1060, 40, 101, 21));
        label_11->setFont(font);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(550, 30, 31, 31));
        pushButton->setStyleSheet(QString::fromUtf8(".QPushButton {\n"
"    background-image: url(\"C:/Users/user/OneDrive/Documents/archi/voc1.png\");\n"
"    background-size: cover; /* Ajuste l'image pour remplir l'\303\251l\303\251ment */\n"
"    background-repeat: no-repeat; /* Emp\303\252che la r\303\251p\303\251tition de l\342\200\231image */\n"
"    width: 24px;  /* Largeur du conteneur */\n"
"    height: 24px; /* Hauteur du conteneur */\n"
"}"));
        exportProjet_2 = new QPushButton(widget);
        exportProjet_2->setObjectName("exportProjet_2");
        exportProjet_2->setGeometry(QRect(260, 470, 131, 61));
        exportProjet_2->setStyleSheet(QString::fromUtf8("QPushButton#exportProjet_2 {\n"
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
"QPushButton#exportProjet_2"
                        ":disabled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(420, 70, 761, 281));
        tableView->horizontalHeader()->setDefaultSectionSize(135);
        tableView->verticalHeader()->setDefaultSectionSize(41);
        lineEdit_debutDatee = new QLineEdit(widget);
        lineEdit_debutDatee->setObjectName("lineEdit_debutDatee");
        lineEdit_debutDatee->setGeometry(QRect(170, 500, 121, 31));
        lineEdit_debutDatee->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_finDatee = new QLineEdit(widget);
        lineEdit_finDatee->setObjectName("lineEdit_finDatee");
        lineEdit_finDatee->setGeometry(QRect(150, 460, 121, 31));
        lineEdit_finDatee->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_etat = new QLineEdit(widget);
        lineEdit_etat->setObjectName("lineEdit_etat");
        lineEdit_etat->setGeometry(QRect(280, 440, 121, 31));
        lineEdit_etat->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        comboBox_tri = new QComboBox(widget);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName("comboBox_tri");
        comboBox_tri->setGeometry(QRect(1170, 40, 76, 26));
        pushButton_stats = new QPushButton(centralwidget);
        pushButton_stats->setObjectName("pushButton_stats");
        pushButton_stats->setGeometry(QRect(810, 600, 93, 29));
        Afficher_statistiques = new QLabel(centralwidget);
        Afficher_statistiques->setObjectName("Afficher_statistiques");
        Afficher_statistiques->setGeometry(QRect(950, 590, 141, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1260, 26));
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
        label_2->setText(QCoreApplication::translate("MainWindow", "tacheID", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "finDate", nullptr));
        pushButtonajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "tacheName", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "tachEtat", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "debutDate", nullptr));
        btnsupprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        pushButton_micro->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_exportPDF->setText(QCoreApplication::translate("MainWindow", "Exporter pdf", nullptr));
        BouttonRechProjet->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        lineEdit_recherche->setText(QString());
        lineEdit_recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez un nom ou un pr\303\251nom", nullptr));
        tri->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Ajouter un architecte", nullptr));
        label_6->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Statistiques sur description de la t\303\242che ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "En attente", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Termin\303\251e", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "En cours", nullptr));
        pushButton_statistique->setText(QCoreApplication::translate("MainWindow", "static", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#222d52;\">Trier par Date:</span></p></body></html>", nullptr));
        pushButton->setText(QString());
        exportProjet_2->setText(QCoreApplication::translate("MainWindow", "calendrier", nullptr));
        comboBox_tri->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("MainWindow", "Date de d\303\251but", nullptr));
        comboBox_tri->setItemText(2, QCoreApplication::translate("MainWindow", "Date de fin", nullptr));

        pushButton_stats->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        Afficher_statistiques->setText(QCoreApplication::translate("MainWindow", "Afficher Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
