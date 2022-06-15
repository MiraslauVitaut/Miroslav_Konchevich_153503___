#ifndef CIRCLE_H
#define CIRCLE_H


#include "shapes.h"
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

class Circle:Shapes
{
private:
    QGraphicsEllipseItem *figure_circle;
    QGraphicsEllipseItem *figure_mass;
public:
    Circle(double x1,double y1,double x2, double y2);
    void addCircle(QGraphicsScene *scene);
    void removeCirle(QGraphicsScene *scene);
    void moveCircle(double x,double y);
    double showFigureShape();
    double showFigurePerimetr();
    void rotateCircle(int angle);
    void scaleCircle(double size);
};

#endif // CIRCLE_H
