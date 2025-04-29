#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtSerialPort/qserialport.h"
#include "qserialport.h"
#include "qtexttospeech.h"
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

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QTextToSpeech *speech;

     void afficher();


};

#endif // MAINWINDOW_H
