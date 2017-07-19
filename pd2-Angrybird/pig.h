#ifndef PIG_H
#define PIG_H

#include "item.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QtMath>
#include <Box2D/Box2D.h>
#include <QDebug>

#define PIG_hp 500
class pig: public Item
{
public:
    pig(float x, float y, float radius, QTimer *timer
         , QPixmap birdpixmap, b2World *world, QGraphicsScene *scene);
    virtual void collision();
};

#endif // PIG_H
