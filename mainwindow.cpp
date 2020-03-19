#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->val = 135;
    ui->lcdNumber->display(this->val);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_downButton_clicked()
{
    ui->lcdNumber->display(--this->val);
}

void MainWindow::on_upButton_clicked()
{
    ui->lcdNumber->display(++this->val);
}
