#ifndef CURVES_H
#define CURVES_H
#include "pointsArray.h"
class Curve:public PointsArray 
{

public:
    virtual void glDraw(int) = 0;
};

class Hermit: public Curve
{
public:
    void glDraw(int);
};

class SpLine: public Curve
{
public:
    void glDraw(int);
};

class Bezier: public Curve
{
private:
    double factorial(int n);
public:
    void glDraw(int);
};
#endif
