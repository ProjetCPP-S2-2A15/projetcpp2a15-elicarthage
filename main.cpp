#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include <QTimer>
#include "connexion.h"
#include "arduino.h"
#include "mainwindow.h"
#include "architecte.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setOrganizationName("ENSI");
    QCoreApplication::setApplicationName("GestionPresenceArchitecte");

    Connection c;
    bool test = c.createconnect();



    MainWindow mainWindow;
    login loginWindow(&mainWindow);
   Arduino *arduino = new Arduino();
    loginWindow.show();

    QTimer::singleShot(100, [&]() {
        if (test) {
             // Envoyer les architectes à l'Arduino
            QMessageBox::information(&loginWindow,
                                     QObject::tr("Database status"),
                                     QObject::tr("Database connection is active"),
                                     QMessageBox::Ok);

             Architecte::resetPresenceDaily();

             arduino->initSerial();  // Initialiser le port série
             arduino->envoyerArchitectesSurArduino();
        } else {
            QMessageBox::critical(&loginWindow,
                                  QObject::tr("Database error"),
                                  QObject::tr("Connection failed"),
                                  QMessageBox::Ok);
        }
    });


    QObject::connect(&mainWindow, &MainWindow::architectesUpdated,
                     arduino, &Arduino::envoyerArchitectesSurArduino);



    QObject::connect(arduino, &Arduino::presenceUpdated,
                     &mainWindow, &MainWindow::refreshTable);

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
