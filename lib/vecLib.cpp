/* FileName: vecLib.cpp
 * Author  : Vector(mcvector.gu@gmail.com)
 * Description:
 *  This file realize the functions in vecLib.h
 */
#include "vecLib.h"
void Point::glDraw()
{
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}

void Line::glDraw()
{
    glBegin(GL_LINES);
        glVertex2i(start.x, start.y);
        glVertex2i(end.x, end.y);
    glEnd();
}

void Rectangle::glDraw()
{

    glRecti(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y);
}

void Polygen::addPoint(Point p)
{
    vertex.push_back(p);
}

void Polygen::addPoint(int x, int y)
{
    Point p(x, y);
    vertex.push_back(p);
}

void glDraw()
{
    int i;
    int n = vertex.size();
    glBegin(GL_LINES);
        for(i = 1; i < n; i++)
        {
            glVertex2i(vertex[i-1], vertex[i%(n-1)]);
        }
    glEnd();
}

