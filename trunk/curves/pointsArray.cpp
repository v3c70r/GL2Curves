#include "pointsArray.h"
void PointsArray::setPosition(int index, double x, double y)
//set point at index to a new coordinate
{
    if(index >= vertex.size())      //index > points in array
        return;
    vertex[index].setX(x);
    vertex[index].setY(y);
}
int PointsArray::selectPoint(double x, double y)
{
    for(int i = 0; i<vertex.size(); i++)
    {
        int errX = x - vertex[i].getX();
        int errY = y - vertex[i].getY();
        if((errX <= 5 && errX >= -5) && (errY <=5 && errY >= -5))
            return i;
    }
    return -1;
}

