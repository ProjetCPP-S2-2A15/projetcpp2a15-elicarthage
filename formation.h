#ifndef FORMATION_H
#define FORMATION_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Formation {
private:
    int id_formation;
    QString thematique;
    QString date_d;
    QString nom;
    QString description;

public:
    Formation();
    Formation(int, QString, QString, QString, QString);

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
};

#endif // FORMATION_H
