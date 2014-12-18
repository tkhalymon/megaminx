#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include "engine/megaminx.h"

Megaminx megaminx;

double viewAngle = 30;
double a = -250;
int activeWindow = 0;
	
bool paused = true;

double defN = 0;
double defK = 0;

double defMX, defMY;
int pressedButton;

void display();
void reshape();
void timer(int);
void mousePressed(int button, int state, int x, int y);
void mouseMove(int x, int y);
void mousePressedMove(int x, int y);
void keyboard(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);

const double FI = (1 + sqrt(5)) / 2;
const double PI = acos(-1);
const double SIDE_ANGLE = 2 * atan(FI);
const double INS_SPHERE_RAD = 90 * sqrt(10 + 22 / sqrt(5)) / 4 - 1;
const double INS_CIRCLE_RAD = 70 / sqrt((5 - sqrt(5)) / 2);

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	// int w = glutGet(GLUT_SCREEN_WIDTH) - 500;
	// int h = glutGet(GLUT_SCREEN_HEIGHT) - 200;
	int w = 500;
	int h = 500;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(w, h);
	glutCreateWindow("Megaminx v 1.0");
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluPerspective(viewAngle, (double)((double)w / (double)h), 1.0, 10000.0);
	glMatrixMode(GL_MODELVIEW);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutMouseFunc(mousePressed);
	glutPassiveMotionFunc(mouseMove);
	glutMotionFunc(mousePressedMove);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	// glutFullScreen();

	glTranslated(0, 0, -800);
	// glRotated(-90, 1, 0, 0);
	
	
	// glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// glutInitWindowSize(500, 20);
	// glutInitWindowPosition(65, 240);
	// glutCreateWindow("debug");
	// glClearColor(0.2, 0.2, 0.2, 1.0);
	// glLoadIdentity();
	// glMatrixMode(GL_PROJECTION);
	// glOrtho(-250, 250, -250, 250, -2000, 2000);
	// glMatrixMode(GL_MODELVIEW);
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// glutDisplayFunc(display);
	// glutTimerFunc(0, timer, 0);
	// glutMouseFunc(mousePressed);
	// glutPassiveMotionFunc(mouseMove);
	// glutMotionFunc(mousePressedMove);
	// glutKeyboardFunc(keyboard);
	// glutSpecialFunc(specialKeyboard);
	// glutSetWindow(1);

	glutMainLoop();
	return 0;
}

void reshape()
{
	int w = glutGet(GLUT_SCREEN_WIDTH) - 500;
	int h = glutGet(GLUT_SCREEN_HEIGHT) - 200;
	glutReshapeWindow(w, h);
	glLoadIdentity();
	// glMatrixMode(GL_PROJECTION);
	// gluPerspective(30, (double)((double)w / (double)h), 1.0, 10000.0);
	// glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA);
	glPointSize(5);
	
	// a++;
	// glBegin(GL_POINTS);
	// glVertex3d(-80, 0, 500);
	// glVertex3d(a, 0, 500);
	// glEnd();
	
	glPushMatrix();
	glRotated(megaminx.n, -1, 0, 0);
	glRotated(megaminx.k, 0, 0, 1);
	megaminx.render();
	glTranslated(0, 0, -100);
	glPopMatrix();
	glDisable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHT1);
	glutSwapBuffers();
}

// void display1()
// {
// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 	glEnable(GL_DEPTH_TEST);
// 	glEnable(GL_BLEND);
// 	glEnable(GL_ALPHA);
// 	glPointSize(5);
// 	glBegin(GL_POINTS);
// 		glVertex3d(atan(a / 250) * 500 / 6, 0, 500);
// 	glEnd();
// 	glPushMatrix();
// 	glTranslated(0, 0, -100);
// 	glPopMatrix();
// 	glDisable(GL_BLEND);
// 	glDisable(GL_DEPTH_TEST);
// 	glDisable(GL_LIGHT1);
// 	glutSwapBuffers();
// }

void timer(int)
{
	// glutSetWindow(2);
	// activeWindow = 2;
	glutPostRedisplay();
	// display1();
	// glutSetWindow(1);
	// activeWindow = 1;
	// display();
	glutTimerFunc(2, timer, 0);
}

void mousePressed(int button, int state, int x, int y)
{
	pressedButton = button;
	if (state == GLUT_DOWN)
	{
		defMX = x;
		defMY = y;
		defN = megaminx.n;
		defK = megaminx.k;
	}
}

void mouseMove(int x, int y)
{

}

void mousePressedMove(int x, int y)
{
	if (pressedButton == GLUT_RIGHT_BUTTON)
	{
		megaminx.n = defN + (defMY - y) / 3;
		if (megaminx.n > 180) megaminx.n = 180;
		if (megaminx.n < -180) megaminx.n = -180;
		megaminx.k = defK + (x - defMX) / 3;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		glutDestroyWindow(1);
		exit(0);
		break;
	case ' ':
		paused = !paused;
		break;
	}
}

void specialKeyboard(int key, int x, int y)
{
	int modif = glutGetModifiers();
	int dir;
	if (modif == 1)
	{
		dir = 1;
	}
	else
	{
		dir = -1;
	}
	switch (key)
	{
	case GLUT_KEY_UP:
		megaminx.n += 2;
		break;
	case GLUT_KEY_DOWN:
		megaminx.n -= 2;
		break;
	case GLUT_KEY_LEFT:
		megaminx.k -= 2;
		break;
	case GLUT_KEY_RIGHT:
		megaminx.k += 2;
		break;
	case GLUT_KEY_F1:
		megaminx.rotate(0, dir);
		break;
	case GLUT_KEY_F2:
		megaminx.rotate(1, dir);
		break;
	case GLUT_KEY_F3:
		megaminx.rotate(2, dir);
		break;
	case GLUT_KEY_F4:
		megaminx.rotate(3, dir);
		break;
	case GLUT_KEY_F5:
		megaminx.rotate(4, dir);
		break;
	case GLUT_KEY_F6:
		megaminx.rotate(5, dir);
		break;
	case GLUT_KEY_F7:
		megaminx.rotate(6, dir);
		break;
	case GLUT_KEY_F8:
		megaminx.rotate(7, dir);
		break;
	case GLUT_KEY_F9:
		megaminx.rotate(8, dir);
		break;
	case GLUT_KEY_F10:
		megaminx.rotate(9, dir);
		break;
	case GLUT_KEY_F11:
		megaminx.rotate(10, dir);
		break;
	case GLUT_KEY_F12:
		megaminx.rotate(11, dir);
		break;
	}
}