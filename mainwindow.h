#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "speechnotifier.h"

#include "arduino.h"
#include "tache.h"
#include "client.h"
#include "statsprojet.h"

#include "QtSerialPort/qserialport.h"
#include <QMainWindow>
#include <QTabWidget>
#include <QTableWidget>  // Inclure le QTableWidget
#include <QPushButton>   // Inclure QPushButton
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QMainWindow>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextDocument>
#include <QStackedWidget>



QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:

    void logoutSuccess();
public:
  explicit MainWindow( QWidget *parent = nullptr);
    ~MainWindow();
    SpeechNotifier *m_speechNotifier;
        QLineEdit* getPasswordLineEdit();
    int generateAutoID();
    bool estTexteValide(const QString &texte);
    void setupValidation();
    void exporterPDFA();

    bool verifierMotDePasse(const QString &motDePasse, QLabel* labelErreur = nullptr);
    void afficherStatistiques();

/*protected:
      bool eventFilter(QObject *obj, QEvent *event);*/


public slots:
        void refreshTableA();
      void handleLoginSuccess(const QString &role);


private slots:
      // Gestion des tâches
      void on_pushButtonajouter_clicked();
      void on_btnsupprimerT_clicked();
      void on_pushButton_modifierT_clicked();

      // Fonctionnalités d'affichage et de recherche
      void on_lineEdit_recherche_textChanged(const QString &text);
      void on_comboBox_tri_currentIndexChanged(int index);

      // Export et statistiques
      void on_pushButton_exportPDF_clicked();
      void on_pushButton_statistique_clicked();

      // Calendrier
      void on_calendarWidget_clicked(const QDate &date);
      void on_pushButton_micro_clicked();
    void on_ajouterProjet_clicked();

    void on_modifierProjet_clicked();

    void on_suppProjet_clicked();

    void on_projectTable_cellClicked(int row, int column);

    void on_pdfProjet_clicked();

    void on_searchButton_clicked();

    void on_TriButton_clicked();

    void on_generateContractButton_clicked();



    void on_btnAjouter_clicked();
    void on_annulerEvent_clicked();
    void on_btnsupprimer_clicked();
    void modifierCellule(const QModelIndex &index);
    void on_lineEdit_Rech_textChanged(const QString &text);
    void on_triCroissantButton_clicked();
    void on_triDecroissantButton_clicked();

    //void toggleServer();
    //void sendChatMessage();
    //void displayMessage(const QString &message);
   // void switchToRessources() ;
   // void switchToProjectsUI();

    void on_annulertri_clicked();
    void affichertri(QString typeFiltre);
    void on_trimateriel_clicked();
    void on_trilogiciel_clicked();
    void exporterPDF();
    void rechercher();
    void afficherGraphiqueMateriels();
    void setupTableWidget();
    void on_ajouter_clicked();
    void on_supprimer_clicked();
    void modifier(int id, const QString &nom, const QString &type, const QString &etat,
                  const QString &fournisseur, const QString &localisation, int quantite);

    //-----------------------------------------
    void on_ressourcesBtn_clicked();
    void on_architecteBtn_clicked();
    void on_tacheBtn_clicked();
    void on_projetBtn_clicked();
    void on_clientBtn_clicked();
    void on_formationsBtn_clicked();
    void on_btnDeconnecter_clicked();
    void on_addClientButton_clicked();
    void on_updateClientButton_clicked();
    void on_deleteClientButton_clicked();
    void on_clientTable_cellClicked(int row, int column);
    void on_searchClientButton_2_clicked();
    void on_sortClientButton_clicked();
    void on_pdfc_clicked();
    //void on_mapViewClient_clicked(const QPointF &pos);
    //void on_showMapButton_clicked();

private:
    StatsProjet *statsProjet;
    QTabWidget *statsTabWidget;
     Ui::MainWindow *ui;

    QList<QWidget*> allModules;
     Arduino *arduino;
     QString currentUserRole;
    bool isModuleAllowed(QWidget *module);
    void setupPermissions();
    QWidget* findParentModule(QWidget *child);
    void showAccessDenied();
bool eventFilter(QObject *obj, QEvent *event);
    void switchWidget(QWidget* widgetToShow);
    bool isValidColumn(const QString &columnName);
    bool validateEmail(const QString &email, bool isModification = false);
    bool isValidSupplementaryHours(const QString &value);
    QString hasherMotDePasse(const QString &motDePasse);
    bool verifierChampsLettresSeules(const QString &champ, QLabel *labelErreur);
    QStackedWidget *stack;

    QTableWidget *tableWidget;
    QLineEdit *lineEdit_Nom;
    QLineEdit *lineEdit_Type;
    QLineEdit *lineEdit_Etat;
    QLineEdit *lineEdit_Fournisseur;
    QLineEdit *lineEdit_Localisation;
    QLineEdit *lineEdit_Quantite;
    QLineEdit *lineEdit_Id;
    QLineEdit *lineEdit_Recherche;
    QWidget *widgetGraphLayoutContainer;
    QSerialPort *serial;
    QTextToSpeech *speech;
    // Méthodes privées
    void mettreAJourCouleursCalendrier();
    void afficherStatistiqueTache();
    QGraphicsScene *clientScene;

    void refreshClientTable();
    void clearClientInputFields();
    class Client getClientFromInput();


    void refreshTablec();
    //bool eventFilterc(QObject *obj, QEvent *event) override;



    // Stockage des tâches par date
    QMap<QDate, QList<Tache>> mapTachesParDate;

    void afficher();
    void refreshTable();
    void generateContract(const QString &clientName, const QString &projectName,
                          const QString &projectDescription, double budget,
                          const QDate &startDate, const QString &projectType);
    QString generateContractText(const QString &clientName, const QString &projectName,
                                 const QString &projectDescription, double budget,
                                 const QDate &startDate, const QString &projectType);
};







#endif // MAINWINDOW_H
