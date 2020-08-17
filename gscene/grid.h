#ifndef GRID_H
#define GRID_H

#include<QGraphicsItem>
#include<QBrush>
#include<QPen>
#include<QPainter>

class Grid : public QGraphicsItem
{
public:
    int positionX, positionY,squareDim; //variables so that we can make the rectangle at desired position
    Grid();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    bool life;




protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // GRID_H
