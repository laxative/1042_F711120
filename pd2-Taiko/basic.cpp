#include "basic.h"
#include "ui_basic.h"
#include "result.h"
#include <QString>

basic::basic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::basic),
    hitsound(new QMediaPlayer),
    hitsidesound(new QMediaPlayer),
    bgm(new QMediaPlayer),
    timer(new QTimer),
    T(0),
    score(0)
{
    ui->setupUi(this);
    srand(time(NULL));
    //set hit sound
    connect(this,SIGNAL(playhitsound()),this,SLOT(HitS()));
    connect(this,SIGNAL(playhitsidesound()),this,SLOT(HitSideS()));
    hitsound->setMedia(QUrl("qrc:/sounds/media/hit.wav"));
    hitsidesound->setMedia(QUrl("qrc:/sounds/media/hitside.wav"));
    bgm->setMedia(QUrl("qrc:/bgm/media/basicbgm.wav"));
    //set graphicsscene, graphicsview
    scene = new QGraphicsScene(20,100,640,150);
    view = new QGraphicsView(ui->boardview);
    view->setScene(scene);
    //lcdnumber
    ui->score->display((int)score);
    //timer
    newgame();
    connect(this->timer,SIGNAL(timeout()),this,SLOT(timego()));
}

basic::~basic()
{
    delete ui;
    delete hitsound;
    delete hitsidesound;
    delete scene;
    delete view;
}

void basic::HitS() {
    hitsound->stop();
    hitsound->play();
}
void basic::HitSideS() {
    hitsidesound->stop();
    hitsidesound->play();
}
void basic::newgame() {
    v.clear();
    additem();
    view->show();
    score = 0;
    T = 0;
    bgm->play();
    ui->A->hide();
    ui->S->hide();
    ui->D->hide();
    ui->F->hide();
    ui->excellent->hide();
    ui->good->hide();
    ui->bad->hide();
    timer->start(3);
    ui->score->display(score);
}
void basic::additem() {
    for(int i=0;i<120;++i) {
        item = new Item(i*550+6000,rand()%4);
        v.push_back(item);
    }
    it = v.begin();
    now = v.begin();
}

void basic::destoryed() {
    if(now!=v.end()) now++;
}

void basic::timego() {
    T += 3;//(plus 0.003s per time)
    if(T<=36000) { //(30 secs) 6sec for prepare
        QString s;
        s.sprintf("%.2f",(float)(36000-T)/1000);
        ui->time->display(s); //show time
        if(it!=v.end()) {
            if((*it)->gettime() <= T) {
                scene->addItem(*it);
                connect(timer,SIGNAL(timeout()),*it,SLOT(itemMove()));
                connect(*it,SIGNAL(item_des()),this,SLOT(destoryed()));
                it++;
            }
        }
    } else{
        result *res = new result;
        timer->stop();
        bgm->stop();
        scene->clear();
        res->setGeometry(this->x()+200,this->y()+150,400,300);
        res->scoreshow(score);
        connect(res,SIGNAL(accepted()),this,SLOT(newgame()));
        connect(res,SIGNAL(rejected()),this,SLOT(close()));
    }
}
void basic::getPoint(int Pos) {
    int dist = abs(Pos-20);
    if(dist < 10) {
        score += 50 * dist;
        ui->excellent->show();
        ui->good->hide();
        ui->bad->hide();
    }else if(dist < 20) {
        score += 30 * dist;
        ui->excellent->hide();
        ui->good->show();
        ui->bad->hide();
    }else{
        ui->excellent->hide();
        ui->good->hide();
        ui->bad->show();
    }
    ui->score->display((int)score);
}
void basic::keyPressEvent(QKeyEvent *k)
{
    if(k->key()==Qt::Key_S || k->key()==Qt::Key_D) {
        if(k->key()==Qt::Key_S) {
            ui->S->show();
            ui->A->hide();
            ui->D->hide();
            ui->F->hide();
        }
        else {
            ui->D->show();
            ui->A->hide();
            ui->S->hide();
            ui->F->hide();
        }
        emit playhitsound();
        if((*now)->gettype() == 0 || (*now)->gettype() == 2) {
            getPoint((*now)->x());
            delete *now;
            now++;
        } else {
            ui->excellent->hide();
            ui->good->hide();
            ui->bad->show();
        }
    } else if(k->key()==Qt::Key_A || k->key()==Qt::Key_F) {
        if(k->key()==Qt::Key_A) {
            ui->A->show();
            ui->S->hide();
            ui->D->hide();
            ui->F->hide();
        }
        else {
            ui->F->show();
            ui->A->hide();
            ui->S->hide();
            ui->D->hide();
        }
        emit playhitsidesound();
        if((*now)->gettype() == 1 || (*now)->gettype() == 3) {
            getPoint((*now)->x());
            delete *now;
            now++;
        } else {
            ui->excellent->hide();
            ui->good->hide();
            ui->bad->show();
        }
    }
}

