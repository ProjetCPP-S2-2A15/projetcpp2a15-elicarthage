#include "speechnotifier.h"
#include <QDebug>

SpeechNotifier::SpeechNotifier(QObject *parent)
    : QObject(parent)
{
    m_speech = new QTextToSpeech(this);
    m_speech->setLocale(QLocale(QLocale::French)); // Définir la locale en français
    m_speech->setRate(0.0); // Vitesse normale
    m_speech->setPitch(0.0); // Ton normal
    m_speech->setVolume(1.0); // Volume maximal
}

SpeechNotifier::~SpeechNotifier()
{
    delete m_speech;
}

void SpeechNotifier::notifyProjectAdded(const QString &projectName)
{
    QString message = tr("Projet %1 ajouté").arg(projectName);
    m_speech->say(message);
    qDebug() << "Notification vocale:" << message;
}

void SpeechNotifier::notifyProjectUpdated(const QString &projectName)
{
    QString message = tr("Projet %1 modifié").arg(projectName);
    m_speech->say(message);
    qDebug() << "Notification vocale:" << message;
}

void SpeechNotifier::notifyProjectDeleted(const QString &projectName)
{
    QString message = tr("Projet %1 supprimé").arg(projectName);
    m_speech->say(message);
    qDebug() << "Notification vocale:" << message;
}
