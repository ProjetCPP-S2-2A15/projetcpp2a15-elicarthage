#include "chatserver.h"
#include <QTcpSocket>
#include <QDebug>

ChatServer::ChatServer(QObject *parent) : QTcpServer(parent) {}

void ChatServer::startServer(quint16 port)
{
    if(!this->listen(QHostAddress::Any, port)) {
        qDebug() << "Server could not start!";
    } else {
        qDebug() << "Server started on port" << port;
    }
}

void ChatServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket *socket = new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);
    clients.insert(socket);

    connect(socket, &QTcpSocket::readyRead, this, &ChatServer::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &ChatServer::onDisconnected);

    qDebug() << "New client connected";
}

void ChatServer::onReadyRead()
{
    QTcpSocket *sender = qobject_cast<QTcpSocket*>(QObject::sender());
    if (!sender) return;

    QString message = QString::fromUtf8(sender->readAll());
    emit newMessage(message);

    // Broadcast to all clients
    for (QTcpSocket *client : qAsConst(clients)) {
        client->write(message.toUtf8());
    }
}

void ChatServer::onDisconnected()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(QObject::sender());
    if (!socket) return;

    clients.remove(socket);
    socket->deleteLater();

    qDebug() << "Client disconnected";
}
