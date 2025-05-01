#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QDebug>
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
    Connection c;

    if (c.createconnect()) {
        qDebug() << "Connexion à la base de données réussie au démarrage.";
    } else {
        qDebug() << "Connexion échouée au démarrage.";
    }
    MainWindow w; // Crée une instance de MainWindow
    w.show();     // Affiche la fenêtre




    Historique::instance(); // Crée le fichier à l'ouverture

    bool test =c.createconnect();
    if (test) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
        QObject::tr( "Connexion à la base de données réussie au démarrage."),QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
            QObject:: tr( "Connexion failed."),QMessageBox::Cancel);
    }

        // Affiche la fenêtre

    return a.exec();
}
