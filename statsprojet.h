#ifndef STATSPROJET_H
#define STATSPROJET_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>

class StatsProjet : public QWidget {
    Q_OBJECT

public:
    explicit StatsProjet(QWidget *parent = nullptr);
    void loadYearlyStats();
    void loadBudgetStats();

private:
    QChartView *chartView;
};

#endif // STATSPROJET_H
