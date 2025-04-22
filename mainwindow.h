#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "speechnotifier.h"

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
    SpeechNotifier *m_speechNotifier;

private slots:
    void on_ajouterProjet_clicked();

    void on_modifierProjet_clicked();

    void on_suppProjet_clicked();

    void on_projectTable_cellClicked(int row, int column);

    void on_pdfProjet_clicked();

    void on_searchButton_clicked();

    void on_TriButton_clicked();

    void on_generateContractButton_clicked();


private:
    Ui::MainWindow *ui;
    void refreshTable();
    void generateContract(const QString &clientName, const QString &projectName,
                          const QString &projectDescription, double budget,
                          const QDate &startDate, const QString &projectType);
    QString generateContractText(const QString &clientName, const QString &projectName,
                                 const QString &projectDescription, double budget,
                                 const QDate &startDate, const QString &projectType);
};
#endif // MAINWINDOW_H
