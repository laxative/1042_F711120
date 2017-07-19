#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "item.h"
#include <QSizeF>
#include <QGraphicsScene>
#include <Box2D/Box2D.h>
#include <QTimer>
#define PI 3.14
class obstacle: public Item
{
public:
    obstacle(float x, float y, float w, float h, int Type, float angle,
             QTimer *timer, b2World *world, QGraphicsScene *scene);
    virtual void collision();

private:
    int type;
};

#endif // OBSTACLE_H
