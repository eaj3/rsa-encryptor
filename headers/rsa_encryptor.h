#ifndef RSA_ENCRYPTOR_H
#define RSA_ENCRYPTOR_H

#include <QObject>

class RSAEncryptor : public QObject
{
    Q_OBJECT

public:
    explicit RSAEncryptor(QObject *parent = nullptr);

};

#endif // RSA_ENCRYPTOR_H
