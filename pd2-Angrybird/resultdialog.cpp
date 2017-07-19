#include "resultdialog.h"
#include "ui_resultdialog.h"

resultdialog::resultdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultdialog)
{
    ui->setupUi(this);
}

resultdialog::~resultdialog()
{
    delete ui;
}
void resultdialog::scoreshow(float score) {
    ui->lcdNumber->display((float)score);
}
void resultdialog::winlose(bool win) {
    if(win) {
        ui->winlose->setText("You win!!");
    }else{
        ui->winlose->setText("You lose~~");
    }
}
