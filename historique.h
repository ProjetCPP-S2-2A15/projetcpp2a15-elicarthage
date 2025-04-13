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
};

#endif // HISTORIQUE_H
