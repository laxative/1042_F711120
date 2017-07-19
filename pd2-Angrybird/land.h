#ifndef LAND_H
#define LAND_H

#include "item.h"
#include <QSizeF>
#include <QGraphicsScene>

class land: public Item
{
public:
    land(float x, float y, float w, float h, QPixmap pixmap
         , b2World *world, QGraphicsScene *scene);
};

#endif // LAND_H
