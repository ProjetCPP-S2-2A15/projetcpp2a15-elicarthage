#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "smsmanager.h"  // Inclure SmsManager pour l'envoi de SMS
#include "formation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAjouter_clicked();
    void on_btnSupprimer_clicked();
    void on_btnModifier_clicked();
    void on_btnTrierThematique_clicked();
    void on_btnRechercherId_clicked();
    void on_btnRechercherDate_clicked();
    void on_btnSendSms_clicked();  // Nouvelle méthode pour envoyer le SMS

private:
    Ui::MainWindow *ui;
    Formation F;
    SmsManager smsManager;  // Instance de SmsManager
    void setupUI();
    void setupConnections();
    void afficherTableView();
    void clearFields();
    void showError(const QString &message);
    void showSuccess(const QString &message);
};

#endif // MAINWINDOW_H
