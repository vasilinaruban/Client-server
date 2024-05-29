#include <QApplication>
#include "client.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Client clientWindow;
    clientWindow.show();

    return app.exec();
}
