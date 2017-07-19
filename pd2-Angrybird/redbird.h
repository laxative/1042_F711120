#ifndef REDBIRD_H
#define REDBIRD_H

#include "bird.h"

class redbird : public bird
{
public:
    redbird(float x, float y, float radius, QTimer *timer
    , b2World *world, QGraphicsScene *scene);
    virtual void skill();
private:
    bool skillUse;
};

#endif // REDBIRD_H
