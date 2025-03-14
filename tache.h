#ifndef TACHE_H
#define TACHE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Tache
{
    int tacheID;
    QString tacheName, description, tachEtat, finDate, debutDate;

public:
    // Constructeurs
    Tache();
    Tache(int, QString, QString, QString, QString, QString);

    // Getters
    int getID() { return tacheID; }
    QString getNom() { return tacheName; }
    QString getDescription() { return description; }
    QString getEtat() { return tachEtat; }
    QString getDebutDate() { return debutDate; }
    QString getFinDate() { return finDate; }

    // Setters
    void setID(int id) { tacheID = id; }
    void setNom(QString nom) { tacheName = nom; }
    void setDescription(QString desc) { description = desc; }
    void setEtat(QString etat) { tachEtat = etat; }
    void setDebutDate(QString date) { debutDate = date; }
    void setFinDate(QString date) { finDate = date; }

    // Fonctionnalités de Base relatives à l'entité Tache
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
};

#endif // TACHE_H
