#include "gamewindow.h"
#include "ui_gamewindow.h"

gamewindow::gamewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gamewindow)
{
    ui->setupUi(this);
    background = new QMovie;
    background->setFileName(":/background/gif/bk.gif");
    ui->label->setMovie(background);
    background->start();
}

gamewindow::~gamewindow()
{
    delete ui;
}
