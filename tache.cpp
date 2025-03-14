#include "tache.h"

Tache::Tache() {}

Tache::Tache(int id, QString name, QString desc, QString etat, QString fin, QString debut)
{
    this->tacheID = id;
    this->tacheName = name;
    this->description = desc;
    this->tachEtat = etat;
    this->finDate = fin;
    this->debutDate = debut;

}

bool Tache::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO TACHE (tacheID, tacheName, description, tachEtat, finDate, debutDate) "
                  "VALUES (:id, :name, :desc, :etat, :fin, :debut)");

    query.bindValue(":id", tacheID);
    query.bindValue(":name", tacheName);
    query.bindValue(":desc", description);
    query.bindValue(":etat", tachEtat);
    query.bindValue(":fin", finDate);
    query.bindValue(":debut", debutDate);


    return query.exec();
}

bool Tache::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM TACHE WHERE tacheID = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQueryModel *Tache::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM TACHE");
    return model;
}
