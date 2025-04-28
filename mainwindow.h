#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QLabel>
#include <QtCharts>
#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include "arduino.h"


QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
      void architectesUpdated();
    void logoutSuccess();


public:
    explicit MainWindow( QWidget *parent = nullptr);
    QLineEdit* getPasswordLineEdit();
    ~MainWindow();
    void actualiserTableArchitecte();
    int generateAutoID();
    bool estTexteValide(const QString &texte);
    void setupValidation();
    void exporterPDF();

    bool verifierMotDePasse(const QString &motDePasse, QLabel* labelErreur = nullptr);
    void afficherStatistiques();

private:
    Ui::MainWindow *ui;
         Arduino *arduino;
    QString currentUserRole; // Ajouter cette variable membre
    QList<QWidget*> allModules;
    bool eventFilter(QObject *obj, QEvent *event);
    bool isModuleAllowed(QWidget *module);
    void setupPermissions();
    QWidget* findParentModule(QWidget *child);
    void showAccessDenied();


    bool isValidColumn(const QString &columnName);
    bool validateEmail(const QString &email, bool isModification = false);
    bool isValidSupplementaryHours(const QString &value);
    QString hasherMotDePasse(const QString &motDePasse);
    bool verifierChampsLettresSeules(const QString &champ, QLabel *labelErreur);


    void switchWidget(QWidget* widgetToShow);
public slots:
        void refreshTable();
    void handleLoginSuccess(const QString &role);

private slots:


    void on_btnAjouter_clicked();
    void on_annulerEvent_clicked();
    void on_btnsupprimer_clicked();
    void modifierCellule(const QModelIndex &index);
    void on_lineEdit_Rech_textChanged(const QString &text);
    void on_triCroissantButton_clicked();
    void on_triDecroissantButton_clicked();
    void on_ressourcesBtn_clicked();
    void on_architecteBtn_clicked();
    void on_tacheBtn_clicked();
    void on_projetBtn_clicked();
    void on_clientBtn_clicked();
    void on_formationsBtn_clicked();
    void on_btnDeconnecter_clicked();
};

#endif // MAINWINDOW_H
