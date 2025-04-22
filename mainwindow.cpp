#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QCoreApplication>
#include <QHBoxLayout>
#include <QWidget>
#include "tache.h"
#include <QInputDialog>
#include <QDate>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QImage>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("ELICAR");

    // Charger les options de la comboBox pour l'état
    ui->comboBox_etat->addItem("Mission APD");
    ui->comboBox_etat->addItem("Mission de programmation");
    ui->comboBox_etat->addItem("Mission APS");
    ui->comboBox_etat->addItem("Les dossiers d'exécution");
    ui->comboBox_etat->addItem("Mission B1 de contrôle travaux");
    ui->comboBox_etat->addItem("Mission B2 de coordination travaux");

    Tache etmp;
    ui->tableView->setModel(etmp.afficher());
    mettreAJourCouleursCalendrier();
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::on_calendarWidget_clicked);
    connect(ui->pushButton_micro, &QPushButton::clicked, this, &MainWindow::on_pushButton_micro_clicked);



    connect(ui->lineEdit_recherche, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_recherche_textChanged);
    connect(ui->comboBox_tri, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::on_comboBox_tri_currentIndexChanged);
    connect(ui->pushButton_exportPDF, &QPushButton::clicked, this, &MainWindow::on_pushButton_exportPDF_clicked);

    // Charger et vérifier l'image de l'icône de l'application
    QPixmap pixmap(":/imlogo.png"); // Utilisation d'un chemin relatif ou ressource
    if (!pixmap.isNull()) {
        QPixmap resizedPixmap = pixmap.scaled(128, 128, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        this->setWindowIcon(QIcon(resizedPixmap));
    } else {
        qDebug() << "L'image du logo n'a pas pu être chargée!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonajouter_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString description = ui->lineEdit_description->text();
    QString etat = ui->comboBox_etat->currentText();

    // Utilisation de QDateEdit pour récupérer les dates
    QDate debutDate = ui->dateEdit_debutDate->date();
    QDate finDate = ui->dateEdit_finDate->date();

    // Vérification des champs vides
    if (nom.isEmpty() || description.isEmpty() || etat.isEmpty() || !debutDate.isValid() || !finDate.isValid()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs avant d'ajouter une tâche.");
        return;
    }

    // Vérification que la date de fin est après la date de début
    if (finDate < debutDate) {
        QMessageBox::warning(this, "Dates invalides", "La date de fin doit être postérieure à la date de début.");
        return;
    }

    // Instanciation de l'objet Tache
    Tache t(id, nom, description, etat, debutDate, finDate);

    // Ajout dans la base de données
    bool test = t.ajouter();

    if (test) {
        Tache etmp;
        ui->tableView->setModel(etmp.afficher());
        mettreAJourCouleursCalendrier();
        QMessageBox::information(this, "Succès", "Ajout effectué avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué.");
    }
}

void MainWindow::on_btnsupprimer_clicked()
{
    // Récupérer l'ID du champ de texte
    int id = ui->lineEdit_IDS->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide.");
        return;
    }

    Tache tache;
    bool test = tache.supprimer(id);

    if (test) {
        QMessageBox::information(this, "Succès", "Suppression effectuée avec succès!");
        ui->tableView->setModel(tache.afficher());
        mettreAJourCouleursCalendrier();
    } else {
        QMessageBox::warning(this, "Erreur", "Suppression non effectuée.");
    }

    // Effacer le champ de texte après l'opération
    ui->lineEdit_IDS->clear();
}

void MainWindow::on_pushButton_modifier_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString desc = ui->lineEdit_description->text();
    QString etat = ui->comboBox_etat->currentText();

    // Utilisation de QDateEdit pour récupérer les dates
    QDate debutDate = ui->dateEdit_debutDate->date();
    QDate finDate = ui->dateEdit_finDate->date();

    // Vérification des champs vides
    if (nom.isEmpty() || desc.isEmpty() || etat.isEmpty() || !debutDate.isValid() || !finDate.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    // Vérification que la date de fin est après la date de début
    if (finDate < debutDate) {
        QMessageBox::warning(this, "Dates invalides", "La date de fin doit être postérieure à la date de début.");
        return;
    }

    // Instanciation de l'objet Tache
    Tache t;
    if (t.modifier(id, nom, desc, etat, debutDate, finDate)) {
        QMessageBox::information(this, "Succès", "Tâche modifiée avec succès !");
        ui->tableView->setModel(t.afficher());
        mettreAJourCouleursCalendrier();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification !");
    }
}

void MainWindow::on_lineEdit_recherche_textChanged(const QString &text)
{
    Tache tache;
    ui->tableView->setModel(tache.recherche(text));
}

void MainWindow::on_comboBox_tri_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    QString critere = ui->comboBox_tri->currentText();
    Tache t;
    ui->tableView->setModel(t.trierPar(critere));
}

void MainWindow::on_pushButton_exportPDF_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QPdfWriter pdf(fileName);
    pdf.setPageSize(QPageSize(QPageSize::A4));
    pdf.setResolution(300);

    QPainter painter(&pdf);
    if (!painter.isActive()) {
        QMessageBox::critical(this, "Erreur", "Impossible de créer le fichier PDF.");
        return;
    }

    int y = 50;
    QFont titleFont;
    titleFont.setBold(true);
    titleFont.setPointSize(18);
    painter.setFont(titleFont);
    painter.drawText(200, y, "Liste des Tâches");
    y += 40;

    QFont headerFont;
    headerFont.setBold(true);
    headerFont.setPointSize(12);
    painter.setFont(headerFont);

    int columnWidths[] = {350, 200, 200};
    QString headers[] = {"Nom de la Tâche", "Date Début", "Date Fin"};

    // Dessiner les en-têtes
    int x = 50;
    for (int i = 0; i < 3; ++i) {
        QRect rect(x, y, columnWidths[i], 30);
        painter.setPen(QPen(Qt::black));
        painter.setBrush(QBrush(Qt::lightGray));
        painter.drawRect(rect);
        painter.drawText(rect, Qt::AlignCenter, headers[i]);
        x += columnWidths[i];
    }
    y += 40;

    QFont contentFont;
    contentFont.setPointSize(10);
    painter.setFont(contentFont);

    QSqlQuery query("SELECT TACHENAME, DEBUTDATE, FINDATE FROM TACHE");
    while (query.next()) {
        x = 50;
        for (int i = 0; i < 3; ++i) {
            QRect rect(x, y, columnWidths[i], 30);
            painter.setBrush(QBrush(Qt::white));
            painter.drawRect(rect);
            painter.drawText(rect, Qt::AlignCenter, query.value(i).toString());
            x += columnWidths[i];
        }
        y += 40;

        if (y > pdf.height() - 100) {
            pdf.newPage();
            y = 50;
        }
    }

    painter.end();
    QMessageBox::information(this, "Export terminé", "Le fichier PDF a été généré avec succès !");
}

void MainWindow::afficherStatistiqueTache()
{
    QSqlQuery query;
    QPieSeries *series = new QPieSeries();

    if (query.exec("SELECT TACHETAT, COUNT(*) FROM TACHE GROUP BY TACHETAT")) {
        while (query.next()) {
            QString etat = query.value(0).toString();
            int count = query.value(1).toInt();
            QPieSlice *slice = series->append(etat + " (" + QString::number(count) + ")", count);
            slice->setLabelVisible();
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête statistique:" << query.lastError().text();
        QMessageBox::warning(this, "Erreur", "Impossible de générer les statistiques.");
        delete series;
        return;
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des tâches par état");
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::AllAnimations);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);
    chartView->setWindowTitle("Statistiques des Tâches");
    chartView->show();
}

void MainWindow::on_pushButton_statistique_clicked()
{
    afficherStatistiqueTache();
}


// Remplacer la méthode mettreAJourCouleursCalendrier
void MainWindow::mettreAJourCouleursCalendrier()
{
    QCalendarWidget* calendar = ui->calendarWidget;
    calendar->setDateTextFormat(QDate(), QTextCharFormat()); // Réinitialise toutes les couleurs

    QSqlQuery query("SELECT debutDate, finDate FROM TACHE");
    QDate aujourdHui = QDate::currentDate();

    while (query.next()) {
        QDate debut = query.value(0).toDate();
        QDate fin = query.value(1).toDate();

        // Colorier toutes les dates entre debut et fin
        for (QDate d = debut; d <= fin; d = d.addDays(1)) {
            QTextCharFormat format;
            int joursRestants = aujourdHui.daysTo(fin);

            if (d == aujourdHui) {
                format.setBackground(Qt::red);
            }
            else if (joursRestants <= 3 && joursRestants > 0) {
                format.setBackground(QColor(255, 165, 0)); // Orange
            }
            else if (joursRestants > 3) {
                format.setBackground(Qt::yellow);
            }
            else {
                format.setBackground(Qt::lightGray);
            }

            calendar->setDateTextFormat(d, format);
        }
    }

    // Forcer le recalcul de l'affichage
    calendar->update();
}
void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->taskDetails->clear();
    QSqlQuery query;
    query.prepare("SELECT TACHENAME FROM TACHE WHERE DEBUTDATE <= :date AND FINDATE >= :date");
    query.bindValue(":date", date);

    if (query.exec()) {
        bool hasTasks = false;
        while (query.next()) {
            hasTasks = true;
            ui->taskDetails->append("📅 " + query.value(0).toString());
        }
        if (!hasTasks) {
            ui->taskDetails->setText("Aucune tâche pour ce jour.");
        }
    } else {
        ui->taskDetails->setText("Erreur lors de la récupération des tâches.");
        qDebug() << "Erreur de requête:" << query.lastError().text();
    }
}
void MainWindow::on_pushButton_micro_clicked()
{
    QProcess *process = new QProcess(this);

    // Lancer le script Python
    process->start("C:/chemin/vers/python.exe", QStringList() << "C:/Users/eya/Desktop/archi/speech_recognition.py");


    connect(process, QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this, [=](int exitCode, QProcess::ExitStatus exitStatus) {
                if (exitStatus == QProcess::NormalExit && exitCode == 0) {
                    QString output = process->readAllStandardOutput();
                    QString cleanedOutput = output.trimmed();  // Supprime les retours à la ligne

                    if (!cleanedOutput.isEmpty()) {
                        ui->lineEdit_recherche->setText(cleanedOutput);
                        Tache t;
                        ui->tableView->setModel(t.recherche(cleanedOutput));
                    } else {
                        QMessageBox::warning(this, "Aucune voix détectée", "La reconnaissance vocale n'a pas réussi.");
                    }
                } else {
                    QMessageBox::critical(this, "Erreur", "Le script de reconnaissance vocale a échoué.");
                }

                process->deleteLater();
            });
}
