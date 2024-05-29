#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Server server;
    QObject::connect(&server, &Server::newMessage, [](const QString &message){
        qDebug() << "Received message:" << message;
    });

    return a.exec();
}
