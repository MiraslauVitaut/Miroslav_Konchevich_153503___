#include "circle.h"

Circle::Circle(double x1, double y1, double x2, double y2)
{
    figure_circle = new QGraphicsEllipseItem(x1,y1,x2,y2);
    this->x1=x1;
    this->x2=x2;
    this->side1 = x2;
    figure_mass = new QGraphicsEllipseItem(side1/2-2.5,side1/2-2.5,5,5,figure_circle);
    this->center_of_mass_x = x1+side1/2;
    this->center_of_mass_y = y1+side1/2;
}

void Circle::addCircle(QGraphicsScene *scene)
{
    scene->addItem(figure_circle);
}

void Circle::removeCirle(QGraphicsScene *scene)
{
    scene->removeItem((figure_circle));
    delete figure_mass;
    delete figure_circle;
}

void Circle::moveCircle(double x, double y)
{
    this->offset_x+=x;
    this->offset_y+=y;
    figure_circle->setPos(this->offset_x,this->offset_y);
    this->x1+=x;
    this->x2+=x;
}

double Circle::showFigureShape()
{
    figure_shape = (3.1415)*(3.1415)*side1/2;
    return figure_shape;
}

double Circle::showFigurePerimetr()
{
    figure_perimeter = 2*3.1415*side1/2;
    return figure_perimeter;

}

void Circle::rotateCircle(int angle)
{
    this->angle+=angle;
    figure_circle->setTransformOriginPoint(this->center_of_mass_x,this->center_of_mass_y);
    figure_circle->setRotation(this->angle);
}

void Circle::scaleCircle(double size)
{
    scale+=size;
    this->side1 +=this->side1*size;
    figure_mass->setScale(figure_mass->scale());
    figure_circle->setScale(scale);

}
