#ifndef ARCHITECTE_H
#define ARCHITECTE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Architecte
{
    int architectID;
    QString architectNom, architectPrenom, architectMail;
    QString role, motDePasse, question, reponse;
    int nombreHeuresSupplementaires;

public:
    // Constructeurs
    Architecte() {}
    Architecte(int, const QString&, const QString&, const QString&, const QString&,
               const QString&, const QString&, const QString&, int);

    // Getters
    int getArchitectID() const { return architectID; }
  /*  QString getArchitectNom() const { return architectNom; }
    QString getArchitectPrenom() const { return architectPrenom; }
    QString getArchitectMail() const { return architectMail; }
    QString getRole() const { return role; }
    QString getMotDePasse() const { return motDePasse; }
    QString getQuestion() const { return question; }
    QString getResponse() const { return reponse; }
    int getNombreHeuresSupplementaires() const { return nombreHeuresSupplementaires; }*/

    // Setters
  /*  void setArchitectID(int id) { this->architectID = id; }
    void setArchitectNom(const QString& nom) { architectNom = nom; }
    void setArchitectPrenom(const QString& prenom) { architectPrenom = prenom; }
    void setArchitectMail(const QString& mail) { architectMail = mail; }
    void setRole(const QString& r) { role = r; }
    void setMotDePasse(const QString& mdp) { motDePasse = mdp; }
    void setQuestion(const QString& q) { question = q; }
    void setResponse(const QString& r) { reponse = r; }
    void setNombreHeuresSupplementaires(int heures) { nombreHeuresSupplementaires = heures; }*/

    // Fonctionnalités de base
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool idExiste(int id);
       bool emailExists(const QString& email);
    bool modifier(int id, const QString &columnName, const QString &newValue);
    void getNomPrenom(int id, QString &nom, QString &prenom);
    QSqlQueryModel* rechercher(const QString &keyword);

    // Correction : Ne pas initialiser model ici
    QSqlQueryModel* afficherAvecTri(const QString& colonne, bool ascendant);
    static bool resetPresenceDaily();
};

#endif // ARCHITECTE_H
