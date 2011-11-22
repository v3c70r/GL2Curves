#include "gpoint2d.h"

GPoint2d::GPoint2d()
{
    mX = mY = 0;
}

GPoint2d::GPoint2d(double x, double y)
{
    mX = x;
    mY = y;
}

GPoint2d::GPoint2d(const GPoint2d &other)
{
    mX = other.mX;
    mY = other.mY;
}

void GPoint2d::operator = (const GPoint2d &other)
{
    mX = other.mX;
    mY = other.mY;
}
