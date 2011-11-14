/* Filename vecLib.h
 * Authour: Vector (mcvector.gu@gmail.com)
 * Descreption:
 *This file is used to define points lines and polygen.
 * Hope this stuff works well!
 * */
#include <vector>

struct Point
{
    int x;
    int y;
    Point(int px, int py)
    {
        x = px;
        y = py;
    }
    void glDraw();
}


struct Line
{
    Point start;
    Point end;

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

}


struct Rectangle
{
    Point topLeft;
    Point bottomRight;
    Rectangle(int x0, int y0, int x1, int y1)
    {
        topLeft.setValue(x0, y0);
        bottomRight.setValue(x0. y0);
    }
    Rectangle(Point p0, Point p1)
    {
        topLeft = p0;
        bottomRight = p1;
    }
    void glDraw();
}

struct Polygen
{
    vector<Point> vertex;
    Polygen(vector<Point> points)
    {
        vertex = points;
    }
    void addPoint(Point p);
    void addPoint(int x, int y);
    void glDraw();
}
    


