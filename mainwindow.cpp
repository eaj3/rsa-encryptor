#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , keyGenerator(new RSAKeyGenerator(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete keyGenerator;
}

void MainWindow::on_btnGenerateKeys_clicked()
{
    QPair<quint32, quint32> keys = keyGenerator->generateKeys();

    qDebug() << "Generated 32bit primes:";
    qDebug() << "p1:" << keys.first;
    qDebug() << "p2:" << keys.second;
}
