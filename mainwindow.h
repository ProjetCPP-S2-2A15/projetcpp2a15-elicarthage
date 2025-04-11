#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

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
    // ==== Module CLIENT ====
    void on_addClientButton_clicked();
    void on_updateClientButton_clicked();
    void on_deleteClientButton_clicked();
    void on_clientTable_cellClicked(int row, int column);
    void on_searchClientButton_clicked();
    void on_sortClientButton_clicked();
    void on_pdfProjet_clicked();
    //void on_showMapButton_clicked();


    // ==== Module PROJET ====

private:
    Ui::MainWindow *ui;

    // === Fonctions utilitaires pour le module client ===
    void refreshClientTable();
    void clearClientInputFields();
    class Client getClientFromInput();

    // === Pour le module projet (à implémenter de ton côté) ===
    void refreshTable(); // <- Peut-être à renommer "refreshProjectTable" si besoin
};

#endif // MAINWINDOW_H
