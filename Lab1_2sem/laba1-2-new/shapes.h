#ifndef SHAPES_H
#define SHAPES_H

#define PI 3.14159265358979


class Shapes
{
protected:
    double x1,x2,x3,x4,x5,x6,x7,x8;
    double y1,y2,y3,y4,y5,y6,y7,y8;
    double offset_x=0, offset_y=0;
    double side1,side2,side3,side4,side5;
    double r,R;
    double figure_shape;
    double figure_perimeter;
    double center_of_mass_x,center_of_mass_y;
    int angle = 0,numbangle;
    double scale=1;
public:
    Shapes();
    ~Shapes();
};

#endif // SHAPES_H
