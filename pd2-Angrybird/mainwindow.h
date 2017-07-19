#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QSound>
#include <QList>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QDebug>
#include <iostream>
#include <QVector>
#include <QLCDNumber>

#include "item.h"
#include "bird.h"
#include "land.h"
#include "transpoint.h"
#include "obstacle.h"
#include "pig.h"
#include "contactlistener.h"

#include "redbird.h"
#include "blackbird.h"
#include "yellowbird.h"
#include "whitebird.h"

#define PI 3.14
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    void closeEvent(QCloseEvent *);
    bool eventFilter(QObject *, QEvent *event);
    void mousePressEvent(QMouseEvent *event);


signals:
    void quitGame();

private slots:
    void tick();
    void QUITSLOT();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<Item *>itemList;
    QList<pig *>pigList;
    QList<bird *>birdList;
    QTimer timer;
    float score;
    //for arrow
    QGraphicsPixmapItem *arrow;
    QPointF click;
    QPointF release;
    bool isClick;

    QSound *breaksound;
    QSound *birdsound;
    QSound *death;
    QSound *clicksound;
    QSound *win;
    QSound *lose;

    void addItems();
    void deleteItems();

    contactListener *contact;
};

#endif // MAINWINDOW_H
