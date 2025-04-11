#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>


#include <QMainWindow>
#include <QTableWidget>  // Inclure QTableWidget pour l'affichage en tableau
#include <QPushButton>   // Inclure QPushButton pour les interactions avec l'interface
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonajouter_clicked();  // Ajouter une tâche
  //  void on_pushButton_modifier_clicked(); // Modifier une tâche
    void on_btnsupprimer_clicked(); // Supprimer une tâche
    //void modifierCellule(const QModelIndex &index);
    void on_pushButton_modifier_clicked();
    void on_lineEdit_recherche_textChanged(const QString &text); // Recherche dynamique
    void on_comboBox_tri_currentIndexChanged(int index);
    void on_pushButton_exportPDF_clicked(); // Nouveau slot pour exporter en PDF
    void afficherStatistiqueTache();
    void on_pushButton_statistique_clicked();


private:
    Ui::MainWindow *ui;
    QSqlDatabase db;  // Connexion à la base de données

    // Déclaration des méthodes pour gérer les interactions de l'interface
    //void onModifyButtonClicked(int row);
    void onDeleteButtonClicked(int row);
    bool isValidColumn(const QString &columnName);

    // Méthode pour initialiser la connexion à la base de données
    bool initialiserConnexionDB();
};

#endif // MAINWINDOW_H
