#ifndef CURVES_H
#define CURVES_H
#include "pointsArray.h"
class Curve:public PointsArray 
{
public:
    virtual void glDraw() = 0;
};

class Hermit: public Curve
{
public:
    void glDraw();
};
#endif
