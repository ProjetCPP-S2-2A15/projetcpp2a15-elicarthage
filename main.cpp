#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include "historique.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c,y;
    Historique::instance(); // Crée le fichier à l'ouverture

    bool test =c.createconnect();
    bool testi=y.connectToArchitectes();
    MainWindow w;
    if (test) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
        QObject::tr( "Connexion à la base de données réussie au démarrage."),QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
            QObject:: tr( "Connexion failed."),QMessageBox::Cancel);
    }
    if (testi) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr( "Connexion à la base de données avec architecte réussie au démarrage."),QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject:: tr( "Connexion with architectes failed."),QMessageBox::Cancel);
    }
        // Affiche la fenêtre

    return a.exec();
}
