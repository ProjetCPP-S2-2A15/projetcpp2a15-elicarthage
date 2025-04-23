#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qgraphicsscene.h"
#include <QMainWindow>
#include <QTableWidget>
#include <QMouseEvent>
#include <QDebug>

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
    void on_mapViewClient_clicked(const QPointF &pos);
    void on_showMapButton_clicked();


    

private:
    Ui::MainWindow *ui;
    QGraphicsScene *clientScene;
    
    void refreshClientTable();
    void clearClientInputFields();
    class Client getClientFromInput();

    
    void refreshTable();
     bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // MAINWINDOW_H
