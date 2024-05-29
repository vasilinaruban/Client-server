// client.h
#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

    QString getServerLineEdit() const;
    int getPortLineEdit() const;
    QString getNameLineEdit() const;
    QString getMessageLineEdit() const;
    void appendChatText(const QString& text);
    void setServerLineEdit(const QString &text);
    void setPortLineEdit(int port);
    void setNameLineEdit(const QString &text); // Добавлено объявление метода
    void setMessageLineEdit(const QString &text); // Добавлено объявление метода
    void setSendButton();
    QTcpSocket* getSocket() const;

public slots:
    void connectToServer();
    void sendMessage();
    void readMessage();

private:
    Ui::Client *ui;
    QTcpSocket *socket_;
};

#endif // CLIENT_H
