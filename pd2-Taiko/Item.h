#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Item : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Item(int when, int what);
    int gettime();
    int gettype();

public slots:
    void itemMove();
    void whatItem();

signals:
    void item_des();

private:
    int time;
    int type;
};

#endif // ITEM_H
