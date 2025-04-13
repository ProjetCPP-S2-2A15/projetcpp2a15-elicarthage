#include "historique.h"

Historique::Historique() {
    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss");
    QString fileName = "historique_" + timestamp + ".log";

    logFile.setFileName(fileName);
    if (logFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&logFile);
        out << "=== Début de session [" << QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss") << "] ===\n";
    }
}

Historique& Historique::instance() {
    static Historique h;
    return h;
}

void Historique::logAction(const QString &actionDetails) {
    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString filename = QString("historique_%1.log")
                           .arg(QDate::currentDate().toString("yyyy-MM-dd"));

    QFile file(filename);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << "[" << dateTime << "] " << actionDetails << "\n";
        file.close();
    }
}
