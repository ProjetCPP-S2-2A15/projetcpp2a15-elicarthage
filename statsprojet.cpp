#include "statsprojet.h"
#include <QSqlQuery>
#include <QBarSeries>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <qsqlerror.h>

StatsProjet::StatsProjet(QWidget *parent) : QWidget(parent) {
    chartView = new QChartView(this);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(chartView);
    setLayout(layout);
}

void StatsProjet::loadYearlyStats() {
    QSqlQuery query;
    query.prepare("SELECT EXTRACT(YEAR FROM DATE_DEBUT) as year, COUNT(*) as count, SUM(BUDGET) as total "
                  "FROM PROJET GROUP BY EXTRACT(YEAR FROM DATE_DEBUT) ORDER BY year");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la requête des statistiques par année:" << query.lastError();
        return;
    }

    QBarSet *countSet = new QBarSet("Nombre de projets");
    QBarSet *budgetSet = new QBarSet("Budget total (k€)");
    QStringList categories;

    while (query.next()) {
        QString year = query.value("year").toString();
        if (year.isEmpty() || year == "0") continue;  // Ignorer les années invalides

        int count = query.value("count").toInt();
        double total = query.value("total").toDouble();

        *countSet << count;
        *budgetSet << total / 1000; // Convertir en k€
        categories << year;
    }

    if (categories.isEmpty()) {
        qDebug() << "Aucune donnée valide trouvée pour les statistiques par année";
        return;
    }

    QBarSeries *series = new QBarSeries();
    series->append(countSet);
    series->append(budgetSet);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des projets par année");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%i");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView->setChart(chart);
}

void StatsProjet::loadBudgetStats() {
    QSqlQuery query;
    query.prepare("SELECT TYPE, SUM(BUDGET) as total FROM PROJET GROUP BY TYPE");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la requête des statistiques par type:" << query.lastError();
        return;
    }

    QPieSeries *series = new QPieSeries();

    while (query.next()) {
        series->append(query.value("TYPE").toString() +
                           QString(" (%1 k€)").arg(query.value("total").toDouble() / 1000),
                       query.value("total").toDouble());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition du budget par type de projet");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);

    chartView->setChart(chart);
}
