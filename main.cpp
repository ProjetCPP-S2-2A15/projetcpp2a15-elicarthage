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

     bool test = c.createconnect();



    Historique::instance(); // Crée le fichier à l'ouverture

     MainWindow mainWindow;

    if (test) {
        mainWindow.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
        QObject::tr( "Connexion à la base de données réussie au démarrage."),QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
            QObject:: tr( "Connexion failed."),QMessageBox::Cancel);
    }


    return a.exec();
}


