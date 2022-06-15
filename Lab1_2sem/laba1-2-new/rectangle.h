#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapes.h"
#include <QGraphicsItem>
#include <QGraphicsScene>

class Rectangle: public Shapes
{
protected:
    QGraphicsRectItem *figure_rect;
    QGraphicsEllipseItem *figure_mass;
public:
    Rectangle(double x1,double y1,double side1,double side2);
    Rectangle(){};
    void addRectangle(QGraphicsScene *scene);
    void removeRectangle(QGraphicsScene *scene);
    void moveRectangle(double x,double y);
    double showFigureShape();
    double showFigurePerimetr();
    void rotateRect(int angle);
    void scaleRect(double size);
};

#endif // RECTANGLE_H
