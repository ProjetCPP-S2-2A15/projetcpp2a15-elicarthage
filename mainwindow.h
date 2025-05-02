#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD

#include "speechnotifier.h"
#include "chatserver.h"
#include "chatclient.h"
#include "arduino.h"
=======
#include "ui_mainwindow_1.h"  // For MainWindow_Projects
#include "ui_mainwindow_2.h"
#include "speechnotifier.h"
#include "chatserver.h"
#include "chatclient.h"
>>>>>>> integration
#include "QtSerialPort/qserialport.h"
#include <QMainWindow>
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
<<<<<<< HEAD
namespace Ui {
class MainWindow;
}

=======

namespace Ui {
class MainWindow_Projects;
class MainWindow_Ressources;
}
>>>>>>> integration
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
<<<<<<< HEAD
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
=======

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    SpeechNotifier *m_speechNotifier;


>>>>>>> integration

private slots:
    void on_ajouterProjet_clicked();

    void on_modifierProjet_clicked();

    void on_suppProjet_clicked();

    void on_projectTable_cellClicked(int row, int column);

    void on_pdfProjet_clicked();

    void on_searchButton_clicked();

    void on_TriButton_clicked();

    void on_generateContractButton_clicked();

<<<<<<< HEAD

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
=======
    //void toggleServer();
    //void sendChatMessage();
    //void displayMessage(const QString &message);
    void switchToRessources() ;
    void switchToProjectsUI();
>>>>>>> integration
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
<<<<<<< HEAD
    //-----------------------------------------
    void on_ressourcesBtn_clicked();
    void on_architecteBtn_clicked();
    void on_tacheBtn_clicked();
    void on_projetBtn_clicked();
    void on_clientBtn_clicked();
    void on_formationsBtn_clicked();
    void on_btnDeconnecter_clicked();
private:
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

=======


private:
    QStackedWidget *stack;
    QWidget *projectsWidget;
    QWidget *ressourcesWidget;
    Ui::MainWindow_Projects *ui1;
    Ui::MainWindow_Ressources *ui2;
>>>>>>> integration
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

    void afficher();
    ChatServer *server;
    ChatClient *client;
    bool isServerRunning = false;
    void refreshTable();
    void generateContract(const QString &clientName, const QString &projectName,
                          const QString &projectDescription, double budget,
                          const QDate &startDate, const QString &projectType);
    QString generateContractText(const QString &clientName, const QString &projectName,
                                 const QString &projectDescription, double budget,
                                 const QDate &startDate, const QString &projectType);
};







#endif // MAINWINDOW_H
