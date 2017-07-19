#include "obstacle.h"

obstacle::obstacle(float x, float y, float w, float h,
                   int Type, float angle, QTimer *timer, b2World *world,
                   QGraphicsScene *scene):Item(world)
{
    type = Type;
    CheckDelete=false;
    // Set pixmap
    if(type==1) { //ice
        item_pixmap.setPixmap(QPixmap(":/obstacle/image/BLOCK_ICE_4X4_1.png"
          ).scaled(w*30, h*30));
        maxhp = hp = (w*30+h*30)*20;
    } else if(type==2) { //ice_rec
        item_pixmap.setPixmap(QPixmap(":/obstacle/image/BLOCK_LIGHT_1_4.png"
          ).scaled(w*30, h*30));
        maxhp = hp = (w*30+h*30)*10;
    } else { //ice_ano
        item_pixmap.setPixmap(QPixmap(":/obstacle/image/BLOCK_LIGHT_4X4_1.png"
          ).scaled(w*30, h*30));
        maxhp = hp = (w*30+h*30)*30;
    }

    // Create body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.bullet = true;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    bodyDef.angle= angle * PI/180;
    item_body = world->CreateBody(&bodyDef);

    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h/2);

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyBox;
    fixturedef.density = 20.0f;
    fixturedef.friction = 0.7f;
    fixturedef.restitution = 0.4f;
    item_body->SetAngularDamping(3);
    item_body->CreateFixture(&fixturedef);

    connect(timer,SIGNAL(timeout()),this,SLOT(paint()));

    item_pixmap.setTransformOriginPoint(
        item_pixmap.boundingRect().width()/2,
                item_pixmap.boundingRect().height()/2);

    scene->addItem(&item_pixmap);
    item_size.setHeight(h);
    item_size.setWidth(w);
}
void obstacle::collision() {
    b2Vec2 speed = item_body->GetLinearVelocity();
    float damage = qPow(speed.x, 2) + qPow(speed.y, 2);

    hp = hp - damage*24;
    if(hp<=0)  {
        CheckDelete=true;
    }

    //change pixmap
    if(hp/maxhp < 0.3) {
        if(type==1) {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_ICE_4X4_4.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        } else if(type==2) {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_LIGHT_4_4.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        } else {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_LIGHT_4X4_4.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        }
    } else if(hp/maxhp < 0.5) {
        if(type==1) {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_ICE_4X4_3.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        } else if(type==2) {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_LIGHT_3_4.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        } else {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_LIGHT_4X4_3.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        }
    } else if(hp/maxhp < 0.8) {
        if(type==1) {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_ICE_4X4_2.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        } else if(type==2) {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_LIGHT_2_4.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        } else {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_LIGHT_4X4_2.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        }
    } else {
        if(type==1) {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_ICE_4X4_1.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        } else if(type==2) {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_LIGHT_1_4.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        } else {
            item_pixmap.setPixmap(
                QPixmap(":/obstacle/image/BLOCK_LIGHT_4X4_1.png")
                        .scaled(item_size.width()*30,
                                item_size.height()*30));
        }
    }
}
