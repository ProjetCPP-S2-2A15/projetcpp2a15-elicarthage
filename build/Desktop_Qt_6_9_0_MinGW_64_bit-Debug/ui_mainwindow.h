/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
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
    QLineEdit *lineEdit_Nom;
    QLineEdit *lineEdit_Type;
    QLineEdit *lineEdit_Etat;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *ajouter;
    QLabel *label_13;
    QLineEdit *lineEdit_Quantite;
    QLineEdit *lineEdit_Localisation;
    QLabel *label_14;
    QLineEdit *lineEdit_Fournisseur;
    QLabel *label_4;
    QPushButton *pushButton_Rechercher;
    QLineEdit *lineEdit_Recherche;
    QLabel *label;
    QLabel *label_11;
    QTableWidget *tableWidget;
    QWidget *chartview;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *widgetGraphLayout;
    QPushButton *pushButton_exporterpdf;
    QPushButton *trilogiciel;
    QWidget *widget_4;
    QLabel *label_12;
    QLineEdit *lineEdit_Id;
    QLabel *label_6;
    QPushButton *supprimer;
    QPushButton *trimateriel;
    QPushButton *annuletri;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1396, 716);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-30, 0, 1431, 661));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgba(240, 240, 240, 1); /* Gris tr\303\250s clair */\n"
"}\n"
""));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(70, 60, 140, 580));
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
"    qproperty-icon: url(C:/Users/tez/Desktop/dash/images/engineer.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#projet {\n"
"    qproperty-icon: url(C:/Users/tez/Desktop/dash/images/dossier.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#tache {\n"
"    qproperty-icon: url(C:/Users/tez/Desktop/dash/images/taches.png)"
                        ";\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#client {\n"
"    qproperty-icon:url(C:/Users/tez/Desktop/dash/images/user.png);\n"
"    qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#formations {\n"
"    qproperty-icon:url(C:/Users/tez/Desktop/dash/images/learning.png);\n"
"  qproperty-iconSize: 24px 24px;\n"
"}\n"
"QPushButton#ressources {\n"
"    qproperty-icon:url(C:/Users/tez/Desktop/dash/images/loan.png);\n"
"  qproperty-iconSize: 24px 24px;\n"
"}\n"
"\n"
"QPushButton#deconnecter {\n"
"    qproperty-icon:url(C:/Users/tez/Desktop/dash/images/deconnexion.png);\n"
"  qproperty-iconSize: 24px 24px;\n"
"}\n"
"QPushButton#logo {\n"
"    qproperty-icon: url(C:/Users/tez/Desktop/dash/imageslogo.png);\n"
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
        ressources->setGeometry(QRect(0, 315, 142, 62));
        ressources->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color:  #ffffff;\n"
"\n"
"    color: black;  /* D\303\251finir la couleur du texte en noir */\n"
"    border: 1px solid black;  /* Optionnel : pour ajouter une bordure noire */\n"
"}\n"
""));
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
"    background-color:  transparent;\n"
"\n"
"    color: white;  /* D\303\251finir la couleur du texte en noir */\n"
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
"    qproperty-icon: url(C:/Users/tez/Pictures/script/projet (1)/projet/dash/images/logo.png);\n"
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
        widget_3->setGeometry(QRect(220, 80, 201, 571));
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
        lineEdit_Nom = new QLineEdit(widget_3);
        lineEdit_Nom->setObjectName("lineEdit_Nom");
        lineEdit_Nom->setGeometry(QRect(10, 40, 141, 31));
        lineEdit_Nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_Type = new QLineEdit(widget_3);
        lineEdit_Type->setObjectName("lineEdit_Type");
        lineEdit_Type->setGeometry(QRect(10, 120, 141, 31));
        lineEdit_Type->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_Etat = new QLineEdit(widget_3);
        lineEdit_Etat->setObjectName("lineEdit_Etat");
        lineEdit_Etat->setGeometry(QRect(10, 200, 141, 31));
        lineEdit_Etat->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_2->setGeometry(QRect(10, 20, 49, 16));
        QFont font;
        font.setBold(true);
        label_2->setFont(font);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 90, 49, 16));
        label_3->setFont(font);
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 170, 49, 16));
        label_5->setFont(font);
        ajouter = new QPushButton(widget_3);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(10, 470, 80, 31));
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}"));
        label_13 = new QLabel(widget_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 320, 71, 16));
        label_13->setFont(font);
        lineEdit_Quantite = new QLineEdit(widget_3);
        lineEdit_Quantite->setObjectName("lineEdit_Quantite");
        lineEdit_Quantite->setGeometry(QRect(10, 350, 141, 31));
        lineEdit_Quantite->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_Localisation = new QLineEdit(widget_3);
        lineEdit_Localisation->setObjectName("lineEdit_Localisation");
        lineEdit_Localisation->setGeometry(QRect(10, 420, 141, 31));
        lineEdit_Localisation->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_14 = new QLabel(widget_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 390, 91, 16));
        label_14->setFont(font);
        lineEdit_Fournisseur = new QLineEdit(widget_3);
        lineEdit_Fournisseur->setObjectName("lineEdit_Fournisseur");
        lineEdit_Fournisseur->setGeometry(QRect(11, 278, 122, 35));
        lineEdit_Fournisseur->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(11, 251, 122, 20));
        label_4->setFont(font);
        pushButton_Rechercher = new QPushButton(widget);
        pushButton_Rechercher->setObjectName("pushButton_Rechercher");
        pushButton_Rechercher->setGeometry(QRect(700, 30, 101, 31));
        pushButton_Rechercher->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}"));
        lineEdit_Recherche = new QLineEdit(widget);
        lineEdit_Recherche->setObjectName("lineEdit_Recherche");
        lineEdit_Recherche->setGeometry(QRect(560, 30, 131, 31));
        lineEdit_Recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 50, 181, 31));
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
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(810, 30, 121, 20));
        label_11->setFont(font);
        tableWidget = new QTableWidget(widget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QFont font1;
        font1.setBold(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        __qtablewidgetitem->setBackground(QColor(223, 197, 254));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        __qtablewidgetitem1->setBackground(QColor(223, 197, 254));
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        __qtablewidgetitem2->setBackground(QColor(223, 197, 254));
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        __qtablewidgetitem3->setBackground(QColor(223, 197, 254));
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(0, 4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(0, 7, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem29);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(440, 80, 871, 311));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(10, 10));
        tableWidget->setBaseSize(QSize(10, 10));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F8F9FA;   /* Fond gris tr\303\250s clair */\n"
"    color: #1B2631;              /* Texte bleu fonc\303\251 */\n"
"    border: 2px solid #1F4E78;   /* Bordure ext\303\251rieure */\n"
"    gridline-color: #5D6D7E;     \n"
"    font-size: 12px;  /* R\303\251duction de la taille de police */\n"
"    selection-background-color: #D6EAF8;\n"
"    selection-color: #1B2631;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 1px; /* R\303\251duction maximale du padding */\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
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
"    max-width: 40px;  /* R\303"
                        "\251duction encore plus prononc\303\251e */\n"
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
"QTableWidget QHeaderView::section:vertical {\n"
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
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        tableWidget->setAlternatingRowColors(false);
        tableWidget->setIconSize(QSize(0, 0));
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(180);
        tableWidget->verticalHeader()->setDefaultSectionSize(50);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        chartview = new QWidget(widget);
        chartview->setObjectName("chartview");
        chartview->setGeometry(QRect(440, 410, 511, 221));
        chartview->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        horizontalLayoutWidget = new QWidget(chartview);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 511, 221));
        widgetGraphLayout = new QHBoxLayout(horizontalLayoutWidget);
        widgetGraphLayout->setObjectName("widgetGraphLayout");
        widgetGraphLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_exporterpdf = new QPushButton(widget);
        pushButton_exporterpdf->setObjectName("pushButton_exporterpdf");
        pushButton_exporterpdf->setGeometry(QRect(440, 30, 111, 31));
        pushButton_exporterpdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"QPushButton#BouttonRechProjet:d"
                        "isabled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        trilogiciel = new QPushButton(widget);
        trilogiciel->setObjectName("trilogiciel");
        trilogiciel->setGeometry(QRect(920, 30, 111, 31));
        trilogiciel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}"));
        widget_4 = new QWidget(widget);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(1030, 410, 281, 121));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #eee5d3;   /* Cadre noir fin (1px) */\n"
"      border-radius: 20px; /* Coins arrondis */      /* Coins arrondis */\n"
"}"));
        label_12 = new QLabel(widget_4);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 60, 49, 16));
        label_12->setFont(font);
        lineEdit_Id = new QLineEdit(widget_4);
        lineEdit_Id->setObjectName("lineEdit_Id");
        lineEdit_Id->setGeometry(QRect(20, 80, 141, 31));
        lineEdit_Id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_6 = new QLabel(widget_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 10, 201, 31));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #E8DDC8; /* Couleur de fond */\n"
"    color: white; /* Texte en blanc pour contraste */\n"
"    font-weight: bold; /* Texte en gras */\n"
"    font-size: 14px; /* Taille du texte */\n"
"    padding: 8px 15px; /* Espacement int\303\251rieur */\n"
"    border-radius: 10px; /* Coins arrondis */\n"
"    text-align: center; /* Centrage du texte */\n"
"}\n"
""));
        supprimer = new QPushButton(widget_4);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(170, 80, 91, 31));
        supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}"));
        trimateriel = new QPushButton(widget);
        trimateriel->setObjectName("trimateriel");
        trimateriel->setGeometry(QRect(1040, 30, 111, 31));
        trimateriel->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}"));
        annuletri = new QPushButton(widget);
        annuletri->setObjectName("annuletri");
        annuletri->setGeometry(QRect(1160, 30, 111, 31));
        annuletri->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1396, 26));
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
        label_2->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Etat", nullptr));
        ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Localisation", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Fournisseur", nullptr));
        pushButton_Rechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        lineEdit_Recherche->setText(QCoreApplication::translate("MainWindow", "Entrer un nom ", nullptr));
        lineEdit_Recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez un nom ou un pr\303\251nom", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ajouter une ressource", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#222d52;\">Trier par Type:</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID_ressource", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Etat", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Fournisseur", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Localisation", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "6", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButton_exporterpdf->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        trilogiciel->setText(QCoreApplication::translate("MainWindow", "par logiciel", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Supprimer une ressource", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        trimateriel->setText(QCoreApplication::translate("MainWindow", "par materiel", nullptr));
        annuletri->setText(QCoreApplication::translate("MainWindow", "annuler le tri", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
