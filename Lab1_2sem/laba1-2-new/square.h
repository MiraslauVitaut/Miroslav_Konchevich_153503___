#ifndef SQUARE_H
#define SQUARE_H

#include "shapes.h"
#include "rectangle.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class Square:public Rectangle
{
public:
    Square(double x1,double y1,double side1,double side2):Rectangle(x1,y1,side1,side2){};
};

#endif // SQUARE_H
