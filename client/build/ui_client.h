/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *serverLineEdit;
    QLineEdit *portLineEdit;
    QLineEdit *nameLineEdit;
    QPushButton *connectButton;
    QTextEdit *chatTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QString::fromUtf8("Client"));
        Client->resize(609, 469);
        Client->setStyleSheet(QString::fromUtf8("background-color: black;"));
        centralwidget = new QWidget(Client);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        serverLineEdit = new QLineEdit(centralwidget);
        serverLineEdit->setObjectName(QString::fromUtf8("serverLineEdit"));
        serverLineEdit->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));

        horizontalLayout->addWidget(serverLineEdit);

        portLineEdit = new QLineEdit(centralwidget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));
        portLineEdit->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));

        horizontalLayout->addWidget(portLineEdit);

        nameLineEdit = new QLineEdit(centralwidget);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));

        horizontalLayout->addWidget(nameLineEdit);

        connectButton = new QPushButton(centralwidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setStyleSheet(QString::fromUtf8("background-color: green; color: black;"));

        horizontalLayout->addWidget(connectButton);


        verticalLayout->addLayout(horizontalLayout);

        chatTextEdit = new QTextEdit(centralwidget);
        chatTextEdit->setObjectName(QString::fromUtf8("chatTextEdit"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        chatTextEdit->setFont(font);
        chatTextEdit->setStyleSheet(QString::fromUtf8("background-color: pink; color: white;"));
        chatTextEdit->setReadOnly(true);

        verticalLayout->addWidget(chatTextEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        messageLineEdit = new QLineEdit(centralwidget);
        messageLineEdit->setObjectName(QString::fromUtf8("messageLineEdit"));
        messageLineEdit->setStyleSheet(QString::fromUtf8("background-color: white; color: black;"));

        horizontalLayout_2->addWidget(messageLineEdit);

        sendButton = new QPushButton(centralwidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setStyleSheet(QString::fromUtf8("background-color: blue; color: black;"));

        horizontalLayout_2->addWidget(sendButton);


        verticalLayout->addLayout(horizontalLayout_2);

        Client->setCentralWidget(centralwidget);

        retranslateUi(Client);

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QCoreApplication::translate("Client", "Chat Client", nullptr));
        serverLineEdit->setInputMask(QString());
        serverLineEdit->setPlaceholderText(QCoreApplication::translate("Client", "IP", nullptr));
        portLineEdit->setPlaceholderText(QCoreApplication::translate("Client", "Port", nullptr));
        nameLineEdit->setPlaceholderText(QCoreApplication::translate("Client", "Name", nullptr));
        connectButton->setText(QCoreApplication::translate("Client", "Connect", nullptr));
        messageLineEdit->setPlaceholderText(QCoreApplication::translate("Client", "Type your message here...", nullptr));
        sendButton->setText(QCoreApplication::translate("Client", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
