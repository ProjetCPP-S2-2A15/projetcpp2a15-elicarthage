#include "connection.h"
#include <QDebug>

Connection::Connection() {}  // Constructeur vide

bool Connection::createconnect() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A"); // Nom de la source de données
    db.setUserName("eya"); // Nom d'utilisateur
    db.setPassword("esprit18"); // Mot de passe

    if (db.open()) {
        qDebug() << "Connexion réussie à la base de données.";
        return true;
    } else {
        qDebug() << "Échec de connexion :" << db.lastError().text();
        return false;
    }
}

void Connection::closeConnection() {
    QSqlDatabase::database().close();
    qDebug() << "Connexion fermée.";
}
