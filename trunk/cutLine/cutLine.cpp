#include <GL/glut.h>
#include <iostream>
#include "line.h"
int iPointNum = 0;
Line line;
int xCross, yCross;
int winWidth = 400, winHeight = 300;	//windows size
int xTL = 100;
int yTL = 225;
int xBR = 300;
int yBR = 75; 
void initial()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	//backgroud color is white
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
    glColor3f(0.0f, 0.0f, 0.0f);
    //draw frame
    glBegin(GL_LINE_LOOP);
        glVertex2d(xTL, yTL);
        glVertex2d(xBR, yTL);
        glVertex2d(xBR, yBR);
        glVertex2d(xTL, yBR);
    glEnd();


    if(iPointNum >= 1)          //if two points have been defined
    {
        //than draw the line
        glColor3f(0.0f, 0.0f, 0.0f);
        line.glDraw();
        glColor3f(1.0f, 0.0f, 0.0f);
        if(iPointNum == 1)
            glRectd(xCross-5,yCross+5, xCross+5, yCross-5);
        if(iPointNum == 2)
        {
        line.cut(xTL, yTL, xBR, yBR);
        line.glDraw();
        glBegin(GL_LINES);
            glVertex2i(xCross-5, yCross);
            glVertex2i(xCross+5, yCross);
            glVertex2i(xCross, yCross-5);
            glVertex2i(xCross, yCross+5);
        glEnd();
        }
    }
    //draw cross on mouse
    if(iPointNum == 0 )
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_LINES);
            glVertex2i(xCross-5, yCross);
            glVertex2i(xCross+5, yCross);
            glVertex2i(xCross, yCross-5);
            glVertex2i(xCross, yCross+5);
        glEnd();
    }

    glutSwapBuffers();
}

void mousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
    if(button == GLUT_LEFT_BUTTON && action == GLUT_DOWN)	//if left button of mouse have been pressed
    {
        if(iPointNum == 0 || iPointNum ==2)		//if first point of line haven't been defined
        {

            line.setStartPoint(xMouse, winHeight-yMouse);
            iPointNum = 1;		//	First point of line have been defined
        }
        else        //first point have been defined, draw a line based on second line
        {
            line.setEndPoint(xMouse, winHeight-yMouse);
            iPointNum = 2;
            glutPostRedisplay();		//call display function
        }
    }

    if(button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN)
    {
        //if right button pressed, clean picture
        iPointNum = 0;
        glutPostRedisplay();
    }
}

void passiveMouseMove(GLint xMouse, GLint yMouse)
{
    //draw line while moving mouse
    if(iPointNum == 1)
    {
        line.setEndPoint(xMouse, winHeight-yMouse);
        glutPostRedisplay();
    }
        xCross = xMouse;
        yCross = winHeight - yMouse;
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
    glutPassiveMotionFunc(passiveMouseMove);
    initial();
    glutMainLoop();
    return 0;
}

















