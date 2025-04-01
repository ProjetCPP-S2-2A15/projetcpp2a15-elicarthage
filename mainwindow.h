#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterProjet_clicked();

    void on_modifierProjet_clicked();

    void on_suppProjet_clicked();

    void on_projectTable_cellClicked(int row, int column);

    void on_pdfProjet_clicked();

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    void refreshTable();
};
#endif // MAINWINDOW_H
