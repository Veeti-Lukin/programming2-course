#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Normally this member should be in private part of the
    // class, but due to the automated tests it must be more
    // accessible.
    QTimer* timer;

private slots:
    // Add your slots here

    // starts tht clock by setting interval to Qtimer object and strting the coruitine
    void startTimer();

    //stops the timer and changes next interval of the timer to remaining time to next interval
    void stopTimer();

    // resets the shown time values to 0 and interval back to 1000ms
    void resetTimer();

    //increases the time shown by one second
    void increaseTime();
private:
    Ui::MainWindow *ui;
    // Add other necessary members here
};

#endif // MAINWINDOW_HH
