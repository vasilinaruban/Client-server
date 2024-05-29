// client.cpp
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
    socket_->connectToHost(getServerLineEdit(), getPortLineEdit());

    if (socket_->waitForConnected(3000)) {
        QMessageBox::information(this, "Connected", "Connected to server");
    } else {
        QMessageBox::critical(this, "Error", "Failed to connect to server");
    }
}

void Client::sendMessage() {
    QString name = getNameLineEdit();
    QString message = getMessageLineEdit();

    if (message.isEmpty()) {
        return;
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << name << message;

    socket_->write(block);

    ui->messageLineEdit->clear();
}

void Client::readMessage() {
    while (socket_->bytesAvailable() > 0) {
        QDataStream in(socket_);
        in.setVersion(QDataStream::Qt_5_12);

        QString name;
        QString message;
        in >> name >> message;

        appendChatText(name + ": " + message);
    }
}

void Client::setServerLineEdit(const QString &text) {
    ui->serverLineEdit->setText(text);
}

void Client::setPortLineEdit(int port) {
    ui->portLineEdit->setText(QString::number(port));
}

QString Client::getServerLineEdit() const {
    return ui->serverLineEdit->text();
}

int Client::getPortLineEdit() const {
    return ui->portLineEdit->text().toInt();
}

QString Client::getNameLineEdit() const {
    return ui->nameLineEdit->text();
}

QString Client::getMessageLineEdit() const {
    return ui->messageLineEdit->text();
}

void Client::appendChatText(const QString &text) {
    ui->chatTextEdit->append(text);
}

void Client::setNameLineEdit(const QString &text) {
    ui->nameLineEdit->setText(text);
}

void Client::setMessageLineEdit(const QString &text) {
    ui->messageLineEdit->setText(text);
}
QTcpSocket* Client::getSocket() const {
    return socket_;
}
