#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    timer(new QTimer),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //disable windows resizing
    this->setFixedSize(this->width(), this->height());

    //set lcdnumber colors
    ui->lcdNumberMin->setPalette(Qt::red);
    ui->lcdNumberSec->setPalette(Qt::yellow);

    timer->setInterval(1000);

    //connect signals and slots
    connect(timer, &QTimer::timeout, this, &MainWindow::increaseTime);
    connect(ui->startButton, &QPushButton::pressed, this, &MainWindow::startTimer);
    connect(ui->stopButton, &QPushButton::pressed, this, &MainWindow::stopTimer);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startTimer() {

    timer->start();
}

void MainWindow::stopTimer() {
    int remaining = timer->remainingTime();
    timer->stop();
    timer->setInterval(remaining);
}

void MainWindow::increaseTime() {
    if (ui->lcdNumberSec->intValue() +1 == 60) {
        ui->lcdNumberSec->display(0);
        ui->lcdNumberMin->display(ui->lcdNumberMin->intValue() +1);
    }

    else {
        ui->lcdNumberSec->display(ui->lcdNumberSec->intValue() +1);
    }

    if (timer->interval() != 1000) {
        timer->setInterval(1000);
    }
}
