#ifndef TEST_CLIENT_H
#define TEST_CLIENT_H

#include <QtTest/QtTest>
#include "client.h"

class TestClient : public QObject {
    Q_OBJECT

private slots:
    void testConnectToServer();
    void testSendMessage();
    void testReadMessage();
};

#endif // TEST_CLIENT_H
