#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>
#include <QSqlDatabase>
#include <QSqlQuery>

class Arduino : public QObject
{
    Q_OBJECT

public:
    explicit Arduino(QObject *parent = nullptr);
    ~Arduino();

    void initSerial();
    void envoyerArchitectesSurArduino();
    void lireNomDepuisArduino();


private:
    QSerialPort *serialPort;

signals:
    void presenceUpdated();
};

#endif // ARDUINO_H
