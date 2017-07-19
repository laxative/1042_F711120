#include "whitebird.h"

whitebird::whitebird(float x, float y, float radius, QTimer *timer
, b2World *world, QGraphicsScene *scene):
    bird(x,y,radius,timer,world,scene)
{
    item_pixmap.setPixmap(QPixmap(":/bird/image/WhiteBird.png")
                          .scaled(radius*2*30, radius*2*30));
    item_pixmap.setTransformOriginPoint(
         item_pixmap.boundingRect().width()/2
        ,item_pixmap.boundingRect().height()/2);

    item_size = QSizeF(radius*2,radius*2);
    skillUse = false;
}
void whitebird::skill() {
    skillUse = true;
    b2Vec2 mypos = item_body->GetPosition();
    int bcnt = item_world->GetBodyCount();
    b2Body* blist= item_world->GetBodyList();
    for(int i = 0;i < bcnt;++i, blist = blist->GetNext()) {
        if(blist == item_body) continue;

        float dis = qSqrt(qPow(blist->GetPosition().x - mypos.x, 2) + qPow(blist->GetPosition().y - mypos.y, 2));
        if(dis < 8) {
            blist->ApplyForceToCenter(b2Vec2((blist->GetPosition().x - mypos.x) * 5000, (blist->GetPosition().y - mypos.y) * 5000), true);
        }
    }
}
