#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QtCharts>
#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
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

    // Déclarez la fonction generateAutoID ici
    int generateAutoID();
     bool estTexteValide(const QString &texte);
     void setupValidation();
   void exporterPDF();
 public:
     bool verifierMotDePasse(const QString &motDePasse, QLabel* labelErreur = nullptr);

    void afficherStatistiques();
private:
    Ui::MainWindow *ui;
    QSortFilterProxyModel *proxyModel;
    void trierTableau(const QString& colonne, Qt::SortOrder order);
    bool isValidColumn(const QString &columnName);



    bool validateEmail(const QString &email, bool isModification = false);

    bool isValidSupplementaryHours(const QString &value);
    QString hasherMotDePasse(const QString &motDePasse);
    bool verifierChampsLettresSeules(const QString &champ, QLabel *labelErreur);

private slots:
    void on_btnAjouter_clicked();
    void on_annulerEvent_clicked();
    void on_btnsupprimer_clicked();
    void modifierCellule(const QModelIndex &index);
    void on_lineEdit_Rech_textChanged(const QString &text);
    void on_triCroissantButton_clicked();
    void on_triDecroissantButton_clicked();





};

#endif // MAINWINDOW_H
