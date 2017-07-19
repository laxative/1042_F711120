#ifndef WHITEBIRD_H
#define WHITEBIRD_H

#include "bird.h"

class whitebird : public bird
{
public:
    whitebird(float x, float y, float radius, QTimer *timer
, b2World *world, QGraphicsScene *scene);
    virtual void skill();

private:
    bool skillUse;

};

#endif // WHITEBIRD_H
