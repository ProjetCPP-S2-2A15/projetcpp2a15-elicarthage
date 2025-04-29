#include "chatclient.h"
#include <QDebug>

ChatClient::ChatClient(QObject *parent) : QObject(parent), socket(new QTcpSocket(this))
{
    connect(socket, &QTcpSocket::readyRead, this, &ChatClient::onReadyRead);
    connect(socket, &QTcpSocket::connected, this, &ChatClient::connected);
    connect(socket, &QTcpSocket::disconnected, this, &ChatClient::disconnected);
}

void ChatClient::connectToServer(const QString &ip, quint16 port)
{
    socket->connectToHost(ip, port);
}

void ChatClient::sendMessage(const QString &message)
{
    if (socket->state() == QTcpSocket::ConnectedState) {
        socket->write(message.toUtf8());
    }
}

void ChatClient::disconnectFromHost()
{
    socket->disconnectFromHost();
}

bool ChatClient::isConnected() const
{
    return socket->state() == QTcpSocket::ConnectedState;
}

void ChatClient::onReadyRead()
{
    const QString message = QString::fromUtf8(socket->readAll());
    emit messageReceived(message);
}

void ChatClient::onConnected()
{
    emit connected();
}

void ChatClient::onDisconnected()
{
    emit disconnected();
}
