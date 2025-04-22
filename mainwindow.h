#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMap>
#include <QDate>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QCalendarWidget>
#include <QTextCharFormat>
#include "tache.h"

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
    // Gestion des tâches
    void on_pushButtonajouter_clicked();
    void on_btnsupprimer_clicked();
    void on_pushButton_modifier_clicked();

    // Fonctionnalités d'affichage et de recherche
    void on_lineEdit_recherche_textChanged(const QString &text);
    void on_comboBox_tri_currentIndexChanged(int index);

    // Export et statistiques
    void on_pushButton_exportPDF_clicked();
    void on_pushButton_statistique_clicked();

    // Calendrier
    void on_calendarWidget_clicked(const QDate &date);
    void on_pushButton_micro_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;  // Connexion à la base de données

    // Méthodes privées
    bool initialiserConnexionDB();
    void mettreAJourCouleursCalendrier();
    void afficherStatistiqueTache();


    // Stockage des tâches par date
    QMap<QDate, QList<Tache>> mapTachesParDate;
};

#endif // MAINWINDOW_H
