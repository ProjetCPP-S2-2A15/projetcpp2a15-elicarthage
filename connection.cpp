#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données
    db.setUserName("tez");//inserer nom de l'utilisateur
    db.setPassword("esprit09");//inserer mot de passe de cet utilisateur

    if (db.open()) {
        return true;
    } else {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    }

}
bool Connection::connectToArchitectes()
{
    // On donne un nom différent à cette connexion pour éviter les conflits
    QSqlDatabase dbArchitectes = QSqlDatabase::addDatabase("QODBC");
    dbArchitectes.setDatabaseName("Source_Projet2A"); // le nom ODBC de la source architectes
    dbArchitectes.setUserName("tez"); // adapte selon les infos de ton collègue
    dbArchitectes.setPassword("esprit09");

    if (dbArchitectes.open()) {
        qDebug() << "Connexion à la base architectes réussie.";
        return true;
    } else {
        qDebug() << "Échec de la connexion à architectes:" << dbArchitectes.lastError().text();
        return false;
    }
}

void Connection::closeconnection(){db.close();}
