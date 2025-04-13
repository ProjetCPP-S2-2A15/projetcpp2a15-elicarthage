#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include <QTimer>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Vérification de la DB en arrière-plan
    Connection c;
    bool test = c.createconnect();

    // Création des fenêtres
    MainWindow mainWindow;
    login loginWindow(&mainWindow);

    // Afficher le login immédiatement
    loginWindow.show();

    // Afficher le message de statut de connexion
    QTimer::singleShot(100, [&]() {
        if(test) {
            QMessageBox::information(&loginWindow,
                                     QObject::tr("Database status"),
                                     QObject::tr("Database connection is active"),
                                     QMessageBox::Ok);
        } else {
            QMessageBox::critical(&loginWindow,
                                  QObject::tr("Database error"),
                                  QObject::tr("Connection failed"),
                                  QMessageBox::Ok);
        }
    });
/*
    QObject::connect(&loginWindow, &login::loginSuccess, [&](const QString &role) {
        loginWindow.hide(); // Cache la fenêtre de login
        //mainWindow.handleLoginSuccess(role); // Traite le rôle
        mainWindow.show(); // Affiche la fenêtre principale
    });
*//*
    QObject::connect(&loginWindow, &login::loginSuccess,
                     [&](const QString &role) {
                         loginWindow.close();
                         mainWindow.handleLoginSuccess(role);
                     });*/

    // Dans main.cpp
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
