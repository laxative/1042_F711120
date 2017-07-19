#include "contactlistener.h"
#include <QDebug>

contactListener::contactListener()
{

}

void contactListener::EndContact(b2Contact *contact) {
    //qDebug() << 'c';
    static_cast<Item*>(contact->GetFixtureA()
                       ->GetBody()->GetUserData())->collision();
    static_cast<Item*>(contact->GetFixtureB()
                       ->GetBody()->GetUserData())->collision();
}
