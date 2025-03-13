#include "mainwindow.h"

#include <QApplication>

#include "connection.h"

#include <QDebug>

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

    return a.exec();
}

