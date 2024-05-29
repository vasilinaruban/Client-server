#include "server.h"
#include <QDebug>
#include <QHostAddress>
#include <QDataStream>

Server::Server(QObject *parent) : QTcpServer(parent) {
    if (!this->listen(QHostAddress::Any, 12345)) {
        qDebug() << "Could not start server";
    } else {
        qDebug() << "Server started!";
        qDebug() << "Listening on address:" << serverAddress().toString() << "port:" << serverPort();
    }
}

void Server::incomingConnection(qintptr socketDescriptor) {
    QTcpSocket *clientSocket = new QTcpSocket(this);
    if (!clientSocket->setSocketDescriptor(socketDescriptor)) {
        qDebug() << "Error setting socket descriptor";
        return;
    }
    connect(clientSocket, &QTcpSocket::readyRead, this, &Server::readClient);
    connect(clientSocket, &QTcpSocket::disconnected, this, &Server::socketDisconnected);
    clients_[clientSocket] = socketDescriptor;
    qDebug() << "Client connected";
}

void Server::readClient() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_12);

    QString name;
    QString message;
    in >> name >> message;  // Читаем имя и сообщение

    qDebug() << "Received message from" << name << ":" << message;

    // Отправка сообщения всем подключенным клиентам
    for (QTcpSocket* client : clients_.keys()) {
        if (client->state() == QAbstractSocket::ConnectedState) {
            QByteArray block;
            QDataStream out(&block, QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_5_12);
            out << name << message;  // Отправляем имя и сообщение
            client->write(block);
        }
    }
    emit newMessage(message);
}

void Server::socketDisconnected() {
    QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
    if (!clientSocket) return;

    qintptr descriptor = clients_[clientSocket];
    clients_.remove(clientSocket);
    clientSocket->deleteLater();
    qDebug() << "Client disconnected";
}
