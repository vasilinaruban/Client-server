#pragma once

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow {
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void connectToServer();
    void sendMessage();
    void readMessage();

private:
    Ui::Client *ui;
    QTcpSocket *socket_;
};
