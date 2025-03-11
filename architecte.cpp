#include "architecte.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>

// Constructeur avec paramètres
Architecte::Architecte(int id, const QString& nom, const QString& prenom,
                       const QString& mail, const QString& role, const QString& motDePasse,
                       const QString& question, const QString& reponse, int heuresSupplementaires)
{
    this->architectID = id;
    this->architectNom = nom;
    this->architectPrenom = prenom;
    this->architectMail = mail;
    this->role = role;
    this->motDePasse = motDePasse;
    this->question = question;
    this->reponse = reponse;
    this->nombreHeuresSupplementaires = heuresSupplementaires;
}

// Fonction pour ajouter toutes les informations en une seule fois
bool Architecte::ajouter()
{
    QSqlQuery query;

    // Préparer la requête d'insertion
    query.prepare("INSERT INTO architecte (id, nom, PRÉNOM, EMAIL, RÔLE, MOT_DE_PASSE, question, reponse, NBR_HEURES_SUPPLEMENTAIRES) "
                  "VALUES (:id, :nom, :prenom, :mail, :role, :motDePasse, :question, :reponse, COALESCE(:heuresSupplementaires, 0))");

    // Lier les valeurs aux paramètres de la requête
    query.bindValue(":id", architectID);  // ID déjà passé en paramètre
    query.bindValue(":nom", architectNom);
    query.bindValue(":prenom", architectPrenom);
    query.bindValue(":mail", architectMail);
    query.bindValue(":role", role);
    query.bindValue(":motDePasse", motDePasse);
    query.bindValue(":question", question);
    query.bindValue(":reponse", reponse);

    // Si heures supplémentaires sont spécifiées, utiliser leur valeur. Sinon, 0
    query.bindValue(":heuresSupplementaires", nombreHeuresSupplementaires == 0 ? QVariant(0) : nombreHeuresSupplementaires);

    // Exécuter la requête et vérifier si elle est réussie
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'architecte:" << query.lastError().text();
        return false;
    }

    return true;
}




QSqlQueryModel* Architecte::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    // Exécuter la requête SQL pour récupérer les données
    model->setQuery("SELECT * FROM ZEINEB.ARCHITECTE");

    // Définir les en-têtes pour les colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRÉNOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("RÔLE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NBR_HEURES_SUPPLEMENTAIRES"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("MOT_DE_PASSE"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("QUESTION"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("REPONSE"));

    return model;
}

bool Architecte::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ZEINEB.ARCHITECTE WHERE id = :id"); // Préparer la requête SQL
    query.bindValue(":id", id); // Associer l'ID directement (pas besoin de conversion)

    // Exécuter la requête et vérifier si elle est exécutée avec succès
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de l'architecte:" << query.lastError().text();
        return false;
    }

    return true;
}
bool Architecte::modifier(int id, const QString &columnName, const QString &newValue)
{
    if (columnName.isEmpty()) {
        qDebug() << "Nom de la colonne vide, mise à jour impossible.";
        return false;
    }

    // Créer une requête SQL pour mettre à jour la valeur dans la base de données
    QSqlQuery query;
    query.prepare(QString("UPDATE ZEINEB.ARCHITECTE SET \"%1\" = :value WHERE ID = :id").arg(columnName));
    query.bindValue(":value", newValue);
    query.bindValue(":id", id);

    // Exécuter la requête
    if (query.exec()) {
        qDebug() << "Modification réussie!";
        return true;
    } else {
        qDebug() << "Erreur de modification: " << query.lastError().text();
        return false;
    }
}

bool Architecte::idExiste(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM ZEINEB.ARCHITECTE WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec())
    {
        if (query.next())
        {
            int count = query.value(0).toInt();
            return count > 0;  // Retourner true si l'ID existe, sinon false
        }
    }
    qDebug() << "Erreur SQL: " << query.lastError().text();
    return false; // Si la requête échoue, on retourne false
}
