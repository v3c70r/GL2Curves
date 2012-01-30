#include <GL/glut.h>
#include "curves.h"

void Hermit::glDraw()
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
    int iterTimes = 50;         //Define times of iteration
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




