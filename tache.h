#ifndef TACHE_H
#define TACHE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Tache
{
    int tacheID;
    QString tacheName, description, tachEtat;
    QDate debutDate, finDate;  // Changement de type

public:
    // Constructeurs
    Tache();
    Tache(int, QString, QString, QString, QDate, QDate);

    // Getters
    int getID() { return tacheID; }
    QString getNom() { return tacheName; }
    QString getDescription() { return description; }
    QString getEtat() { return tachEtat; }
    QDate getDebutDate() { return debutDate; }
    QDate getFinDate() { return finDate; }

    // Setters
    void setID(int id) { tacheID = id; }
    void setNom(QString nom) { tacheName = nom; }
    void setDescription(QString desc) { description = desc; }
    void setEtat(QString etat) { tachEtat = etat; }
    void setDebutDate(QDate date) { debutDate = date; }
    void setFinDate(QDate date) { finDate = date; }

    // Fonctionnalités de Base relatives à l'entité Tache
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel *afficher();
    QSqlQueryModel* recherche(const QString &text);
    QSqlQueryModel* trierPar(const QString& critere);




    bool modifier(int id, QString name, QString desc, QString etat, QDate debut, QDate fin);
};

#endif // TACHE_H
