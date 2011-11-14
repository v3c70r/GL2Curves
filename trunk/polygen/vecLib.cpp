/* FileName: vecLib.cpp
 * Author  : Vector(mcvector.gu@gmail.com)
 * Description:
 *  This file realize the functions in vecLib.h
 */
#include "vecLib.h"
struct Line;
struct Rectangle;
struct Polygen;
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



void Polygen::glDraw()
{
    int i;
    int n = vertex.size();
        for(i = 1; i <= n; i++)
        {
    glBegin(GL_LINES);
            glVertex2i(vertex[i-1].x, vertex[i-1].y);
            glVertex2i(vertex[i%n].x, vertex[i%n].y);
    glEnd();

        }
}

