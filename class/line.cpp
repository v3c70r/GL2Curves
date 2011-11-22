#include <stdio.h>
#include <GL/glut.h>
#include "gpoint2d.h"
GPoint2d gPt0, gPt1;
bool gIsPaint = false;
bool gIsLBtnDown = false;
void displayEvent()
{
    glClearColor(0.5f, 0.2f, 0.9f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);   
    glColor3f(1.0, 1.0, 1.0);
    if(gIsPaint)
    {
    glBegin(GL_LINES);
        glVertex2i(gPt0.x(), gPt0.y());
        glVertex2i(gPt1.x(), gPt1.y());
    glEnd();
    }
        
    glFlush();
    glutSwapBuffers();
}

void resizeEvent(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void mouseEvent(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON)
    {
        if(state == GLUT_DOWN)
        {
            gPt0.set(x, y);
            gPt1 = gPt0;
            gIsLBtnDown = true;
            gIsPaint = true;
        }
        else if(state == GLUT_UP)
        {
            gPt1.set(x, y);
            gIsLBtnDown = false;
        }
        glutPostRedisplay();
    }
}
void mouseMoveEvent(int x, int y)
{
    if(gIsLBtnDown)
    {
        gPt1.set(x, y);
        glutPostRedisplay();
    }

}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(100, 200);
    glutCreateWindow("Line 2D");


    glutDisplayFunc(displayEvent);
    glutMouseFunc(mouseEvent);
    glutReshapeFunc(resizeEvent);
    glutMotionFunc(mouseMoveEvent);
    glutMainLoop();

    return 0;
}
