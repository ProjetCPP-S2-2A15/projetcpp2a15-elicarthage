#include "emailnotifier.h"

#include "SmtpClient.h"
#include "MimeMessage.h"
#include "MimeText.h"
#include "EmailAddress.h"
#include <QDebug>

void EmailNotifier::envoyerAlerte(const QString& destinataire, const QString& contenu)
{
    // 1. Création du message
    MimeMessage message;

    EmailAddress sender("moetez.benattia02@gmail.com", "Système Ressource");
    EmailAddress recipient(destinataire, "architectes");

    message.setSender(sender);
    message.addRecipient(recipient);
    message.setSubject(" Alerte sur une ressource");

    MimeText* text = new MimeText();
    text->setText(contenu);
    message.addPart(text);

    // 2. Configuration du client SMTP
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);

    // 3. Connexion et authentification
    smtp.connectToHost();

    // Authentification avec email et mot de passe d'application
    smtp.login("moetez.benattia02@gmail.com", "fbvw zesb jdki ojkv");

    // 4. Envoi
    // Envoi
    smtp.sendMail(message); // ne retourne rien

    qDebug() << " Mail envoyé à :" << destinataire;


    smtp.quit();
}
