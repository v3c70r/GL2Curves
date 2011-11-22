#ifndef GPOINT2D_H
#define GPOINT2D_H

class GPoint2d
{
public:
    double mX, mY;
public:
    GPoint2d();
    GPoint2d(double x, double y);
    GPoint2d(const GPoint2d &other);
    
    double x()
    { return mX; }
    
    double y()
    { return mY; }
    
    void setX(double x)
    { mX = x; }
    
    void setY(double y)
    { mY = y; }
    
    void set(double x, double y)
    { mX = x;   mY = y; }
    
    void operator = (const GPoint2d &other);
};

#endif
