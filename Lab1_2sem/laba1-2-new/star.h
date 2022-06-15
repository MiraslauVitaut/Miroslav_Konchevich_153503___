#ifndef STAR_H
#define STAR_H

#include "shapes.h"
#include <QGraphicsItem>
#include <QGraphicsScene>

class Star:public Shapes
{
protected:
QGraphicsPolygonItem *figure_star;
QPolygonF polStar;
QGraphicsEllipseItem *figure_mass;


public:
Star(int r,int R,int numb);
void addStar(QGraphicsScene *scene);
void removeStar(QGraphicsScene *scene);
void moveStar(double x1,double y1);
double showFigureShape();
double showFigurePerimetr();
void rotateStar(int angle);
void scaleStar(double size);
};

#endif // STAR_H
