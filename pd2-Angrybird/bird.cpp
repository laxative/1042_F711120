#include "bird.h"

bird::bird(float x, float y, float radius, QTimer *timer
           , b2World *world
, QGraphicsScene *scene):Item(world)
{

    skillUse = false;
    shoot = false;
    CheckDelete = false;
    hp = 100000000;

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_staticBody;
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

    setVisible(false);

}
void bird::setVelocity(b2Vec2 velocity)
{
    item_body->SetLinearVelocity(velocity);
}

void bird::skill() {}
void bird::collision() {}
