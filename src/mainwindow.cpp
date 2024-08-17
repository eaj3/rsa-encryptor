#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , keyGenerator(new RSAKeyGenerator(this))
{
    ui->setupUi(this);
    txtKeys = ui->txtKeys;
    btnEncrypt = ui->btnEncrypt;
    btnDecrypt = ui->btnDecrypt;
    txtInputEncrypt = ui->txtInputEncrypt;
    txtInputDecrypt = ui->txtInputDecrypt;
    txtOutputEncrypt = ui->txtOutputEncrypt;
    txtOutputDecrypt = ui->txtOutputDecrypt;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete keyGenerator;
}

void MainWindow::on_btnGenerateKeys_clicked()
{
    QPair<quint32, quint32> keys = keyGenerator->generateKeys();

    qDebug() << "Generated keys:";
    qDebug() << "p1:" << keys.first;
    qDebug() << "p2:" << keys.second;

    // Display the generated keys to txtKeys
    txtKeys->setHtml(
        QString("Random 32-bit primes:<br>"
                "p1: %1<br>"
                "p2: %2<br>"
                )
            .arg(keys.first)
            .arg(keys.second)
        );

    // Enable ui for encryption/decryption
    btnEncrypt->setEnabled(true);
    btnDecrypt->setEnabled(true);
    txtInputEncrypt->setEnabled(true);
    txtInputDecrypt->setEnabled(true);
    txtOutputEncrypt->setEnabled(true);
    txtOutputDecrypt->setEnabled(true);
}

void MainWindow::on_btnEncrypt_clicked()
{

}

