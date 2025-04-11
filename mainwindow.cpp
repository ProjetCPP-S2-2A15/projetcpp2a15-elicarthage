#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include "tache.h"
#include <QInputDialog>
#include <QDate>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ELICAR");

     // Charger les options de la comboBox pour l'état
    ui->comboBox_etat->addItem("Mission APD");
    ui->comboBox_etat->addItem("Mission de programmation");
    ui->comboBox_etat->addItem("Mission  APS");
    ui->comboBox_etat->addItem("Les dossiers d'exuction");
    ui->comboBox_etat->addItem("Mission B1 de controle traveaux");
    ui->comboBox_etat->addItem("Mission B2 de condination traveaux");

    Tache etmp;
    ui->tableView->setModel(etmp.afficher());

    connect(ui->lineEdit_recherche, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_recherche_textChanged);
    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_comboBox_tri_currentIndexChanged);
    connect(ui->pushButton_exportPDF, &QPushButton::clicked, this, &MainWindow::on_pushButton_exportPDF_clicked);



    // Charger et vérifier l'image de l'icône de l'application
    QPixmap pixmap("C:/Users/eya/Desktop/archi/imlogo.png");
    if (!pixmap.isNull()) {
        QPixmap resizedPixmap = pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->setWindowIcon(QIcon(resizedPixmap));
    } else {
        qDebug() << "L'image du logo n'a pas pu être chargée!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonajouter_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();
    QString etat = ui->comboBox_etat->currentText();


    // Utilisation de QDateEdit pour récupérer les dates
    QDate debutDate = ui->dateEdit_debutDate->date();  // Récupérer la date de début
    QDate finDate = ui->dateEdit_finDate->date();  // Récupérer la date de fin

    // Vérification des champs vides
    if (nom.isEmpty() || description.isEmpty() || etat.isEmpty() || !debutDate.isValid() || !finDate.isValid()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs avant d'ajouter une tâche.");
        return;
    }

    // Instanciation de l'objet Tache
    Tache t(id, nom, description, etat, debutDate, finDate);

    // Ajout dans la base de données
    bool test = t.ajouter();

    if (test) {
        Tache etmp;
        ui->tableView->setModel(etmp.afficher());

        QMessageBox::information(this, "Succès", "Ajout effectué avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
    }
}


void MainWindow::on_btnsupprimer_clicked()
{
    // Récupérer l'ID du champ de texte
    int id = ui->lineEdit_IDS->text().toInt();

    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    Tache tache;
    bool test = tache.supprimer(id);

    if (test) {
        QMessageBox::information(this, "Succès", "Suppression effectuée avec succès!");
        ui->tableView->setModel(tache.afficher());
    } else {
        QMessageBox::warning(this, "Erreur", "Suppression non effectuée.");
    }

    // Effacer le champ de texte après l'opération
    ui->lineEdit_IDS->clear();
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString desc = ui->lineEdit_description->text();
    QString etat = ui->comboBox_etat->currentText();


    // Utilisation de QDateEdit pour récupérer les dates
    QDate debutDate = ui->dateEdit_debutDate->date();  // Récupérer la date de début
    QDate finDate = ui->dateEdit_finDate->date();      // Récupérer la date de fin

    // Vérification des champs vides
    if (nom.isEmpty() || desc.isEmpty() || etat.isEmpty() || !debutDate.isValid() || !finDate.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Instanciation de l'objet Tache
    Tache t;
    if (t.modifier(id, nom, desc, etat, debutDate, finDate)) {
        QMessageBox::information(this, "Succès", "Tâche modifiée avec succès !");
        ui->tableView->setModel(t.afficher()); // Rafraîchir la liste des tâches
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification !");
    }
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &text)
{
    Tache tache;
    ui->tableView->setModel(tache.recherche(text));  // Recherche dynamique
}
void MainWindow::on_comboBox_tri_currentIndexChanged(int index)
{
     Q_UNUSED(index);
    QString critere = ui->comboBox_tri->currentText();
    Tache t;
    ui->tableView->setModel(t.trierPar(critere));
}

void MainWindow::on_pushButton_exportPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
    if (fileName.isEmpty()) return;

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize::A4); // Utilise A4 comme taille de page
    pdf.setResolution(300);

    QPainter painter(&pdf);
    int y = 50; // Position initiale pour commencer à dessiner

    // Ajouter un logo en haut à gauche
    QImage logo(":/path/to/your/logo.png"); // Remplace le chemin par le bon chemin de ton logo
    if (!logo.isNull()) {
        painter.drawImage(50, y, logo);
        y += logo.height() + 20; // Ajuster la position en fonction de la hauteur du logo
    }

    // Titre principal
    QFont titleFont;
    titleFont.setBold(true);
    titleFont.setPointSize(18);
    painter.setFont(titleFont);
    painter.drawText(200, y, "Liste des Tâches");
    y += 40; // Espacement après le titre

    // En-têtes de tableau
    QFont headerFont;
    headerFont.setBold(true);
    headerFont.setPointSize(16); // Augmenter la taille de la police des en-têtes
    painter.setFont(headerFont);

    // Définir la largeur des colonnes plus grande
    int columnWidth1 = 350; // Largeur de la première colonne (Nom de la tâche)
    int columnWidth2 = 350; // Largeur de la deuxième colonne (Date de début)
    int columnWidth3 = 350; // Largeur de la troisième colonne (Date de fin)

    // Dessiner les en-têtes du tableau avec des bordures
    QRect rect(50, y, columnWidth1, 50); // Augmenter la hauteur des cellules
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::lightGray));
    painter.drawRect(rect); // Bordure de la cellule
    painter.drawText(rect, Qt::AlignCenter, "Nom de la Tâche");

    rect.moveLeft(rect.right());
    painter.drawRect(rect);
    painter.drawText(rect, Qt::AlignCenter, "Date Début");

    rect.moveLeft(rect.right());
    painter.drawRect(rect);
    painter.drawText(rect, Qt::AlignCenter, "Date Fin");

    y += 60; // Espacement entre les en-têtes et le début des lignes de données

    // Polices pour le contenu
    QFont contentFont;
    contentFont.setPointSize(14); // Augmenter la taille de la police du contenu
    painter.setFont(contentFont);

    QSqlQuery query("SELECT TACHENAME, DEBUTDATE, FINDATE FROM TACHE");
    while (query.next()) {
        QString nom = query.value(0).toString();
        QString debut = query.value(1).toDate().toString("dd/MM/yyyy");
        QString fin = query.value(2).toDate().toString("dd/MM/yyyy");

        // Dessiner les lignes du tableau
        QRect rowRect(50, y, columnWidth1, 50); // Augmenter la hauteur des lignes
        painter.setBrush(QBrush(Qt::white)); // Fond blanc pour les lignes de tableau
        painter.drawRect(rowRect); // Bordure de la cellule
        painter.drawText(rowRect, Qt::AlignCenter, nom.left(40)); // Limiter le texte à 40 caractères

        rowRect.moveLeft(rowRect.right());
        painter.drawRect(rowRect);
        painter.drawText(rowRect, Qt::AlignCenter, debut);

        rowRect.moveLeft(rowRect.right());
        painter.drawRect(rowRect);
        painter.drawText(rowRect, Qt::AlignCenter, fin);

        y += 60; // Espacement entre les lignes

        // Si la page est presque pleine, ajouter une nouvelle page
        if (y > 800) {
            pdf.newPage();
            y = 50; // Réinitialiser la position y pour la nouvelle page
        }
    }

    painter.end();

    QMessageBox::information(this, "Export terminé", "Le fichier PDF a été généré avec succès !");
}
void MainWindow::afficherStatistiqueTache()
{
    QSqlQuery query;
    QPieSeries *series = new QPieSeries();

    // Requête pour compter les tâches selon leur état
    if (query.exec("SELECT TACHETAT, COUNT(*) FROM TACHE GROUP BY TACHETAT")) {
        while (query.next()) {
            QString etat = query.value(0).toString();
            int count = query.value(1).toInt();
            series->append(etat + " (" + QString::number(count) + ")", count);
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête statistique:" << query.lastError().text();
    }

    // Créer le graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des tâches par état");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);

    // Créer une fenêtre avec le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 400);
    chartView->setWindowTitle("Statistiques des Tâches");
    chartView->show();
}
void MainWindow::on_pushButton_statistique_clicked()
{
    afficherStatistiqueTache();
}
