#include "Item.h"

Item::Item(int when, int what)
{
    time = when;
    type = what;
    whatItem();
}
void Item::itemMove() {
    if(x() >= 0) {
        setPos(x()-1,y());
    }else{
        emit item_des();
        delete this;
    }
}
int Item::gettime() {
    return time;
}
int Item::gettype() {
    return type;
}

void Item::whatItem() {
    switch(type) {
        case 0:
            setPixmap(QPixmap(":/item/images/1.png"));
            setPos(620,150);
            break;
        case 1:
            setPixmap(QPixmap(":/item/images/2.png"));
            setPos(620,150);
            break;
        case 2:
            setPixmap(QPixmap(":/item/images/3.png"));
            setPos(620,150);
            break;
        case 3:
            setPixmap(QPixmap(":/item/images/4.png"));
            setPos(620,150);
            break;
        default:
            break;
    }
}
