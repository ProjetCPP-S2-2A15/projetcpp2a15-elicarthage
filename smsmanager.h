#ifndef SMSMANAGER_H
#define SMSMANAGER_H

#include <QString>

class SmsManager {
public:
    // Méthode pour envoyer un SMS
    void sendSms(const QString& toPhone, const QString& message);
};

#endif // SMSMANAGER_H
