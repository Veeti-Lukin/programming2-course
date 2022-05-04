#include "mainwindow.hh"
#include "ui_mainwindow.h"

const int GRID_THICKNESS = 2;
const int GRID_SIDE = 50;

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

    // empty the visual gameboard
    if (scene != nullptr) {
        delete scene;
    }

    int visualGameboardSideLenght = ui->gamebooardGraphicsView->height();
    int numberTileSideLenght = (visualGameboardSideLenght-(gameboard_size-1 * GRID_THICKNESS))
            /gameboard_size;

    // setup new visual gameboard scene
    scene = new QGraphicsScene(this);
    ui->gamebooardGraphicsView->setScene(scene);
    scene->setSceneRect(0, 0, visualGameboardSideLenght, visualGameboardSideLenght);
}

void MainWindow::loadMenuPage()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);
}

