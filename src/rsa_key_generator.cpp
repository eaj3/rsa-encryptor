#include "rsa_key_generator.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QDebug>

RSAKeyGenerator::RSAKeyGenerator(QObject *parent)
    : QObject(parent)
{
}

QPair<quint32, quint32> RSAKeyGenerator::generateKeys()
{
    quint32 p1 = generateLargePrime();
    quint32 p2 = generateLargePrime(p1);
    return qMakePair(p1, p2);
}

bool RSAKeyGenerator::isPrime(quint32 number)
{
    if (number <= 1) return false;
    if (number <= 3) return true;
    if (number % 2 == 0 || number % 3 == 0) return false;

    for (quint32 i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) return false;
    }
    return true;
}

// Dynamically generate a 32bit prime number
quint32 RSAKeyGenerator::generateLargePrime(quint32 exclude)
{
    quint32 prime;
    QRandomGenerator rng(QDateTime::currentMSecsSinceEpoch());

    quint32 min = 0x10000000; // minimum 32bit unsigned integer
    quint32 max = 0xFFFFFFFF;
    do {
        prime = rng.bounded(min, max);
    } while (!isPrime(prime) || prime == exclude);

    return prime;
}
