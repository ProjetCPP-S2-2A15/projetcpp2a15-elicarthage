#include "smsmanager.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include "smsmanager.h"
#include <QUrlQuery>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QProcessEnvironment>

void SmsManager::sendSms(const QString& toPhone, const QString& message) {
    QNetworkAccessManager* manager = new QNetworkAccessManager();

    // Chargement sécurisé des identifiants Twilio depuis les variables d'environnement
    QString sid = qEnvironmentVariable("TWILIO_SID");
    QString token = qEnvironmentVariable("TWILIO_TOKEN");

    if (sid.isEmpty() || token.isEmpty()) {
        qDebug() << "Erreur : TWILIO_SID ou TWILIO_TOKEN non défini dans les variables d'environnement.";
        return;
    }

    // Construction de l'URL avec le SID
    QUrl url(QString("https://api.twilio.com/2010-04-01/Accounts/%1/Messages.json").arg(sid));
    QNetworkRequest request(url);

    // Authentification
    QString credentials = sid + ":" + token;
    QByteArray authHeader = "Basic " + credentials.toUtf8().toBase64();
    request.setRawHeader("Authorization", authHeader);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Paramètres de la requête
    QUrlQuery params;
    params.addQueryItem("To", toPhone);
    params.addQueryItem("From", "+12183876242");  // Ton numéro Twilio
    params.addQueryItem("Body", message);

    // Envoi de la requête POST
    QNetworkReply* reply = manager->post(request, params.toString(QUrl::FullyEncoded).toUtf8());

    // Gestion de la réponse
    QObject::connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "✅ SMS envoyé avec succès.";
        } else {
            qDebug() << "❌ Erreur d'envoi:" << reply->errorString();
        }
        reply->deleteLater();
    });
}
