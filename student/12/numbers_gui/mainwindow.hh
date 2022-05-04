#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "gameboard.hh"
#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    // a scene that the visual gameboard will be drawn on to;
    QGraphicsScene* scene = nullptr;
    // goal number wich indicates game won if merged to
    int goalNumber = 2048;
    // how many columns and rows the gameboard has
    int gameboardSize = 5;
    // actual backend gameboard object
    GameBoard gameboardObject;

    // lenght of one side of the QGraphicsview object on ui where
    // the visual gameborad will be drawn on to
    int visualGameboardSideLenght;

    // lenght of one side of the visual numbertiles that will be drwn to the ui
    int numberTileSideLenght;

    std::vector<QRect> visualNumberTiles;

    // draws the background grid for the visual gameboard
    // *numberTileSideLenght* and
    // *visualGameboardSideLenght* (QCraphicsview objects side lenght)
    //must be given
    void drawGrid();

    void drawNumberTiles();

private slots:
    void loadGamePage();
    void loadMenuPage();
};
#endif // MAINWINDOW_HH
