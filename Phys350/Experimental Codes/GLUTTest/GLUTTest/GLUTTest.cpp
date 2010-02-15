// GLUTTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <GL\glut.h>

void disp(void){}

void keyb(unsigned char key, int x, int y){}

int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(0,NULL);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);

	glutInitWindowSize(500,500);
	glutInitWindowPosition (100, 100);
	
	glutDisplayFunc(disp);
	glutKeyboardFunc(keyb);

	glutMainLoop();

	return 0;
}

