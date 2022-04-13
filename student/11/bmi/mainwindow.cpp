#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QString>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->closeButton, &QPushButton::pressed, this, &MainWindow::close);
    connect(ui->countButton, &QPushButton::pressed, this, &MainWindow::onCountPress);
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::calculate_bmi(float height, float weight)
{
    return (weight/((height/100 )* (height/100)));
}

void MainWindow::onCountPress()
{
    if (ui->heightLineEdit->text().toInt() == 0 || ui->heightLineEdit->text().isEmpty()) {
        ui->infoTextBrowser->setText("Cannot count");
        return;
    }

    double bmi = calculate_bmi(ui->heightLineEdit->text().toInt(),
                               ui->weightLineEdit->text().toInt());
    ui->resultLabel->setText(QString::number(bmi));

    if (bmi >= 25) {
        ui->infoTextBrowser->setText("You are overweight.");
    }

    if (bmi <= 18.5) {
        ui->infoTextBrowser->setText("You are underweight.");
    }

    else {
        ui->infoTextBrowser->setText("Your weight is normal.");
    }
}

