#include "hamming.h"

// Пример реализации методов кодирования и декодирования
QString Hamming::encode(const QString &data) {
    // Простая заглушка для кодирования
    QString encoded = data.toUtf8().toHex();
    return encoded;
}

QString Hamming::decode(const QString &data) {
    // Простая заглушка для декодирования
    QByteArray decoded = QByteArray::fromHex(data.toUtf8());
    return QString::fromUtf8(decoded);
}
