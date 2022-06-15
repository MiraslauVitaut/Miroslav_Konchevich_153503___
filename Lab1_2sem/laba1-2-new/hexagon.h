#ifndef HEXAGON_H
#define HEXAGON_H


#include "shapes.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class Hexagon:Shapes
{
private:
QGraphicsPolygonItem *figure_hexagon;
QPolygonF polHexagon;
QGraphicsEllipseItem *figure_mass;

public:
    Hexagon(double r);
    void addHexagon(QGraphicsScene *scene);
    void removeHexagon(QGraphicsScene *scene);
    void moveHexagon(double x,double y);
    double showFigureShape();
    double showFigurePerimetr();
    void rotateHex(int angle);
    void scaleHex(double size);
};

#endif // HEXAGON_H
