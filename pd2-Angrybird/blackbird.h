#ifndef BLACKBIRD_H
#define BLACKBIRD_H

#include "bird.h"

class blackbird : public bird
{

public:

    blackbird(float x, float y, float radius, QTimer *timer
    , b2World *world, QGraphicsScene *scene);
    virtual void skill();

private:
    bool skillUse;
};

#endif // BLACKBIRD_H
