#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Ressource {
private:
    QString NOM;
    QString TYPE;
    QString ETAT;
    QString FOURNISSEUR;
    QString LOCALISATION;
    int QUANTITE;
    QString getLastError() const;


public:
    // Constructeurs
    Ressource();
    Ressource( const QString &nom, const QString &type, const QString &etat,
              const QString &fournisseur, const QString &localisation, int quantite);

    // Getters et Setters
    int getID() const;
    QString getNom() const;
    QString getType() const;
    QString getEtat() const;
    QString getFournisseur() const;
    QString getLocalisation() const;
    int getQuantite() const;

    void setID(int id);
    void setNom(const QString &nom);
    void setType(const QString &type);
    void setEtat(const QString &etat);
    void setFournisseur(const QString &fournisseur);
    void setLocalisation(const QString &localisation);
    void setQuantite(int quantite);

    bool ajouter(); // Ajouter une ressource
    bool modifier(int id, const QString &nom, const QString &type, const QString &etat,
                  const QString &fournisseur, const QString &localisation, int quantite);
    bool supprimer(int id); // Supprimer une ressource
    QSqlQueryModel* afficher();
};

#endif // RESSOURCE_H
