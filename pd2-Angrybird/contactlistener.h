#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <Box2D/Box2D.h>
#include "bird.h"
#include "item.h"

class contactListener : public b2ContactListener
{
public:
    contactListener();
    void EndContact(b2Contact *contact);
};

#endif // CONTACTLISTENER_H
