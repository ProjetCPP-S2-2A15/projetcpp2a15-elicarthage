#ifndef SPEECHNOTIFIER_H
#define SPEECHNOTIFIER_H

#include <QObject>
#include <QTextToSpeech>

class SpeechNotifier : public QObject
{
    Q_OBJECT

public:
    explicit SpeechNotifier(QObject *parent = nullptr);
    ~SpeechNotifier();

    void notifyProjectAdded(const QString &projectName);
    void notifyProjectUpdated(const QString &projectName);
    void notifyProjectDeleted(const QString &projectName);

private:
    QTextToSpeech *m_speech;
};

#endif // SPEECHNOTIFIER_H
