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
    QLineEdit *project_id;
    QLineEdit *project_name;
    QLineEdit *project_name_2;
    QLineEdit *project_type;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *ajouterEvent;
    QPushButton *annulerEvent;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *project_name_3;
    QLineEdit *project_name_4;
    QLineEdit *project_name_5;
    QTableWidget *tableWidget;
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
    QPushButton *pushButton;
    QPushButton *exportProjet_2;
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
        widget->setGeometry(QRect(-10, 0, 1251, 600));
        widget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: rgba(240, 240, 240, 1); /* Gris tr\303\250s clair */\n"
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
        widget_3->setGeometry(QRect(150, 20, 221, 411));
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
        project_id = new QLineEdit(widget_3);
        project_id->setObjectName("project_id");
        project_id->setGeometry(QRect(90, 50, 121, 31));
        project_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        project_name = new QLineEdit(widget_3);
        project_name->setObjectName("project_name");
        project_name->setGeometry(QRect(90, 90, 121, 31));
        project_name->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        project_name_2 = new QLineEdit(widget_3);
        project_name_2->setObjectName("project_name_2");
        project_name_2->setGeometry(QRect(90, 210, 121, 31));
        project_name_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        project_type = new QLineEdit(widget_3);
        project_type->setObjectName("project_type");
        project_type->setGeometry(QRect(90, 290, 121, 31));
        project_type->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        label_2->setGeometry(QRect(20, 50, 61, 31));
        QFont font;
        font.setBold(true);
        label_2->setFont(font);
        label_3 = new QLabel(widget_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 130, 81, 31));
        label_3->setFont(font);
        label_4 = new QLabel(widget_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 300, 49, 16));
        label_4->setFont(font);
        label_5 = new QLabel(widget_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 220, 61, 16));
        label_5->setFont(font);
        ajouterEvent = new QPushButton(widget_3);
        ajouterEvent->setObjectName("ajouterEvent");
        ajouterEvent->setGeometry(QRect(20, 360, 80, 31));
        ajouterEvent->setStyleSheet(QString::fromUtf8("QPushButton#ajouterEvent {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton#ajouterEvent:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton#ajouterEvent:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"}\n"
"\n"
"QPushButton#ajouterEvent:dis"
                        "abled {\n"
"    background-color: #95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        annulerEvent = new QPushButton(widget_3);
        annulerEvent->setObjectName("annulerEvent");
        annulerEvent->setGeometry(QRect(120, 360, 80, 31));
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
        label_12->setGeometry(QRect(10, 90, 81, 31));
        label_12->setFont(font);
        label_13 = new QLabel(widget_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(10, 180, 61, 16));
        label_13->setFont(font);
        label_14 = new QLabel(widget_3);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(10, 260, 81, 16));
        label_14->setFont(font);
        project_name_3 = new QLineEdit(widget_3);
        project_name_3->setObjectName("project_name_3");
        project_name_3->setGeometry(QRect(90, 170, 121, 31));
        project_name_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        project_name_4 = new QLineEdit(widget_3);
        project_name_4->setObjectName("project_name_4");
        project_name_4->setGeometry(QRect(90, 250, 121, 31));
        project_name_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        project_name_5 = new QLineEdit(widget_3);
        project_name_5->setObjectName("project_name_5");
        project_name_5->setGeometry(QRect(90, 130, 121, 31));
        project_name_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        tableWidget = new QTableWidget(widget);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
        QFont font1;
        font1.setBold(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font1);
        __qtablewidgetitem->setBackground(QColor(223, 197, 254));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
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
        __qtablewidgetitem4->setFont(font1);
        __qtablewidgetitem4->setBackground(QColor(223, 197, 254));
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignCenter);
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem15);
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
        tableWidget->setItem(1, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(1, 4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(1, 7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(1, 8, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setItem(2, 4, __qtablewidgetitem29);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(380, 80, 851, 311));
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
"    gridline-color: #5D6D7E;\n"
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
"    max-width: 40px;  /* R\303\251d"
                        "uction encore plus prononc\303\251e */\n"
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
        widget_4->setGeometry(QRect(490, 420, 741, 171));
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
        label_7 = new QLabel(widget_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 10, 331, 16));
        label_7->setFont(font);
        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(450, 34, 121, 16));
        label_9 = new QLabel(widget_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(450, 110, 151, 16));
        label_10 = new QLabel(widget_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(450, 72, 141, 16));
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(1100, 40, 101, 21));
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
        widget_2->raise();
        widget_3->raise();
        exportProjet->raise();
        BouttonRechProjet->raise();
        taperRech->raise();
        tri->raise();
        label->raise();
        tableWidget->raise();
        widget_4->raise();
        label_11->raise();
        pushButton->raise();
        exportProjet_2->raise();
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
        label_4->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "finDate", nullptr));
        ajouterEvent->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        annulerEvent->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "tacheName", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "tachEtat", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "debutDate", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "tacheID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "tacheName", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "description", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "tachEtat", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "finDate", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "debutDate", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "tacheStatus", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "nbr des heures suppl\303\251mentaire\n"
"", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "6", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        exportProjet->setText(QCoreApplication::translate("MainWindow", "Exporter pdf", nullptr));
        BouttonRechProjet->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        taperRech->setText(QString());
        taperRech->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez un nom ou un pr\303\251nom", nullptr));
        tri->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Ajouter un architecte", nullptr));
        label_6->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "Statistiques sur statut de la t\303\242che ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "En attente", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Termin\303\251e", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "En cours", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#222d52;\">Trier par Date:</span></p></body></html>", nullptr));
        pushButton->setText(QString());
        exportProjet_2->setText(QCoreApplication::translate("MainWindow", "calendrier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
