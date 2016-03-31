#include "opengl.c"

int main(int argc, char const *argv[])
{
	glDepthRange(0,1);
	glViewPort(0,0,2,2);
	glMatrixMode(MODELVIEW);
	glLoadIdentity();
	glMatrixMode(PROJECTION);
	glLoadIdentity();
	glTranslated(100, 100, 100);
	glScaled(10, 10, 10);
	glBegin(GL_LINES);
		//point1---------------
		glVertex2ui(500,500);
		glVertex2ui(500,1000);
		//---------------------
		//point2---------------
		glVertex2ui(60,70);
		glVertex2ui(499,300);
		//---------------------
		//point3---------------
		glVertex2ui(0,600);
		glVertex2ui(800,600);
		//---------------------
		//point6---------------
		glVertex2ui(20, 30);
		glVertex2ui(100,1500);
		//---------------------
		//point4---------------
		glVertex2ui(10,2);
		glVertex2ui(800,757);
		//---------------------
		//point5---------------
		glVertex2ui(1000,1000);
		glVertex2ui(800,300);
		//---------------------
		//point5---------------
		glVertex2ui(0,0);
		glVertex2ui(50,50);
		//---------------------
	glEnd();
	return 0;
}