#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>

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

private:
    Ui::MainWindow *ui;
    bool isValidColumn(const QString &columnName);

    bool verifierMotDePasse(const QString &motDePasse);
    bool validateEmail(const QString &email);
    bool isValidSupplementaryHours(const QString &value);
    QString hasherMotDePasse(const QString &motDePasse);
    bool verifierChampsLettresSeules(const QString &champ, QLabel *labelErreur);

private slots:
    void on_btnAjouter_clicked();
    void on_annulerEvent_clicked();
    void on_btnsupprimer_clicked();
    void modifierCellule(const QModelIndex &index);



};

#endif // MAINWINDOW_H
