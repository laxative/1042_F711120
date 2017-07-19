#include "result.h"
#include "ui_result.h"

result::result(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::result)
{
    ui->setupUi(this);
}

result::~result()
{
    delete ui;
}
void result::scoreshow(int score) {
    this->show();
    ui->score->display((int)score);
}
