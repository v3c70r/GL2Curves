#include <GL\glut.h>
#include <iostream>
#include "vecLib.h"
#include <vector>
using namespace std;

int winWidth;
int winHeight;
Polygen myPoly;

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
     
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    myPoly.glDraw();

    glutSwapBuffers();
}

void mousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)   //if left button of mouse have been pressed
    {


        Point newPoint(xMouse, winHeight-yMouse);
        myPoly.addPoint(newPoint);
    }
    glutPostRedisplay();

}



int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//double buffer
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Draw Line");
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);
    glutMouseFunc(mousePlot);
    initial();
    glutMainLoop();
    return 0;
}

















