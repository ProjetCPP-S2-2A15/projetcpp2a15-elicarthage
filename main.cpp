#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include <QTimer>
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Connection c;
    bool test = c.createconnect();


    MainWindow mainWindow;
    login loginWindow(&mainWindow);

    loginWindow.show();

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
