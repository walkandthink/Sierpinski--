#include <GL/glut.h>
#include <iostream>
using namespace std;

struct GLintPoint
{
	GLsizei x,y;
};

void drawDot(GLsizei x,GLsizei y)
{
	GLfloat f1,f2,f3;
	if (x>y)
	{
		f1=(GLfloat)y/(GLfloat)x;
		f2=f1*f1;
		f3=f2*f1;
	}
	else
	{
		f1=(GLfloat)x/(GLfloat)y;
		f2=f1*f1;
		f3=f2*f1;
	}
	glBegin(GL_POINTS);
	glColor3f(f2,f3,f1);
	glVertex2i(x,y);
	glEnd();
}

void Sierpinski_render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLintPoint T[3]={{10,10},{600,10},{300,480}};
	int index=rand()%3;
	GLintPoint point=T[index];
	drawDot(point.x,point.y);
	for (int i=0;i<55000;i++)
	{
		index=rand()%3;
		point.x=(point.x+T[index].x)/2;
		point.y=(point.y+T[index].y)/2;
		drawDot(point.x,point.y);
	}
	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}

int main(int argv,char *argc[])
{
	glutInit(&argv,argc);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(150,150);
	glutCreateWindow("Sierpinksin垫片");
	glutDisplayFunc(Sierpinski_render);
	init();
	glutMainLoop();
}
