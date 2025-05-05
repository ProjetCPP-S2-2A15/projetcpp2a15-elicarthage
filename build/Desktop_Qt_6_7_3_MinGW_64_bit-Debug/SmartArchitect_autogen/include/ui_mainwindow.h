/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget_2;
    QLabel *label_79;
    QLabel *label_80;
    QLabel *label_81;
    QLabel *label_82;
    QTabWidget *tabWidget_6;
    QWidget *tab_7;
    QGroupBox *groupBox_5;
    QTableWidget *projectTable;
    QPushButton *pushButton_25;
    QLabel *label_83;
    QComboBox *rechProjet_5;
    QPushButton *BouttonRechProjet_5;
    QPushButton *pdfProjet;
    QComboBox *TriProjet_5;
    QPushButton *pushButton_31;
    QLabel *label_84;
    QLabel *label_85;
    QPushButton *pushButton_36;
    QLineEdit *taperRech_5;
    QLabel *label_86;
    QPushButton *pushButton_26;
    QPushButton *pushButton_37;
    QPushButton *pushButton_38;
    QPushButton *pushButton_39;
    QPushButton *pushButton_40;
    QWidget *widget_4;
    QLineEdit *project_id;
    QLineEdit *project_name;
    QLineEdit *project_description;
    QLineEdit *project_type;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *ajouterProjet;
    QPushButton *modifierProjet;
    QDateEdit *project_date_deb;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *project_budget;
    QLineEdit *project_etat;
    QPushButton *suppProjet;
    QPushButton *TriButton;
    QPushButton *generateContractButton;
    QLabel *label_88;
    QLabel *label_89;
    QLabel *label_90;
    QWidget *tab_2;
    QWidget *widget_3;
    QLabel *label_87;
    QLabel *label_91;
    QLabel *label_92;
    QLabel *label_93;
    QLabel *label_105;
    QLabel *label_106;
    QLabel *label_107;
    QGroupBox *groupBox_6;
    QGroupBox *serverGroupBox;
    QLabel *serverIpLabel;
    QLineEdit *serverIpLineEdit;
    QLabel *serverPortLabel;
    QSpinBox *serverPortSpinBox;
    QPushButton *startServerButton;
    QTextEdit *chatTextEdit;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QLabel *statusLabel;
    QFrame *portSpinBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 546);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(-10, 0, 1481, 661));
        tab = new QWidget();
        tab->setObjectName("tab");
        widget_2 = new QWidget(tab);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, -40, 1431, 841));
        widget_2->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));
        label_79 = new QLabel(widget_2);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(1180, 30, 31, 21));
        label_79->setPixmap(QPixmap(QString::fromUtf8("../../../../../power-off.png")));
        label_79->setScaledContents(true);
        label_80 = new QLabel(widget_2);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(610, 170, 20, 20));
        label_80->setPixmap(QPixmap(QString::fromUtf8("../../../../../magnifier.png")));
        label_80->setScaledContents(true);
        label_81 = new QLabel(widget_2);
        label_81->setObjectName("label_81");
        label_81->setGeometry(QRect(440, 20, 71, 16));
        label_81->setPixmap(QPixmap(QString::fromUtf8("../../../../../461537616_2828568600639017_3927034258301617377_n.png")));
        label_81->setScaledContents(true);
        label_82 = new QLabel(widget_2);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(1050, 30, 21, 21));
        label_82->setPixmap(QPixmap(QString::fromUtf8("../../../../../notification.png")));
        label_82->setScaledContents(true);
        tabWidget_6 = new QTabWidget(widget_2);
        tabWidget_6->setObjectName("tabWidget_6");
        tabWidget_6->setGeometry(QRect(0, 50, 1321, 621));
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        groupBox_5 = new QGroupBox(tab_7);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(0, 0, 1641, 600));
        projectTable = new QTableWidget(groupBox_5);
        if (projectTable->columnCount() < 7)
            projectTable->setColumnCount(7);
        QFont font;
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        __qtablewidgetitem->setBackground(QColor(223, 197, 254));
        projectTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        __qtablewidgetitem1->setBackground(QColor(223, 197, 254));
        projectTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        __qtablewidgetitem2->setBackground(QColor(223, 197, 254));
        projectTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        __qtablewidgetitem3->setBackground(QColor(223, 197, 254));
        projectTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        projectTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        projectTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        projectTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (projectTable->rowCount() < 6)
            projectTable->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignCenter);
        projectTable->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignCenter);
        projectTable->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignCenter);
        projectTable->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignCenter);
        projectTable->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignCenter);
        projectTable->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignCenter);
        projectTable->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        projectTable->setItem(0, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        projectTable->setItem(0, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        projectTable->setItem(0, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        projectTable->setItem(0, 3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        projectTable->setItem(1, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        projectTable->setItem(1, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        projectTable->setItem(1, 2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        projectTable->setItem(1, 3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        projectTable->setItem(2, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        projectTable->setItem(2, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        projectTable->setItem(2, 2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        projectTable->setItem(2, 3, __qtablewidgetitem24);
        projectTable->setObjectName("projectTable");
        projectTable->setEnabled(true);
        projectTable->setGeometry(QRect(410, 130, 651, 301));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(projectTable->sizePolicy().hasHeightForWidth());
        projectTable->setSizePolicy(sizePolicy);
        projectTable->setMinimumSize(QSize(10, 10));
        projectTable->setBaseSize(QSize(10, 10));
        projectTable->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F8F9FA;   /* Fond gris tr\303\250s clair pour une meilleure lisibilit\303\251 */\n"
"    color: #1B2631;              /* Texte bleu fonc\303\251/gris anthracite */\n"
"    border: 2px solid #1F4E78;   /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 8px;\n"
"    gridline-color: #5D6D7E;     /* Couleur des lignes de grille */\n"
"    font-size: 14px;\n"
"    selection-background-color: #D6EAF8; /* Fond bleu clair pour la s\303\251lection */\n"
"    selection-color: #1B2631;   /* Texte bleu fonc\303\251 pour l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #D6EAF8;  /* Bleu clair pour l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    color: #1B2631;             /* Texte bleu fonc\303\251 */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #1F4E78;  /* En-t\303\252te de colonne bleu fonc\303\251 */\n"
"    col"
                        "or: white;               /* Texte blanc dans l'en-t\303\252te */\n"
"    padding: 6px;\n"
"    font-weight: bold;\n"
"    border: 1px solid #154360;\n"
"}\n"
"\n"
"QHeaderView::section:hover {\n"
"    background-color: #154360;  /* Bleu plus fonc\303\251 au survol */\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #1F4E78; /* Bouton de coin en bleu fonc\303\251 */\n"
"    border: 1px solid #154360;\n"
"}\n"
""));
        projectTable->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        projectTable->setSizeAdjustPolicy(QAbstractScrollArea::SizeAdjustPolicy::AdjustIgnored);
        projectTable->setAlternatingRowColors(false);
        projectTable->setIconSize(QSize(0, 0));
        projectTable->setWordWrap(true);
        projectTable->setCornerButtonEnabled(true);
        projectTable->horizontalHeader()->setDefaultSectionSize(180);
        projectTable->verticalHeader()->setDefaultSectionSize(50);
        projectTable->verticalHeader()->setProperty("showSortIndicator", QVariant(true));
        pushButton_25 = new QPushButton(groupBox_5);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(800, 350, 71, 61));
        pushButton_25->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(170, 170, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Downloads/home-interface-symbol.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_25->setIcon(icon);
        pushButton_25->setIconSize(QSize(40, 40));
        pushButton_25->setFlat(true);
        label_83 = new QLabel(groupBox_5);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(570, 520, 101, 20));
        rechProjet_5 = new QComboBox(groupBox_5);
        rechProjet_5->addItem(QString());
        rechProjet_5->addItem(QString());
        rechProjet_5->addItem(QString());
        rechProjet_5->setObjectName("rechProjet_5");
        rechProjet_5->setGeometry(QRect(820, 90, 121, 31));
        rechProjet_5->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2C3E50;   /* Bleu fonc\303\251 professionnel */\n"
"    color: white;                /* Texte blanc pour un bon contraste */\n"
"    border: 2px solid #1F4E78;   /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #3498DB;   /* Bleu plus clair au survol */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #1F4E78;   /* Fond du bouton d\303\251roulant */\n"
"    border-left: 2px solid #154360;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #34495E;   /* Fond de la liste d\303\251roulante */\n"
"    color: white;                /* Texte blanc */\n"
"    border: 1px solid #1F4E78;\n"
"    selection-background-color: #5DADE2;  /* Bleu clair pour l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    selection-color: #1B2631;  /* Texte fonc\303\251 pour la s\303\251lection */\n"
"}\n"
""));
        BouttonRechProjet_5 = new QPushButton(groupBox_5);
        BouttonRechProjet_5->setObjectName("BouttonRechProjet_5");
        BouttonRechProjet_5->setGeometry(QRect(610, 70, 91, 31));
        BouttonRechProjet_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"    \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"    \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: "
                        "#95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        pdfProjet = new QPushButton(groupBox_5);
        pdfProjet->setObjectName("pdfProjet");
        pdfProjet->setGeometry(QRect(880, 20, 131, 31));
        pdfProjet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"    \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"    \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: "
                        "#95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        TriProjet_5 = new QComboBox(groupBox_5);
        TriProjet_5->addItem(QString());
        TriProjet_5->addItem(QString());
        TriProjet_5->addItem(QString());
        TriProjet_5->setObjectName("TriProjet_5");
        TriProjet_5->setGeometry(QRect(660, 510, 111, 31));
        TriProjet_5->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2C3E50;   /* Bleu fonc\303\251 professionnel */\n"
"    color: white;                /* Texte blanc pour un bon contraste */\n"
"    border: 2px solid #1F4E78;   /* Bordure bleu fonc\303\251 */\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"    font-size: 13px;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 2px solid #3498DB;   /* Bleu plus clair au survol */\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #1F4E78;   /* Fond du bouton d\303\251roulant */\n"
"    border-left: 2px solid #154360;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #34495E;   /* Fond de la liste d\303\251roulante */\n"
"    color: white;                /* Texte blanc */\n"
"    border: 1px solid #1F4E78;\n"
"    selection-background-color: #5DADE2;  /* Bleu clair pour l'\303\251l\303\251ment s\303\251lectionn\303\251 */\n"
"    selection-color: #1B2631;  /* Texte fonc\303\251 pour la s\303\251lection */\n"
"}\n"
""));
        pushButton_31 = new QPushButton(groupBox_5);
        pushButton_31->setObjectName("pushButton_31");
        pushButton_31->setGeometry(QRect(920, 210, 81, 51));
        pushButton_31->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../../Downloads/power-off.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_31->setIcon(icon1);
        pushButton_31->setFlat(true);
        label_84 = new QLabel(groupBox_5);
        label_84->setObjectName("label_84");
        label_84->setGeometry(QRect(1200, 40, 31, 21));
        label_84->setPixmap(QPixmap(QString::fromUtf8("../../../../../logout.png")));
        label_84->setScaledContents(true);
        label_85 = new QLabel(groupBox_5);
        label_85->setObjectName("label_85");
        label_85->setGeometry(QRect(420, 90, 56, 16));
        pushButton_36 = new QPushButton(groupBox_5);
        pushButton_36->setObjectName("pushButton_36");
        pushButton_36->setGeometry(QRect(590, 110, 31, 29));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../../Downloads/magnifier.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_36->setIcon(icon2);
        pushButton_36->setFlat(true);
        taperRech_5 = new QLineEdit(groupBox_5);
        taperRech_5->setObjectName("taperRech_5");
        taperRech_5->setGeometry(QRect(430, 70, 171, 31));
        taperRech_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"    border: 2px solid #3498DB;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}\n"
""));
        label_86 = new QLabel(groupBox_5);
        label_86->setObjectName("label_86");
        label_86->setGeometry(QRect(0, 0, 151, 601));
        label_86->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(34, 32, 82, 255), stop:1 rgba(0, 0, 0, 255));\n"
"border-radius: 10px;"));
        pushButton_26 = new QPushButton(groupBox_5);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(0, 40, 140, 60));
        pushButton_37 = new QPushButton(groupBox_5);
        pushButton_37->setObjectName("pushButton_37");
        pushButton_37->setGeometry(QRect(0, 120, 140, 60));
        pushButton_38 = new QPushButton(groupBox_5);
        pushButton_38->setObjectName("pushButton_38");
        pushButton_38->setGeometry(QRect(0, 200, 140, 60));
        pushButton_39 = new QPushButton(groupBox_5);
        pushButton_39->setObjectName("pushButton_39");
        pushButton_39->setGeometry(QRect(0, 280, 140, 60));
        pushButton_40 = new QPushButton(groupBox_5);
        pushButton_40->setObjectName("pushButton_40");
        pushButton_40->setGeometry(QRect(0, 360, 142, 62));
        pushButton_40->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"\n"
"    color: black;  /* D\303\251finir la couleur du texte en noir */\n"
"    border: 1px solid black;  /* Optionnel : pour ajouter une bordure noire */\n"
"}\n"
""));
        widget_4 = new QWidget(groupBox_5);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(160, 10, 221, 441));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #eee5d3; \n"
"    border: 1px solid black;   /* Cadre noir fin (1px) */\n"
"      border-radius: 20px; /* Coins arrondis */      /* Coins arrondis */\n"
"}\n"
"\n"
"QWidget > * {\n"
"    border: none;              /* D\303\251sactive la bordure pour les \303\251l\303\251ments enfants */\n"
"}\n"
""));
        project_id = new QLineEdit(widget_4);
        project_id->setObjectName("project_id");
        project_id->setGeometry(QRect(10, 30, 111, 31));
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
        project_name = new QLineEdit(widget_4);
        project_name->setObjectName("project_name");
        project_name->setGeometry(QRect(10, 80, 111, 31));
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
        project_description = new QLineEdit(widget_4);
        project_description->setObjectName("project_description");
        project_description->setGeometry(QRect(10, 130, 111, 31));
        project_description->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        project_type = new QLineEdit(widget_4);
        project_type->setObjectName("project_type");
        project_type->setGeometry(QRect(10, 230, 111, 31));
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
        label_2 = new QLabel(widget_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 49, 16));
        label_2->setFont(font);
        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 60, 71, 16));
        label_3->setFont(font);
        label_4 = new QLabel(widget_4);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 160, 61, 16));
        label_4->setFont(font);
        label_5 = new QLabel(widget_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 110, 61, 16));
        label_5->setFont(font);
        ajouterProjet = new QPushButton(widget_4);
        ajouterProjet->setObjectName("ajouterProjet");
        ajouterProjet->setGeometry(QRect(10, 360, 80, 31));
        ajouterProjet->setStyleSheet(QString::fromUtf8("QPushButton#ajouterEvent {\n"
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
        modifierProjet = new QPushButton(widget_4);
        modifierProjet->setObjectName("modifierProjet");
        modifierProjet->setGeometry(QRect(110, 360, 80, 31));
        modifierProjet->setStyleSheet(QString::fromUtf8("QPushButton#annulerEvent {\n"
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
        project_date_deb = new QDateEdit(widget_4);
        project_date_deb->setObjectName("project_date_deb");
        project_date_deb->setGeometry(QRect(10, 180, 111, 31));
        project_date_deb->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"    border: 2px solid #3498DB;    /* Bordure bleu plus clair au focus */\n"
"    background-color: #ECF0F1;    /* Fond gris clair subtil au focus */\n"
"}"));
        project_date_deb->setMinimumDateTime(QDateTime(QDate(2024, 1, 1), QTime(11, 0, 0)));
        project_date_deb->setMinimumDate(QDate(2024, 1, 1));
        label_6 = new QLabel(widget_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 210, 61, 16));
        label_6->setFont(font);
        label_7 = new QLabel(widget_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 260, 61, 16));
        label_7->setFont(font);
        label_8 = new QLabel(widget_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 310, 61, 16));
        label_8->setFont(font);
        project_budget = new QLineEdit(widget_4);
        project_budget->setObjectName("project_budget");
        project_budget->setGeometry(QRect(10, 280, 101, 31));
        project_budget->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        project_etat = new QLineEdit(widget_4);
        project_etat->setObjectName("project_etat");
        project_etat->setGeometry(QRect(10, 330, 111, 31));
        project_etat->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        suppProjet = new QPushButton(widget_4);
        suppProjet->setObjectName("suppProjet");
        suppProjet->setGeometry(QRect(50, 400, 91, 31));
        suppProjet->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"    \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"    \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: "
                        "#95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        TriButton = new QPushButton(groupBox_5);
        TriButton->setObjectName("TriButton");
        TriButton->setGeometry(QRect(950, 90, 91, 31));
        TriButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"    \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"    \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: "
                        "#95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        generateContractButton = new QPushButton(groupBox_5);
        generateContractButton->setObjectName("generateContractButton");
        generateContractButton->setGeometry(QRect(750, 20, 121, 31));
        generateContractButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2C3E50;  /* Bleu fonc\303\251 professionnel */\n"
"    color: white;               /* Texte blanc pour un bon contraste */\n"
"    border-radius: 6px;         /* Coins l\303\251g\303\250rement arrondis */\n"
"    padding: 6px 12px;          /* Espacement r\303\251duit pour un design plus compact */\n"
"    font-size: 13px;            /* Texte plus petit et plus \303\251l\303\251gant */\n"
"    font-weight: normal;        /* Texte normal pour un style minimaliste */\n"
"    border: 1px solid #1A252F;  /* Bordure discr\303\250te l\303\251g\303\250rement plus fonc\303\251e */\n"
"    \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"    \n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: "
                        "#95A5A6;  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        tabWidget_6->addTab(tab_7, QString());
        label_88 = new QLabel(widget_2);
        label_88->setObjectName("label_88");
        label_88->setGeometry(QRect(1240, 30, 31, 31));
        label_88->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/images/logout.png")));
        label_88->setScaledContents(true);
        label_89 = new QLabel(widget_2);
        label_89->setObjectName("label_89");
        label_89->setGeometry(QRect(1190, 30, 41, 31));
        label_89->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/images/notification.png")));
        label_89->setScaledContents(true);
        label_90 = new QLabel(widget_2);
        label_90->setObjectName("label_90");
        label_90->setGeometry(QRect(1140, 30, 41, 31));
        label_90->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/images/power-off.png")));
        label_90->setScaledContents(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        widget_3 = new QWidget(tab_2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(220, 110, 1431, 841));
        widget_3->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));
        label_87 = new QLabel(widget_3);
        label_87->setObjectName("label_87");
        label_87->setGeometry(QRect(1180, 30, 31, 21));
        label_87->setPixmap(QPixmap(QString::fromUtf8("../../../../../power-off.png")));
        label_87->setScaledContents(true);
        label_91 = new QLabel(widget_3);
        label_91->setObjectName("label_91");
        label_91->setGeometry(QRect(610, 170, 20, 20));
        label_91->setPixmap(QPixmap(QString::fromUtf8("../../../../../magnifier.png")));
        label_91->setScaledContents(true);
        label_92 = new QLabel(widget_3);
        label_92->setObjectName("label_92");
        label_92->setGeometry(QRect(440, 20, 71, 16));
        label_92->setPixmap(QPixmap(QString::fromUtf8("../../../../../461537616_2828568600639017_3927034258301617377_n.png")));
        label_92->setScaledContents(true);
        label_93 = new QLabel(widget_3);
        label_93->setObjectName("label_93");
        label_93->setGeometry(QRect(1050, 30, 21, 21));
        label_93->setPixmap(QPixmap(QString::fromUtf8("../../../../../notification.png")));
        label_93->setScaledContents(true);
        label_105 = new QLabel(widget_3);
        label_105->setObjectName("label_105");
        label_105->setGeometry(QRect(1240, 30, 31, 31));
        label_105->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/images/logout.png")));
        label_105->setScaledContents(true);
        label_106 = new QLabel(widget_3);
        label_106->setObjectName("label_106");
        label_106->setGeometry(QRect(1190, 30, 41, 31));
        label_106->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/images/notification.png")));
        label_106->setScaledContents(true);
        label_107 = new QLabel(widget_3);
        label_107->setObjectName("label_107");
        label_107->setGeometry(QRect(1140, 30, 41, 31));
        label_107->setPixmap(QPixmap(QString::fromUtf8("../../../../../Downloads/images/power-off.png")));
        label_107->setScaledContents(true);
        groupBox_6 = new QGroupBox(widget_3);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(-120, -60, 1181, 471));
        serverGroupBox = new QGroupBox(tab_2);
        serverGroupBox->setObjectName("serverGroupBox");
        serverGroupBox->setGeometry(QRect(10, 10, 431, 301));
        serverIpLabel = new QLabel(serverGroupBox);
        serverIpLabel->setObjectName("serverIpLabel");
        serverIpLabel->setGeometry(QRect(30, 30, 81, 21));
        serverIpLineEdit = new QLineEdit(serverGroupBox);
        serverIpLineEdit->setObjectName("serverIpLineEdit");
        serverIpLineEdit->setGeometry(QRect(70, 30, 113, 20));
        serverPortLabel = new QLabel(serverGroupBox);
        serverPortLabel->setObjectName("serverPortLabel");
        serverPortLabel->setGeometry(QRect(20, 72, 37, 20));
        serverPortSpinBox = new QSpinBox(serverGroupBox);
        serverPortSpinBox->setObjectName("serverPortSpinBox");
        serverPortSpinBox->setGeometry(QRect(40, 70, 42, 22));
        startServerButton = new QPushButton(serverGroupBox);
        startServerButton->setObjectName("startServerButton");
        startServerButton->setGeometry(QRect(90, 70, 80, 21));
        chatTextEdit = new QTextEdit(serverGroupBox);
        chatTextEdit->setObjectName("chatTextEdit");
        chatTextEdit->setGeometry(QRect(120, 250, 301, 41));
        messageLineEdit = new QLineEdit(serverGroupBox);
        messageLineEdit->setObjectName("messageLineEdit");
        messageLineEdit->setGeometry(QRect(22, 99, 391, 121));
        sendButton = new QPushButton(serverGroupBox);
        sendButton->setObjectName("sendButton");
        sendButton->setGeometry(QRect(340, 270, 80, 18));
        statusLabel = new QLabel(serverGroupBox);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(300, 30, 61, 20));
        portSpinBox = new QFrame(serverGroupBox);
        portSpinBox->setObjectName("portSpinBox");
        portSpinBox->setGeometry(QRect(380, 30, 21, 21));
        portSpinBox->setFrameShape(QFrame::Shape::StyledPanel);
        portSpinBox->setFrameShadow(QFrame::Shadow::Raised);
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_6->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_79->setText(QString());
        label_80->setText(QString());
        label_81->setText(QString());
        label_82->setText(QString());
        groupBox_5->setTitle(QString());
        QTableWidgetItem *___qtablewidgetitem = projectTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID_PROJET", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = projectTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = projectTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "DESCRIPTION", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = projectTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "DATE_DEBUT", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = projectTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "TYPE", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = projectTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "BUDGET", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = projectTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "ETAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = projectTable->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = projectTable->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = projectTable->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = projectTable->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = projectTable->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = projectTable->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "6", nullptr));

        const bool __sortingEnabled = projectTable->isSortingEnabled();
        projectTable->setSortingEnabled(false);
        projectTable->setSortingEnabled(__sortingEnabled);

        pushButton_25->setText(QString());
        label_83->setText(QCoreApplication::translate("MainWindow", "Trier selon", nullptr));
        rechProjet_5->setItemText(0, QCoreApplication::translate("MainWindow", "NOM", nullptr));
        rechProjet_5->setItemText(1, QCoreApplication::translate("MainWindow", "BUDGET", nullptr));
        rechProjet_5->setItemText(2, QCoreApplication::translate("MainWindow", "DATE_DEBUT", nullptr));

        BouttonRechProjet_5->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        pdfProjet->setText(QCoreApplication::translate("MainWindow", "Exporter pdf", nullptr));
        TriProjet_5->setItemText(0, QCoreApplication::translate("MainWindow", "ID_PROJET", nullptr));
        TriProjet_5->setItemText(1, QCoreApplication::translate("MainWindow", "NOM", nullptr));
        TriProjet_5->setItemText(2, QCoreApplication::translate("MainWindow", "TYPE", nullptr));

        pushButton_31->setText(QString());
        label_84->setText(QString());
        label_85->setText(QString());
        pushButton_36->setText(QString());
        label_86->setText(QString());
        pushButton_26->setText(QCoreApplication::translate("MainWindow", "Ressource", nullptr));
        pushButton_37->setText(QCoreApplication::translate("MainWindow", "formation", nullptr));
        pushButton_38->setText(QCoreApplication::translate("MainWindow", "T\303\242che", nullptr));
        pushButton_39->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        pushButton_40->setText(QCoreApplication::translate("MainWindow", "Projets", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Projet ID", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nom du Projet", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Date d\303\251but ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        ajouterProjet->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        modifierProjet->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Budget", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        suppProjet->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        TriButton->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        generateContractButton->setText(QCoreApplication::translate("MainWindow", "G\303\251n\303\251rer Contrat", nullptr));
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Gestion projets", nullptr));
        label_88->setText(QString());
        label_89->setText(QString());
        label_90->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Projets", nullptr));
        label_87->setText(QString());
        label_91->setText(QString());
        label_92->setText(QString());
        label_93->setText(QString());
        label_105->setText(QString());
        label_106->setText(QString());
        label_107->setText(QString());
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        serverGroupBox->setTitle(QCoreApplication::translate("MainWindow", "ServerGroupBox", nullptr));
        serverIpLabel->setText(QCoreApplication::translate("MainWindow", "Server IP", nullptr));
        serverPortLabel->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        startServerButton->setText(QCoreApplication::translate("MainWindow", "D\303\251marrer", nullptr));
        sendButton->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        statusLabel->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
