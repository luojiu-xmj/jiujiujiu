#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->easy,&QPushButton::released,this,&MainWindow::changewin);
    connect(&d,&dishu::mySignal,this,&MainWindow::dealsub);
    connect(this->ui->difficult,&QPushButton::released,this,&MainWindow::changewina);
    connect(&di,&dishua::mySignal,this,&MainWindow::dealsuba);
    connect(this->ui->devil,&QPushButton::released,this,&MainWindow::changewinb);
    connect(&dis,&dishub::mySignal,this,&MainWindow::dealsubb);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changewin()
{
    d.show();
    this->hide();
}
void MainWindow::dealsub()
{
    d.hide();

    this->show();
}

void MainWindow::changewina()
{
    di.show();
    this->hide();
}
void MainWindow::dealsuba()
{
    di.hide();
    this->show();
}

void MainWindow::changewinb()
{
    dis.show();
    this->hide();
}
void MainWindow::dealsubb()
{
    dis.hide();

    this->show();
}





