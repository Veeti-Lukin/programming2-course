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


    std::vector<QRect> visualNumberTiles;

    // draws the background grid for the visual gameboard
    // *numberTileSideLenght* and
    // *visualGameboardSideLenght* (QCraphicsview objects side lenght)
    //must be given
    void drawGrid(int numberTileSideLenght, int visualGameboardSideLenght);

private slots:
    void loadGamePage();
    void loadMenuPage();
};
#endif // MAINWINDOW_HH
