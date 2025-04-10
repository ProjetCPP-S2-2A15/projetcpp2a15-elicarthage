#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>

// Constructor with parameters
Client::Client(int id, const QString& nom, const QString& prenom, const QString& tel, const QString& mail, const QString& adresse, const QString& type)
{
    clientId = id;
    clientNom = nom;
    clientPrenom = prenom;
    clientTel = tel;
    clientMail = mail;
    clientAdresse = adresse;
    clientType = type;
}

// Function to add a client to the database
bool Client::ajouter()
{
    QSqlQuery query;

    // Prepare the SQL query for insertion
    query.prepare("INSERT INTO CLIENT (ID, NOM, PRENOM, TEL, EMAIL, ADRESSE, TYPE) "
                  "VALUES (:id, :nom, :prenom, :tel, :email, :adresse, :type)");

    // Bind values to the query parameters
    query.bindValue(":id", clientId);
    query.bindValue(":nom", clientNom);
    query.bindValue(":prenom", clientPrenom);
    query.bindValue(":tel", clientTel);
    query.bindValue(":email", clientMail);
    query.bindValue(":adresse", clientAdresse);
    query.bindValue(":type", clientType);

    // Execute the query and check for errors
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout du client:" << query.lastError().text();
        return false;
    }
    return true;
}

// Function to display all clients in a QSqlQueryModel
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Exécuter la requête SQL pour récupérer les données
    QSqlQuery query;
    query.prepare("SELECT ID, NOM, PRENOM, TEL, EMAIL, ADRESSE, TYPE FROM CLIENT");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des données:" << query.lastError().text();
        return nullptr;  // Retourner nullptr si la requête échoue
    }

    model->setQuery(query);

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPE"));

    return model;
}


// Function to delete a client by ID
bool Client::supprimer(int id)
{
    QSqlQuery query;

    // Prepare the SQL query for deletion
    query.prepare("DELETE FROM CLIENT WHERE ID = :id");
    query.bindValue(":id", id);

    // Execute the query and check for errors
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du client:" << query.lastError().text();
        return false;
    }

    return true;
}

// Function to update a client's information
bool Client::modifier(int id, const QString &columnName, const QString &newValue)
{
    if (columnName.isEmpty()) {
        qDebug() << "Nom de la colonne vide, mise à jour impossible.";
        return false;
    }

    QSqlQuery query;

    // Prepare the SQL query for updating
    query.prepare(QString("UPDATE CLIENT SET %1 = :value WHERE ID = :id").arg(columnName));
    query.bindValue(":value", newValue);
    query.bindValue(":id", id);

    // Execute the query and check for errors
    if (query.exec()) {
        qDebug() << "Modification réussie!";
        return true;
    } else {
        qDebug() << "Erreur de modification:" << query.lastError().text();
        return false;
    }
}

// Function to check if a client ID exists in the database
bool Client::idExiste(int id)
{
    QSqlQuery query;

    // Prepare the SQL query to check for the existence of the ID
    query.prepare("SELECT COUNT(*) FROM CLIENT WHERE ID = :id");
    query.bindValue(":id", id);

    // Execute the query and check for errors
    if (query.exec()) {
        if (query.next()) {
            int count = query.value(0).toInt();
            return count > 0; // Return true if the ID exists, otherwise false
        }
    }

    qDebug() << "Erreur SQL:" << query.lastError().text();
    return false; // Return false if the query fails
}
