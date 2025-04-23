#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidget>

bool Client::addClient() {
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTS (CIN, NOM, PRENOM, EMAIL, ADRESSE, TYPE,X,Y) "
                  "VALUES (:cin, :nom, :prenom,  :email, :adresse, :type, :x, :y)");

    query.bindValue(":cin", cin.toInt());  // CIN doit être un entier
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type", type);
    query.bindValue(":x", x_str.toDouble());  // convertis en float
    query.bindValue(":y", y_str.toDouble());


    if (!query.exec()) {
        lastError = query.lastError().text();
        qDebug() << "Erreur lors de l'ajout du client:" << lastError;
        return false;
    }
    return true;
    /*if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout du client:" << query.lastError().text();
        return false;
    }
    return true;
*/
}

void Client::display(QTableWidget *tableWidget) {
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return;
    }

    tableWidget->clearContents();
    tableWidget->setRowCount(0);

    while (query.next()) {
        int row = tableWidget->rowCount();
        tableWidget->insertRow(row);

        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("CIN").toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("EMAIL").toString()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("ADRESSE").toString()));
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("TYPE").toString()));
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("x").toString()));
        tableWidget->setItem(row, 7, new QTableWidgetItem(query.value("y").toString()));

    }

    qDebug() << "Nombre de clients chargés depuis la base de données:" << tableWidget->rowCount();
}

bool Client::updateClient(const QString &originalCin) {
    QSqlQuery query;
    query.prepare("UPDATE CLIENTS SET CIN = :cin, NOM = :nom, PRENOM = :prenom, EMAIL = :email, ADRESSE = :adresse, TYPE = :type, X= :x, Y= :y "
                  "WHERE CIN = :original_cin");

    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":type", type);
    query.bindValue(":original_cin", originalCin);
    query.bindValue(":x", x_str.toDouble());
    query.bindValue(":y", y_str.toDouble());


    if (!query.exec()) {
        lastError = query.lastError().text();
        qDebug() << "Erreur lors de la mise à jour du client :" << lastError;
        return false;
    }
    return true;
}

bool Client::deleteClient(const QString &cin) {
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTS WHERE CIN = :cin");
    query.bindValue(":cin", cin);

    if (!query.exec()) {
        lastError = query.lastError().text();
        qDebug() << "Erreur lors de la suppression du client :" << lastError;
        return false;
    }
    return true;
}
