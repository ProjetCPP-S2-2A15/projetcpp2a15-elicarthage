#include "historique.h"

Historique::Historique() {
    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    fileName = QString("historique_%1.log").arg(date);

    // Ouvrir une seule fois en append (ajout)
    logFile.setFileName(fileName);
    if (logFile.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&logFile);

        // Vérifie si le fichier est vide avant d'écrire l'en-tête
        if (logFile.size() == 0) {
            out << "=== Début de session [" << QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss") << "] ===\n";
        }
    }
}

Historique& Historique::instance() {
    static Historique h;
    return h;
}

void Historique::logAction(const QString &actionDetails) {
    if (!logFile.isOpen()) {
        // Tentative de réouverture au cas où
        logFile.open(QIODevice::Append | QIODevice::Text);
    }

    if (logFile.isOpen()) {
        QTextStream out(&logFile);
        QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        out << "[" << dateTime << "] " << actionDetails << "\n";
    }
}
