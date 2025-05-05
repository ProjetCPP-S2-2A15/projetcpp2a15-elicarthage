#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QTcpSocket>
#include <QObject>

class ChatClient : public QObject
{
    Q_OBJECT
public:
    explicit ChatClient(QObject *parent = nullptr);
    void connectToServer(const QString &ip, quint16 port);
    void sendMessage(const QString &message);
    void disconnectFromHost();
    bool isConnected() const;

signals:
    void messageReceived(const QString &message);
    void connected();
    void disconnected();

private slots:
    void onReadyRead();
    void onConnected();
    void onDisconnected();

private:
    QTcpSocket *socket;
};

#endif // CHATCLIENT_H
