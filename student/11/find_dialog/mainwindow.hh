#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void onFindPress();

private:
    Ui::MainWindow *ui;

    // used for holding the the file in string format after reading the file
    std::string file_as_str = "";
};
#endif // MAINWINDOW_HH
