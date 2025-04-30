#include "connection.h"
#include <QMessageBox>
#include <QSqlError>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données
    db.setUserName("tez");//inserer nom de l'utilisateur
    db.setPassword("esprit09");//inserer mot de passe de cet utilisateur

    if (db.open()) {
        test = true;
        QMessageBox::information(nullptr, "Connexion réussie", "Connexion à la base de données établie avec succès !");
    } else {
        QMessageBox::critical(nullptr, "Erreur de connexion", "Impossible de se connecter à la base de données : " + db.lastError().text());
    }

    return test;  // Pas de app.exec() ici !

}
