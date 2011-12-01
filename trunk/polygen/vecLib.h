/* Filename vecLib.h
 * Authour: Vector (mcvector.gu@gmail.com)
 * Descreption:
 *This file is used to define points lines and polygen.
 * Hope this stuff works well!
 * */
/*********************
 *Require  : Add drage points in polygen
 **********************/
#include <GL/glut.h>
#include <vector>
#include <stdio.h>
using namespace std;
struct Line;
struct Rectangle;
struct Polygen;
struct Point
{
    int x;
    int y;
    Point(){;}
    Point(int px, int py)
    {
        x = px;
        y = py;
    }
    void glDraw();
};


struct Line
{
    Point start;
    Point end;

    Line(){;}
    Line(int x0, int y0, int x1, int y1)
    {
        start.x = x0;
        start.y = y0;
        end.x = x1;
        end.y = y1;
    }

    Line(Point p0, Point p1)
    {
        start = p0;
        end = p1;
    }
    void glDraw();
};


struct Rectangle
{
    Point topLeft;
    Point bottomRight;
    Rectangle(){;}
    Rectangle(int x0, int y0, int x1, int y1)
    {
        topLeft.x = x0;
        topLeft.y = y0;
        bottomRight.x = x0;
        bottomRight.y = y0;
    }
    Rectangle(Point p0, Point p1)
    {
        topLeft = p0;
        bottomRight = p1;
    }
    void glDraw();
};

struct Polygen
{
    vector<Point> vertex;
    Polygen(){;}
    Polygen(vector<Point> points)
    {
        vertex = points;
    }
    void setPointPosition(int index, int x, int y);

    void addPoint(Point p)
    {
        vertex.push_back(p);
    }

    void addPoint(int x, int y)
    {
        Point p(x, y);
        vertex.push_back(p);
    }
//delete a point based on it's index;
    void deletePoint(int index)
    {
        vertex.erase(vertex.begin()+index);
    }
    void drawCoordinate();

//this function gonna return an index of point if this point is near x, y,
//if there's no point fond in this area, return -1
    int selectPoint(int x, int y);         

    void glDraw();
};
    


