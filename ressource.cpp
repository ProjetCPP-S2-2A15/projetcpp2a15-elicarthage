#include "ressource.h"
#include "emailnotifier.h"  // Assure-toi que ce fichier existe et contient la déclaration de la classe EmailNotifier
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>




Ressource::Ressource()
    : NOM(""), TYPE(""), ETAT(""),
    FOURNISSEUR(""), LOCALISATION(""), QUANTITE(0) {}

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

QString RessourceManager::recupererDernierEmail() {
    QSqlQuery query;
    if (query.exec("SELECT EMAIL FROM (SELECT * FROM architectes ORDER BY DATE_AJOUT ) WHERE ROWNUM = 1")) {
        if (query.next()) {
            QString email = query.value(0).toString();
            qDebug() << " Found architect email:" << email;
            return email;
        } else {
            qDebug() << "No architect found in the database!";
        }
    } else {
        qDebug() << "SQL Error:" << query.lastError().text();
    }
    return "";
}


bool Ressource::modifier(int id, const QString &nom, const QString &type, const QString &etat,
                         const QString &fournisseur, const QString &localisation, int quantite)
{
    QSqlQuery query;
    query.prepare("UPDATE ressource SET nom = :nom, type = :type, etat = :etat, "
                  "fournisseur = :fournisseur, localisation = :localisation, quantite = :quantite "
                  "WHERE id = :id");

    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":etat", etat);
    query.bindValue(":fournisseur", fournisseur);
    query.bindValue(":localisation", localisation);
    query.bindValue(":quantite", quantite);
    query.bindValue(":id", id);

    qDebug() << "Executing Secure SQL Query";

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la ressource:" << query.lastError().text();
        return false;
    }

    qDebug() << "Modification réussie pour l'ID:" << id;
    return true;
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

    return true;
}
bool Ressource::supprimer(int id) {
    QSqlQuery query;
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
void RessourceManager::verifierEtNotifier(Ressource ressource) {
    // Retrieve the last architect's email
    QString dernierEmail = recupererDernierEmail();


    QString alerte;

    // Debugging: Check resource status and quantity
    qDebug() << "Resource Status: " << ressource.status();
    qDebug() << "Resource Quantity: " << ressource.quantite();
    QString etatNormalise = ressource.status().trimmed().toLower();

    if (etatNormalise == "inactive") {
        alerte = "⚠ Le logiciel '" + ressource.nom() + "' est devenu inactif.";
    }
    else if (etatNormalise == "indisponible") {
        alerte = "⚠ Le matériel '" + ressource.nom() + "' est indisponible.";
    }


    // Only send email if an alert was set
    if (!alerte.isEmpty()) {
        //EmailNotifier::envoyerAlerte("moetez.benattia02@gmail.com", "Test manuel depuis Qt");

        EmailNotifier::envoyerAlerte(dernierEmail, alerte);  // Send the alert email
        qDebug() << "Sending alert email to: " << dernierEmail;
        qDebug() << "Message envoyé :" << alerte;

    } else {
        qDebug() << "No alert to send.";
    }
    if (dernierEmail.isEmpty()) {
        qDebug() << "Aucun architecte trouvé pour l'envoi du mail.";
        return;
    }
}









