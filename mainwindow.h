#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>  // Inclure QTableWidget
#include <QPushButton>   // Inclure QPushButton
#include <QSqlDatabase>  // Inclure QSqlDatabase pour la gestion SQL
#include <QSqlQuery>     // Inclure QSqlQuery pour exécuter des requêtes SQL
#include <QSqlError>     // Inclure QSqlError pour afficher les erreurs SQL
#include <QDebug>        // Pour afficher les erreurs dans la console

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);  // Ajout de `explicit` pour éviter les erreurs d’implicit conversion
    ~MainWindow();

private slots:  // Déplacer "private slots:" ici
    void on_pushButton_ajouter_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;  // Ajout de la connexion à la base de données

    // Déclaration des méthodes pour gérer les boutons
    void onModifyButtonClicked(int row);
    void onDeleteButtonClicked(int row);
};

#endif // MAINWINDOW_H
