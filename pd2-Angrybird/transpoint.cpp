#include "transpoint.h"

transPoint::transPoint()
{
}
QSizeF transPoint::object_windowsize = QSizeF();
QSizeF transPoint::object_worldsize = QSizeF();

void transPoint::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    object_worldsize = worldsize;
    object_windowsize = windowsize;
}

QPointF transPoint::meterToPix(b2Vec2 body_pos, QSizeF body_meter)
{
    QPointF pos;
    pos.setX(((body_pos.x-body_meter.width()/2)/object_worldsize.width())
             * object_windowsize.width());
    pos.setY((1.0f-((body_pos.y+body_meter.height()/2)
             /object_worldsize.height()))*object_windowsize.height());
    return pos;
}

QPointF transPoint::pixToMeter(QPointF pos) {
    QPointF out;
    out.setX((pos.x()/object_windowsize.width())*object_worldsize.width());
    out.setY((1.0f-pos.y()/object_windowsize.height())
             *object_worldsize.height());
    return out;
}
