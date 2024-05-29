#include "client.h"
#include "ui_client.h"
#include <QDataStream>
#include <QMessageBox>

Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
    , socket_(new QTcpSocket(this)) {
    ui->setupUi(this);

    connect(ui->connectButton, &QPushButton::clicked, this, &Client::connectToServer);
    connect(ui->sendButton, &QPushButton::clicked, this, &Client::sendMessage);
    connect(ui->messageLineEdit, &QLineEdit::returnPressed, this, &Client::sendMessage);
    connect(socket_, &QTcpSocket::readyRead, this, &Client::readMessage);
}

Client::~Client() {
    delete ui;
}

void Client::connectToServer() {
    socket_->connectToHost(ui->serverLineEdit->text(), ui->portLineEdit->text().toInt());

    if (socket_->waitForConnected(3000)) {
        QMessageBox::information(this, "Connected", "Connected to server");
    } else {
        QMessageBox::critical(this, "Error", "Failed to connect to server");
    }
}

void Client::sendMessage() {
    QString name = ui->nameLineEdit->text();  // Получаем имя пользователя
    QString message = ui->messageLineEdit->text();

    if (message.isEmpty()) {
        return;  // Не отправляем пустое сообщение
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << name << message;  // Отправляем имя и сообщение

    socket_->write(block);

    ui->messageLineEdit->clear();  // Очищаем поле ввода сообщения после отправки
}

void Client::readMessage() {
    while (socket_->bytesAvailable() > 0) {
        QDataStream in(socket_);
        in.setVersion(QDataStream::Qt_5_12);

        QString name;
        QString message;
        in >> name >> message;  // Читаем имя и сообщение

        ui->chatTextEdit->append(name + ": " + message);
    }
}
