#include "formation.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <utility>

Formation::Formation() : id(0) {}

Formation::Formation(int id, QString thematique, QString date_d, QString nom, QString description)
    : id(id), thematique(thematique), date_d(date_d), nom(nom), description(description) {}

int Formation::getId() { return id; }
QString Formation::getNom() { return nom; }
QString Formation::getThematique() { return thematique; }
QString Formation::getDate() { return date_d; }
QString Formation::getDescription() { return description; }

bool Formation::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO FORMATION (ID_FORMATION, THEMATIQUE, DATE_D, NOM, DESCRIPTION) "
                "VALUES (:id, :thematique, TO_DATE(:date_d, 'YYYY-MM-DD'), :nom, :description)");

    query.bindValue(":id", id);
    query.bindValue(":thematique", thematique);
    query.bindValue(":date_d", date_d);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout:" << query.lastError().text();
        return false;
    }
    return true;
}

QSqlQueryModel* Formation::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_FORMATION, NOM, THEMATIQUE, TO_CHAR(DATE_D, 'DD/MM/YYYY') as DATE_D, DESCRIPTION FROM FORMATION");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Thématique"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Description"));
    return model;
}

bool Formation::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM FORMATION WHERE ID_FORMATION = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

bool Formation::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE FORMATION SET THEMATIQUE = :thematique, DATE_D = TO_DATE(:date_d, 'YYYY-MM-DD'), "
                "NOM = :nom, DESCRIPTION = :description WHERE ID_FORMATION = :id");

    query.bindValue(":id", id);
    query.bindValue(":thematique", thematique);
    query.bindValue(":date_d", date_d);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification:" << query.lastError().text();
        return false;
    }
    return query.numRowsAffected() > 0;
}

QSqlQueryModel* Formation::sort() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_FORMATION, NOM, THEMATIQUE, TO_CHAR(DATE_D, 'DD/MM/YYYY') as DATE_D, DESCRIPTION "
                   "FROM FORMATION ORDER BY THEMATIQUE ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Thématique"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date début"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Description"));
    return model;
}

QSqlQueryModel* Formation::rechercherParId(int id) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_FORMATION, NOM, THEMATIQUE, TO_CHAR(DATE_D, 'DD/MM/YYYY') as DATE_D, DESCRIPTION "
                 "FROM FORMATION WHERE ID_FORMATION = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        model->setQuery(std::move(query));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Thématique"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date début"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Description"));
    } else {
        qDebug() << "Erreur lors de la recherche par ID:" << query.lastError().text();
    }
    return model;
}

QSqlQueryModel* Formation::rechercherParDate(const QDate& date) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT ID_FORMATION, NOM, THEMATIQUE, TO_CHAR(DATE_D, 'DD/MM/YYYY') as DATE_D, DESCRIPTION "
                 "FROM FORMATION WHERE TRUNC(DATE_D) = TO_DATE(:date, 'YYYY-MM-DD')");
    query.bindValue(":date", date.toString("yyyy-MM-dd"));

    if (query.exec()) {
        model->setQuery(std::move(query));
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Thématique"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date début"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Description"));
    } else {
        qDebug() << "Erreur lors de la recherche par date:" << query.lastError().text();
    }
    return model;
}
