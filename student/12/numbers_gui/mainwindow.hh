#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>

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
    // seed that will be used to generate the game by random generator
    int randGenSeed = 0;
    // how many columns and rows the gameboard has
    int gameboard_size = 4;

private slots:
    void loadGamePage();
    void loadMenuPage();
};
#endif // MAINWINDOW_HH
