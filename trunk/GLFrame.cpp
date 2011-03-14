/*********************************
*A basic openGL you need, you can add
*or delete any functions. 
**********************************/
//include
#include <iostream>
#include <GL/glut.h>

//display function
void display()
{
	//to do
	glutSwapBuffers();			//use double buffer
}

//timerFunction
//modify things that change by time
void timerFunction()
{
	//change values here
	glutPostRedisplay();
	glutTimerFunc(33,timerFunction,1);
}

//changeSize function
//call when window size changed
void changeSize(int w, int h)
{
	GLfloat aspectRatio;

	//prevent a divide by zero
	if(h==0)
		h = 1;
	//Set Viewport
	glViewport(0, 0, w, h);

	//reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Establish clipping voluem(left, right, bottom, top, near, far)
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if(w<=h)
		glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 * aspectRatio, 1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//menu
//optional

/*
void proessMenu(int value)
{
	switch( value )
	{
		case 1:
		........
	}
	glutPostRedisplay();
}
*/

//special keys
//optional
/*
void specialKeys( int key, int x, int y )
{
	if( key == ...)
	{
		......
	}
	glutPostRedisplay();
}
*/


int main( int argc, int **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode( | );
	glutCreateWindow("Name of window");
	glutDisplayFunc();
	glutReshapeFunc();
	SetupRC();

	glutMainLoop();

	return 0;
}



















