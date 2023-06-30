#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::handleTimer);

    ui->stopButton->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    int seconds = ui->numSeconds->value();

    if (seconds <= 0)
    {
        QMessageBox::warning(this, "Помилка", "Кількість секунд має бути більше 0!");
        return;
    }

    ui->stopButton->setEnabled(true);

    int interval = seconds * 1000;
    timer->start(interval);
}

void MainWindow::on_stopButton_clicked()
{
    timer->stop();
    ui->stopButton->setEnabled(false);
    QMessageBox::information(this, "Таймер", "Таймер не встиг спрацювати!");
}

void MainWindow::handleTimer()
{
    timer->stop();
    ui->stopButton->setEnabled(false);
    QMessageBox::information(this, "Таймер", "Таймер спрацював!");
}
