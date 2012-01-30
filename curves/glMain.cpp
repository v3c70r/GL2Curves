#include <GL/glut.h>
#include <iostream>
#include "curves.h"
#include <vector>
using namespace std;
//set font

int winWidth;
int winHeight;
Hermit myHermit;
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
    char instruction_1[] = "#Drag a point to move it.";
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
    //Draw Hermit here
    myHermit.glDraw();

    glutSwapBuffers();
}

void mousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)   //if left button of mouse have been pressed
    {
        if((selectedPoint = myHermit.selectPoint(xMouse, winHeight-yMouse)) == -1)     //if no point selecte, add a point to it's end
        {
            Point2D newPoint(xMouse, winHeight-yMouse);
            myHermit.addBack(newPoint);
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
        if((selectedPoint = myHermit.selectPoint(xMouse,winHeight-yMouse)) != -1)
        {
            myHermit.deletePoint(selectedPoint);
        }
    }
    glutPostRedisplay();

}

void mouseMoveEvent(int x, int y)
{
    if(movePoint)
    {
        myHermit.setPosition(selectedPoint ,x , winHeight-y);
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


