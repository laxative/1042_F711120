#ifndef BIRD_H
#define BIRD_H

#include "item.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>


class bird: public Item
{
public:
    bird(float x, float y, float radius, QTimer *timer
         , b2World *world, QGraphicsScene *scene);
    void setVelocity(b2Vec2 velocity);
    virtual void collision();
    virtual void skill();

};

#endif // BIRD_H
