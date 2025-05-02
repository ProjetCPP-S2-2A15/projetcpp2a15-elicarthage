#include "mainwindow.h"
#include <QApplication>
#include "connection.h"
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QDebug>
#include "historique.h"
#include "architecte.h"
#include "arduino.h"
#include "login.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("ENSI");
    QCoreApplication::setApplicationName("GestionPresenceArchitecte");

    Connection c;

     bool test = c.createconnect();



    Historique::instance(); // Crée le fichier à l'ouverture

     MainWindow mainWindow;
    login loginWindow(&mainWindow);
    Arduino *arduino = new Arduino();
    loginWindow.show();

    if (test) {
        mainWindow.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
        QObject::tr( "Connexion à la base de données réussie au démarrage."),QMessageBox::Cancel);
       Architecte::resetPresenceDaily();

       arduino->initSerial();  // Initialiser le port série
       arduino->envoyerArchitectesSurArduino();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
            QObject:: tr( "Connexion failed."),QMessageBox::Cancel);
    }





    QObject::connect(arduino, &Arduino::presenceUpdated,
                     &mainWindow, &MainWindow::refreshTableA);

    QObject::connect(&loginWindow, &login::loginSuccess,
                     &mainWindow, &MainWindow::handleLoginSuccess);

    QObject::connect(&loginWindow, &login::loginSuccess,
                     [&]() { loginWindow.close(); });
    QObject::connect(&mainWindow, &MainWindow::logoutSuccess, [&]() {
        mainWindow.hide();
        loginWindow.clearInterface();
        loginWindow.show();
    });

    return a.exec();
}


