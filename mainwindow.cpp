#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QPageSize>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    refreshClientTable();

    connect(ui->clientTable, &QTableWidget::cellClicked, this, &MainWindow::on_clientTable_cellClicked);
    connect(ui->searchClientButton, &QPushButton::clicked, this, &MainWindow::on_searchClientButton_clicked);
    connect(ui->sortClientButton, &QPushButton::clicked, this, &MainWindow::on_sortClientButton_clicked);
    clientScene = new QGraphicsScene(this);
    ui->mapViewClient->setScene(clientScene);
    ui->mapViewClient->installEventFilter(this);

    QGraphicsPixmapItem *carte = new QGraphicsPixmapItem(QPixmap("C:\\Users\\chokr\\Downloads\\Atelier_Connexion\\Atelier_Connexion\\map.jpg"));
    clientScene->addItem(carte);

     //
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshClientTable()
{
    Client client;
    ui->clientTable->setColumnCount(6);
    ui->clientTable->setHorizontalHeaderLabels({"CIN", "Nom", "Prénom", "Email", "Adresse", "Type"});
    client.display(ui->clientTable);

    if (ui->clientTable->rowCount() == 0) {
        QMessageBox::warning(this, "Attention", "Aucun client à afficher.");
    }
}

void MainWindow::on_addClientButton_clicked()
{
    Client client;
    QString email = ui->email_input->text().trimmed();
     QString cin = ui->cin_input->text().trimmed();
    QString x_str = ui->posx_client->text();
    QString y_str = ui->posy_client->text();
    client.setCIN(cin);
    client.setNom(ui->nom_input->text().trimmed());
    client.setPrenom(ui->prenom_input->text().trimmed());
    client.setEmail(email);
    client.setAdresse(ui->adresse_input->text().trimmed());
    client.setType(ui->type_input->text().trimmed());
    client.setX(x_str);
    client.setY(y_str);


    if (client.getCIN().isEmpty() || client.getNom().isEmpty() || client.getPrenom().isEmpty() ||
        client.getEmail().isEmpty() || client.getAdresse().isEmpty() || client.getType().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }
    QRegularExpression cinRegex("^\\d{8}$");
    if (!cinRegex.match(cin).hasMatch()) {
        QMessageBox::warning(this, "CIN invalide", "Le CIN doit contenir exactement 8 chiffres.");
        return;
    }

    QRegularExpression emailRegex("^[\\w.-]+@([\\w-]+\\.)+[\\w-]{2,4}$");

    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide", "L'adresse e-mail saisie est invalide.");
        return;
    }

    if (client.addClient()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès.");
        refreshClientTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du client."+ client.getLastError());
    }


}

void MainWindow::on_deleteClientButton_clicked()
{
    int row = ui->clientTable->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un client à supprimer.");
        return;
    }

    QString cin = ui->clientTable->item(row, 0)->text();
    Client client;
    if (client.deleteClient(cin)) {
        QMessageBox::information(this, "Succès", "Client supprimé avec succès.");
        refreshClientTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::on_updateClientButton_clicked()
{
    Client client;
    client.setCIN(ui->cin_input->text().trimmed());
    client.setNom(ui->nom_input->text().trimmed());
    client.setPrenom(ui->prenom_input->text().trimmed());
    client.setEmail(ui->email_input->text().trimmed());
    client.setAdresse(ui->adresse_input->text().trimmed());
    client.setType(ui->type_input->text().trimmed());

    if (client.getCIN().isEmpty() || client.getNom().isEmpty() || client.getPrenom().isEmpty() ||
        client.getEmail().isEmpty() || client.getAdresse().isEmpty() || client.getType().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    if (client.updateClient(client.getCIN())) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès.");
        refreshClientTable();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}

void MainWindow::on_clientTable_cellClicked(int row, int column)
{
    Q_UNUSED(column);
    if (row < 0) return;

    ui->cin_input->setText(ui->clientTable->item(row, 0)->text());
    ui->nom_input->setText(ui->clientTable->item(row, 1)->text());
    ui->prenom_input->setText(ui->clientTable->item(row, 2)->text());
    ui->email_input->setText(ui->clientTable->item(row, 3)->text());
    ui->adresse_input->setText(ui->clientTable->item(row, 4)->text());
    ui->type_input->setText(ui->clientTable->item(row, 5)->text());
}
void MainWindow::on_pdfProjet_clicked()
{ // Sélection du chemin et du nom du fichier PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "*.pdf");
    if (filePath.isEmpty()) return;

    if (!filePath.endsWith(".pdf")) {
        filePath += ".pdf";
    }

    // Initialisation de QPdfWriter
    QPdfWriter pdfWriter(filePath);
    pdfWriter.setPageSize(QPageSize::A4);
    pdfWriter.setResolution(300);
    pdfWriter.setPageMargins(QMargins(50, 50, 50, 50));

    QPainter painter(&pdfWriter);
    if (!painter.isActive()) {
        QMessageBox::warning(this, "Erreur", "Impossible de créer le fichier PDF.");
        return;
    }

    // Police et couleur du titre
    QFont titleFont("Helvetica", 24, QFont::Bold);
    painter.setFont(titleFont);
    painter.setPen(QColor(0, 0, 255)); // Bleu pour le titre
    painter.drawText(QRect(0, 0, pdfWriter.width(), 100), Qt::AlignCenter, "Liste des Clients");

    // Police et couleur du contenu
    QFont contentFont("Helvetica", 12);
    painter.setFont(contentFont);
    painter.setPen(Qt::black);

    // Définir la position initiale et la hauteur des lignes
    int yOffset = 180;
    int rowHeight = 40;

    // Colonnes pour l'affichage (Project ID et Project Name)
    QStringList headers = {"CIN", "Nom"};
    int columnCount = headers.size();
    int totalWidth = pdfWriter.width() - 100;
    QVector<int> columnWidths = {
        static_cast<int>(totalWidth * 0.2),
        static_cast<int>(totalWidth * 0.4)
    };

    // Couleur de fond pour l'entête
    QColor headerColor(173, 216, 230); // Bleu clair pour l'entête
    painter.setPen(headerColor);

    // Affichage des entêtes de colonne
    int leftMargin = 50;
    for (int col = 0; col < columnCount; ++col) {
        painter.drawText(leftMargin, yOffset, columnWidths[col], rowHeight, Qt::AlignCenter, headers[col]);
        leftMargin += columnWidths[col];
    }
    yOffset += rowHeight;
    painter.drawLine(50, yOffset, pdfWriter.width() - 50, yOffset); // Ligne sous les entêtes
    yOffset += 10;

    // Requête SQL pour récupérer les projets
    QSqlQuery query;
    if (!query.exec("SELECT CIN, NOM FROM CLIENTS")) {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la récupération des données : " + query.lastError().text());
        return;
    }

    // Vérification si des projets sont récupérés
    if (!query.next()) {
        QMessageBox::information(this, "Info", "Aucun projet trouvé.");
        return;
    }

    // Parcours des projets et ajout au PDF
    do {
        leftMargin = 50;
        QStringList rowData = {
            query.value(0).toString(), // Project ID
            query.value(1).toString()  // Project Name
        };

        // Ajout des données à chaque ligne du PDF
        painter.setPen(Qt::black);
        for (int col = 0; col < columnCount; ++col) {
            painter.drawText(leftMargin, yOffset, columnWidths[col], rowHeight, Qt::AlignCenter, rowData[col]);
            leftMargin += columnWidths[col];
        }
        yOffset += rowHeight;

        // Si la page est pleine, crée une nouvelle page
        if (yOffset + rowHeight > pdfWriter.height() - 50) {
            pdfWriter.newPage();
            yOffset = 100;
            leftMargin = 50;
            painter.setPen(headerColor);
            for (int col = 0; col < columnCount; ++col) {
                painter.drawText(leftMargin, yOffset, columnWidths[col], rowHeight, Qt::AlignCenter, headers[col]);
                leftMargin += columnWidths[col];
            }
            yOffset += rowHeight;
            painter.drawLine(50, yOffset, pdfWriter.width() - 50, yOffset);
            yOffset += 10;
        }
    } while (query.next()); // Parcours de tous les projets

    // Fin du dessin sur le PDF
    painter.end();

    // Message de succès
    QMessageBox::information(this, "Succès", "Le fichier PDF a été exporté avec succès !");
}
void MainWindow::on_searchClientButton_clicked()
{
    QString searchText = ui->searchClient_input->text().toLower();
    int rows = ui->clientTable->rowCount();
    int cols = ui->clientTable->columnCount();

    for (int i = 0; i < rows; ++i) {
        bool match = false;
        for (int j = 0; j < cols; ++j) {
            auto item = ui->clientTable->item(i, j);
            if (item && item->text().toLower().contains(searchText)) {
                match = true;
                break;
            }
        }
        ui->clientTable->setRowHidden(i, !match);
    }
}

void MainWindow::on_sortClientButton_clicked()
{
    QString critere = ui->rechProjet_5->currentText();
    if (critere == "CIN")
        ui->clientTable->sortByColumn(0, Qt::AscendingOrder);
    else if (critere == "Nom")
        ui->clientTable->sortByColumn(1, Qt::AscendingOrder);
}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->mapViewClient && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        // Convertir la position du clic (widget -> scène)
        QPointF scenePos = ui->mapViewClient->mapToScene(mouseEvent->pos());

        // Affichage dans les champs (à adapter selon ton UI)
        ui->posx_client->setText(QString::number(scenePos.x()));
        ui->posy_client->setText(QString::number(scenePos.y()));

        return true; // événement traité
    }

    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::on_mapViewClient_clicked(const QPointF &point) {
    qDebug() << "Clicked at" << point;
}

