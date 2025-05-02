#include "arduino.h"
#include <QDebug>
#include <QThread>
#include <QSqlError>
#include <QString>
#include "mainwindow.h"
Arduino::Arduino(QObject *parent)
    : QObject(parent),
    serialPort(nullptr)
{
}

Arduino::~Arduino() {
    if (serialPort && serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
}

void Arduino::initSerial() {
    serialPort = new QSerialPort();
    serialPort->setPortName("COM5");
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (!serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Impossible d'ouvrir le port série!";
    } else {

        qDebug() << "Port série ouvert avec succès.";
    }

    connect(serialPort, &QSerialPort::readyRead, this, &Arduino::lireNomDepuisArduino);

}

void Arduino::lireNomDepuisArduino() {
    QByteArray data = serialPort->readAll();
    static QString buffer;

    buffer += QString::fromUtf8(data);
    if (!buffer.contains('\n')) return;

    QStringList lignes = buffer.split('\n');
    for (int i = 0; i < lignes.size() - 1; ++i) {
        QString ligne = lignes[i].trimmed();


        qDebug() << "Nom reçu de l'Arduino : " << ligne;


        QStringList nomPrenom = ligne.split(" ");
        if (nomPrenom.size() == 2) {
            QString nom = nomPrenom[0];
            QString prenom = nomPrenom[1];


            QSqlDatabase db = QSqlDatabase::database();
            if (!db.isOpen()) {
                qDebug() << "Base de données non ouverte.";
                return;
            }

            QSqlQuery query(db);
            query.prepare("SELECT id FROM ARCHITECTE WHERE nom = :nom AND PRÉNOM = :prenom");
            query.bindValue(":nom", nom);
            query.bindValue(":prenom", prenom);

            if (!query.exec()) {
                qDebug() << "Erreur SQL : " << query.lastError().text();
                return;
            }

            if (query.next()) {
                int id = query.value(0).toInt();
                qDebug() << "ID de l'architecte : " << id;


                QSqlQuery updateQuery(db);
                updateQuery.prepare("UPDATE ARCHITECTE SET ETAT_PRESENCE = 'P' WHERE id = :id");
                updateQuery.bindValue(":id", id);

                if (!updateQuery.exec()) {
                    qDebug() << "Erreur lors de la mise à jour de l'état de présence :" << updateQuery.lastError().text();
                } else {

                    qDebug() << "Présence mise à jour pour l'architecte avec ID :" << id;
                    emit presenceUpdated();
                }
            }
        }

        buffer = lignes.last();
    }
}




void Arduino::envoyerArchitectesSurArduino() {
    if (!serialPort || !serialPort->isOpen()) {
        qDebug() << "Port série non ouvert!";
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Base de données non ouverte dans Arduino.";
        return;
    }

    serialPort->write("CLEAR\n");

    serialPort->flush();
    QThread::msleep(200);

    QSqlQuery query(db);
    if (!query.exec("SELECT nom, PRÉNOM FROM ARCHITECTE WHERE ETAT_PRESENCE = 'A'")) {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return;
    }

    while (query.next()) {
        QString nom = query.value(0).toString();
        QString prenom = query.value(1).toString();
        QString ligne = nom + " " + prenom + "\n";

        serialPort->write(ligne.toUtf8());
        serialPort->flush();
        QThread::msleep(500);
        qDebug() << "Envoyé à l'Arduino : " << ligne;
    }
}
