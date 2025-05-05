#include "connection.h"
#include <QMessageBox>
#include <QSqlError>
Connection::Connection() {}


bool Connection::createconnect()
{
    bool test=false;


    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
     db.setDatabaseName("Source_Projet2A");
    // db.setDatabaseName("Source_Projet2A");//inserer le nom de la source de données

    db.setUserName("eya");//inserer nom de l'utilisateur
    db.setPassword("esprit18");//inserer mot de passe de cet utilisateur


    if (db.open())
        test=true;

    return  test;

}



void Connection::closeconnection(){db.close();}

