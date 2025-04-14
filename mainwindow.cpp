#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QIntValidator>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setupUI();
    setupConnections();
    afficherTableView();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupUI() {
    ui->lineEdit_id->setPlaceholderText("ID Formation");
    ui->lineEdit_thematique->setPlaceholderText("Thématique");
    ui->lineEdit_nom->setPlaceholderText("Nom*");
    ui->lineEdit_description->setPlaceholderText("Description");
    ui->lineEdit_idSupp->setPlaceholderText("ID à supprimer");
    ui->lineEdit_idRecherche->setPlaceholderText("Entrer l'ID");

    ui->dateEdit_date->setDisplayFormat("dd/MM/yyyy");
    ui->dateEdit_date->setDate(QDate::currentDate());
    ui->dateEdit_rechercheDate->setDisplayFormat("dd/MM/yyyy");
    ui->dateEdit_rechercheDate->setDate(QDate::currentDate());

    ui->lineEdit_id->setValidator(new QIntValidator(0, 999999, this));
    ui->lineEdit_idSupp->setValidator(new QIntValidator(1, 999999, this));
    ui->lineEdit_idRecherche->setValidator(new QIntValidator(1, 999999, this));

    ui->btnAjouter->setToolTip("Ajouter une nouvelle formation");
    ui->btnModifier->setToolTip("Modifier la formation sélectionnée");
    ui->btnSupprimer->setToolTip("Supprimer la formation sélectionnée");
    ui->btnRechercherId->setToolTip("Rechercher par ID");
    ui->btnRechercherDate->setToolTip("Rechercher par date de début");
    ui->btnTrierThematique->setToolTip("Trier par thématique");

    // Ajouter un bouton pour envoyer un SMS
    ui->btnSendSms->setToolTip("Envoyer un SMS");
}

void MainWindow::setupConnections() {
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::on_btnAjouter_clicked);
    connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::on_btnModifier_clicked);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::on_btnSupprimer_clicked);
    connect(ui->btnRechercherId, &QPushButton::clicked, this, &MainWindow::on_btnRechercherId_clicked);
    connect(ui->btnRechercherDate, &QPushButton::clicked, this, &MainWindow::on_btnRechercherDate_clicked);
    connect(ui->btnTrierThematique, &QPushButton::clicked, this, &MainWindow::on_btnTrierThematique_clicked);
    connect(ui->btnSendSms, &QPushButton::clicked, this, &MainWindow::on_btnSendSms_clicked);  // Connexion du bouton SMS
}

void MainWindow::on_btnSendSms_clicked() {
    // Récupérer les informations du formulaire (par exemple, un numéro de téléphone et un message)
    QString toPhone = ui->lineEdit_thematique->text();  // Utilisation de la thématique comme exemple pour le téléphone
    QString message = ui->lineEdit_nom->text();  // Utilisation du nom comme exemple pour le message

    if (toPhone.isEmpty() || message.isEmpty()) {
        showError("Le numéro de téléphone et le message ne peuvent pas être vides.");
        return;
    }

    // Appeler la méthode pour envoyer le SMS
    smsManager.sendSms(toPhone, message);

    showSuccess("SMS envoyé !");
}

void MainWindow::afficherTableView() {
    QSqlQueryModel* oldModel = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    QSqlQueryModel* model = F.afficher();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    delete oldModel;
}

void MainWindow::clearFields() {
    ui->lineEdit_id->clear();
    ui->lineEdit_thematique->clear();
    ui->lineEdit_nom->clear();
    ui->lineEdit_description->clear();
    ui->dateEdit_date->setDate(QDate::currentDate());
}

void MainWindow::showError(const QString &message) {
    QMessageBox::critical(this, "Erreur", message);
}

void MainWindow::showSuccess(const QString &message) {
    QMessageBox::information(this, "Succès", message);
}

void MainWindow::on_btnAjouter_clicked() {
    int id = ui->lineEdit_id->text().toInt();
    QString thematique = ui->lineEdit_thematique->text();
    QString date_d = ui->dateEdit_date->date().toString("yyyy-MM-dd");
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();

    if (nom.isEmpty() || date_d.isEmpty()) {
        showError("Les champs marqués d'un * sont obligatoires.");
        return;
    }

    Formation f(id, thematique, date_d, nom, description);
    if (f.ajouter()) {
        showSuccess("Formation ajoutée avec succès !");
        clearFields();
        afficherTableView();
    } else {
        showError("Échec de l'ajout de la formation !");
    }
}

void MainWindow::on_btnSupprimer_clicked() {
    int id = ui->lineEdit_idSupp->text().toInt();
    if (id <= 0) {
        showError("Veuillez entrer un ID valide.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                "Voulez-vous vraiment supprimer la formation ID: " + QString::number(id) + "?",
                                QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (F.supprimer(id)) {
            showSuccess("Formation supprimée avec succès !");
            ui->lineEdit_idSupp->clear();
            afficherTableView();
        } else {
            showError("Échec de la suppression de la formation !");
        }
    }
}

void MainWindow::on_btnModifier_clicked() {
    int id = ui->lineEdit_id->text().toInt();
    QString thematique = ui->lineEdit_thematique->text();
    QString date_d = ui->dateEdit_date->date().toString("yyyy-MM-dd");
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();

    if (nom.isEmpty() || date_d.isEmpty()) {
        showError("Les champs marqués d'un * sont obligatoires.");
        return;
    }

    Formation f(id, thematique, date_d, nom, description);
    if (f.modifier()) {
        showSuccess("Formation modifiée avec succès !");
        clearFields();
        afficherTableView();
    } else {
        showError("Échec de la modification de la formation !");
    }
}

void MainWindow::on_btnTrierThematique_clicked() {
    QSqlQueryModel* oldModel = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    QSqlQueryModel* model = F.sort();
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    delete oldModel;
}

void MainWindow::on_btnRechercherId_clicked() {
    int id = ui->lineEdit_idRecherche->text().toInt();
    if (id <= 0) {
        showError("Veuillez entrer un ID valide.");
        return;
    }

    QSqlQueryModel* oldModel = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    QSqlQueryModel* model = F.rechercherParId(id);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();

    if (model->rowCount() == 0) {
        showError("Aucune formation trouvée avec cet ID.");
    }
    delete oldModel;
}

void MainWindow::on_btnRechercherDate_clicked() {
    QDate date = ui->dateEdit_rechercheDate->date();

    QSqlQueryModel* oldModel = qobject_cast<QSqlQueryModel*>(ui->tableView->model());
    QSqlQueryModel* model = F.rechercherParDate(date);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();

    if (model->rowCount() == 0) {
        showError(QString("Aucune formation trouvée pour la date %1.").arg(date.toString("dd/MM/yyyy")));
    }
    delete oldModel;
}
