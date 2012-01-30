#ifndef POINTSARRAY_H
#define POINTSARRAY_H
#include "point2D.h"
#include <vector>
class PointsArray
{
protected:
    std::vector<Point2D> vertex;
public:
    void addBack(Point2D point)         //add a point at end of the array
    {
        vertex.push_back(point);
    }
    int size()                          //return the size of array
    {
        return vertex.size();
    }
    Point2D at(int index)            //return point at index
    {
        return vertex[index];
    }
    Point2D operator [] (int index) const
    {
        return vertex[index];
    }
    void deletePoint( int index )       //remove point at index from array
    {
        vertex.erase(vertex.begin() + index );
    }
    void setPosition(int index, double x, double y); //change position of a selected point
    int selectPoint( double x, double y);  //select a point near (x, y)
};


#endif
