#include "formation.h"
#include <QSqlError>
#include <QDebug>

// Constructeur par défaut
Formation::Formation() {
    id_formation = 0;
    thematique = "";
    date_d = "";
    nom = "";
    description = "";
}

// Constructeur avec paramètres
Formation::Formation(int id, QString th, QString date, QString n, QString desc) {
    id_formation = id;
    thematique = th;
    date_d = date;
    nom = n;
    description = desc;
}

// Ajouter une formation
bool Formation::ajouter() {
    if (thematique.isEmpty() || date_d.isEmpty() || nom.isEmpty() || description.isEmpty()) {
        qDebug() << "Erreur: Certains champs sont vides.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO formation (id_formation, thematique, date_d, nom, description) "
                  "VALUES (:id, :thematique, :date_d, :nom, :description)");

    query.bindValue(":id", id_formation);
    query.bindValue(":thematique", thematique);
    query.bindValue(":date_d", date_d);
    query.bindValue(":nom", nom);
    query.bindValue(":description", description);

    if (!query.exec()) {
        qDebug() << "Erreur d'insertion: " << query.lastError().text();
        return false;
    }

    return true;
}

// Supprimer une formation
bool Formation::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM formation WHERE id_formation = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur de suppression: " << query.lastError().text();
        return false;
    }

    return true;
}

// Afficher toutes les formations
QSqlQueryModel* Formation::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM formation");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage: " << model->lastError().text();
    }

    return model;
}
