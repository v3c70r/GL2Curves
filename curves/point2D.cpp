#include <stdio.h>
#include <GL/glut.h>
#include "point2D.h"
Point2D Point2D::operator - (const Point2D &other) const
{
    Point2D temp;
    temp.setX(this->x - other.x);
    temp.setY(this->y - other.y);
    return temp;
}

Point2D Point2D::operator + (const Point2D &other) const
{
    Point2D temp;
    temp.setX(this->x + other.x);
    temp.setY(this->y + other.y);
    return temp;
}

Point2D Point2D::operator * (const Point2D &other) const
{
    Point2D temp;
    temp.setX(this->x * other.x);
    temp.setY(this->y * other.y);
    return temp;
}
Point2D Point2D::operator * (double num) const
{
    Point2D temp;
    temp.setX(this->x * num);
    temp.setY(this->y * num);
    return temp;
}

void Point2D::glDraw(int type)
{
    if( type == POINT_WITH_COORDINATE )
    {
        //draw Rectangle
        glBegin(GL_LINE_LOOP);
            glVertex2d(x-5, y+5);
            glVertex2d(x+5, y+5);
            glVertex2d(x+5, y-5);
            glVertex2d(x-5, y-5);
        glEnd();
        //draw Coordinate
        void *font = GLUT_BITMAP_8_BY_13;
        char text[32];
        sprintf(text, "(%d, %d)", (int)x, (int)y);
        glRasterPos2d(x-10, y+5);
        for(int j=0; text[j] != '\0'; j++)
        {
            glutBitmapCharacter(font, text[j]);
        }

    }
    //since a single point is not neccessary to be drawd, thus the second type
    //of method isn't defined here
}
            
            
