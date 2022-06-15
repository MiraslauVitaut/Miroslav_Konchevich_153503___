#ifndef TRIANGLE_H
#define TRIANGLE_H


#include "shapes.h"
#include <QGraphicsItem>
#include <QGraphicsScene>

class Triangle: Shapes
{
private:
QGraphicsPolygonItem *figure_triangle;
QPolygonF polTriangle;
QGraphicsEllipseItem *figure_mass;


public:
Triangle(double x1,double y1,double x2, double y2,double x3, double y3);
void addTriangle(QGraphicsScene *scene);
void removeTriangle(QGraphicsScene *scene);
void moveTriangle(double x1,double y1);
double showFigureShape();
double showFigurePerimetr();
void rotateTriangle(int angle);
void scaleTriangle(double size);
};

#endif // TRIANGLE_H
