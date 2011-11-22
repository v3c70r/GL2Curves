//filename: ddaLine.cpp
//Description:
//This file is to draw a line with DDA
#include <cmath>
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
using namespace std; int winWidth;
int winHeight;

void glMidBresenhamLine(int x0, int y0, int x1, int y1)
{
    int temp, dx, dy, d, upIncre, downIncre, x, y;
    if(x0 > x1)     //check if start from x0
    {
        //swap two points
        x = x0; x0 = x1; x1 = x;
        y = y0; y0 = y1; y1 = y;
    }
    int direct = (y1-y0)/abs(y1-y0);
    x = x0; y = y0;
    dx = x1 - x0;
    dy = y1 - y0;
    d = direct*dx - 2*dy;
    upIncre = 2*dx - 2*dy;
    downIncre = -2*dy;
    //if direct < 0 , swap upIncre and downIncre
    if(direct < 0)
    {
        temp = upIncre;
        upIncre = downIncre;
        downIncre = temp;
    }

    for(; x<=x1 ; x++)
    {

        glBegin(GL_POINTS);
            glVertex2i(x, y);
        glEnd();
        x++;
        if( d < 0 )
        {
            y += direct;
            d += upIncre;
        }
        else
            d += downIncre;
    }
}
    



void glDDALine(int x0, int y0, int x1, int y1)
{
    int dx, dy, epsl, k;
    float x, y, xIncre, yIncre;
    dx = x1- x0;
    dy = y1- y0;
    x=x0;
    y=y0;
    if(abs(dx)>abs(dy))
    {
        epsl = abs(dx);
    }
    else
    {
        epsl = abs(dy);
    }
    xIncre = float(dx)/epsl;
    yIncre = float(dy)/epsl;
    for(k = 0; k<=epsl; k++)
    {
        glBegin(GL_POINTS);
            glVertex2d((int)(x+.5f), (int)(y+.5f));
        glEnd();
        x += xIncre;
        y += yIncre;
    }
}


//Inital glut
void initial()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   //backgroud color is white
}

void changeSize(int w, int h)
{
    //call while window changed
    winWidth = w;
    winHeight = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

void display()
{
    //display function
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f);
    //glDDALine(0, 0, 30, 30);
    glMidBresenhamLine(0, 0, 100, 100);
    glutSwapBuffers();

}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);    //double buffer
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Draw Line");
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);
    initial();
    glutMainLoop();
    return 0;
}



