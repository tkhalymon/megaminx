#include <GL/glut.h>

void initGLUT(int argc, char** argv);
void display();
void timer(int);
void mousePressed(int button, int state, int x, int y);
void mouseMove(int x, int y);
void mousePressedMove(int x, int y);
void keyboard(unsigned char key, int x, int y);
void specialKeyboard(int key, int x, int y);

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	int w = glutGet(GLUT_SCREEN_WIDTH);
	int h = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowSize(w, h);
	glutCreateWindow("Megaminx v 0.1");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glLoadIdentity();
	gluPerspective(30, (double)((double)w / (double)h), 1, 10000);
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
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslated(0, 0, -1000);

	glColor3d(1, 1, 1);
	glutSolidSphere(200, 100, 100);

	glPopMatrix();

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
	switch(key)
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

void initGLUT(int argc, char** argv)
{
	
}
