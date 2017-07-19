#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include "bird.h"

class yellowbird : public bird
{
public:
    yellowbird(float x, float y, float radius, QTimer *timer
, b2World *world, QGraphicsScene *scene);
    virtual void skill();
private:
    bool skillUse;
};

#endif // YELLOWBIRD_H
