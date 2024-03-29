#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <fstream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //disable windows resizing
    this->setFixedSize(this->width(), this->height());

    //connect signals to slots
    connect(ui->closePushButton, &QPushButton::clicked, this, &MainWindow::close);
    connect(ui->findPushButton, &QPushButton::clicked, this, &MainWindow::onFindPress);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::read_file(const std::string &file_name, std::string &str_holder) {

    std::ifstream file_object(file_name);

    if (!file_object) {
        // file was not found
        return false;
    }
    std::stringstream str_stream;
    str_stream << file_object.rdbuf();//read the file

    str_holder = str_stream.str();
    return true;
}

bool MainWindow::find_substr(std::string str, std::string substr, bool match_case) {

    if (!match_case) {
        to_lower(str);
        to_lower(substr);
    }

    return str.find(substr) != std::string::npos;
}



void MainWindow::onFindPress() {

    if (!read_file(ui->fileLineEdit->text().toStdString(), file_as_str)) {
        ui->textBrowser->setText("File not found");
        return;
    }

    if (ui->keyLineEdit->text().toStdString().empty()){
        ui->textBrowser->setText("File found");
        return;
    }

    if (!find_substr(file_as_str, ui->keyLineEdit->text().toStdString(),
                    ui->matchCheckBox->isChecked())) {

        ui->textBrowser->setText("Word not found");
        return;
    }

    ui->textBrowser->setText("Word found");
}


void MainWindow::to_lower(std::string &str) {

    for (char &c: str) {
        c = tolower(c);
    }
}

