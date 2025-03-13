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
void Connection::closeconnection(){db.close();}
