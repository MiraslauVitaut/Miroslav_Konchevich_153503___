#ifndef ARBITARY_H
#define ARBITARY_H

#include "shapes.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

class Arbitary:Shapes
{
public:
    QPolygonF *dotsPol;
    QGraphicsPolygonItem *arbitary_figure;
    QGraphicsScene *Wscene;
    int a;
};

#endif // ARBITARY_H
