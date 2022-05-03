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

   //connect slots and signals of menupage
    connect(ui->playButton, &QPushButton::pressed, this, &MainWindow::loadGamePage);

    //connect slots and signals of gamepage
     connect(ui->menuButton, &QPushButton::pressed, this, &MainWindow::loadMenuPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadGamePage()
{
    ui->stackedWidget->setCurrentWidget(ui->gamePage);
}

void MainWindow::loadMenuPage()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);
}

