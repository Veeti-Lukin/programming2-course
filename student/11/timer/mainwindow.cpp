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

    //connect signals and slots
    connect(timer, &QTimer::timeout, this, &MainWindow::increaseTime);

    timer->setInterval(1000);
    timer->start();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::increaseTime() {
    if (ui->lcdNumberSec->intValue() +1 == 60) {
        ui->lcdNumberSec->display(0);
        ui->lcdNumberMin->display(ui->lcdNumberMin->intValue() +1);
    }

    else {
        ui->lcdNumberSec->display(ui->lcdNumberSec->intValue() +1);
    }
}
