#include "ressource.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>



// Constructeur par défaut
Ressource::Ressource()
    : NOM(""), TYPE(""), ETAT(""),
    FOURNISSEUR(""), LOCALISATION(""), QUANTITE(0) {}

// Constructeur paramétré
Ressource::Ressource( const QString &nom, const QString &type, const QString &etat,
                     const QString &fournisseur, const QString &localisation, int quantite) {
    this->NOM = nom;
    this->TYPE = type;
    this->ETAT = etat;
    this->FOURNISSEUR = fournisseur;
    this->LOCALISATION = localisation;
    this->QUANTITE = quantite;
}

QString Ressource::getLastError() const {
    QSqlQuery query;
    return query.lastError().text();
}
bool Ressource::modifier(int id, const QString &nom, const QString &type, const QString &etat,
                         const QString &fournisseur, const QString &localisation, int quantite) {
    QSqlQuery query;
    query.prepare("UPDATE ressources SET nom = ?, type = ?, etat = ?, fournisseur = ?, localisation = ?, quantite = ? WHERE id = ?");

    if (query.exec()) {
        return true;
    } else {
        return false;
    }
}

bool Ressource::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO ressource (ID, NOM, TYPE, ETAT, FOURNISSEUR, LOCALISATION, QUANTITE) "
                  "VALUES (ressource_seq.NEXTVAL, :NOM, :TYPE, :ETAT, :FOURNISSEUR, :LOCALISATION, :QUANTITE)");

    query.bindValue(":NOM", NOM);
    query.bindValue(":TYPE", TYPE);
    query.bindValue(":ETAT", ETAT);
    query.bindValue(":FOURNISSEUR", FOURNISSEUR);
    query.bindValue(":LOCALISATION", LOCALISATION);
    query.bindValue(":QUANTITE", QUANTITE);

    // Debug : Log la requête
    qDebug() << "Executing SQL query: " << query.executedQuery();

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout :" << query.lastError().text();
        return false;
    }
    if (TYPE == "Materiel" && ETAT == "indisponible") {
        QMessageBox::warning(nullptr, "Erreur", "Un matériel ne peut pas être indisponible !");
        return false;
    }

    return true;
}
bool Ressource::supprimer(int id) {
    QSqlQuery query;
    // Only use the ID in the WHERE clause for DELETE
    query.prepare("DELETE FROM RESSOURCE WHERE ID = :ID");
    query.bindValue(":ID", id);  // Bind the input ID to the query

    if (query.exec()) {
        return true;  // Return true if the deletion is successful
    } else {
        qDebug() << "Error deleting resource:" << query.lastError().text();
        return false;  // Return false if there's an error
    }
}
QSqlQueryModel* Ressource::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM ressource");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("FOURNISSEUR"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("LOCALISATION"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("QUANTITE"));

    return model;
}








