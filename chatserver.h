#ifndef CHATSERVER_H
#define CHATSERVER_H

#include <QTcpServer>
#include <QSet>

class ChatServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit ChatServer(QObject *parent = nullptr);
    void startServer(quint16 port);

signals:
    void newMessage(const QString &msg);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    QSet<QTcpSocket*> clients;
};

#endif // CHATSERVER_H
