#ifndef TRANSPOINT_H
#define TRANSPOINT_H

#include <Box2D/Box2D.h>
#include <QPointF>
#include <QSizeF>

class transPoint
{
public:
    transPoint();
    static void setGlobalSize(QSizeF worldsize, QSizeF windowsize);
    static QPointF pixToMeter(QPointF pos);
    static QPointF meterToPix(b2Vec2 body_pos, QSizeF body_meter);

private:
    static QSizeF object_worldsize, object_windowsize;
};

#endif // TRANSPOINT_H
