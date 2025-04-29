#ifndef HISTORIQUE_H
#define HISTORIQUE_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Historique
{
public:
    static Historique& instance(); // Singleton

    void logAction(const QString &action);

private:
    Historique(); // Constructeur privé
    QFile logFile;
    QString fileName; // Nom du fichier (par jour)
};

#endif // HISTORIQUE_H
