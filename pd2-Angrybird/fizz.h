#ifndef FIZZ_H
#define FIZZ_H

#include "bird.h"

class fizz : public bird
{
public:
    fizz(float x, float y, float radius, QTimer *timer
         , b2World *world, QGraphicsScene *scene);
     virtual void skill();
private:
     bool skillUse;
};

#endif // FIZZ_H
