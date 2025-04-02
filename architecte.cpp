#include "architecte.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QCryptographicHash>


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


bool Architecte::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO architecte (id, nom, PRÉNOM, EMAIL, RÔLE, MOT_DE_PASSE, question, reponse, NBR_HEURES_SUPPLEMENTAIRES) "
                  "VALUES (:id, :nom, :prenom, :mail, :role, :motDePasse, :question, :reponse, COALESCE(:heuresSupplementaires, 0))");


    query.bindValue(":id", architectID);
    query.bindValue(":nom", architectNom);
    query.bindValue(":prenom", architectPrenom);
    query.bindValue(":mail", architectMail);
    query.bindValue(":role", role);
    query.bindValue(":motDePasse", motDePasse);
    query.bindValue(":question", question);
    query.bindValue(":reponse", reponse);


    query.bindValue(":heuresSupplementaires", nombreHeuresSupplementaires == 0 ? QVariant(0) : nombreHeuresSupplementaires);


    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'architecte:" << query.lastError().text();
        return false;
    }

    return true;
}




QSqlQueryModel* Architecte::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();


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
    query.prepare("DELETE FROM ZEINEB.ARCHITECTE WHERE id = :id");
    query.bindValue(":id", id);


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


    QSqlQuery query;
    query.prepare(QString("UPDATE ZEINEB.ARCHITECTE SET \"%1\" = :value WHERE ID = :id").arg(columnName));
    query.bindValue(":value", newValue);
    query.bindValue(":id", id);


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
            return count > 0;
        }
    }
    qDebug() << "Erreur SQL: " << query.lastError().text();
    return false;
}

void Architecte::getNomPrenom(int id, QString &nom, QString &prenom) {
    QSqlQuery query;
    query.prepare("SELECT NOM, PRÉNOM FROM ZEINEB.ARCHITECTE WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur de requête SQL:" << query.lastError().text();
        return;
    }

    if (query.next()) {
        nom = query.value("NOM").toString();
        prenom = query.value("PRÉNOM").toString();
    } else {
        qDebug() << "Aucun résultat trouvé pour l'ID:" << id;
    }
}

QSqlQueryModel* Architecte::rechercher(const QString &keyword)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM ZEINEB.ARCHITECTE WHERE "
                  "LOWER(NOM) LIKE LOWER(:keyword) OR "
                  "LOWER(PRÉNOM) LIKE LOWER(:keyword)");

    query.bindValue(":keyword", "%" + keyword + "%");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche:" << query.lastError().text();
        return nullptr;
    }

    // Utiliser std::move pour éviter la copie
    model->setQuery(std::move(query));

    return model;
}

QSqlQueryModel* Architecte::afficherAvecTri(const QString& colonne, bool ascendant)
{


    QSqlQueryModel *model = new QSqlQueryModel();
    QString order = ascendant ? "ASC" : "DESC";

    // Modifier la requête pour trier par la première lettre du nom
    QString query;
    if (colonne == "NOM") {
        query = QString("SELECT * FROM ZEINEB.ARCHITECTE ORDER BY SUBSTR(%1, 1, 1) %2").arg(colonne).arg(order);
    } else {
        query = QString("SELECT * FROM ZEINEB.ARCHITECTE ORDER BY %1 %2").arg(colonne).arg(order);
    }



    model->setQuery(query);

    // Vérifier les erreurs SQL
    if (model->lastError().isValid()) {
        qDebug() << "afficherAvecTri: Erreur SQL =" << model->lastError().text();
        delete model; // Libérer la mémoire en cas d'erreur
        return nullptr; // Retourner nullptr pour indiquer une erreur
    }

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
