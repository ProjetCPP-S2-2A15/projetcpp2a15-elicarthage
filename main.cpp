#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Vérification de la DB en arrière-plan
    Connection c;
    bool test = c.createconnect();

    // Création des fenêtres dans le bon ordre
    MainWindow mainWindow; // Doit être créé en premier maintenant
    login loginWindow(&mainWindow); // Passez le pointeur de MainWindow

    // Afficher le login immédiatement
    loginWindow.show();

    // Afficher le message après un court délai
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

    QObject::connect(&loginWindow, &login::loginSuccess, [&]() {
        loginWindow.hide();
        mainWindow.show();
    });

    return a.exec();
}
