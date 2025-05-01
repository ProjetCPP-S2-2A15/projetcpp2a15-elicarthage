/********************************************************************************
** Form generated from reading UI file 'mainwindow_1.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_1_H
#define UI_MAINWINDOW_1_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_projectsWidget
{
public:
    QTabWidget *tabWidget_2;
    QWidget *tabWidget_2Page1;
    QLabel *label_79;
    QLabel *label_80;
    QLabel *label_81;
    QLabel *label_82;
    QTabWidget *tabWidget_6;
    QWidget *tab_7;
    QLabel *label_88;
    QLabel *label_89;
    QLabel *label_90;
    QToolBox *toolBox;
    QWidget *toolBoxPage1;
    QWidget *toolBoxPage2;
    QWidget *widget_3;
    QLabel *label_87;
    QLabel *label_91;
    QLabel *label_92;
    QLabel *label_93;
    QLabel *label_105;
    QLabel *label_106;
    QLabel *label_107;
    QGroupBox *groupBox_6;
    QWidget *widget_5;
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

    void setupUi(QWidget *projectsWidget)
    {
        if (projectsWidget->objectName().isEmpty())
            projectsWidget->setObjectName("projectsWidget");
        projectsWidget->resize(1428, 757);
        tabWidget_2 = new QTabWidget(projectsWidget);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(410, 180, 1431, 841));
        tabWidget_2->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));
        tabWidget_2Page1 = new QWidget();
        tabWidget_2Page1->setObjectName("tabWidget_2Page1");
        label_79 = new QLabel(tabWidget_2Page1);
        label_79->setObjectName("label_79");
        label_79->setGeometry(QRect(1180, 30, 31, 21));
        label_79->setPixmap(QPixmap(QString::fromUtf8("../../../../power-off.png")));
        label_79->setScaledContents(true);
        label_80 = new QLabel(tabWidget_2Page1);
        label_80->setObjectName("label_80");
        label_80->setGeometry(QRect(610, 170, 20, 20));
        label_80->setPixmap(QPixmap(QString::fromUtf8("../../../../magnifier.png")));
        label_80->setScaledContents(true);
        label_81 = new QLabel(tabWidget_2Page1);
        label_81->setObjectName("label_81");
        label_81->setGeometry(QRect(440, 20, 71, 16));
        label_81->setPixmap(QPixmap(QString::fromUtf8("../../../../461537616_2828568600639017_3927034258301617377_n.png")));
        label_81->setScaledContents(true);
        label_82 = new QLabel(tabWidget_2Page1);
        label_82->setObjectName("label_82");
        label_82->setGeometry(QRect(1050, 30, 21, 21));
        label_82->setPixmap(QPixmap(QString::fromUtf8("../../../../notification.png")));
        label_82->setScaledContents(true);
        tabWidget_6 = new QTabWidget(tabWidget_2Page1);
        tabWidget_6->setObjectName("tabWidget_6");
        tabWidget_6->setGeometry(QRect(0, 50, 1321, 621));
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        tabWidget_6->addTab(tab_7, QString());
        label_88 = new QLabel(tabWidget_2Page1);
        label_88->setObjectName("label_88");
        label_88->setGeometry(QRect(1240, 30, 31, 31));
        label_88->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/images/logout.png")));
        label_88->setScaledContents(true);
        label_89 = new QLabel(tabWidget_2Page1);
        label_89->setObjectName("label_89");
        label_89->setGeometry(QRect(1190, 30, 41, 31));
        label_89->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/images/notification.png")));
        label_89->setScaledContents(true);
        label_90 = new QLabel(tabWidget_2Page1);
        label_90->setObjectName("label_90");
        label_90->setGeometry(QRect(1140, 30, 41, 31));
        label_90->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/images/power-off.png")));
        label_90->setScaledContents(true);
        tabWidget_2->addTab(tabWidget_2Page1, QString());
        toolBox = new QToolBox(projectsWidget);
        toolBox->setObjectName("toolBox");
        toolBox->setGeometry(QRect(650, 200, 1481, 661));
        toolBoxPage1 = new QWidget();
        toolBoxPage1->setObjectName("toolBoxPage1");
        toolBoxPage1->setGeometry(QRect(0, 0, 1481, 591));
        toolBox->addItem(toolBoxPage1, QString::fromUtf8(""));
        toolBoxPage2 = new QWidget();
        toolBoxPage2->setObjectName("toolBoxPage2");
        toolBoxPage2->setGeometry(QRect(0, 0, 1481, 591));
        widget_3 = new QWidget(toolBoxPage2);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(220, 110, 1431, 841));
        widget_3->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);"));
        label_87 = new QLabel(widget_3);
        label_87->setObjectName("label_87");
        label_87->setGeometry(QRect(1180, 30, 31, 21));
        label_87->setPixmap(QPixmap(QString::fromUtf8("../../../../power-off.png")));
        label_87->setScaledContents(true);
        label_91 = new QLabel(widget_3);
        label_91->setObjectName("label_91");
        label_91->setGeometry(QRect(610, 170, 20, 20));
        label_91->setPixmap(QPixmap(QString::fromUtf8("../../../../magnifier.png")));
        label_91->setScaledContents(true);
        label_92 = new QLabel(widget_3);
        label_92->setObjectName("label_92");
        label_92->setGeometry(QRect(440, 20, 71, 16));
        label_92->setPixmap(QPixmap(QString::fromUtf8("../../../../461537616_2828568600639017_3927034258301617377_n.png")));
        label_92->setScaledContents(true);
        label_93 = new QLabel(widget_3);
        label_93->setObjectName("label_93");
        label_93->setGeometry(QRect(1050, 30, 21, 21));
        label_93->setPixmap(QPixmap(QString::fromUtf8("../../../../notification.png")));
        label_93->setScaledContents(true);
        label_105 = new QLabel(widget_3);
        label_105->setObjectName("label_105");
        label_105->setGeometry(QRect(1240, 30, 31, 31));
        label_105->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/images/logout.png")));
        label_105->setScaledContents(true);
        label_106 = new QLabel(widget_3);
        label_106->setObjectName("label_106");
        label_106->setGeometry(QRect(1190, 30, 41, 31));
        label_106->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/images/notification.png")));
        label_106->setScaledContents(true);
        label_107 = new QLabel(widget_3);
        label_107->setObjectName("label_107");
        label_107->setGeometry(QRect(1140, 30, 41, 31));
        label_107->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/images/power-off.png")));
        label_107->setScaledContents(true);
        groupBox_6 = new QGroupBox(toolBoxPage2);
        groupBox_6->setObjectName("groupBox_6");
        groupBox_6->setGeometry(QRect(9, 9, 1181, 471));
        toolBox->addItem(toolBoxPage2, QString::fromUtf8(""));
        widget_5 = new QWidget(projectsWidget);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(0, 0, 1641, 600));
        projectTable = new QTableWidget(widget_5);
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
        projectTable->setGeometry(QRect(400, 130, 651, 301));
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
        pushButton_25 = new QPushButton(widget_5);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(800, 350, 71, 61));
        pushButton_25->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(170, 170, 255);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/home-interface-symbol.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_25->setIcon(icon);
        pushButton_25->setIconSize(QSize(40, 40));
        pushButton_25->setFlat(true);
        label_83 = new QLabel(widget_5);
        label_83->setObjectName("label_83");
        label_83->setGeometry(QRect(570, 520, 101, 20));
        rechProjet_5 = new QComboBox(widget_5);
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
        BouttonRechProjet_5 = new QPushButton(widget_5);
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
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #95A5A6;"
                        "  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        pdfProjet = new QPushButton(widget_5);
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
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #95A5A6;"
                        "  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        TriProjet_5 = new QComboBox(widget_5);
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
        pushButton_31 = new QPushButton(widget_5);
        pushButton_31->setObjectName("pushButton_31");
        pushButton_31->setGeometry(QRect(920, 210, 81, 51));
        pushButton_31->setFont(font);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../Downloads/power-off.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_31->setIcon(icon1);
        pushButton_31->setFlat(true);
        label_84 = new QLabel(widget_5);
        label_84->setObjectName("label_84");
        label_84->setGeometry(QRect(1200, 40, 31, 21));
        label_84->setPixmap(QPixmap(QString::fromUtf8("../../../../logout.png")));
        label_84->setScaledContents(true);
        label_85 = new QLabel(widget_5);
        label_85->setObjectName("label_85");
        label_85->setGeometry(QRect(420, 90, 56, 16));
        pushButton_36 = new QPushButton(widget_5);
        pushButton_36->setObjectName("pushButton_36");
        pushButton_36->setGeometry(QRect(590, 110, 31, 29));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../Downloads/magnifier.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_36->setIcon(icon2);
        pushButton_36->setFlat(true);
        taperRech_5 = new QLineEdit(widget_5);
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
        label_86 = new QLabel(widget_5);
        label_86->setObjectName("label_86");
        label_86->setGeometry(QRect(0, 0, 151, 601));
        label_86->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(34, 32, 82, 255), stop:1 rgba(0, 0, 0, 255));\n"
"border-radius: 10px;"));
        pushButton_26 = new QPushButton(widget_5);
        pushButton_26->setObjectName("pushButton_26");
        pushButton_26->setGeometry(QRect(0, 40, 140, 60));
        pushButton_37 = new QPushButton(widget_5);
        pushButton_37->setObjectName("pushButton_37");
        pushButton_37->setGeometry(QRect(0, 120, 140, 60));
        pushButton_38 = new QPushButton(widget_5);
        pushButton_38->setObjectName("pushButton_38");
        pushButton_38->setGeometry(QRect(0, 200, 140, 60));
        pushButton_39 = new QPushButton(widget_5);
        pushButton_39->setObjectName("pushButton_39");
        pushButton_39->setGeometry(QRect(0, 280, 140, 60));
        pushButton_40 = new QPushButton(widget_5);
        pushButton_40->setObjectName("pushButton_40");
        pushButton_40->setGeometry(QRect(0, 360, 142, 62));
        pushButton_40->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: white;\n"
"\n"
"    color: black;  /* D\303\251finir la couleur du texte en noir */\n"
"    border: 1px solid black;  /* Optionnel : pour ajouter une bordure noire */\n"
"}\n"
""));
        widget_4 = new QWidget(widget_5);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(160, 10, 221, 441));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #eee5d3;\n"
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
        project_date_deb->setMinimumDateTime(QDateTime(QDate(2024, 1, 1), QTime(2, 0, 0)));
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
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #95A5A6;"
                        "  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        TriButton = new QPushButton(widget_5);
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
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #95A5A6;"
                        "  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));
        generateContractButton = new QPushButton(widget_5);
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
"\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #34495E;  /* Bleu l\303\251g\303\250rement plus clair au survol */\n"
"    border: 1px solid #2C3E50;  /* Bordure harmonis\303\251e */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #1A252F;  /* Bleu encore plus fonc\303\251 lorsqu'on clique */\n"
"\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #95A5A6;"
                        "  /* Gris bleut\303\251 pour un bouton d\303\251sactiv\303\251 */\n"
"    color: #D0D3D4;             /* Texte plus clair pour indiquer l\342\200\231inactivit\303\251 */\n"
"    border: 1px solid #7F8C8D;\n"
"}\n"
""));

        retranslateUi(projectsWidget);

        tabWidget_6->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(projectsWidget);
    } // setupUi

    void retranslateUi(QWidget *projectsWidget)
    {
        projectsWidget->setWindowTitle(QCoreApplication::translate("projectsWidget", "Form", nullptr));
        label_79->setText(QString());
        label_80->setText(QString());
        label_81->setText(QString());
        label_82->setText(QString());
        tabWidget_6->setTabText(tabWidget_6->indexOf(tab_7), QCoreApplication::translate("projectsWidget", "Gestion projets", nullptr));
        label_88->setText(QString());
        label_89->setText(QString());
        label_90->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabWidget_2Page1), QString());
        toolBox->setItemText(toolBox->indexOf(toolBoxPage1), QString());
        label_87->setText(QString());
        label_91->setText(QString());
        label_92->setText(QString());
        label_93->setText(QString());
        label_105->setText(QString());
        label_106->setText(QString());
        label_107->setText(QString());
        groupBox_6->setTitle(QCoreApplication::translate("projectsWidget", "GroupBox", nullptr));
        toolBox->setItemText(toolBox->indexOf(toolBoxPage2), QString());
        QTableWidgetItem *___qtablewidgetitem = projectTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("projectsWidget", "ID_PROJET", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = projectTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("projectsWidget", "NOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = projectTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("projectsWidget", "DESCRIPTION", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = projectTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("projectsWidget", "DATE_DEBUT", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = projectTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("projectsWidget", "TYPE", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = projectTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("projectsWidget", "BUDGET", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = projectTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("projectsWidget", "ETAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = projectTable->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("projectsWidget", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = projectTable->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("projectsWidget", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = projectTable->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("projectsWidget", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = projectTable->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("projectsWidget", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = projectTable->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("projectsWidget", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = projectTable->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("projectsWidget", "6", nullptr));

        const bool __sortingEnabled = projectTable->isSortingEnabled();
        projectTable->setSortingEnabled(false);
        projectTable->setSortingEnabled(__sortingEnabled);

        pushButton_25->setText(QString());
        label_83->setText(QCoreApplication::translate("projectsWidget", "Trier selon", nullptr));
        rechProjet_5->setItemText(0, QCoreApplication::translate("projectsWidget", "NOM", nullptr));
        rechProjet_5->setItemText(1, QCoreApplication::translate("projectsWidget", "BUDGET", nullptr));
        rechProjet_5->setItemText(2, QCoreApplication::translate("projectsWidget", "DATE_DEBUT", nullptr));

        BouttonRechProjet_5->setText(QCoreApplication::translate("projectsWidget", "Rechercher", nullptr));
        pdfProjet->setText(QCoreApplication::translate("projectsWidget", "Exporter pdf", nullptr));
        TriProjet_5->setItemText(0, QCoreApplication::translate("projectsWidget", "ID_PROJET", nullptr));
        TriProjet_5->setItemText(1, QCoreApplication::translate("projectsWidget", "NOM", nullptr));
        TriProjet_5->setItemText(2, QCoreApplication::translate("projectsWidget", "TYPE", nullptr));

        pushButton_31->setText(QString());
        label_84->setText(QString());
        label_85->setText(QString());
        pushButton_36->setText(QString());
        label_86->setText(QString());
        pushButton_26->setText(QCoreApplication::translate("projectsWidget", "Ressource", nullptr));
        pushButton_37->setText(QCoreApplication::translate("projectsWidget", "formation", nullptr));
        pushButton_38->setText(QCoreApplication::translate("projectsWidget", "T\303\242che", nullptr));
        pushButton_39->setText(QCoreApplication::translate("projectsWidget", "Client", nullptr));
        pushButton_40->setText(QCoreApplication::translate("projectsWidget", "Projets", nullptr));
        label_2->setText(QCoreApplication::translate("projectsWidget", "Projet ID", nullptr));
        label_3->setText(QCoreApplication::translate("projectsWidget", "Nom du Projet", nullptr));
        label_4->setText(QCoreApplication::translate("projectsWidget", "Date d\303\251but ", nullptr));
        label_5->setText(QCoreApplication::translate("projectsWidget", "Description", nullptr));
        ajouterProjet->setText(QCoreApplication::translate("projectsWidget", "Ajouter", nullptr));
        modifierProjet->setText(QCoreApplication::translate("projectsWidget", "modifier", nullptr));
        label_6->setText(QCoreApplication::translate("projectsWidget", "Type", nullptr));
        label_7->setText(QCoreApplication::translate("projectsWidget", "Budget", nullptr));
        label_8->setText(QCoreApplication::translate("projectsWidget", "etat", nullptr));
        suppProjet->setText(QCoreApplication::translate("projectsWidget", "Supprimer", nullptr));
        TriButton->setText(QCoreApplication::translate("projectsWidget", "Trier", nullptr));
        generateContractButton->setText(QCoreApplication::translate("projectsWidget", "G\303\251n\303\251rer Contrat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow_Projects: public Ui_projectsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_1_H
