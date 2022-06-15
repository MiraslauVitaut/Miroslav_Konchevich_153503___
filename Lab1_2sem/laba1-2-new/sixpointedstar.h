#ifndef SIXPOINTEDSTAR_H
#define SIXPOINTEDSTAR_H

#include <star.h>
#include <QGraphicsScene>

class SixPointedStar:public Star
{
public:
    SixPointedStar(int r,int R, int numb=6):Star(r,R,numb){};
};

#endif // SIXPOINTEDSTAR_H
