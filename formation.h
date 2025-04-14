#ifndef FORMATION_H
#define FORMATION_H

#include <QString>
#include <QSqlQueryModel>
#include <QDate>

class Formation {
public:
    Formation();
    Formation(int, QString, QString, QString, QString);

    int getId();
    QString getNom();
    QString getThematique();
    QString getDate();
    QString getDescription();

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* sort();
    QSqlQueryModel* rechercherParId(int);
    QSqlQueryModel* rechercherParDate(const QDate& date);

private:
    int id;
    QString thematique, date_d, nom, description;
};

#endif // FORMATION_H
