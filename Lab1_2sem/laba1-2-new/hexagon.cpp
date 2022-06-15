#include "hexagon.h"


Hexagon::Hexagon(double r)
{
    double angle=0;
    for(int i = 0;i<6;i++){
    polHexagon<<QPointF(r * cos(angle * PI/180),r* sin(angle * PI/180));
    angle = angle + 360.0/6;
    }
    figure_hexagon = new QGraphicsPolygonItem(polHexagon);
    this->side1 = r;

    figure_mass = new QGraphicsEllipseItem(-2.5,-2.5,5,5,figure_hexagon);
    center_of_mass_x = 0;
    center_of_mass_y = 0;

}

void Hexagon::addHexagon(QGraphicsScene *scene)
{
    scene->addItem(figure_hexagon);

}

void Hexagon::removeHexagon(QGraphicsScene *scene)
{
    scene->removeItem(figure_hexagon);
    delete figure_mass;
    delete figure_hexagon;

}

void Hexagon::moveHexagon(double x, double y)
{
    this->offset_x+=x;
    this->offset_y+=y;
    figure_hexagon->setPos(this->offset_x,this->offset_y);
}

double Hexagon::showFigureShape()
{
    figure_shape = side1*side1*3*sqrt(3)/2;
    return figure_shape;

}

double Hexagon::showFigurePerimetr()
{
    figure_perimeter = 6*side1;
    return figure_perimeter;

}

void Hexagon::rotateHex(int angle)
{
    this->angle+=angle;
    figure_hexagon->setTransformOriginPoint(this->center_of_mass_x,this->center_of_mass_y);
    figure_hexagon->setRotation(this->angle);
}

void Hexagon::scaleHex(double size)
{
    scale+=size;
    this->side1 +=this->side1*size;
    figure_mass->setScale(figure_mass->scale());
    figure_hexagon->setScale(scale);

}
