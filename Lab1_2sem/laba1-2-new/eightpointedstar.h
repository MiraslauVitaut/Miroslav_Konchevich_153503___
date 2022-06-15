#ifndef EIGHTPOINTEDSTAR_H
#define EIGHTPOINTEDSTAR_H

#include "star.h"
#include <QGraphicsScene>

class EightPointedStar: public Star
{
public:
    EightPointedStar(int r,int R, int numb=8):Star(r,R,numb){};
};

#endif // EIGHTPOINTEDSTAR_H
