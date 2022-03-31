#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QPoint>
#include <QCursor>
#include <QGraphicsView>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init_alphabets();
    init_numbers();
    init_text_browser();
    init_clear_button();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleClearButtonClick()
{
    written_text_ = "";
    text_browser_->setText(written_text_);
}

void MainWindow::handleLetterButtonClick()
{
    handle_character_click(alphabets_, 'a');
}

void MainWindow::handleNumberButtonClick()
{
    handle_character_click(numbers_, '0');
}

// To avoid repetitive code, this method implements a general handling
// for both letter and number push button clicks.
void MainWindow::handle_character_click(
        const std::vector<QPushButton *>& button_vec,
        char starter)
{
    // Storing global cursor position
    QPoint global_click_position = QCursor::pos();

    // Counting local cursor position, i.e. decreasing
    // Main Window's location from the global one
    int local_x = global_click_position.x() - geometry().x();
    int local_y = global_click_position.y() - geometry().y();
    QPoint local_click_position = QPoint(local_x, local_y);

    // Searching for the button clicked
    for(unsigned int i = 0; i < button_vec.size(); ++i)
    {
        if(button_vec.at(i)->geometry().contains(local_click_position))
        {
            char c = starter + i;
            written_text_ += c;
            text_browser_->setText(written_text_);
            return; // For efficiency reasons
                    // (only one button can be clicked at a time)
        }
    }
}

void MainWindow::init_alphabets()
{
    // Horizontal layout for letter buttons
    QWidget* central = new QWidget(this);
    QHBoxLayout* hLayout = new QHBoxLayout(central);

    // Setting letter buttons in the horizontal layout and connecting all of
    // them to the same slot (no coordinates needed)
    for(char c = 'A'; c <= 'Z'; ++c)
    {
        QString letter = "";
        letter += c;
        QPushButton* pushButton = new QPushButton(letter, this);
        pushButton->setFixedWidth(NARROW_BUTTON_WIDTH);
        alphabets_.push_back(pushButton);
        hLayout->addWidget(pushButton);

        connect(pushButton, &QPushButton::clicked,
                this, &MainWindow::handleLetterButtonClick);
    }

    setCentralWidget(central);
}

void MainWindow::init_numbers()
{
    // Setting a graphics view to put number buttons inside them.
    // However, number buttons could be put directly on Main Window
    // (you can try what happens if you remove the lines before for loop).
    QGraphicsView* view_ = new QGraphicsView(this);
    view_->setGeometry(VIEW_X,
                       VIEW_Y,
                       MARGIN + 10 * (NARROW_BUTTON_WIDTH + MARGIN),
                       MARGIN + DEFAULT_BUTTON_HEIGTH + MARGIN);

    // Setting number buttons in a horizontal line and connecting all of them
    // to the same slot (specific coordinates required)
    for(char c = '0', i = 0; c <= '9'; ++c, ++i)
    {
        QString number = "";
        number += c;
        QPushButton* pushButton = new QPushButton(number, this);
        pushButton->setGeometry(2 * MARGIN + i * (NARROW_BUTTON_WIDTH + MARGIN),
                                MARGIN + VIEW_Y,
                                NARROW_BUTTON_WIDTH,
                                DEFAULT_BUTTON_HEIGTH);
        numbers_.push_back(pushButton);

        connect(pushButton, &QPushButton::clicked,
                this, &MainWindow::handleNumberButtonClick);
    }
}

void MainWindow::init_text_browser()
{
    text_browser_ = new QTextBrowser(this);
    text_browser_->setGeometry(MARGIN, MARGIN, DISPLAY_WIDTH, DISPLAY_HEIGTH);
}

void MainWindow::init_clear_button()
{
    clear_button_ = new QPushButton(this);
    clear_button_->setText("Clear");
    int width = clear_button_->width(); // We don't want to change width
    clear_button_->setGeometry(MARGIN,
                               MARGIN + DISPLAY_HEIGTH + MARGIN,
                               width,
                               DEFAULT_BUTTON_HEIGTH);

    connect(clear_button_, SIGNAL(clicked()),
            this, SLOT(handleClearButtonClick()));
}
