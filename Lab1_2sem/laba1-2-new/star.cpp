#include "star.h"

Star::Star(int r,int R,int numb)
{
    for(int i =0;i<numb;i++){
        polStar<<QPoint(r*cos(2*i*M_PI/numb), r*sin(2*i*M_PI/numb));
        polStar<<QPoint(R*cos((2*i+1)*M_PI/numb), R*sin((2*i+1)*M_PI/numb));
    }
    figure_star = new QGraphicsPolygonItem(polStar);
    figure_mass = new QGraphicsEllipseItem(-2.5,-2.5,5,5,figure_star);
    this->center_of_mass_x = 0;
    this->center_of_mass_y = 0;
    this->numbangle = numb;
    this->r = r;
    this->R = R;
    this->side1 = sqrt((r/2.0)*(r/2.0)+(R-r));
}

void Star::addStar(QGraphicsScene *scene)
{
        scene->addItem(figure_star);
}

void Star::removeStar(QGraphicsScene *scene)
{
    scene->removeItem(figure_star);
    delete figure_mass;
    delete figure_star;
}

void Star::moveStar(double x,double y)
{
    this->offset_x+=x;
    this->offset_y+=y;
    figure_star->setPos(this->offset_x,this->offset_y);
}

double Star::showFigureShape()
{
    return this->numbangle*sin(PI/this->numbangle)*this->r*this->R;
}

double Star::showFigurePerimetr()
{
    return this->side1*this->numbangle;
}

void Star::rotateStar(int angle)
{
    this->angle+=angle;
    figure_star->setTransformOriginPoint(this->center_of_mass_x,this->center_of_mass_y);
    figure_star->setRotation(this->angle);
}

void Star::scaleStar(double size)
{
    scale+=size;
    this->side1 +=this->side1*size;
    this->r +=this->r*size;
    this->R +=this->R*size;
    figure_mass->setScale(figure_mass->scale());
    figure_star->setScale(scale);
}
