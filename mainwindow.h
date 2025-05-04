#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "speechnotifier.h"
#include "chatserver.h"
#include "chatclient.h"
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
namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
  explicit MainWindow( QWidget *parent = nullptr);
    ~MainWindow();
    SpeechNotifier *m_speechNotifier;


/*protected:
      bool eventFilter(QObject *obj, QEvent *event);*/

private slots:
    void on_ajouterProjet_clicked();

    void on_modifierProjet_clicked();

    void on_suppProjet_clicked();

    void on_projectTable_cellClicked(int row, int column);

    void on_pdfProjet_clicked();

    void on_searchButton_clicked();

    void on_TriButton_clicked();

    void on_generateContractButton_clicked();

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
    //void on_btnDeconnecter_clicked();
private:
     Ui::MainWindow *ui;

    QList<QWidget*> allModules;

    bool isModuleAllowed(QWidget *module);
    void setupPermissions();
    QWidget* findParentModule(QWidget *child);
    void showAccessDenied();

    void switchWidget(QWidget* widgetToShow);

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
