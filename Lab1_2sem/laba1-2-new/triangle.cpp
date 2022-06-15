 #include "triangle.h"

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
    polTriangle<<QPointF(x1,y1)<<QPointF(x2,y2)<<QPointF(x3,y3);
    figure_triangle = new QGraphicsPolygonItem(polTriangle);
    this->x1=x1;
    this->x2=x2;
    this->x3=x3;
    this->y1=y1;
    this->y2=y2;
    this->y3=y3;
    this->side1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    this->side2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    this->side3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    figure_mass = new QGraphicsEllipseItem(x3/2-2.5,y1/2-2.5,5,5,figure_triangle);
    this->center_of_mass_x = x3/2;
    this->center_of_mass_y = y1/2;
}

void Triangle::addTriangle(QGraphicsScene *scene)
{
    scene->addItem(figure_triangle);
}

void Triangle::removeTriangle(QGraphicsScene *scene)
{
    scene->removeItem(figure_triangle);
    delete figure_mass;
    delete figure_triangle;
}

void Triangle::moveTriangle(double x,double y)
{
    this->offset_x+=x;
    this->offset_y+=y;
    figure_triangle->setPos(this->offset_x,this->offset_y);
    this->x1+=x;
    this->x2+=x;
    this->x3+=x;
    this->y1+=y;
    this->y2+=y;
    this->y3+=y;
}

double Triangle::showFigureShape()
{
    figure_perimeter = side1+side2+side3;
    figure_shape = sqrt((figure_perimeter/2.0)*(figure_perimeter/2.0-side1)*(figure_perimeter/2.0-side2)*(figure_perimeter/2.0-side3));
    return figure_shape;
}

double Triangle::showFigurePerimetr()
{
    figure_perimeter = side1+side2+side3;
    return figure_perimeter;
}

void Triangle::rotateTriangle(int angle)
{
    this->angle+=angle;
    figure_triangle->setTransformOriginPoint(this->center_of_mass_x,this->center_of_mass_y);
    figure_triangle->setRotation(this->angle);
}

void Triangle::scaleTriangle(double size)
{
    scale+=size;
    this->side1 +=this->side1*size;
    this->side2 +=this->side2*size;
    this->side3 +=this->side3*size;

    figure_mass->setScale(figure_mass->scale());
    figure_triangle->setScale(scale);

}




