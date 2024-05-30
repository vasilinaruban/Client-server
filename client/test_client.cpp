// test_client.cpp
#include <QtTest>
#include "client.h"
#include "ui_client.h"

class TestClient : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void cleanupTestCase();
    void testConnectToServer();
    void testSendMessage();
    void testReadMessage();

private:
    Client *client;
};

void TestClient::initTestCase()
{
    client = new Client();
}

void TestClient::cleanupTestCase()
{
    delete client;
}

void TestClient::testConnectToServer()
{
    client->setServerLineEdit("0.0.0.0");
    client->setPortLineEdit(12345);

    QSignalSpy spy(client->getSocket(), &QTcpSocket::connected);
    client->connectToServer();

    QVERIFY(spy.wait(3100)); // ожидание подключения в течение 3100 мс
    QCOMPARE(spy.count(), 1);
}

void TestClient::testSendMessage()
{
    client->setNameLineEdit("TestUser");
    client->setMessageLineEdit("Hello, World!");

    QSignalSpy spy(client->getSocket(), &QTcpSocket::bytesWritten);
    client->sendMessage();

    QVERIFY(spy.wait(1000)); // ожидание отправки сообщения в течение 1000 мс
    QCOMPARE(spy.count(), 1);
}

void TestClient::testReadMessage()
{
    QSignalSpy spy(client->getSocket(), &QTcpSocket::readyRead);
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_12);
    out << QString("ServerUser") << QString("Hello, Client!");

    client->getSocket()->write(data);
    QVERIFY(spy.wait(1000)); // ожидание чтения сообщения в течение 1000 мс

    client->readMessage();
    // Дополнительная проверка содержания чата после получения сообщения
    // Проверка может быть адаптирована в зависимости от того, как именно
    // вы реализуете обновление интерфейса
//    QVERIFY(client.appendChatText().contains("ServerUser: Hello, Client!"));
}

QTEST_MAIN(TestClient)
#include "test_client.moc"
