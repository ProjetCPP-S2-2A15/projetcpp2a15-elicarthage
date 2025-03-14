#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlQueryModel>

class Client {
private:
    int clientId;                // Identifiant unique du client
    QString clientNom;           // Nom du client
    QString clientPrenom;        // Prénom du client
    QString clientTel;           // Numéro de téléphone du client
    QString clientMail;          // Adresse e-mail du client
    QString clientAdresse;       // Adresse du client
    QString clientType;          // Type de client (e.g., "Particulier", "Entreprise")

public:
    // Constructeurs
    Client();
    Client(int id, const QString& nom, const QString& prenom, const QString& tel, const QString& mail, const QString& adresse, const QString& type);

    // Méthodes pour interagir avec la base de données
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    bool modifier(int id, const QString& columnName, const QString& newValue);
    bool idExiste(int id);

    // Getters
    int getClientId() const;
    QString getClientNom() const;
    QString getClientPrenom() const;
    QString getClientTel() const;
    QString getClientMail() const;
    QString getClientAdresse() const;
    QString getClientType() const;


    // Setters
    void setClientId(int id);
    void setClientNom(const QString& nom);
    void setClientPrenom(const QString& prenom);
    void setClientTel(const QString& tel);
    void setClientMail(const QString& mail);
    void setClientAdresse(const QString& adresse);
    void setClientType(const QString& type);

};

#endif // CLIENT_H
