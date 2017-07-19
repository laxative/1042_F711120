#ifndef BASIC_H
#define BASIC_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QVector>
#include <QMediaPlayer>
#include <QLCDNumber>
#include <QPushButton>
#include <QObject>
#include "Item.h"

#include <ctime>
#include <algorithm>

namespace Ui {
class basic;
}

class basic : public QMainWindow
{
    Q_OBJECT

public:
    explicit basic(QWidget *parent = 0);
    ~basic();

public slots:
    void keyPressEvent(QKeyEvent *k);
    void HitS();
    void HitSideS();
    void timego();
    void additem();
    void destoryed();
    void getPoint(int Pos);
    void newgame();

signals:
    void playhitsound();
    void playhitsidesound();

private:
    Ui::basic *ui;
    QMediaPlayer *hitsound;
    QMediaPlayer *hitsidesound;
    QMediaPlayer *bgm;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    Item *item;
    QVector<Item*> v;
    QVector<Item*>::iterator it;
    QVector<Item*>::iterator now;
    int T;
    int score;
};

#endif // BASIC_H
