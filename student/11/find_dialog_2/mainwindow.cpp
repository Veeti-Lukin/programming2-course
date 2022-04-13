#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "utilities.hh"

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

