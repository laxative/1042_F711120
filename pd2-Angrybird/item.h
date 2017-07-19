#ifndef ITEM_H
#define ITEM_H

#include <Box2D/Box2D.h>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QtMath>

class Item : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Item(b2World *world);
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    virtual void collision();
    ~Item();
    float maxhp;
    float hp;
    bool CheckDelete;
    bool skillUse;
    bool shoot;
    void setVisible(bool vis);
    void changeType(bool change);

public slots:
    void paint();


protected:
    b2Body *item_body;
    QSizeF item_size;
    QGraphicsPixmapItem item_pixmap;
    b2World *item_world;
    static QSizeF item_worldsize, item_windowsize;
};

#endif // ITEM_H
