 #include "tache.h"
#include <QSqlError>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
// Constructeurs
Tache::Tache() {}

Tache::Tache(int id, QString name, QString desc, QString etat, QDate debut, QDate fin)
{
    this->tacheID = id;
    this->tacheName = name;
    this->description = desc;
    this->tachEtat = etat;
    this->debutDate = debut;
    this->finDate = fin;
}

bool Tache::ajouter()
{
    // Vérification des champs vides
    if (tacheName.isEmpty() || description.isEmpty() || tachEtat.isEmpty() || !debutDate.isValid() || !finDate.isValid()) {
        qDebug() << "Erreur : Champs vides ou dates invalides.";
        return false;
    }

    // Vérification si la date de début est bien spécifiée, sinon mettre la date actuelle
    QDate today = QDate::currentDate();
    if (debutDate != today) {
        qDebug() << "Erreur : la date de début doit être la date d'aujourd'hui.";
        return false;
    }

    if (tacheID < 100000 || tacheID > 999999) {
        qDebug() << "Erreur : l'ID de la tâche doit être un nombre de 6 chiffres.";
        return false;
    }

    if (debutDate > finDate) {
        qDebug() << "Erreur : La date de début est postérieure à la date de fin.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO TACHE (tacheID, tacheName, description, tachEtat, debutDate, finDate) "
                  "VALUES (:id, :name, :desc, :etat, TO_DATE(:debut, 'YYYY-MM-DD'), TO_DATE(:fin, 'YYYY-MM-DD'))");

    query.bindValue(":id", tacheID);
    query.bindValue(":name", tacheName);
    query.bindValue(":desc", description);
    query.bindValue(":etat", tachEtat);
    query.bindValue(":debut", debutDate.toString("yyyy-MM-dd"));  // Passer la date de début formatée
    query.bindValue(":fin", finDate.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de la tâche:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Tache::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TACHE WHERE tacheID = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de la tâche:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Tache::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TACHE");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("FIN_DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("DEBUT_DATE"));

    return model;
}

bool Tache::modifier(int id, QString name, QString desc, QString etat, QDate debut, QDate fin)
{
    if (name.isEmpty() || desc.isEmpty() || etat.isEmpty() || !debut.isValid() || !fin.isValid() || debut > fin) {
        qDebug() << "Erreur : Champs invalides pour la modification.";
        return false;
    }

    QSqlQuery query;
    query.prepare("UPDATE TACHE SET tacheName = :name, description = :desc, tachEtat = :etat, "
                  "debutDate = TO_DATE(:debut, 'YYYY-MM-DD'), finDate = TO_DATE(:fin, 'YYYY-MM-DD') "
                  "WHERE tacheID = :id");

    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":desc", desc);
    query.bindValue(":etat", etat);
    query.bindValue(":debut", debut.toString("yyyy-MM-dd"));
    query.bindValue(":fin", fin.toString("yyyy-MM-dd"));

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de la tâche:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Tache::recherche(const QString &text)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM TACHE WHERE tacheName LIKE :text OR description LIKE :text");
    query.bindValue(":text", "%" + text + "%");

    query.exec();
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DEBUT_DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("FIN_DATE"));

    return model;
}
QSqlQueryModel* Tache::trierPar(const QString& critere)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = "SELECT * FROM TACHE";

    if (critere == "Nom")
        queryStr += " ORDER BY tacheName ASC";
    else if (critere == "Date de début")
        queryStr += " ORDER BY debutDate ASC";
    else if (critere == "Date de fin")
        queryStr += " ORDER BY finDate ASC";

    model->setQuery(queryStr);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ETAT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DEBUT_DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("FIN_DATE"));

    return model;
}

