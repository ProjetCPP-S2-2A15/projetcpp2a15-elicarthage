#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>

class Client {
private:
    QString cin;
    QString nom;
    QString prenom;
    QString email;
    QString adresse;
    QString type;
    double x, y;
    QString lastError;

public:
    Client() {}
    Client(const QString &cin, const QString &nom, const QString &prenom,
           const QString &email, const QString &adresse, const QString &type, double x, double y)
        : cin(cin), nom(nom), prenom(prenom), email(email), adresse(adresse), type(type), x(x), y(y) {}

    // Getters
    QString getCIN() const { return cin; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getEmail() const { return email; }
    QString getAdresse() const { return adresse; }
    QString getType() const { return type; }
    double getX() const { return x; }
    double getY() const { return y; }
    QString getLastError() const { return lastError; }

    // Setters
    void setCIN(const QString &value) { cin = value; }
    void setNom(const QString &value) { nom = value; }
    void setPrenom(const QString &value) { prenom = value; }
    void setEmail(const QString &value) { email = value; }
    void setAdresse(const QString &value) { adresse = value; }
    void setType(const QString &value) { type = value; }
    void setX(double value) { x = value; }
    void setY(double value) { y = value; }


    // CRUD
    bool addClient();
    void display(QTableWidget *tableWidget);
    bool deleteClient(const QString &cin);
    bool updateClient(const QString &originalCIN);
};

#endif // CLIENT_H
