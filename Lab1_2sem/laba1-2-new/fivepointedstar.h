#ifndef FIVEPOINTEDSTAR_H
#define FIVEPOINTEDSTAR_H

#include <QGraphicsScene>
#include "star.h"

class FivePointedStar:public Star
{
public:
    FivePointedStar(int r,int R, int numb=5):Star(r,R,numb){};
};

#endif // FIVEPOINTEDSTAR_H
