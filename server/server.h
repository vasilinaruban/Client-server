#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QMap>

class Server : public QTcpServer {
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

protected:
    void incomingConnection(qintptr socketDescriptor) override;
signals:
    void newMessage(const QString &message);


private slots:
    void readClient();
    void socketDisconnected();

private:
    QMap<QTcpSocket*, qintptr> clients_;
};

#endif // SERVER_H
