#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resultdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isClick = false;
    qApp->installEventFilter(this); //for event filter
    score = 0;
    birdsound = new QSound(":/sound/sound/bird.wav");
    death = new QSound(":/sound/sound/death.wav");
    breaksound = new QSound(":/sound/sound/glass.wav");
    clicksound = new QSound(":sound/sound/click.wav");
    win = new QSound(":/sound/sound/win.wav");
    lose = new QSound(":sound/sound/lose.wav");
}

void MainWindow::showEvent(QShowEvent *) {
    //set graphicsScene
    scene = new QGraphicsScene(0,0,ui->graphicsView->width()
                               ,ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    //set world
    contact = new contactListener;
    world = new b2World(b2Vec2(0.0f, -9.8f));
    Item::setGlobalSize(QSizeF(50,30),this->size());
    transPoint::setGlobalSize(QSizeF(50,30),this->size());
    world->SetContactListener(contact);

    //for arrow
    arrow = new QGraphicsPixmapItem;
    arrow->setPixmap(QPixmap(":/thing/image/arrow.png").scaled(
                         200,150,Qt::IgnoreAspectRatio,
                         Qt::SmoothTransformation));
    arrow->setTransformOriginPoint(
                arrow->pixmap().width()/2, arrow->pixmap().height()/2);
    arrow->setVisible(false);
    scene->addItem(arrow);

    //create bow
    QGraphicsPixmapItem *bow = new QGraphicsPixmapItem;
    bow->setPixmap(QPixmap(":/thing/image/bow.png").scaled(250,200));
    bow->setPos(20,635);
    scene->addItem(bow);

    //add item
    addItems();
    qDebug() << birdList.size();

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/8);

}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    bird *curbird;
    if(!birdList.empty()) {
        curbird = birdList.front();
        if(!curbird->shoot) {
            isClick = true;
            click = transPoint::pixToMeter(event->pos());
        } else if(!curbird->skillUse){
                curbird->skillUse = true;
                curbird->skill();
        }
    }
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    if(isClick && event->type() == QEvent::MouseMove) {
        if(!birdList.empty() && !birdList.front()->shoot) {
        //for arrow
        release = transPoint::pixToMeter(
            static_cast<QMouseEvent*>(event)->pos());

        arrow->resetTransform();
        arrow->setScale(qSqrt(qPow(release.x()-click.x(),2)+
                              qPow(release.y()-click.y(),2))/30 + 0.5);
        arrow->setPos(60,550);
        arrow->setRotation(-qAtan2(click.y()-release.y(),
                                  click.x()-release.x())*180/PI);
        arrow->setVisible(true);
        }
    }
    if(isClick && event->type() == QEvent::MouseButtonRelease)
    {
        birdsound->play();
        isClick = false;
        arrow->setVisible(false);
        if(!birdList.empty() && !birdList.front()->shoot) {
        birdList.front()->changeType(true); //change to dynamic
        birdList.front()->setVelocity(b2Vec2((click.x()-release.x())*5,
                                  (click.y()-release.y())*5));
        birdList.front()->shoot = true;

        }
    }
    return false;
}
void MainWindow::closeEvent(QCloseEvent *)
{
    emit quitGame();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
    ui->score->display((float)score);
    ui->birdnum->display((int)birdList.size());
    deleteItems();
    if(pigList.size()==1 || birdList.size()==0) {
        resultdialog *res = new resultdialog;
        //res->setGeometry(this->x()+200,this->y()+150,400,300);
        res->show();
        res->winlose(pigList.size()==1);
        res->scoreshow(score);
        if(pigList.size()==1) {
            win->play();
        } else {
            lose->play();
        }
        if(res->exec()) {
            clicksound->play();
            score = 0;
            while(!itemList.empty()) {
                delete itemList.front();
                itemList.pop_front();
            }
            while(!pigList.empty()) {
                delete pigList.front();
                pigList.pop_front();
            }
            while(!birdList.empty()) {
                delete birdList.front();
                birdList.pop_front();
            }
            addItems();
        }else {
            this->close();
        }
    }
}
void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
void MainWindow::addItems() {

    itemList.clear();
    // Create Obstacle
    itemList.push_back(new obstacle(29.0f,4.0f,2.5f,1.0f,2,90,
                                    &timer,world,scene));
    itemList.push_back(new obstacle(30.0f,4.0f,2.5f,1.0f,2,90,
                                    &timer,world,scene));
    itemList.push_back(new obstacle(36.0f,4.0f,2.5f,1.0f,2,90,
                                    &timer,world,scene));
    itemList.push_back(new obstacle(37.0f,4.0f,2.5f,1.0f,2,90,
                                    &timer,world,scene));
    itemList.push_back(new obstacle(33.0f,6.0f,8.0f,1.0f,2,0,
                                    &timer,world,scene));

    itemList.push_back(new obstacle(30.5f,8.0f,1.5f,1.5f,1,0,
                                    &timer,world,scene));
    itemList.push_back(new obstacle(35.5f,8.0f,1.5f,1.5f,1,0,
                                    &timer,world,scene));
    itemList.push_back(new obstacle(30.5f,9.0f,1.5f,1.5f,1,0,
                                    &timer,world,scene));
    itemList.push_back(new obstacle(35.5f,9.0f,1.5f,1.5f,1,0,
                                    &timer,world,scene));
    itemList.push_back(new obstacle(33.0f,10.0f,6.0f,1.0f,2,0,
                                    &timer,world,scene));

    itemList.push_back(new obstacle(33.2f,12.0f,4.0f,1.0f,2,90,
                                    &timer,world,scene));

    itemList.push_back(new obstacle(18.0f,9.0f,12.0f,1.0f,2,270,
                                    &timer,world,scene));
    itemList.push_back(new obstacle(19.0f,9.0f,12.0f,1.0f,2,270,
                                    &timer,world,scene));


    //set pig
    pigList.push_back(new pig(33.0f,4.0f,1.0f,&timer
        ,QPixmap(":/pig/image/pig.png"),world,scene));
    pigList.push_back(new pig(33.0f,8.0f,1.0f,&timer
        ,QPixmap(":/pig/image/pig.png"),world,scene));
    pigList.push_back(new pig(33.0f,14.0f,1.0f,&timer
        ,QPixmap(":/pig/image/pig2.png"),world,scene));
    pigList.push_back(new pig(25.0f,4.0f,1.0f,&timer
        ,QPixmap(":/pig/image/pig2.png"),world,scene));
    pigList.push_back(new pig(45.0f,4.0f,1.0f,&timer
        ,QPixmap(":/pig/image/pig2.png"),world,scene));

    //for NULL
    pigList.push_back(new pig(1.0f,1.0f,1.0f,&timer
        ,QPixmap(":/pig/image/pig2.png"),world,scene));
    pigList[pigList.size()-1]->setVisible(false);
    pigList[pigList.size()-1]->changeType(false);

    // Create Land
    itemList.push_back(new land(25,2,50,1,
       QPixmap(":/obstacle/image/XMAS2014_GROUND.png").scaled(
             width(),height()/6.0f),world,scene));

    // Create bird
    birdList.clear();
    birdList.push_back(new redbird(4.8f,7.6f,0.8f,&timer,world,scene));
    birdList.push_back(new yellowbird(4.8f,7.6f,0.8f,&timer,world,scene));
    birdList.push_back(new whitebird(4.8f,7.6f,1.0f,&timer,world,scene));
    birdList.push_back(new blackbird(4.8f,7.6f,1.0f,&timer,world,scene));


    birdList.front()->setVisible(true);

}
void MainWindow::deleteItems() {
    QList<Item *>::iterator it;
    QList<pig *>::iterator It;
    //check for obstacle
    for(it=itemList.begin();it!=itemList.end();it++) {
        if((*it)->CheckDelete) {
            breaksound->play();
            delete (*it);
            itemList.erase(it);
            score = score + (*it)->maxhp*0.8763;
        }
    }
    for(It=pigList.begin();It!=pigList.end();It++) {
        if((*It)->CheckDelete) {
            death->play();
            delete (*It);
            pigList.erase(It);
            score = score + 5000;
        }
    }
    if(!birdList.empty() && birdList.front()->CheckDelete) {
        //qDebug() << "dbird";
        delete birdList.front();
        birdList.pop_front();
        if(!birdList.empty()) birdList.front()->setVisible(true);
    }
}

void MainWindow::on_pushButton_clicked()
{
    clicksound->play();
    score = 0;
    while(!itemList.empty()) {
        delete itemList.front();
        itemList.pop_front();
    }
    while(!pigList.empty()) {
        delete pigList.front();
        pigList.pop_front();
    }
    while(!birdList.empty()) {
        delete birdList.front();
        birdList.pop_front();
    }
    addItems();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}
