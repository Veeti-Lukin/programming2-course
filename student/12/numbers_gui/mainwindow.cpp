#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "gameboard.hh"
#include <string>

const int GRID_THICKNESS = 2;
const int MAX_GAMEBOARD_SIZE = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameboardObject(GameBoard())
{
    ui->setupUi(this);

    // disable window scaling
    this->setFixedSize(this->width(), this->height());

    this->setWindowTitle("2048 Game");

    // add gameboard size choices to ui
    for (int i = 4; i <= MAX_GAMEBOARD_SIZE; i++){
        std::string stringForm = std::to_string(i) + "x" + std::to_string(i);
            ui->gameboardSizeComboBox->addItem(QString::fromStdString(stringForm),
                                               QVariant(i));
    }

   //connect slots and signals of menupage
    connect(ui->playButton, &QPushButton::pressed, this, &MainWindow::loadGamePage);

    //connect slots and signals of gamepage
     connect(ui->menuButton, &QPushButton::pressed, this, &MainWindow::loadMenuPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawGrid(int numberTileSideLenght, int visualGameboardSideLenght)
{
    QPen blackpen(Qt::black);
    blackpen.setWidth(GRID_THICKNESS);

    // draw a lines between every empty tile place on x and y axis
    for (int x = numberTileSideLenght; x < visualGameboardSideLenght; x += numberTileSideLenght+1) {
        scene->addLine(x,0, x, visualGameboardSideLenght, blackpen);
    }
    for (int y = numberTileSideLenght+1; y < visualGameboardSideLenght; y += numberTileSideLenght+1) {
        scene->addLine(0,y, visualGameboardSideLenght, y, blackpen);
    }
}

void MainWindow::loadGamePage()
{
    ui->stackedWidget->setCurrentWidget(ui->gamePage);
    gameboardSize = ui->gameboardSizeComboBox->currentData().toInt();

    // initialize/reset the actual gameboard object
    gameboardObject.setSize(gameboardSize);
    gameboardObject.init_empty();
    gameboardObject.fill(ui->seedSpinBox->value());

    // empty the visual gameboard
    if (scene != nullptr) {
        delete scene;
    }

    int visualGameboardSideLenght = ui->gamebooardGraphicsView->height();
    int numberTileSideLenght = (visualGameboardSideLenght-(gameboardSize-1 * GRID_THICKNESS))
            /gameboardSize;

    // setup new visual gameboard scene
    scene = new QGraphicsScene(this);
    ui->gamebooardGraphicsView->setScene(scene);
    scene->setSceneRect(0, 0, visualGameboardSideLenght, visualGameboardSideLenght);
    drawGrid(numberTileSideLenght, visualGameboardSideLenght);

    gameboardObject.print();
}

void MainWindow::loadMenuPage()
{
    ui->stackedWidget->setCurrentWidget(ui->menuPage);
}

