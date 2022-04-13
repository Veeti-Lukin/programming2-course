#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //disable windows resizing
    this->setFixedSize(this->width(), this->height());

    //connect singals to slots
    connect(ui->countPushButton, &QPushButton::pressed, this, &MainWindow::onCountPress);
    connect(ui->spinBoxN, qOverload<int>(&QSpinBox::valueChanged), this, &MainWindow::onCountPress);
    connect(ui->spinBoxG, qOverload<int>(&QSpinBox::valueChanged), this, &MainWindow::onCountPress);
    connect(ui->spinBoxP, qOverload<int>(&QSpinBox::valueChanged), this, &MainWindow::onCountPress);
    connect(ui->spinBoxE, qOverload<int>(&QSpinBox::valueChanged), this, &MainWindow::onCountPress);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCountPress() {
    unsigned int total_score = count_final_grade(ui->spinBoxN->value(),
                                                 ui->spinBoxG->value(),
                                                 ui->spinBoxP->value(),
                                                 ui->spinBoxE->value());
    ui->textBrowser->setText("Total grade:" + QString::number(total_score));
}

