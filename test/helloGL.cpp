#include <GL/glut.h>
#include <iostream>
int iPointNum = 0;
int x1 = 0, x2 = 0, y1 = 0, y2 = 0, xCross = 0, yCross = 0,  strIndex;		//tow points of line
int winWidth = 400, winHeight = 300;	//windows size
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
	//display function
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f);
    //out put mouse coordinate


	if(iPointNum >= 1)          //if two points have been defined
	{
		//than draw the line
        glColor3f(0.0f, 0.0f, 0.0f);
		glBegin(GL_LINES);
			glVertex2i(x1, y1);
			glVertex2i(x2, y2);
		glEnd();
        glColor3f(1.0f, 0.0f, 0.0f);
        if(iPointNum == 1)
            glRectd(xCross-5,yCross+5, xCross+5, yCross-5);
        if(iPointNum == 2)
        {
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
			x1 = xMouse;
			y1 = winHeight - yMouse;
			iPointNum = 1;		//	First point of line have been defined
		}
		else		//first point have been defined, draw a line based on second line
		{
			x2 = xMouse;
			y2 = winHeight - yMouse;
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
	//wut's this for?
	if(iPointNum == 1)
	{
		x2 = xMouse;
		y2 = winHeight - yMouse;
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

















