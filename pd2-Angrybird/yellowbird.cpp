#include "yellowbird.h"

yellowbird::yellowbird(float x, float y, float radius, QTimer *timer
, b2World *world, QGraphicsScene *scene):
    bird(x,y,radius,timer,world,scene)
{
    item_pixmap.setPixmap(QPixmap(":/bird/image/yellowBird.png").
                          scaled(radius*2*30, radius*2*30));
    item_pixmap.setTransformOriginPoint(
         item_pixmap.boundingRect().width()/2
        ,item_pixmap.boundingRect().height()/2);

    item_size = QSizeF(radius*2,radius*2);
    skillUse = false;
}
void yellowbird::skill() {
    skillUse = true;
    item_body->SetLinearVelocity(b2Vec2(item_body->GetLinearVelocity().x*25,
    item_body->GetLinearVelocity().y*25));
}
