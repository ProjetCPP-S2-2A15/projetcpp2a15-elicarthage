
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "projet.h"
#include <QMessageBox>
#include <QFileDialog>          // Pour le choix du fichier à sauvegarder
#include <QPdfWriter>           // Pour générer un fichier PDF
#include <QPainter>             // Pour dessiner sur le PDF
#include <QMessageBox>          // Pour afficher des messages d'information ou d'erreur
#include <QSqlQuery>            // Pour exécuter des requêtes SQL
#include <QSqlError>            // Pour gérer les erreurs de la base de données
#include <QFont>                // Pour utiliser les polices dans le PDF
#include <QColor>               // Pour définir les couleurs (bleu dans ce cas)
#include <QMargins>             // Pour définir les marges du PDF
#include <QPagedPaintDevice>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     refreshTable();
    connect(ui->projectTable, &QTableWidget::cellClicked, this, &MainWindow::on_projectTable_cellClicked);
    connect(ui->BouttonRechProjet_5, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
    connect(ui->TriButton, &QPushButton::clicked, this, &MainWindow::on_TriButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//crud
void MainWindow::refreshTable()
{
    Projet projet;
     ui->projectTable->setColumnCount(7);
 ui->projectTable->setHorizontalHeaderLabels({"ID_PROJET", "NOM", "DESCRIPTION", "DATE_DEBUT", "TYPE", "BUDGET", "ETAT"});
        projet.display(ui->projectTable);
        if (ui->projectTable->rowCount() == 0) {
            QMessageBox::warning(this, "Attention", "Aucune donnée à afficher dans la table des événements.");
            qDebug() << "Aucune ligne trouvée dans le QTableWidget.";
            return;
        }
        qDebug() << "Données chargées dans projectTable. Lignes:" << ui->projectTable->rowCount() << "Colonnes:" << ui->projectTable->columnCount();
    }

void MainWindow::on_ajouterProjet_clicked()
{

    QString projectId = ui->project_id->text().trimmed();
    QString projectName = ui->project_name->text().trimmed();
    QString projectDescription = ui->project_description->text().trimmed();
    QDate projectDateDeb = QDate::fromString(ui->project_date_deb->text(), "yyyy-MM-dd");
    QString projectType = ui->project_type->text().trimmed();
    bool budgetOk;
    double projectBudget = ui->project_budget->text().toDouble(&budgetOk);
    QString projectEtat = ui->project_etat->text().trimmed();

    // Validation de l'ID du projet (alphanumérique, max 6 caractères)
    if (projectId.isEmpty() || projectId.length() > 6 || projectId.contains(QChar(' '))) {
        QMessageBox::warning(this, "Erreur", "L'ID du projet doit contenir au maximum 6 caractères alphanumériques sans espace.");
        return;
    }

    // Validation du nom du projet (1 à 50 caractères)
    if (projectName.isEmpty() || projectName.length() > 50) {
        QMessageBox::warning(this, "Erreur", "Le nom du projet doit contenir entre 1 et 50 caractères.");
        return;
    }

    // Validation de la description (non vide)
    if (projectDescription.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "La description du projet ne peut pas être vide.");
        return;
    }

    // Validation du type de projet (1 à 30 caractères)
    if (projectType.isEmpty() || projectType.length() > 30) {
        QMessageBox::warning(this, "Erreur", "Le type du projet doit contenir entre 1 et 30 caractères.");
        return;
    }

    // Validation de l'état du projet (doit être 'En cours', 'Terminé' ou 'Annulé')
    QStringList validEtats = {"En cours", "Terminé", "Annulé"};
    if (!validEtats.contains(projectEtat, Qt::CaseInsensitive)) {
        QMessageBox::warning(this, "Erreur", "L'état du projet doit être 'En cours', 'Terminé' ou 'Annulé'.");
        return;
    }

    // Validation du budget (doit être un nombre positif)
    if (!budgetOk || projectBudget < 0) {
        QMessageBox::warning(this, "Erreur", "Le budget du projet doit être un nombre positif.");
        return;
    }


    Projet projet;
    projet.setProjectId(projectId);
    projet.setProjectName(projectName);
    projet.setProjectDescription(projectDescription);
    projet.setProjectDateDeb(projectDateDeb);
    projet.setProjectType(projectType);
    projet.setProjectBudget(projectBudget);
    projet.setProjectEtat(projectEtat);

    if (projet.addProjet()) {
        QMessageBox::information(this, "Succès", "Projet ajouté avec succès !");

        ui->project_id->clear();
        ui->project_name->clear();
        ui->project_description->clear();
        ui->project_date_deb->clear();
        ui->project_type->clear();
        ui->project_budget->clear();
        ui->project_etat->clear();

        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du projet : " + projet.getLastError());
    }
}

void MainWindow::on_modifierProjet_clicked()
{  if (ui->project_id->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un projet à modifier.");
        return;
    }

    QString projectId = ui->project_id->text().trimmed();
    QString projectName = ui->project_name->text().trimmed();
    QString projectDescription = ui->project_description->text().trimmed();
    QDate projectDateDeb = ui->project_date_deb->date();
    QString projectType = ui->project_type->text().trimmed();

    bool budgetOk;
    double projectBudget = ui->project_budget->text().toDouble(&budgetOk);
    QString projectEtat = ui->project_etat->text().trimmed();

    // Vérification des champs obligatoires
    if (projectId.isEmpty() || projectName.isEmpty() || projectDescription.isEmpty() ||
        projectType.isEmpty() || projectEtat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs obligatoires.");
        return;
    }

    if (!projectDateDeb.isValid()) {
        QMessageBox::warning(this, "Erreur", "La date de début du projet est invalide.");
        return;
    }

    if (!budgetOk || projectBudget < 0) {
        QMessageBox::warning(this, "Erreur", "Le budget doit être un nombre positif.");
        return;
    }

    // Création et mise à jour du projet
    Projet projet;
    projet.setProjectId(projectId);
    projet.setProjectName(projectName);
    projet.setProjectDescription(projectDescription);
    projet.setProjectDateDeb(projectDateDeb);
    projet.setProjectType(projectType);
    projet.setProjectBudget(projectBudget);
    projet.setProjectEtat(projectEtat);

    if (projet.updateProjet(projectId)) {
        QMessageBox::information(this, "Succès", "Projet modifié avec succès !");

        // Nettoyage des champs après modification
        ui->project_id->clear();
        ui->project_name->clear();
        ui->project_description->clear();
        ui->project_date_deb->clear();
        ui->project_type->clear();
        ui->project_budget->clear();
        ui->project_etat->clear();

        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du projet.");
    }
}

void MainWindow::on_suppProjet_clicked()
{
    int row = ui->projectTable->currentRow();

    // Vérifier si une ligne est bien sélectionnée
    if (row < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un projet à supprimer.");
        return;
    }

    // Récupérer l'ID du projet à partir de la table
    QString projectId = ui->projectTable->item(row, 0)->text();

    if (projectId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "L'ID du projet est invalide.");
        return;
    }

    // Confirmer la suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce projet ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    // Supprimer le projet
    Projet projet;
    if (projet.deleteProjet(projectId)) {
        QMessageBox::information(this, "Succès", "Projet supprimé avec succès !");

        // Supprimer la ligne de la table et rafraîchir les données
        ui->projectTable->removeRow(row);
        refreshTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du projet.");
    }
}

void MainWindow::on_projectTable_cellClicked(int row, int column)
{
    // Vérification que la ligne sélectionnée est valide
    if (row < 0 || column < 0 || !ui->projectTable->item(row, 0)) {
        return;
    }

    // Récupération des données de la ligne sélectionnée
    QTableWidgetItem *itemId = ui->projectTable->item(row, 0);
    QTableWidgetItem *itemName = ui->projectTable->item(row, 1);
    QTableWidgetItem *itemDesc = ui->projectTable->item(row, 2);
    QTableWidgetItem *itemDate = ui->projectTable->item(row, 3);
    QTableWidgetItem *itemType = ui->projectTable->item(row, 4);
    QTableWidgetItem *itemBudget = ui->projectTable->item(row, 5);
    QTableWidgetItem *itemEtat = ui->projectTable->item(row, 6);

    if (!itemId || !itemName || !itemDesc || !itemDate || !itemType || !itemBudget || !itemEtat) {
        return; // Évite tout crash si une cellule est vide
    }

    // Affichage des données dans les champs de saisie
    ui->project_id->setText(itemId->text());
    ui->project_name->setText(itemName->text());
    ui->project_description->setText(itemDesc->text());
    ui->project_type->setText(itemType->text());

    // Vérification et conversion correcte du budget
    bool budgetOk;
    double budget = itemBudget->text().toDouble(&budgetOk);
    if (budgetOk) {
        ui->project_budget->setText(QString::number(budget, 'f', 2));
    } else {
        QMessageBox::warning(this, "Erreur", "Valeur de budget invalide.");
    }

    ui->project_etat->setText(itemEtat->text());
}

void MainWindow::on_pdfProjet_clicked()
{ // Sélection du chemin et du nom du fichier PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "*.pdf");
    if (filePath.isEmpty()) return;

    if (!filePath.endsWith(".pdf")) {
        filePath += ".pdf";
    }

    // Initialisation de QPdfWriter
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300);
    pdfWriter.setPageMargins(QMargins(50, 50, 50, 50));

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::warning(this, "Erreur", "Impossible de créer le fichier PDF.");
        return;
    }

    // Police et couleur du titre
    QFont titleFont("Helvetica", 24, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(QColor(0, 0, 255)); // Bleu pour le titre
    painter.drawText(QRect(0, 0, pdfWriter.width(), 100), Qt::AlignCenter, "Project List");

    // Police et couleur du contenu
    QFont contentFont("Helvetica", 12);
    painter.setFont(contentFont);
    painter.setPen(Qt::black);

    // Définir la position initiale et la hauteur des lignes
    int yOffset = 180;
    int rowHeight = 40;

    // Colonnes pour l'affichage (Project ID et Project Name)
    QStringList headers = {"Project ID", "Project Name"};
    int columnCount = headers.size();
    int totalWidth = pdfWriter.width() - 100;
    QVector<int> columnWidths = {
        static_cast<int>(totalWidth * 0.2),
        static_cast<int>(totalWidth * 0.4)
    };

    // Couleur de fond pour l'entête
    QColor headerColor(173, 216, 230); // Bleu clair pour l'entête
    painter.setPen(headerColor);

    // Affichage des entêtes de colonne
    int leftMargin = 50;
    for (int col = 0; col < columnCount; ++col) {
        painter.drawText(leftMargin, yOffset, columnWidths[col], rowHeight, Qt::AlignCenter, headers[col]);
        leftMargin += columnWidths[col];
    }
    yOffset += rowHeight;
    painter.drawLine(50, yOffset, pdfWriter.width() - 50, yOffset); // Ligne sous les entêtes
    yOffset += 10;

    // Requête SQL pour récupérer les projets
    QSqlQuery query;
    if (!query.exec("SELECT ID_PROJET, NOM FROM PROJETS")) {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la récupération des données : " + query.lastError().text());
        return;
    }

    // Vérification si des projets sont récupérés
    if (!query.next()) {
        QMessageBox::information(this, "Info", "Aucun projet trouvé.");
        return;
    }

    // Parcours des projets et ajout au PDF
    do {
        leftMargin = 50;
        QStringList rowData = {
            query.value(0).toString(), // Project ID
            query.value(1).toString()  // Project Name
        };

        // Ajout des données à chaque ligne du PDF
        painter.setPen(Qt::black);
        for (int col = 0; col < columnCount; ++col) {
            painter.drawText(leftMargin, yOffset, columnWidths[col], rowHeight, Qt::AlignCenter, rowData[col]);
            leftMargin += columnWidths[col];
        }
        yOffset += rowHeight;

        // Si la page est pleine, crée une nouvelle page
        if (yOffset + rowHeight > pdfWriter.height() - 50) {
            pdfWriter.newPage();
            yOffset = 100;
            leftMargin = 50;
            painter.setPen(headerColor);
            for (int col = 0; col < columnCount; ++col) {
                painter.drawText(leftMargin, yOffset, columnWidths[col], rowHeight, Qt::AlignCenter, headers[col]);
                leftMargin += columnWidths[col];
            }
            yOffset += rowHeight;
            painter.drawLine(50, yOffset, pdfWriter.width() - 50, yOffset);
            yOffset += 10;
        }
    } while (query.next()); // Parcours de tous les projets

    // Fin du dessin sur le PDF
    painter.end();

    // Message de succès
    QMessageBox::information(this, "Succès", "Le fichier PDF a été exporté avec succès !");
}

void MainWindow::on_searchButton_clicked() {
    QString searchText = ui->taperRech_5->text().trimmed().toLower(); // Get search text (case-insensitive)
    int rowCount = ui->projectTable->rowCount();
    int columnCount = ui->projectTable->columnCount();

    for (int row = 0; row < rowCount; ++row) {
        bool matchFound = false;
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = ui->projectTable->item(row, col);
            if (item && item->text().toLower().contains(searchText)) {
                matchFound = true;
                break;
            }
        }
        // Show/hide row based on match
        ui->projectTable->setRowHidden(row, !matchFound);
    }
}

void MainWindow::on_TriButton_clicked()
{
    QString colonneTri = ui->rechProjet_5->currentText();

    if (colonneTri == "NOM") {
        // Tri alphabétique
        ui->projectTable->sortByColumn(1, Qt::AscendingOrder);
    }
    else if (colonneTri == "BUDGET") {
        // Tri du budget (du plus élevé au plus bas)
        ui->projectTable->sortByColumn(5, Qt::DescendingOrder);
    }
    else if (colonneTri == "DATE_DEBUT") {
        // Tri par date (du plus récent au plus ancien)
        ui->projectTable->sortByColumn(3, Qt::DescendingOrder);
    }
}

