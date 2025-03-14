#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "formation.h"
#include <QMessageBox>

// Constructeur de MainWindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Afficher la liste des formations au démarrage
    ui->tableView->setModel(F.afficher());
}

// Destructeur de MainWindow
MainWindow::~MainWindow()
{
    delete ui;
}

// Bouton Ajouter
void MainWindow::on_btnAjouter_clicked() {
    int id = ui->lineEdit_id->text().toInt();
    QString thematique = ui->lineEdit_thematique->text().trimmed();
    QString date_d = ui->lineEdit_date->text().trimmed();
    QString nom = ui->lineEdit_nom->text().trimmed();
    QString description = ui->lineEdit_description->text().trimmed();

    // Vérification des champs
    if (thematique.isEmpty() || date_d.isEmpty() || nom.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }

    Formation newFormation(id, thematique, date_d, nom, description);

    if (newFormation.ajouter()) {
        QMessageBox::information(this, "Succès", "Formation ajoutée !");
        ui->tableView->setModel(F.afficher());  // Mise à jour de l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Ajout échoué !");
    }
}

// Bouton Supprimer
void MainWindow::on_btnSupprimer_clicked() {
    int id = ui->lineEdit_idSupp->text().toInt();

    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide !");
        return;
    }

    if (F.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Formation supprimée !");
        ui->tableView->setModel(F.afficher());  // Mise à jour de l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Suppression échouée !");
    }
}
