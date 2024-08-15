#ifndef RSA_KEY_GENERATOR_H
#define RSA_KEY_GENERATOR_H

#include <QObject>
#include <QPair>

class RSAKeyGenerator : public QObject
{
    Q_OBJECT

public:
    explicit RSAKeyGenerator(QObject *parent = nullptr);
    QPair<quint32, quint32> generateKeys();

private:
    bool isPrime(quint32 number);
    quint32 generateLargePrime(quint32 exclude = 0);
};

#endif // RSA_KEY_GENERATOR_H
