#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QWidget>
#include "tache.h"  // Ajout de l'inclusion de la classe Tache

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ELICAR");

    // Charger et vérifier l'image de l'icône de l'application
    QPixmap pixmap("C:/Users/eya/Desktop/archi/imlogo.png");
    if (!pixmap.isNull()) {
        QPixmap resizedPixmap = pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->setWindowIcon(QIcon(resizedPixmap));
    } else {
        qDebug() << "L'image du logo n'a pas pu être chargée!";
    }

    int columnActions = 6;
    ui->tableWidget->setColumnWidth(columnActions, 200);

    int rowCount = ui->tableWidget->rowCount();

    for (int row = 0; row < rowCount; ++row) {
        QPushButton *btnModify = new QPushButton("Modifier");
        btnModify->setFixedSize(80, 31);
        btnModify->setStyleSheet(
            "QPushButton { background-color: #1f4e78; color: white; border-radius: 6px; padding: 6px 12px; font-size: 13px; font-weight: normal; border: 1px solid #1A252F; }"
            "QPushButton:hover { background-color: #34495E; border: 1px solid #2C3E50; }"
            "QPushButton:pressed { background-color: #1A252F; }"
            "QPushButton:disabled { background-color: #95A5A6; color: #D0D3D4; border: 1px solid #7F8C8D; }"
            );

        QPushButton *btnDelete = new QPushButton("Supprimer");
        btnDelete->setFixedSize(90, 31);
        btnDelete->setStyleSheet(
            "QPushButton { background-color: #1f4e78; color: white; border-radius: 6px; padding: 6px 12px; font-size: 13px; font-weight: normal; border: 1px solid #1A252F; }"
            "QPushButton:hover { background-color: #34495E; border: 1px solid #2C3E50; }"
            "QPushButton:pressed { background-color: #1A252F; }"
            "QPushButton:disabled { background-color: #95A5A6; color: #D0D3D4; border: 1px solid #7F8C8D; }"
            );

        QWidget *widget = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widget);
        layout->addWidget(btnModify);
        layout->addWidget(btnDelete);
        layout->setContentsMargins(0, 0, 0, 0);

        ui->tableWidget->setCellWidget(row, columnActions, widget);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();
    QString etat = ui->lineEdit_etat->text();
    QString debutDate = ui->lineEdit_debutDate->text();
    QString finDate = ui->lineEdit_finDate->text();

    // Vérification des champs vides
    if (nom.isEmpty() || description.isEmpty() || etat.isEmpty() || debutDate.isEmpty() || finDate.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs avant d'ajouter une tâche.");
        return;
    }

    // Instanciation de l'objet Tache
    Tache t(id, nom, description, etat, debutDate, finDate);

    // Ajout dans la base de données
    bool test = t.ajouter();

    if (test) {
        QMessageBox::information(this, "Succès", "Ajout effectué avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
    }
}
