#include "land.h"

land::land(float x, float y, float w, float h, QPixmap pixmap
           , b2World *world, QGraphicsScene *scene):Item(world)
{
    CheckDelete = false;
    // Set pixmap
    item_pixmap.setPixmap(pixmap);

    // Create body
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    item_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h/2);
    item_body->CreateFixture(&bodyBox,9.0f);
    item_size = QSizeF(w,h);

    scene->addItem(&item_pixmap);
    paint();
}
