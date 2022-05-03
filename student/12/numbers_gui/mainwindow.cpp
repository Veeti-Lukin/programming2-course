#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // disable window scaling
    this->setFixedSize(this->width(), this->height());

    this->setWindowTitle("2048 Game");
}

MainWindow::~MainWindow()
{
    delete ui;
}

