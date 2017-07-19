#include "pig.h"

pig::pig(float x, float y, float radius, QTimer *timer
           , QPixmap birdpixmap, b2World *world
           , QGraphicsScene *scene):Item(world)
{
    maxhp = hp = PIG_hp;
    CheckDelete=false;
    // Set pixmap
    item_pixmap.setPixmap(birdpixmap.scaled(60, 60)); //set bird size
    item_pixmap.setTransformOriginPoint(
         item_pixmap.boundingRect().width()/2
        ,item_pixmap.boundingRect().height()/2);
    item_size = QSizeF(radius*2,radius*2);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    item_body = world->CreateBody(&bodydef);

    b2CircleShape bodyshape;
    bodyshape.m_radius = radius;

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = 10.0f;
    fixturedef.friction = 0.2f;
    fixturedef.restitution = 0.3f;
    item_body->SetAngularDamping(3);
    item_body->CreateFixture(&fixturedef);

    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));
    scene->addItem(&item_pixmap);

}
void pig::collision() {
    b2Vec2 speed = item_body->GetLinearVelocity();
    float damage = qPow(speed.x, 2) + qPow(speed.y, 2);
    /*qDebug() << "HP :" << hp << "->" << hp - damage
             << CheckDelete << maxhp << hp/maxhp;*/

    hp = hp - damage*24;
        if(hp<=0)  {
        CheckDelete=true;
    }
}
