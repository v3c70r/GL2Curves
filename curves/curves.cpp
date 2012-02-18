#include <GL/glut.h>
#include "curves.h"
#include <cmath>

void Hermit::glDraw(int iterTimes)
    //iterTimes defines how many steps in the point
{
    //less than 4 points, draw points only
    if( vertex.size() < 4)
    {
        //draw points in array
        for( int i = 0; i < vertex.size(); i++)
            vertex[i].glDraw( POINT_WITH_COORDINATE );
        return;
    }
    if ( vertex.size() > 4)
        return;
    //else
    Point2D rStart, rEnd, tPre, tNext;
    double t, step;
    rStart = vertex[1] - vertex[0];
    rEnd = vertex[3] - vertex[2];
    step = 1.0/iterTimes;
    t = 0;
    tPre = vertex[0];
    for(int i=0; i< iterTimes; i++)
    {
        t += step;
        tNext = vertex[0]*(2*t*t*t - 3*t*t + 1) + vertex[2]*(-2*t*t*t + 3*t*t)
            + rStart*(t*t*t - 2*t*t + t) + rEnd*(t*t*t - t*t);
        glBegin(GL_LINE);
            glVertex2d(tPre.getX(), tPre.getY());
            glVertex2d(tNext.getX(), tNext.getY());
        glEnd();
            
        tPre = tNext;
    }
    //draw points in array again
    for( int i = 0; i < vertex.size(); i++)
        vertex[i].glDraw(POINT_WITH_COORDINATE );
    return;
}

double Bezier::factorial(int n)
{
    double res = 1;
    for(int i = 2; i <= n; i++)
        res *= i;
    return res;
}

void Bezier::glDraw(int iterTimes)
{
    //draw Bezier curve
    int size = vertex.size();
    if (size >= 2)
    {
        Point2D pPre, pNext;
        double t, step;
        pPre = vertex[0];
        step = 1.0/iterTimes;
        for(int i = 0; i < iterTimes; i++)
        {
            t += step;
            pNext.setX(0);
            pNext.setY(0);
            for(int i = 0; i < size; i++)
                pNext = pNext + vertex[i]*(factorial(size-1)/(factorial(i)*factorial(size-1-i)))
                    *pow(t,i)*pow((1-t), (size-1-i));
            
            glBegin(GL_LINE);
                glVertex2d(pPre.getX(), pPre.getY());
                glVertex2d(pNext.getX(), pNext.getY());
            glEnd();
            pPre = pNext;
        }
    }
    //draw points in array again
    for( int i = 0; i < size; i++)
    {
        if( i < size-1)
        {
            //draw line between verteices
            glBegin(GL_LINE);
                glVertex2d(vertex[i].getX(), vertex[i].getY());
                glVertex2d(vertex[i+1].getX(), vertex[i+1].getY());
            glEnd();
        }
        vertex[i].glDraw(POINT_WITH_COORDINATE );
    }
}

void SpLine::glDraw(int iterTimes)
{
    double t, step;
    Point2D pStart, pEnd, rStart, rEnd;
    step = 1.0/iterTimes;
    int size = vertex.size();
    if ( size >= 4 )
    {
        //draw SpLine
        for(int i = 0; i < size - 3; i++)
        {
            t = 0;
            pStart = vertex[i+1];
            rStart = vertex[i+1] - vertex[i];
            if ( i == size - 4)
                rEnd = vertex[i+3] - vertex[i+2];
            else
                rEnd = vertex[i+2] - vertex[i+1];
            
            for(int j=0; j< iterTimes; j++)
            {
                t += step;
                pEnd = vertex[i+1]*(2*t*t*t - 3*t*t + 1) + vertex[i+2]*(-2*t*t*t + 3*t*t)
                    + rStart*(t*t*t - 2*t*t + t) + rEnd*(t*t*t - t*t);
                glBegin(GL_LINE);
                    glVertex2d(pStart.getX(), pStart.getY());
                    glVertex2d(pEnd.getX(), pEnd.getY());
                glEnd();
                    
                pStart = pEnd;
            }
        }
    }
    //draw points
    for( int i = 0; i < size; i++)
    {
        vertex[i].glDraw(POINT_WITH_COORDINATE );
    }
}

        
