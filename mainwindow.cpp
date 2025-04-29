#include "mainwindow.h"
#include "ressource.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include <QListWidget>
#include <QMessageBox>
#include <QSqlError>
#include <QTimer>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QInputDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QFormLayout>
#include <QSpinBox>
#include "ressource.h"
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QComboBox>
#include <QPdfWriter>
#include <iostream>
#include "historique.h"
#include <QTextEdit>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTextToSpeech>


void MainWindow::on_annulertri_clicked() {
    afficher();
}

void MainWindow::affichertri(QString filtre) {
    ui->tableWidget->clear();  // Nettoyer le tableau
    ui->tableWidget->setRowCount(0);

    // Définir les noms des colonnes
    QStringList headers = {"ID", "Nom", "Type", "État", "Fournisseur", "Localisation", "Quantité", "Action"};
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);

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
            ui->tableWidget->insertRow(row);

            for (int col = 0; col < 7; col++) {  // Mettre les valeurs des 7 colonnes
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
            }

            // Ajouter le bouton Modifier
            QPushButton *btnModifier = new QPushButton("Modifier");
            btnModifier->setStyleSheet("QPushButton { background-color: #3498db; color: white; border-radius: 5px; padding: 5px; }"
                                        "QPushButton:hover { background-color: #2980b9; }");
            btnModifier->setFixedSize(70, 25);
            connect(btnModifier, &QPushButton::clicked, this, [this, row]() {
                int id = ui->tableWidget->item(row, 0)->text().toInt();
                QString nom = ui->tableWidget->item(row, 1)->text();
                QString type = ui->tableWidget->item(row, 2)->text();
                QString etat = ui->tableWidget->item(row, 3)->text();
                QString fournisseur = ui->tableWidget->item(row, 4)->text();
                QString localisation = ui->tableWidget->item(row, 5)->text();
                int quantite = ui->tableWidget->item(row, 6)->text().toInt();

                modifier(id, nom, type, etat, fournisseur, localisation, quantite);
            });

            ui->tableWidget->setCellWidget(row, 7, btnModifier);  // Colonne "Action" pour le bouton

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
    ui->tableWidget->setRowCount(0);

    // Récupérer le texte du champ de recherche
    QString rechercheNom = ui->lineEdit_Recherche->text();

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
        ui->tableWidget->insertRow(row);

        int id = query.value("id").toInt();
        QString nom = query.value("nom").toString();
        QString type = query.value("type").toString();
        QString etat = query.value("etat").toString();
        QString fournisseur = query.value("fournisseur").toString();
        QString localisation = query.value("localisation").toString();
        int quantite = query.value("quantite").toInt();

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(nom));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(type));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(etat));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(fournisseur));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(localisation));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(QString::number(quantite)));

        QPushButton *modifierButton = new QPushButton("Modifier");
        modifierButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; border-radius: 5px; padding: 5px; }"
                                      "QPushButton:hover { background-color: #2980b9; }");

        connect(modifierButton, &QPushButton::clicked, this, [this, id, nom, type, etat, fournisseur, localisation, quantite]() {
            modifier(id, nom, type, etat, fournisseur, localisation, quantite);
        });

        ui->tableWidget->setCellWidget(row, 7, modifierButton);

        row++;
    }
}


void MainWindow::afficherGraphiqueMateriels() {
    // Nettoyage de l'ancien contenu
    QLayoutItem *item;
    while ((item = ui->widgetGraphLayout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            item->widget()->deleteLater();
        }
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
    ui->widgetGraphLayout->addWidget(graphWidget);
}


void MainWindow::afficher() {
    // Clear the table before filling it
    ui->tableWidget->setRowCount(0); // Remove any existing rows

    // Prepare the SQL query
    QSqlQuery query;
    query.exec("SELECT * FROM ressource");

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);  // Insert a new row

        // Assign data to correct columns based on the column index
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("id").toString())); // ID
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("nom").toString())); // NOM
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("type").toString())); // TYPE
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("etat").toString())); // ETAT
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("fournisseur").toString())); // FOURNISSEUR
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("localisation").toString())); // LOCALISATION
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("quantite").toString())); // QUANTITE

        QPushButton *modifyButton = new QPushButton("Modifier");
        modifyButton->setStyleSheet("QPushButton { background-color: #3498db; color: white; border-radius: 5px; padding: 5px; }"
                                    "QPushButton:hover { background-color: #2980b9; }");
        modifyButton->setFixedSize(70, 25);
        connect(modifyButton, &QPushButton::clicked, [this, row]() {
            // Get the values from the table row and pass them to the modifier function
            int id = ui->tableWidget->item(row, 0)->text().toInt();
            QString nom = ui->tableWidget->item(row, 1)->text();
            QString type = ui->tableWidget->item(row, 2)->text();
            QString etat = ui->tableWidget->item(row, 3)->text();
            QString fournisseur = ui->tableWidget->item(row, 4)->text();
            QString localisation = ui->tableWidget->item(row, 5)->text();
            int quantite = ui->tableWidget->item(row, 6)->text().toInt();

            // Call the modifier function with the parameters
            this->modifier(id, nom, type, etat, fournisseur, localisation, quantite);
        });

        // Set the button in the last column of the table
        ui->tableWidget->setCellWidget(row, 7, modifyButton);

        row++;  // Go to the next row

    }
    afficherGraphiqueMateriels();

}
void MainWindow::setupTableWidget() {
    ui->tableWidget->setColumnCount(8);  // 7 columns for ID, NOM, TYPE, ETAT, FOURNISSEUR, LOCALISATION, QUANTITE + 1 column for "action"

    ui->tableWidget->setHorizontalHeaderLabels({"ID", "NOM", "TYPE", "ETAT", "FOURNISSEUR", "LOCALISATION", "QUANTITE", "action"});

    ui->tableWidget->setRowCount(16);  // Set number of rows as per your data


}


void MainWindow::on_ajouter_clicked() {
    QString nom = ui->lineEdit_Nom->text().trimmed();
    QString type = ui->lineEdit_Type->text().trimmed();
    QString etat = ui->lineEdit_Etat->text().trimmed();
    QString fournisseur = ui->lineEdit_Fournisseur->text().trimmed();
    QString localisation = ui->lineEdit_Localisation->text().trimmed();
    // Vérifier si les champs sont vides
    if (nom.isEmpty() || type.isEmpty() || etat.isEmpty() || fournisseur.isEmpty() || localisation.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    // Vérifier la quantité
    bool ok;
    int quantite = ui->lineEdit_Quantite->text().toInt(&ok);
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
    QString idStr = ui->lineEdit_Id->text().trimmed();  // Récupérer l'ID

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
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    connect(ui->annuletri, &QPushButton::clicked, this, &MainWindow::on_annulertri_clicked);
    connect(ui->trimateriel, &QPushButton::clicked, this, &MainWindow::on_trimateriel_clicked);
    connect(ui->trilogiciel, &QPushButton::clicked, this, &MainWindow::on_trilogiciel_clicked);
    connect(ui->pushButton_exporterpdf, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    connect(ui->pushButton_Rechercher, &QPushButton::clicked, this, &MainWindow::rechercher);

    QRegularExpression regex("^[A-Za-zÀ-ÖØ-öø-ÿ ]+$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->lineEdit_Nom->setValidator(validator);
    ui->lineEdit_Type->setValidator(validator);
    QRegularExpression regexType("^(logiciel|materiel)$", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionValidator *validatorType = new QRegularExpressionValidator(regexType, this);
    ui->lineEdit_Type->setValidator(validatorType);
    ui->lineEdit_Etat->setValidator(validator);
    QRegularExpression regexEtat("^(active|inactive|disponible|indisponible)$", QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionValidator *validatorEtat = new QRegularExpressionValidator(regexEtat, this);
    ui->lineEdit_Etat->setValidator(validatorEtat);
    ui->lineEdit_Fournisseur->setValidator(validator);
    ui->lineEdit_Localisation->setValidator(validator);
    QRegularExpression regexQuantite("^[0-9]+$");
    QRegularExpressionValidator *validatorQuantite = new QRegularExpressionValidator(regexQuantite, this);
    ui->lineEdit_Quantite->setValidator(validatorQuantite);

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
    ui->tableWidget->setColumnWidth(columnActions, 200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

