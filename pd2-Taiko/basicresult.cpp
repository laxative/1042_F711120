#include "basicresult.h"
#include "ui_basicresult.h"
#include <QDebug>

basicresult::basicresult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::basicresult)
{
    ui->setupUi(this);
}

basicresult::~basicresult()
{
    delete ui;
}
void basicresult::scoreshow(int score) {
    this->show();
    ui->score->display((int)score);
}
