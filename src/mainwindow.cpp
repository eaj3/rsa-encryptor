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
}
