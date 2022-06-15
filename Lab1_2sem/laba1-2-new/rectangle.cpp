#include "rectangle.h"

Rectangle::Rectangle(double x1,double y1,double side1,double side2)
{
    figure_rect=new QGraphicsRectItem{x1,y1,side1,side2};
    this->x1=x1;
    this->y1=y1;
    this->side1 = side1;
    this->side2 = side2;
    figure_mass = new QGraphicsEllipseItem(side1/2-2.5,side2/2-2.5,5,5,figure_rect);
    center_of_mass_x = side1/2;
    center_of_mass_y = side2/2;
}

void Rectangle::addRectangle(QGraphicsScene *scene)
{
    scene->addItem(figure_rect);
}

void Rectangle::removeRectangle(QGraphicsScene *scene)
{
    scene->removeItem(figure_rect);
    delete figure_mass;
    delete figure_rect;
}

void Rectangle::moveRectangle(double x, double y)
{
    this->offset_x+=x;
    this->offset_y+=y;
    figure_rect->setPos(this->offset_x,this->offset_y);
    this->x1+=x;
    this->y1+=y;
}

double Rectangle::showFigureShape()
{
    figure_shape = side1*side2;
    return figure_shape;

}

double Rectangle::showFigurePerimetr()
{
    figure_perimeter = 2*side1+2*side2;
    return figure_perimeter;

}

void Rectangle::rotateRect(int angle)
{
    this->angle+=angle;
    figure_rect->setTransformOriginPoint(this->center_of_mass_x,this->center_of_mass_y);
    figure_rect->setRotation(this->angle);

}

void Rectangle::scaleRect(double size)
{
    scale+=size;
    this->side1 +=this->side1*size;
    this->side2 +=this->side2*size;
    figure_mass->setScale(figure_mass->scale());
    figure_rect->setScale(scale);
}
