#include <GL/glut.h>
#include <iostream>
#include "vecLib.h"
#include <vector>
using namespace std;
//set font

int winWidth;
int winHeight;
Polygen myPoly;
int selectedPoint;
bool movePoint = false;

void initial()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   //backgroud color is white
    //set font
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
     
    void *font = GLUT_BITMAP_8_BY_13;
    glClear(GL_COLOR_BUFFER_BIT);

    //instructions
    glColor3d(255,0,0);
    char instruction_1[] = "#You can drag a point to move it.";
    char instruction_2[] = "#Right click on a point to delete it.";
    glRasterPos2d(5, winHeight-10);
    for(int j=0; instruction_1[j] != '\0'; j++)
    {
        glutBitmapCharacter(font, instruction_1[j]);
    }
    glRasterPos2d(5, winHeight-25);
    for(int j=0; instruction_2[j] != '\0'; j++)
    {
        glutBitmapCharacter(font, instruction_2[j]);
    }
    //myPoly.glDraw();
    myPoly.glFill(255,0,5);
    glColor3d(0,0,0);
    myPoly.glDraw();

    glutSwapBuffers();
}

void mousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)   //if left button of mouse have been pressed
    {
        if((selectedPoint = myPoly.selectPoint(xMouse, winHeight-yMouse)) == -1)     //if no point selecte, add a point to it's end
        {
            Point newPoint(xMouse, winHeight-yMouse);
            myPoly.addPoint(newPoint);
        }
        else                //change position of a point
        {
            movePoint = true;
        }
    }
    if(button == GLUT_LEFT_BUTTON && action == GLUT_UP)   //if left button of mouse have been released
    {
        movePoint = false;
    }
    if(button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN)   //if right button of mouse have been down. erase selected pont
    {
        if((selectedPoint = myPoly.selectPoint(xMouse,winHeight-yMouse)) != -1)
        {
            myPoly.deletePoint(selectedPoint);
        }
    }
    glutPostRedisplay();

}

void mouseMoveEvent(int x, int y)
{
    if(movePoint)
    {
        myPoly.setPointPosition(selectedPoint ,x , winHeight-y);
        glutPostRedisplay();
    }
}


int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	//double buffer
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Draw Polygen");
    glutDisplayFunc(display);
    glutReshapeFunc(changeSize);
    glutMouseFunc(mousePlot);
    glutMotionFunc(mouseMoveEvent);
    initial();
    glutMainLoop();
    return 0;
}


