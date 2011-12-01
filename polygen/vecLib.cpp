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

void Polygen::setPointPosition(int index, int x, int y)         //change position of an excit point
{
    if(index >= vertex.size())      //index > points in array
        return;
    vertex[index].x = x;
    vertex[index].y = y;
}

void Polygen::glDraw()
{
    int i;
    int n = vertex.size();
    for(i = 1; i <= n; i++)
    {
    drawCoordinate();
    glRectd(vertex[i%n].x-5, vertex[i%n].y-5, vertex[i%n].x+5, vertex[i%n].y+5);
    glBegin(GL_LINES);
            glVertex2i(vertex[i-1].x, vertex[i-1].y);
            glVertex2i(vertex[i%n].x, vertex[i%n].y);
    glEnd();
    }

}

int Polygen::selectPoint(int x, int y)
{
    for(int i = 0; i<vertex.size(); i++)
    {
        int errX = x - vertex[i].x;
        int errY = y - vertex[i].y;
        if((errX <= 5 && errX >= -5) && (errY <=5 && errY >= -5))
            return i;
    }
    return -1;
}

void Polygen::drawCoordinate()
{
    void *font = GLUT_BITMAP_8_BY_13;
    for(int i=0; i<vertex.size(); i++)
    {
        char text[32];
        sprintf(text, "(%d, %d)", (int)vertex[i].x, (int)vertex[i].y);
        glRasterPos2d(vertex[i].x-10, vertex[i].y+5);
        for(int j=0; text[j] != '\0'; j++)
        {
            glutBitmapCharacter(font, text[j]);
        }
    }
}






