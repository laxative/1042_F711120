#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    movesound(new QMediaPlayer),
    selectsound(new QMediaPlayer),
    selectIndex(0)
{
    ui->setupUi(this);
    connect(this,SIGNAL(playMoveSound()),this,SLOT(MoveS()));
    connect(this,SIGNAL(playselectSound()),this,SLOT(SelectS()));
    movesound->setMedia(QUrl("qrc:/sounds/media/hitside.wav"));
    selectsound->setMedia(QUrl("qrc:/sounds/media/hit.wav"));
}
MainWindow::~MainWindow()
{
    delete ui;
    delete movesound;
    delete selectsound;
}
void MainWindow::MoveS() {
    movesound->stop();
    movesound->play();
}

void MainWindow::SelectS(){
    selectsound->stop();
    selectsound->play();
}

void MainWindow::changeSelect() {
    emit playMoveSound();
    if(selectIndex==0)
        ui->finger->setGeometry(ui->finger->x(), 320 , 50, 70);
    else
        ui->finger->setGeometry(ui->finger->x(), 445 , 50, 70);
}
void MainWindow::select() {
    emit playselectSound();
    switch(selectIndex) {
    case 0:
        basicwindow = new basic;
        basicwindow->setWindowTitle("Basic");
        basicwindow->setGeometry(this->x(),this->y(),800,600);
        basicwindow->show();
        this->hide();
        break;
    case 2:
        this->close();
        break;
    default:
        break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_Up) {
        selectIndex-=2;
        if(selectIndex==-2)  selectIndex=2;
        changeSelect();
    } else if(k->key() == Qt::Key_Down) {
        selectIndex+=2;
        if(selectIndex==4)  selectIndex=0;
        changeSelect();
    } else if(k->key() == Qt::Key_Enter || k->key() == Qt::Key_Return) {
        select();
    }
}
