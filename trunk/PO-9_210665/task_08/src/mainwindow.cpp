#include "mainwindow.h" //210665
#include "./ui_mainwindow.h" //210665
#include "customwidget.h"
MainWindow::MainWindow(QWidget *parent) //210665
    : QMainWindow(parent) //210665
    , ui(new Ui::MainWindow) //210665
{
    ui->setupUi(this); //210665
    ui->groupBox->setLayout(new QVBoxLayout(this));//
    ui->groupBox->layout()->addWidget(new CustomWidget(this));//
}
MainWindow::~MainWindow() //210665
{ //210665
    delete ui; //210665
} //210665
