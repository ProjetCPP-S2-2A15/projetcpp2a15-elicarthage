#include "projet.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


bool Projet::addProjet() {
    QSqlQuery query;
    query.prepare("INSERT INTO PROJETS (ID_PROJET, NOM, DESCRIPTION, DATE_DEBUT, TYPE, BUDGET, ETAT) "
                  "VALUES (:project_id, :project_name, :project_description, :project_date_deb, :project_type, :project_budget, :project_etat)");

    query.bindValue(":project_id", project_id);
    query.bindValue(":project_name", project_name);
    query.bindValue(":project_description", project_description);
    query.bindValue(":project_date_deb", project_date_deb.toString("yyyy-MM-dd"));
    query.bindValue(":project_type", project_type);
    query.bindValue(":project_budget", project_budget);
    query.bindValue(":project_etat", project_etat);

    if (!query.exec()) {
        lastError = query.lastError().text();
        qDebug() << "Erreur lors de l'ajout du projet:" << lastError;
        return false;
    }
    return true;
}

void Projet::display(QTableWidget *tableWidget) {
    QSqlQuery query;
    query.prepare("SELECT * FROM PROJETS");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return;
    }
    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    while (query.next()) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID_PROJET").toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("DESCRIPTION").toString()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATE_DEBUT").toString()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("TYPE").toString()));
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("BUDGET").toString()));
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("ETAT").toString()));
    }
    qDebug() << "Nombre de projets chargés depuis la base de données:" << tableWidget->rowCount();
}

bool Projet::updateProjet(const QString &originalId) {
    QSqlQuery query;
    query.prepare("UPDATE PROJETS SET ID_PROJET = :project_id, NOM = :project_name, DESCRIPTION = :project_description, "
                  "DATE_DEBUT = :project_date_deb, TYPE = :project_type, BUDGET = :project_budget, ETAT = :project_etat "
                  "WHERE ID_PROJET = :original_id");

    query.bindValue(":project_id", project_id);
    query.bindValue(":project_name", project_name);
    query.bindValue(":project_description", project_description);
    query.bindValue(":project_date_deb", project_date_deb);
    query.bindValue(":project_type", project_type);
    query.bindValue(":project_budget", project_budget);
    query.bindValue(":project_etat", project_etat);
    query.bindValue(":original_id", originalId);

    if (!query.exec()) {
        lastError = query.lastError().text();
        qDebug() << "Erreur lors de la mise à jour du projet :" << lastError;
        return false;
    }
    return true;
}

bool Projet::deleteProjet(const QString &projectId) {
    QSqlQuery query;
    query.prepare("DELETE FROM PROJETS WHERE ID_PROJET = :project_id");
    query.bindValue(":project_id", projectId);
    return query.exec();
}
