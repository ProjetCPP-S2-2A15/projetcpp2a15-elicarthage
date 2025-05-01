#include "mainwindow.h"
#include "projet.h"
#include "historique.h"

#include "ressource.h"

#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QSqlError>
#include <QFont>
#include <QColor>
#include <QMargins>
#include <QPagedPaintDevice>
#include <QInputDialog>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextStream>
#include <QDir>
#include <QPushButton>
#include <QWidget>
#include <QListWidget>
#include <QMessageBox>
#include <QTimer>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QFormLayout>
#include <QSpinBox>
#include <QPrinter>
#include <QComboBox>
#include <iostream>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextToSpeech>
#include "ui_mainwindow_1.h" // For MainWindow_Resources
#include "ui_mainwindow_2.h"
 // For MainWindow_Resources




 void MainWindow::switchToRessources() {
     stack->setCurrentIndex(1); // Affiche ui2
 }


 void MainWindow::switchToProjectsUI()
 {
     stack->setCurrentIndex(0);  // 0 for Projects UI
 }
void MainWindow::on_annulertri_clicked() {

    afficher();
}

void MainWindow::affichertri(QString filtre) {
    ui2->tableWidget->clear();  // Nettoyer le tableau
    ui2->tableWidget->setRowCount(0);

    // Définir les noms des colonnes
    QStringList headers = {"ID", "Nom", "Type", "État", "Fournisseur", "Localisation", "Quantité", "Action"};
    ui2->tableWidget->setColumnCount(headers.size());
    ui2->tableWidget->setHorizontalHeaderLabels(headers);
     QSqlQuery query;
    if (filtre.isEmpty()) {
        query.prepare("SELECT * FROM ressource");
    } else {
        query.prepare("SELECT * FROM ressource WHERE type = :filtre");
        query.bindValue(":filtre", filtre);
    }

    if (query.exec()) {
        int row = 0;
        while (query.next()) {
            ui2->tableWidget->insertRow(row);

            for (int col = 0; col < 7; col++) {  // Mettre les valeurs des 7 colonnes
                ui2->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
            }

            // Ajouter le bouton Modifier
            /*QPushButton *btnModifier = new QPushButton("Modifier");
            btnModifier->setStyleSheet("QPushButton { background-color: #3498db; color: white; border-radius: 5px; padding: 5px; }"
                                        "QPushButton:hover { background-color: #2980b9; }");
            btnModifier->setFixedSize(70, 25);
            //connect(ui2->btnModifier, &QPushButton::clicked, this, [this, row]() {
                int id = ui2->tableWidget->item(row, 0)->text().toInt();
                QString nom = ui2->tableWidget->item(row, 1)->text();
                QString type = ui2->tableWidget->item(row, 2)->text();
                QString etat = ui2->tableWidget->item(row, 3)->text();
                QString fournisseur = ui2->tableWidget->item(row, 4)->text();
                QString localisation = ui2->tableWidget->item(row, 5)->text();
                int quantite = ui2->tableWidget->item(row, 6)->text().toInt();

                modifier(id, nom, type, etat, fournisseur, localisation, quantite);
            });

            ui2->tableWidget->setCellWidget(row, 7, btnModifier);  // Colonne "Action" pour le bouton*/

            row++;
        }
    }
}

void MainWindow::on_trimateriel_clicked() {
    qDebug() << "Tri par Matériel";

    affichertri("materiel");  // Filtrer les ressources de type "Matériel"
}

void MainWindow::on_trilogiciel_clicked() {
    qDebug() << "Tri par logiciel";


    affichertri("logiciel");  // Filtrer les ressources de type "Logiciel"
}


void MainWindow::exporterPDF() {
    // Demander où enregistrer le fichier
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichier PDF (*.pdf)");
    if (filePath.isEmpty()) {
        return;  // Si l'utilisateur annule, on ne fait rien
    }

    // Créer un document PDF
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setResolution(300);

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier PDF pour l'écriture.");
        return;
    }

    // En-tête du PDF
    painter.setFont(QFont("Arial", 16, QFont::Bold));
    painter.drawText(200, 200, "Liste des Ressources Disponibles et Actives");

    // Requête SQL pour récupérer les ressources disponibles et actives
    QSqlQuery query;
    query.prepare("SELECT * FROM ressource WHERE (type = 'materiel' AND etat = 'disponible') OR (type = 'logiciel' AND etat = 'active')");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la récupération des données.");
        return;
    }

    // Positionnement du tableau
    int x = 100;
    int y = 400;
    int rowHeight = 300;
    int colWidth = 330;

    // Dessiner l'en-tête du tableau
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.drawText(x, y, "ID");
    painter.drawText(x + colWidth, y, "Nom");
    painter.drawText(x + 2 * colWidth, y, "Type");
    painter.drawText(x + 3 * colWidth, y, "État");
    painter.drawText(x + 4 * colWidth, y, "Fournisseur");
    painter.drawText(x + 5 * colWidth, y, "Localisation");
    painter.drawText(x + 6 * colWidth, y, "Quantité");

    y += rowHeight;

    // Remplir le tableau avec les ressources disponibles
    painter.setFont(QFont("Arial", 10));
    while (query.next()) {
        painter.drawText(x, y, query.value("id").toString());
        painter.drawText(x + colWidth, y, query.value("nom").toString());
        painter.drawText(x + 2 * colWidth, y, query.value("type").toString());
        painter.drawText(x + 3 * colWidth, y, query.value("etat").toString());
        painter.drawText(x + 4 * colWidth, y, query.value("fournisseur").toString());
        painter.drawText(x + 5 * colWidth, y, query.value("localisation").toString());
        painter.drawText(x + 6 * colWidth, y, query.value("quantite").toString());

        y += rowHeight;
    }

    painter.end();  // Fin de l'écriture du PDF

    QMessageBox::information(this, "Succès", "Le fichier PDF a été généré avec succès !");
}

void MainWindow::rechercher() {

    // Effacer les anciennes lignes affichées dans la table
    ui2->tableWidget->setRowCount(0);

    // Récupérer le texte du champ de recherche
    QString rechercheNom = ui2->lineEdit_Recherche->text();

    // Préparer la requête SQL avec un filtre par nom
    QSqlQuery query;
    query.prepare("SELECT * FROM ressource WHERE nom LIKE ?");
    query.addBindValue("%" + rechercheNom + "%"); // Permet de rechercher partiellement un nom

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche.");
        return;
    }

    int row = 0;
    while (query.next()) {
        ui2->tableWidget->insertRow(row);

        int id = query.value("id").toInt();
        QString nom = query.value("nom").toString();
        QString type = query.value("type").toString();
        QString etat = query.value("etat").toString();
        QString fournisseur = query.value("fournisseur").toString();
        QString localisation = query.value("localisation").toString();
        int quantite = query.value("quantite").toInt();

        ui2->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
        ui2->tableWidget->setItem(row, 1, new QTableWidgetItem(nom));
        ui2->tableWidget->setItem(row, 2, new QTableWidgetItem(type));
        ui2->tableWidget->setItem(row, 3, new QTableWidgetItem(etat));
        ui2->tableWidget->setItem(row, 4, new QTableWidgetItem(fournisseur));
        ui2->tableWidget->setItem(row, 5, new QTableWidgetItem(localisation));
        ui2->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(quantite)));

        QPushButton *modifierButton = new QPushButton("Modifier");
        modifierButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; border-radius: 5px; padding: 5px; }"
                                      "QPushButton:hover { background-color: #2980b9; }");

        connect(modifierButton, &QPushButton::clicked, this, [this, id, nom, type, etat, fournisseur, localisation, quantite]() {
            modifier(id, nom, type, etat, fournisseur, localisation, quantite);
        });

        ui2->tableWidget->setCellWidget(row, 7, modifierButton);

        row++;
    }
}


void MainWindow::afficherGraphiqueMateriels() {
    // Nettoyage de l'ancien contenu
    QLayoutItem* item;
    while ((item = ui2->widgetGraphLayout->layout()->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Partie graphique pour les matériels
    QBarSeries *series = new QBarSeries();
    QStringList categories;

    QSqlQuery query;
    query.exec("SELECT nom, quantite FROM ressource WHERE type = 'materiel' ORDER BY quantite DESC");
    while (query.next()) {
        QString nom = query.value("nom").toString();
        int quantite = query.value("quantite").toInt();

        QBarSet *set = new QBarSet(nom);
        *set << quantite;
        series->append(set);
        categories << nom;
    }

    QChart *chart = new QChart();
    chart->setTitle("Quantité des matériels");
    chart->addSeries(series);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Quantité");
    axisY->setRange(0, 300);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Partie liste des logiciels actifs
    QListWidget *logicielList = new QListWidget();
    logicielList->setStyleSheet("QListWidget { font-size: 14px; padding: 5px; background-color: #ffffff; border: 1px solid #ccc; }");

    logicielList->addItem("Logiciels actifs :");

    QSqlQuery queryLogiciels;
    queryLogiciels.exec("SELECT nom FROM ressource WHERE type = 'logiciel' AND etat = 'active'");
    while (queryLogiciels.next()) {
        logicielList->addItem("• " + queryLogiciels.value("nom").toString());
    }

    // Disposition côte à côte
    QWidget *graphWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(graphWidget);
    layout->addWidget(chartView, 2);     // 3/4 pour le graphique
    layout->addWidget(logicielList, 2);  // 1/4 pour la liste
    ui2->widgetGraphLayout->addWidget(graphWidget);
}


void MainWindow::afficher() {
    // Clear the table before filling it
    ui2->tableWidget->setRowCount(0); // Remove any existing rows

    // Prepare the SQL query
    QSqlQuery query;
    query.exec("SELECT * FROM ressource");

    int row = 0;
    while (query.next()) {
        ui2->tableWidget->insertRow(row);  // Insert a new row

        // Assign data to correct columns based on the column index
        ui2->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("id").toString())); // ID
        ui2->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("nom").toString())); // NOM
        ui2->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("type").toString())); // TYPE
        ui2->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("etat").toString())); // ETAT
        ui2->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("fournisseur").toString())); // FOURNISSEUR
        ui2->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("localisation").toString())); // LOCALISATION
        ui2->tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("quantite").toString())); // QUANTITE

        QPushButton *modifyButton = new QPushButton("Modifier");
        modifyButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; border-radius: 5px; padding: 5px; }"
                                    "QPushButton:hover { background-color: #2980b9; }");
        modifyButton->setFixedSize(70, 25);
        connect(modifyButton, &QPushButton::clicked, [this, row]() {
            // Get the values from the table row and pass them to the modifier function
            int id = ui2->tableWidget->item(row, 0)->text().toInt();
            QString nom = ui2->tableWidget->item(row, 1)->text();
            QString type = ui2->tableWidget->item(row, 2)->text();
            QString etat = ui2->tableWidget->item(row, 3)->text();
            QString fournisseur = ui2->tableWidget->item(row, 4)->text();
            QString localisation = ui2->tableWidget->item(row, 5)->text();
            int quantite = ui2->tableWidget->item(row, 6)->text().toInt();

            // Call the modifier function with the parameters
            this->modifier(id, nom, type, etat, fournisseur, localisation, quantite);
        });

        // Set the button in the last column of the table
        ui2->tableWidget->setCellWidget(row, 7, modifyButton);

        row++;  // Go to the next row

    }
    afficherGraphiqueMateriels();

}
void MainWindow::setupTableWidget() {
    ui2->tableWidget->setColumnCount(8);  // 7 columns for ID, NOM, TYPE, ETAT, FOURNISSEUR, LOCALISATION, QUANTITE + 1 column for "action"

    ui2->tableWidget->setHorizontalHeaderLabels({"ID", "NOM", "TYPE", "ETAT", "FOURNISSEUR", "LOCALISATION", "QUANTITE", "action"});

    ui2->tableWidget->setRowCount(16);  // Set number of rows as per your data


}


void MainWindow::on_ajouter_clicked() {
    QString nom = ui2->lineEdit_Nom->text().trimmed();
    QString type = ui2->lineEdit_Type->text().trimmed();
    QString etat = ui2->lineEdit_Etat->text().trimmed();
    QString fournisseur = ui2->lineEdit_Fournisseur->text().trimmed();
    QString localisation = ui2->lineEdit_Localisation->text().trimmed();
    // Vérifier si les champs sont vides
    if (nom.isEmpty() || type.isEmpty() || etat.isEmpty() || fournisseur.isEmpty() || localisation.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    // Vérifier la quantité
    bool ok;
    int quantite = ui2->lineEdit_Quantite->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer une quantité valide !");
        return;
    }

    // Vérification spécifique pour le type "logiciel"
    if (type.toLower() == "logiciel") {
        if (quantite != 0) {
            QMessageBox::warning(this, "Erreur", "La quantité doit être 0 pour un logiciel !");
            return;
        }
        if (etat.toLower() != "active" && etat.toLower() != "inactive") {
            QMessageBox::warning(this, "Erreur", "L'état d'un logiciel doit être 'active' ou 'inactive' !");
            return;
        }
    }

    // Vérification spécifique pour le type "matériel"
    if (type.toLower() == "materiel") {
        if (etat.toLower() != "disponible" && etat.toLower() != "indisponible") {
            QMessageBox::warning(this, "Erreur", "L'état d'un matériel doit être 'disponible' ou 'indisponible' !");
            return;
        }
        if (etat.toLower() == "indisponible"){
            if (quantite != 0) {
                QMessageBox::warning(this, "Erreur", "La quantité doit être 0 pour un materiel indisponible !");
                return;
            }


        }
    }



    // Vérifier si les champs sont vides
    if (nom.isEmpty() || type.isEmpty() || etat.isEmpty() || fournisseur.isEmpty() || localisation.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    // Vérifier si les champs contiennent uniquement des lettres et espaces
    QRegularExpression regex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]+$");
    if (!regex.match(nom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Nom' ne doit contenir que des lettres et des espaces !");
        return;
    }
    if (!regex.match(fournisseur).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Fournisseur' ne doit contenir que des lettres et des espaces !");
        return;
    }
    if (!regex.match(localisation).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le champ 'Localisation' ne doit contenir que des lettres et des espaces !");
        return;
    }

    // Si tout est correct, ajouter dans la base de données
    Ressource r(nom, type, etat, fournisseur, localisation, quantite);
    if (r.ajouter()) {
        QMessageBox::information(this, "Succès", "Ajout réussi !");
        afficher();  // Mettre à jour l'affichage
        afficherGraphiqueMateriels();
        QString logMsg = QString("Ajout de la ressource : Nom='%1', Type='%2', État='%3', Fournisseur='%4', Localisation='%5', Quantité=%6")
                             .arg(nom, type, etat, fournisseur, localisation)
                             .arg(quantite);
        Historique::instance().logAction(logMsg);
        if (serial->isOpen()) {
            serial->write("A");
            qDebug() << "🔊 Signal 'A' envoyé à l'Arduino pour ajout.";
        } else {
            qDebug() << "⚠️ Le port série n'est pas ouvert.";
        }
        QString message = "La ressource " + nom + " a été ajoutée.";
        qDebug() << "🔊 Synthèse vocale : " << message;  // 👉 Debug ici
        speech->say(message);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout !");
    }


    QString logMsg = QString("Ajout de la ressource : Nom='%1', Type='%2', État='%3', Fournisseur='%4', Localisation='%5', Quantité=%6")
                         .arg(nom, type, etat, fournisseur, localisation)
                         .arg(quantite);
    Historique::instance().logAction(logMsg);



}

void MainWindow::on_supprimer_clicked() {
    QString idStr = ui2->lineEdit_Id->text().trimmed();  // Récupérer l'ID

    // Vérifier si l'ID est vide
    if (idStr.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Veuillez entrer un ID !");
        return;
    }

    // Vérifier si l'ID ne contient que des chiffres
    QRegularExpression regex("^[0-9]+$");
    if (!regex.match(idStr).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'ID doit contenir uniquement des chiffres !");
        return;
    }

    int id = idStr.toInt();  // Convertir en entier

    // Vérifier si l'ID existe dans la base de données
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM ressource WHERE id = :id");
    checkQuery.bindValue(":id", id);
    if (!checkQuery.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la vérification de l'ID !");
        return;
    }

    checkQuery.next();
    if (checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "L'ID n'existe pas !");
        return;
    }

    // Suppression
    Ressource r;
    if (r.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Suppression réussie !");
        afficher();  // Mettre à jour l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
    }
    if (r.supprimer(id)) {
        afficher();
        QString logMsg = QString("Suppression de la ressource avec ID=%1").arg(id);
        Historique::instance().logAction(logMsg);
        if (serial->isOpen()) {
            serial->write("D");
            qDebug() << "🔊 Signal 'A' envoyé à l'Arduino pour ajout.";
        } else {
            qDebug() << "⚠️ Le port série n'est pas ouvert.";
        }

    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression !");
    }

}
// Définition de la fonction modifierLigne dans mainwindow.cpp

void MainWindow::modifier(int id, const QString &nom, const QString &type, const QString &etat,
                          const QString &fournisseur, const QString &localisation, int quantite)
{
    Ressource r;
    QDialog dialog(this);
    dialog.setWindowTitle("Modifier Ressource");
    QFormLayout form(&dialog);

    QLineEdit *nomEdit = new QLineEdit(nom, &dialog);

    QComboBox *typeEdit = new QComboBox(&dialog);
    typeEdit->addItem("logiciel");
    typeEdit->addItem("materiel");
    typeEdit->setCurrentText(type);

    QComboBox *etatEdit = new QComboBox(&dialog);
    etatEdit->addItem("active");
    etatEdit->addItem("inactive");
    etatEdit->addItem("disponible");
    etatEdit->addItem("indisponible");
    etatEdit->setCurrentText(etat);

    QLineEdit *fournisseurEdit = new QLineEdit(fournisseur, &dialog);
    QLineEdit *localisationEdit = new QLineEdit(localisation, &dialog);
    QSpinBox *quantiteEdit = new QSpinBox(&dialog);

    // Initialisation correcte de la quantité
    if (type.toLower() == "logiciel") {
        quantiteEdit->setRange(0, 0);
        quantiteEdit->setValue(0);
    } else if (etat.toLower() == "indisponible") {
        quantiteEdit->setRange(0, 0);
        quantiteEdit->setValue(0);
    } else if (etat.toLower() == "disponible") {
        quantiteEdit->setRange(1, 1000);
        quantiteEdit->setValue(qMax(1, quantite));
    } else {
        quantiteEdit->setRange(0, 1000);
        quantiteEdit->setValue(quantite);
    }

    // Mise à jour dynamique du QSpinBox selon le type
    connect(typeEdit, &QComboBox::currentTextChanged, [&](const QString &newType) {
        if (newType.toLower() == "logiciel") {
            quantiteEdit->setRange(0, 0);
            quantiteEdit->setValue(0);
        } else {
            if (etatEdit->currentText().toLower() == "disponible") {
                quantiteEdit->setRange(1, 1000);
                if (quantiteEdit->value() < 1)
                    quantiteEdit->setValue(1);
            } else if (etatEdit->currentText().toLower() == "indisponible") {
                quantiteEdit->setRange(0, 0);
                quantiteEdit->setValue(0);
            } else {
                quantiteEdit->setRange(0, 1000);
                quantiteEdit->setValue(quantite);
            }
        }
    });

    connect(etatEdit, &QComboBox::currentTextChanged, [&](const QString &newEtat) {
        QString currentType = typeEdit->currentText().toLower();
        if (newEtat.toLower() == "indisponible") {
            quantiteEdit->setRange(0, 0);
            quantiteEdit->setValue(0);
        } else if (newEtat.toLower() == "disponible") {
            quantiteEdit->setRange(1, 1000);
            if (quantiteEdit->value() < 1)
                quantiteEdit->setValue(1);
        } else {
            if (currentType == "logiciel") {
                quantiteEdit->setRange(0, 0);
                quantiteEdit->setValue(0);
            } else {
                quantiteEdit->setRange(0, 1000);
                quantiteEdit->setValue(quantite);
            }
        }
    });

    // Ajouter les champs au formulaire
    form.addRow("Nom:", nomEdit);
    form.addRow("Type:", typeEdit);
    form.addRow("État:", etatEdit);
    form.addRow("Fournisseur:", fournisseurEdit);
    form.addRow("Localisation:", localisationEdit);
    form.addRow("Quantité:", quantiteEdit);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    form.addRow(&buttonBox);

    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QString newNom = nomEdit->text().trimmed();
        QString newType = typeEdit->currentText().trimmed();
        QString newEtat = etatEdit->currentText().trimmed();
        QString newFournisseur = fournisseurEdit->text().trimmed();
        QString newLocalisation = localisationEdit->text().trimmed();
        int newQuantite = quantiteEdit->value();

        if (newNom.isEmpty() || newType.isEmpty() || newEtat.isEmpty() || newFournisseur.isEmpty() || newLocalisation.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
            return;
        }

        QRegularExpression regex("^[A-Za-zÀ-ÖØ-öø-ÿ -]+$");
        if (!regex.match(newNom).hasMatch() ||
            !regex.match(newFournisseur).hasMatch() ||
            !regex.match(newLocalisation).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "Seules les lettres et espaces sont autorisés !");
            return;
        }

        if (newType.toLower() == "logiciel" && newQuantite != 0) {
            QMessageBox::warning(this, "Erreur", "La quantité doit être 0 pour un logiciel !");
            return;
        }
        if (newEtat.toLower() == "indisponible" && newQuantite != 0) {
            QMessageBox::warning(this, "Erreur", "La quantité doit être 0 !");
            return;
        }
        if (newEtat.toLower() == "disponible" && newQuantite < 1) {
            QMessageBox::warning(this, "Erreur", "La quantité doit être au minimum 1 !");
            return;
        }

        if (newType.toLower() == "logiciel" && (newEtat.toLower() != "active" && newEtat.toLower() != "inactive")) {
            QMessageBox::warning(this, "Erreur", "L'état d'un logiciel doit être 'active' ou 'inactive' !");
            return;
        }
        if (newType.toLower() == "materiel" && (newEtat.toLower() != "disponible" && newEtat.toLower() != "indisponible")) {
            QMessageBox::warning(this, "Erreur", "L'état d'un matériel doit être 'disponible' ou 'indisponible' !");
            return;
        }

        // Si toutes les conditions sont validées, alors procéder à la modification
        qDebug() << "Modification des valeurs pour l'ID:" << id;
        qDebug() << "Nom:" << newNom;
        qDebug() << "Type:" << newType;
        qDebug() << "État:" << newEtat;
        qDebug() << "Fournisseur:" << newFournisseur;
        qDebug() << "Localisation:" << newLocalisation;
        qDebug() << "Quantité:" << newQuantite;

        bool success = r.modifier(id, newNom, newType, newEtat, newFournisseur, newLocalisation, newQuantite);
        if (success) {
            QMessageBox::information(this, "Succès", "Modification réussie !");

            Ressource nouvelleRessource(newNom, newType, newEtat, newFournisseur, newLocalisation, newQuantite);
            RessourceManager::verifierEtNotifier(nouvelleRessource);
            afficher();  // rafraîchir

            if (serial->isOpen()) {
                serial->write("M");
                qDebug() << "🔊 Signal 'A' envoyé à l'Arduino pour ajout.";
            } else {
                qDebug() << "⚠️ Le port série n'est pas ouvert.";
            }


        }
        else {
            QMessageBox::critical(this, "Erreur", "Échec de la modification !");
        }
        // Log l'action, que la modification soit réussie ou échouée
        QString logMsg = QString("Modification de la ressource ID=%1 : Nom='%2', Type='%3', État='%4', Fournisseur='%5', Localisation='%6', Quantité=%7")
                             .arg(id)
                             .arg(newNom, newType, newEtat, newFournisseur, newLocalisation)
                             .arg(newQuantite);
        Historique::instance().logAction(logMsg);


    }

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui1(new Ui::MainWindow_Projects),
    ui2(new Ui::MainWindow_Ressources)
{
    // Setup des interfaces
    QWidget *projectsWidget = new QWidget();
    ui1->setupUi(projectsWidget);

    QWidget *resourcesWidget = new QWidget();
    ui2->setupUi(resourcesWidget);

    // Stacked Widget
    stack = new QStackedWidget(this);
    stack->addWidget(projectsWidget);   // Index 0 - Projets
    stack->addWidget(resourcesWidget);  // Index 1 - Ressources
    setCentralWidget(stack);

    // Initialisations
    m_speechNotifier = new SpeechNotifier(this);
    serial = new QSerialPort(this);
    speech = new QTextToSpeech(this);
    speech->setLocale(QLocale(QLocale::French));

    // Connexions
    connect(ui1->pushButton_26, &QPushButton::clicked,
            this, &MainWindow::switchToRessources);
    connect(ui2->projet, &QPushButton::clicked,
            this, &MainWindow::switchToProjectsUI);
    // Connecte ton bouton pour basculer
    connect(ui1->pushButton_26, &QPushButton::clicked, this, &MainWindow::switchToRessources);


    // --- Manually Created Widgets ---
    tableWidget = new QTableWidget(this);
    lineEdit_Nom = new QLineEdit(this);
    lineEdit_Type = new QLineEdit(this);
    // ... (add other QLineEdit widgets as before)

    // Form layout for manual widgets
    QFormLayout *formLayout = new QFormLayout();
    formLayout->addRow("Nom:", lineEdit_Nom);
    formLayout->addRow("Type:", lineEdit_Type);
    // ... (add other rows)

    // Add manual widgets to main layout
    //mainLayout->addLayout(formLayout);
    //mainLayout->addWidget(tableWidget);
    lineEdit_Etat = new QLineEdit(this);
    lineEdit_Fournisseur = new QLineEdit(this);
    lineEdit_Localisation = new QLineEdit(this);
    lineEdit_Quantite = new QLineEdit(this);
    lineEdit_Id = new QLineEdit(this);
    lineEdit_Recherche = new QLineEdit(this);
    refreshTable();
    connect(ui1->projectTable, &QTableWidget::cellClicked, this, &MainWindow::on_projectTable_cellClicked);
    connect(ui1->BouttonRechProjet_5, &QPushButton::clicked, this, &MainWindow::on_searchButton_clicked);
    connect(ui1->TriButton, &QPushButton::clicked, this, &MainWindow::on_TriButton_clicked);
    connect(ui1->generateContractButton, &QPushButton::clicked, this, &MainWindow::on_generateContractButton_clicked);
    m_speechNotifier = new SpeechNotifier(this);
    // Dans le constructeur
    server = new ChatServer(this);
    client = new ChatClient(this);

    //connect(server, &ChatServer::newMessage, this, &MainWindow::displayMessage);
    //connect(client, &ChatClient::messageReceived, this, &MainWindow::displayMessage);

    // Connectez vos boutons UI
    //connect(ui1->startServerButton, &QPushButton::clicked, this, &MainWindow::toggleServer);
    //connect(ui1->sendButton, &QPushButton::clicked, this, &MainWindow::sendChatMessage);
    serial = new QSerialPort(this); // ✅ initialise la variable membre
    // Création de l'objet dans le constructeur de ta classe (ou au bon endroit)
    speech = new QTextToSpeech(this);
    speech->setLocale(QLocale(QLocale::French, QLocale::France)); // facultatif : met la langue en français



    serial->setPortName("COM3");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::WriteOnly)) {
        qDebug() << "✅ Port série ouvert pour output";
    } else {
        qDebug() << "❌ Erreur ouverture série:" << serial->errorString();
    }


    // Exemple : dire le nom de la ressource



    // Les connect doivent être en dehors du if/else
    connect(ui2->annuletri, &QPushButton::clicked, this, &MainWindow::on_annulertri_clicked);
    connect(ui2->trimateriel, &QPushButton::clicked, this, &MainWindow::on_trimateriel_clicked);
    connect(ui2->trilogiciel, &QPushButton::clicked, this, &MainWindow::on_trilogiciel_clicked);
    connect(ui2->pushButton_exporterpdf, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    connect(ui2->pushButton_Rechercher, &QPushButton::clicked, this, &MainWindow::rechercher);

    QRegularExpression regex("^[A-Za-zÀ-ÖØ-öø-ÿ ]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui2->lineEdit_Nom->setValidator(validator);
    ui2->lineEdit_Type->setValidator(validator);
    QRegularExpression regexType("^(logiciel|materiel)$", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionValidator *validatorType = new QRegularExpressionValidator(regexType, this);
    ui2->lineEdit_Type->setValidator(validatorType);
    ui2->lineEdit_Etat->setValidator(validator);
    QRegularExpression regexEtat("^(active|inactive|disponible|indisponible)$", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionValidator *validatorEtat = new QRegularExpressionValidator(regexEtat, this);
    ui2->lineEdit_Etat->setValidator(validatorEtat);
    ui2->lineEdit_Fournisseur->setValidator(validator);
    ui2->lineEdit_Localisation->setValidator(validator);
    QRegularExpression regexQuantite("^[0-9]+$");
    QRegularExpressionValidator *validatorQuantite = new QRegularExpressionValidator(regexQuantite, this);
    ui2->lineEdit_Quantite->setValidator(validatorQuantite);

    Ressource r;
    setupTableWidget();
    afficher();
    this->setWindowTitle("ELICAR");

    QPixmap pixmap("C:/Users/tez/Desktop/dash/images/logo.png");
    if (!pixmap.isNull()) {
        QPixmap resizedPixmap = pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->setWindowIcon(QIcon(resizedPixmap));
    } else {
        qDebug() << "L'image du logo n'a pas pu être chargée!";
    }

    int columnActions = 7;
    ui2->tableWidget->setColumnWidth(columnActions, 200);
}

MainWindow::~MainWindow()
{
    delete ui1;
    delete ui2;
}

//crud
void MainWindow::refreshTable()
{
    Projet projet;
     ui1->projectTable->setColumnCount(7);
     ui1->projectTable->setHorizontalHeaderLabels({"ID_PROJET", "NOM", "DESCRIPTION", "DATE_DEBUT", "TYPE", "BUDGET", "ETAT"});
        projet.display(ui1->projectTable);
        if (ui1->projectTable->rowCount() == 0) {
            QMessageBox::warning(this, "Attention", "Aucune donnée à afficher dans la table des événements.");
            qDebug() << "Aucune ligne trouvée dans le QTableWidget.";
            return;
        }
        qDebug() << "Données chargées dans projectTable. Lignes:" << ui1->projectTable->rowCount() << "Colonnes:" << ui1->projectTable->columnCount();
    }

void MainWindow::on_ajouterProjet_clicked()
{

    QString projectId = ui1->project_id->text().trimmed();
    QString projectName = ui1->project_name->text().trimmed();
    QString projectDescription = ui1->project_description->text().trimmed();
    QDate projectDateDeb = QDate::fromString(ui1->project_date_deb->text(), "yyyy-MM-dd");
    QString projectType = ui1->project_type->text().trimmed();
    bool budgetOk;
    double projectBudget = ui1->project_budget->text().toDouble(&budgetOk);
    QString projectEtat = ui1->project_etat->text().trimmed();

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
        qDebug() << "ajouter trés bien";


        ui1->project_id->clear();
        ui1->project_name->clear();
        ui1->project_description->clear();
        ui1->project_date_deb->clear();
        ui1->project_type->clear();
        ui1->project_budget->clear();
        ui1->project_etat->clear();

        refreshTable();
        m_speechNotifier->notifyProjectAdded(projectName);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du projet : " + projet.getLastError());
    }

}

void MainWindow::on_modifierProjet_clicked()
{  if (ui1->project_id->text().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un projet à modifier.");
        return;
    }

    QString projectId = ui1->project_id->text().trimmed();
    QString projectName = ui1->project_name->text().trimmed();
    QString projectDescription = ui1->project_description->text().trimmed();
    QDate projectDateDeb = ui1->project_date_deb->date();
    QString projectType = ui1->project_type->text().trimmed();

    bool budgetOk;
    double projectBudget = ui1->project_budget->text().toDouble(&budgetOk);
    QString projectEtat = ui1->project_etat->text().trimmed();

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
        ui1->project_id->clear();
        ui1->project_name->clear();
        ui1->project_description->clear();
        ui1->project_date_deb->clear();
        ui1->project_type->clear();
        ui1->project_budget->clear();
        ui1->project_etat->clear();

        refreshTable();
        m_speechNotifier->notifyProjectUpdated(projectName);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du projet.");
    }
}

void MainWindow::on_suppProjet_clicked()
{
    int row = ui1->projectTable->currentRow();
    QString projectName = ui1->project_name->text().trimmed();

    // Vérifier si une ligne est bien sélectionnée
    if (row < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un projet à supprimer.");
        return;
    }

    // Récupérer l'ID du projet à partir de la table
    QString projectId = ui1->projectTable->item(row, 0)->text();

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
        ui1->projectTable->removeRow(row);
        refreshTable();
        m_speechNotifier->notifyProjectDeleted(projectName);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression du projet.");
    }
}

void MainWindow::on_projectTable_cellClicked(int row, int column)
{
    // Vérification que la ligne sélectionnée est valide
    if (row < 0 || column < 0 || !ui1->projectTable->item(row, 0)) {
        return;
    }

    // Récupération des données de la ligne sélectionnée
    QTableWidgetItem *itemId = ui1->projectTable->item(row, 0);
    QTableWidgetItem *itemName = ui1->projectTable->item(row, 1);
    QTableWidgetItem *itemDesc = ui1->projectTable->item(row, 2);
    QTableWidgetItem *itemDate = ui1->projectTable->item(row, 3);
    QTableWidgetItem *itemType = ui1->projectTable->item(row, 4);
    QTableWidgetItem *itemBudget = ui1->projectTable->item(row, 5);
    QTableWidgetItem *itemEtat = ui1->projectTable->item(row, 6);

    if (!itemId || !itemName || !itemDesc || !itemDate || !itemType || !itemBudget || !itemEtat) {
        return; // Évite tout crash si une cellule est vide
    }

    // Affichage des données dans les champs de saisie
    ui1->project_id->setText(itemId->text());
    ui1->project_name->setText(itemName->text());
    ui1->project_description->setText(itemDesc->text());
    ui1->project_type->setText(itemType->text());

    // Vérification et conversion correcte du budget
    bool budgetOk;
    double budget = itemBudget->text().toDouble(&budgetOk);
    if (budgetOk) {
        ui1->project_budget->setText(QString::number(budget, 'f', 2));
    } else {
        QMessageBox::warning(this, "Erreur", "Valeur de budget invalide.");
    }

    ui1->project_etat->setText(itemEtat->text());
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
    QString searchText = ui1->taperRech_5->text().trimmed().toLower(); // Get search text (case-insensitive)
    int rowCount = ui1->projectTable->rowCount();
    int columnCount = ui1->projectTable->columnCount();

    for (int row = 0; row < rowCount; ++row) {
        bool matchFound = false;
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem *item = ui1->projectTable->item(row, col);
            if (item && item->text().toLower().contains(searchText)) {
                matchFound = true;
                break;
            }
        }
        // Show/hide row based on match
        ui1->projectTable->setRowHidden(row, !matchFound);
    }
}

void MainWindow::on_TriButton_clicked()
{
    QString colonneTri = ui1->rechProjet_5->currentText();

    if (colonneTri == "NOM") {
        // Tri alphabétique
        ui1->projectTable->sortByColumn(1, Qt::AscendingOrder);
    }
    else if (colonneTri == "BUDGET") {
        // Tri du budget (du plus élevé au plus bas)
        ui1->projectTable->sortByColumn(5, Qt::DescendingOrder);
    }
    else if (colonneTri == "DATE_DEBUT") {
        // Tri par date (du plus récent au plus ancien)
        ui1->projectTable->sortByColumn(3, Qt::DescendingOrder);
    }
}

void MainWindow::on_generateContractButton_clicked() {
    if (ui1->project_id->text().isEmpty()) {
        QMessageBox::warning(this, "Error", "Please select a project first.");
        return;
    }

    bool ok;
    QString clientName = QInputDialog::getText(this, "Client Information",
                                               "Enter Client Name:", QLineEdit::Normal,
                                               "", &ok);
    if (!ok || clientName.isEmpty()) {
        return;
    }

    QString projectName = ui1->project_name->text();
    QString projectDescription = ui1->project_description->text();
    double budget = ui1->project_budget->text().toDouble();
    QDate startDate = ui1->project_date_deb->date();
    QString projectType = ui1->project_type->text();

    generateContract(clientName, projectName, projectDescription, budget, startDate, projectType);
}

QString MainWindow::generateContractText(const QString &clientName, const QString &projectName,
                                         const QString &projectDescription, double budget,
                                         const QDate &startDate, const QString &projectType) {
    QString contract;

    contract += "ARCHITECTURAL DESIGN AGREEMENT\n\n";
    contract += "This Agreement is made and entered into as of " + QDate::currentDate().toString("MMMM d, yyyy") + " by and between:\n\n";
    contract += "CLIENT: " + clientName + "\n";
    contract += "ARCHITECT: [Elyes Khiari]\n\n";
    contract += "1. PROJECT DESCRIPTION\n";
    contract += "The Architect agrees to provide professional services for the following project:\n";
    contract += "Project Name: " + projectName + "\n";
    contract += "Project Type: " + projectType + "\n";
    contract += "Description: " + projectDescription + "\n";
    contract += "Estimated Start Date: " + startDate.toString("MMMM d, yyyy") + "\n\n";
    contract += "2. SCOPE OF SERVICES\n";
    contract += "The Architect's services shall include but not be limited to:\n";
    contract += "- Schematic Design\n- Design Development\n- Construction Documents\n- Construction Administration\n\n";
    contract += "3. COMPENSATION\n";
    contract += "The Client agrees to pay the Architect a total fee of $" + QString::number(budget, 'f', 2) + " for the services described above.\n\n";
    contract += "4. TERM AND TERMINATION\n";
    contract += "This Agreement shall commence on the date first written above and shall continue until the completion of all services.\n\n";
    contract += "5. SIGNATURES\n\n";
    contract += "CLIENT:\n__________________________\nDate: ___________\n\n";
    contract += "ARCHITECT:\n__________________________\nDate: ___________\n";

    return contract;
}

void MainWindow::generateContract(const QString &clientName, const QString &projectName,
                                  const QString &projectDescription, double budget,
                                  const QDate &startDate, const QString &projectType) {
    QString contractText = generateContractText(clientName, projectName, projectDescription,
                                                budget, startDate, projectType);

    // Create a dialog to display and save the contract
    QDialog *contractDialog = new QDialog(this);
    contractDialog->setWindowTitle("Project Contract");
    contractDialog->resize(600, 800);

    QVBoxLayout *layout = new QVBoxLayout(contractDialog);

    QTextEdit *contractDisplay = new QTextEdit();
    contractDisplay->setPlainText(contractText);
    contractDisplay->setReadOnly(true);
    layout->addWidget(contractDisplay);

    QHBoxLayout *buttonLayout = new QHBoxLayout();

    QPushButton *saveButton = new QPushButton("Save Contract");
    QPushButton *printButton = new QPushButton("Print");
    QPushButton *closeButton = new QPushButton("Close");

    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(printButton);
    buttonLayout->addWidget(closeButton);
    layout->addLayout(buttonLayout);


    connect(printButton, &QPushButton::clicked, [=]() {
        QString fileName = QFileDialog::getSaveFileName(this, "Export Contract as PDF",
                                                        QDir::homePath() + "/" + projectName + "_Contract.pdf",
                                                        "PDF Files (*.pdf)");
        if (!fileName.isEmpty()) {
            QPdfWriter pdfWriter(fileName);
            pdfWriter.setPageSize(QPageSize::A4);

            QPainter painter(&pdfWriter);
            if (!painter.isActive()) {
                QMessageBox::warning(this, "Error", "Could not create PDF file.");
                return;
            }

            QFont font = painter.font();
            font.setPointSize(12);
            painter.setFont(font);

            QTextDocument doc;
            doc.setPlainText(contractText);
            doc.drawContents(&painter);

            painter.end();
            QMessageBox::information(this, "Success", "Contract exported as PDF.");
        }
    });

    connect(closeButton, &QPushButton::clicked, contractDialog, &QDialog::close);

    contractDialog->exec();
}
//void MainWindow::toggleServer()
/*{
    if (!isServerRunning) {
        //server->startServer(ui1->serverPortSpinBox->value());
        //ui1->startServerButton->setText("Arrêter le serveur");
        isServerRunning = true;
    } else {
        server->close();
        ui->startServerButton->setText("Démarrer le serveur");
        isServerRunning = false;
    }
}
*/
/*void MainWindow::sendChatMessage()
{
    QString message = ui1->messageLineEdit->text();
    if (!message.isEmpty()) {
        client->sendMessage(message);
        ui->messageLineEdit->clear();
        displayMessage("Moi: " + message); // Feedback immédiat
    }
}
*/
/*void MainWindow::displayMessage(const QString &message)
{
    ui1->chatTextEdit->append(message);
}*/

