#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>  // Inclure le QTableWidget
#include <QPushButton>   // Inclure QPushButton

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

private:
    Ui::MainWindow *ui;

private slots:
    void on_btnAjouter_clicked();
    void on_annulerEvent_clicked();
    void on_btnsupprimer_clicked();
    void modifierCellule(const QModelIndex &index);
    bool isValidColumn(const QString &columnName);

   // void verifierMotDePasse(const QString &motDePasse);
  //  void validateEmail(const QString &email);
    bool isValidSupplementaryHours(const QString &value);
    QString hasherMotDePasse(const QString &motDePasse);

};

#endif // MAINWINDOW_H
