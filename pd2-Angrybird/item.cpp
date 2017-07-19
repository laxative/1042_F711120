#include "item.h"
#include "transpoint.h"
#include <QDebug>

Item::Item(b2World *world):item_body(NULL),item_world(world)
{
}

Item::~Item()
{
    item_world->DestroyBody(item_body);
}
QSizeF Item::item_windowsize = QSizeF();
QSizeF Item::item_worldsize = QSizeF();

void Item::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    item_worldsize = worldsize;
    item_windowsize = windowsize;
}

void Item::paint()
{
    b2Vec2 pos = item_body->GetPosition();
    //qDebug() << pos.x << pos.y;
    QPointF mappedPoint = transPoint::meterToPix(pos, item_size);


    item_pixmap.setPos(mappedPoint);
    item_pixmap.resetTransform();
    item_pixmap.setRotation(-(item_body->GetAngle()*180/3.14159));
    b2Vec2 bodypos = item_body->GetPosition();
    //qDebug() << bodypos.x << bodypos.y;
    if((bodypos.x > 50 || bodypos.x < 0)) {
        CheckDelete = true;
    }
    if(hp == 100000000) { //for bird
        b2Vec2 speed = item_body->GetLinearVelocity();
        if(qFabs(speed.x) < 10e-7 && qFabs(speed.y) < 10e-7 && shoot) {
            CheckDelete = true;
        }
    }
}

void Item::collision() { }
void Item::setVisible(bool vis) {
    item_pixmap.setVisible(vis);
    item_body->GetFixtureList()->SetSensor(!vis);
}
void Item::changeType(bool change) {
    if(change) item_body->SetType(b2_dynamicBody);
    else item_body->SetType(b2_staticBody);
}
