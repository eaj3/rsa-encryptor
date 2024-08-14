#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <rsa_key_generator.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGenerateKeys_clicked();

private:
    Ui::MainWindow *ui;
    RSAKeyGenerator *keyGenerator;
};
#endif // MAINWINDOW_H
