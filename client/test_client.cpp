#include "test_client.h"
#include <QTcpServer>
#include <QSignalSpy>

void TestClient::testConnectToServer() {
    QTcpServer server;
    QVERIFY(server.listen(QHostAddress::Any, 12345));

    Client client;
    client.show();
    client.ui->serverLineEdit->setText("127.0.0.1");
    client.ui->portLineEdit->setText("12345");

    QSignalSpy spyConnected(client.socket_, &QTcpSocket::connected);
    QSignalSpy spyError(client.socket_, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error));

    QTest::mouseClick(client.ui->connectButton, Qt::LeftButton);

    QVERIFY(spyConnected.wait());
    QCOMPARE(spyError.count(), 0);

    server.close();
}

void TestClient::testSendMessage() {
    QTcpServer server;
    QVERIFY(server.listen(QHostAddress::Any, 12345));

    Client client;
    client.show();
    client.ui->serverLineEdit->setText("127.0.0.1");
    client.ui->portLineEdit->setText("12345");

    client.connectToServer();
    QVERIFY(client.socket_->waitForConnected(3000));

    QTcpSocket *serverSocket = server.nextPendingConnection();
    QVERIFY(serverSocket->waitForReadyRead(3000));

    client.ui->nameLineEdit->setText("TestUser");
    client.ui->messageLineEdit->setText("Hello, World!");

    QSignalSpy spyWrite(client.socket_, &QTcpSocket::bytesWritten);
    QTest::mouseClick(client.ui->sendButton, Qt::LeftButton);

    QVERIFY(spyWrite.wait());
    QVERIFY(serverSocket->waitForReadyRead(3000));

    QByteArray block = serverSocket->readAll();
    QDataStream in(&block, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_5_12);
    QString name, message;
    in >> name >> message;

    QCOMPARE(name, QString("TestUser"));
    QCOMPARE(message, QString("Hello, World!"));

    serverSocket->disconnectFromHost();
    server.close();
}

void TestClient::testReadMessage() {
    QTcpServer server;
    QVERIFY(server.listen(QHostAddress::Any, 12345));

    Client client;
    client.show();
    client.ui->serverLineEdit->setText("127.0.0.1");
    client.ui->portLineEdit->setText("12345");

    client.connectToServer();
    QVERIFY(client.socket_->waitForConnected(3000));

    QTcpSocket *serverSocket = server.nextPendingConnection();
    QVERIFY(serverSocket->waitForReadyRead(3000));

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << QString("ServerUser") << QString("Hello from server!");

    QSignalSpy spyRead(client.socket_, &QTcpSocket::readyRead);
    serverSocket->write(block);
    serverSocket->flush();

    QVERIFY(spyRead.wait());

    QCOMPARE(client.ui->chatTextEdit->toPlainText(), QString("ServerUser: Hello from server!"));

    serverSocket->disconnectFromHost();
    server.close();
}

QTEST_MAIN(TestClient)
#include "test_client.moc"
