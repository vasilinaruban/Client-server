#pragma once

#include <QString>

class Hamming {
public:
    static QString encode(const QString &data);
    static QString decode(const QString &data);
};
