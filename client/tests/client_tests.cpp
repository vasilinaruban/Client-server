#include <QtTest/QtTest>
#include "../client.h"

class ClientTest : public QObject {
    Q_OBJECT

private slots:
    void testConnection();
    void testSendMessage();
};

void ClientTest::testConnection() {
    // Пример теста для подключения к серверу
    Client client;
    client.connectToServer();
    // Добавьте проверки для проверки ожидаемого поведения
}

void ClientTest::testSendMessage() {
    // Пример теста для отправки сообщения
    Client client;
    client.sendMessage();
    // Добавьте проверки для проверки ожидаемого поведения
}

QTEST_MAIN(ClientTest)
#include "client_tests.moc"
