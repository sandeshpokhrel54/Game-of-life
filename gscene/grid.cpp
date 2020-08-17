#include "grid.h"

Grid::Grid()
{
    life = false;
    setFlag(QGraphicsItem::ItemIsSelectable);


}

QRectF Grid::boundingRect() const
{
    return QRectF(squareDim*positionX, squareDim*positionY, squareDim, squareDim);
}

void Grid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::white);

    //setting color of the cell according to its life state
    if(life)
    {
        brush.setColor(Qt::black);
    }
    else
    {
        brush.setColor(Qt::white);
    }

    painter->fillRect(rec,brush);
    painter->drawRect(rec);

}


void Grid::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //make cell alive if dead and dead if alive
    if(!life)
        life = true;
    else
        life = false;
    update();
    QGraphicsItem::mousePressEvent(event);
}


