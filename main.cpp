#include <GL/glut.h>
#include <math.h>

void display();
void timer(int);
void mousePressed(int button, int state, int x, int y);
void mouseMove(int x, int y);
void mousePressedMove(int x, int y);
void keyboard(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);

const double FI = (1 + sqrt(5)) / 2;
const double PI = acos(-1);
const double SIDE_ANGLE = 2 * atan(FI);
const double INS_SPHERE_RAD = 100 * sqrt(10 + 22 / sqrt(5)) / 4;
const double INS_CIRCLE_RAD = 100 / sqrt((5 - sqrt(5)) / 2);

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(w, h);
	glutCreateWindow("Megaminx v 0.1");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	gluPerspective(30, (double)((double)w / (double)h), 1.0, 10000.0);
	glMatrixMode(GL_MODELVIEW);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutDisplayFunc(display);
	glutTimerFunc(20, timer, 0);
	glutMouseFunc(mousePressed);
	glutPassiveMotionFunc(mouseMove);
	glutMotionFunc(mousePressedMove);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutFullScreen();
	glTranslated(0, 0, -1000);
	glutMainLoop();
	return 0;
}

void drawSide()
{
	glBegin(GL_POLYGON);
	glVertex3d(INS_CIRCLE_RAD * cos(PI * 2 / 5 * 0 + PI / 2), INS_CIRCLE_RAD * sin(PI * 2 / 5 * 0 + PI / 2), INS_SPHERE_RAD);
	glVertex3d(INS_CIRCLE_RAD * cos(PI * 2 / 5 * 1 + PI / 2), INS_CIRCLE_RAD * sin(PI * 2 / 5 * 1 + PI / 2), INS_SPHERE_RAD);
	glVertex3d(INS_CIRCLE_RAD * cos(PI * 2 / 5 * 2 + PI / 2), INS_CIRCLE_RAD * sin(PI * 2 / 5 * 2 + PI / 2), INS_SPHERE_RAD);
	glVertex3d(INS_CIRCLE_RAD * cos(PI * 2 / 5 * 3 + PI / 2), INS_CIRCLE_RAD * sin(PI * 2 / 5 * 3 + PI / 2), INS_SPHERE_RAD);
	glVertex3d(INS_CIRCLE_RAD * cos(PI * 2 / 5 * 4 + PI / 2), INS_CIRCLE_RAD * sin(PI * 2 / 5 * 4 + PI / 2), INS_SPHERE_RAD);
	glEnd();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glRotated(1, 0, 1, 0);
	glColor3d(1, 1, 1);
	glPushMatrix();
	drawSide();
	glPopMatrix();
	glPushMatrix();
	glColor3d(1, 1, 0);
	glRotated(36, 0, 0, 1);
	glRotated(SIDE_ANGLE / PI * 180 - 180, 1, 0, 0);
	drawSide();
	glTranslated(0, 0, -100);
	glPopMatrix();
	glDisable(GL_DEPTH_TEST);
	glutSwapBuffers();
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(20, timer, 0);
}

void mousePressed(int button, int state, int x, int y)
{

}

void mouseMove(int x, int y)
{

}

void mousePressedMove(int x, int y)
{

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		glutDestroyWindow(1);
		exit(0);
		break;
	}
}

void specialKeyboard(int key, int x, int y)
{

}