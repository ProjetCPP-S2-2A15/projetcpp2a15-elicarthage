#ifndef RESSOURCE_H
#define RESSOURCE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Ressource {
public:
    Ressource();
    Ressource(const QString &nom, const QString &type, const QString &etat,
              const QString &fournisseur, const QString &localisation, int quantite);

    bool ajouter();
    bool modifier(int id, const QString &nom, const QString &type, const QString &etat,
                  const QString &fournisseur, const QString &localisation, int quantite);
    bool supprimer(int);
    QSqlQueryModel* afficher();
    QString getLastError() const;

    // ✅ Getters
    QString nom() const { return NOM; }
    QString status() const { return ETAT; }
    int quantite() const { return QUANTITE; }
    bool isDisponible() const { return disponible; }
    void setDisponible(bool dispo) { disponible = dispo; }

private:
    QString NOM, TYPE, ETAT, FOURNISSEUR, LOCALISATION;
    int QUANTITE;
    bool disponible = true;
};

class RessourceManager {
public:
    static QString recupererDernierEmail();
    static void verifierEtNotifier(Ressource ressource);
};
#endif // RESSOURCE_H
