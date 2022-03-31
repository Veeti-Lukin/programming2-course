#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QPushButton>
#include <QTextBrowser>
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

private slots:
    void handleClearButtonClick();
    void handleLetterButtonClick();
    void handleNumberButtonClick();

private:
    Ui::MainWindow *ui;

    // Space between elements, both horizontally and vertically
    const int MARGIN = 20;

    // Constants for push buttons
    const int NARROW_BUTTON_WIDTH = 20;
    const int DEFAULT_BUTTON_HEIGTH = 30;

    // Size of the text browser
    const int DISPLAY_WIDTH = 200;
    const int DISPLAY_HEIGTH = 30;

    // Location of the graphics view and scene
    const int VIEW_X = 20;
    const int VIEW_Y = 350;

    std::vector<QPushButton*> alphabets_;
    std::vector<QPushButton*> numbers_;

    QPushButton* clear_button_;
    QTextBrowser* text_browser_;
    QString written_text_ = "";

    // Handles both letter and number mouse clicks
    void handle_character_click(const std::vector<QPushButton*>& button_vec,
                                char starter);

    // Initialization methods for buttons and text browser
    // (set the locations of these widgets)
    void init_alphabets();
    void init_numbers();
    void init_text_browser();
    void init_clear_button();
};
#endif // MAINWINDOW_HH
