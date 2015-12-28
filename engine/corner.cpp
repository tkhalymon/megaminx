#include <GL/glut.h>
#include <math.h>
#include "corner.h"
#include "utils.h"

const double FI = (1 + sqrt(5)) / 2;
const double PI = acos(-1);
const double SIDE_ANGLE = 2 * atan(FI);
const double INS_SPHERE_RAD = 100 * sqrt(10 + 22 / sqrt(5)) / 4;
const double INS_CIRCLE_RAD = 100 / sqrt((5 - sqrt(5)) / 2);

Corner::Corner()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			_color[i][j] = 0.5;
		}
	}
		for (int i = 0; i < 7; ++i)
	{
		_vertex[i][2] = -INS_SPHERE_RAD;
	}

	_vertex[0][0] = INS_CIRCLE_RAD * cos(PI * 2 / 5 + 3 * PI / 10) / 5 * 2;
	_vertex[0][1] = INS_CIRCLE_RAD * sin(PI * 2 / 5 + 3 * PI / 10) / 5 * 2;

	_vertex[1][0] = INS_CIRCLE_RAD * cos(PI * 2 / 5 + 3 * PI / 10) + 100 / sin(2 * PI / 5) * 2 / 5;
	_vertex[1][1] = INS_CIRCLE_RAD * sin(PI * 2 / 5 + 3 * PI / 10);

	_vertex[2][0] = INS_CIRCLE_RAD * cos(PI * 2 / 5 + 3 * PI / 10);
	_vertex[2][1] = INS_CIRCLE_RAD * sin(PI * 2 / 5 + 3 * PI / 10);

	_vertex[3][0] = INS_CIRCLE_RAD * cos(3 * PI / 10) - 100 / sin(2 * PI / 5) * 2 / 5;
	_vertex[3][1] = INS_CIRCLE_RAD * sin(3 * PI / 10);
	rotateVertex(_vertex[3], 'z', PI * 2 / 5);
	
	_vertex[4][0] = INS_CIRCLE_RAD * cos(3 * PI / 10) / 5 * 2;
	_vertex[4][1] = INS_CIRCLE_RAD * sin(3 * PI / 10) / 5 * 2;
	rotateVertex(_vertex[4], 'z', -PI * 3 / 5);
	rotateVertex(_vertex[4], 'x', PI - SIDE_ANGLE);
	rotateVertex(_vertex[4], 'z', PI * 2 / 5);

	_vertex[5][0] = INS_CIRCLE_RAD * cos(3 * PI / 10) - 100 / sin(2 * PI / 5) * 2 / 5;
	_vertex[5][1] = INS_CIRCLE_RAD * sin(3 * PI / 10);
	rotateVertex(_vertex[5], 'z', -PI * 3 / 5);
	rotateVertex(_vertex[5], 'x', PI - SIDE_ANGLE);
	rotateVertex(_vertex[5], 'z', PI * 2 / 5);
	
	_vertex[6][0] = INS_CIRCLE_RAD * cos(3 * PI / 10) / 5 * 2;
	_vertex[6][1] = INS_CIRCLE_RAD * sin(3 * PI / 10) / 5 * 2;
	rotateVertex(_vertex[6], 'z', -PI * 5 / 5);
	rotateVertex(_vertex[6], 'x', PI - SIDE_ANGLE);
	
}


void Corner::init(int n)
{
	for (int i = 0; i < 7; ++i)
	{
		switch (n + 1)
		{
		case 1:
			initColor(1, 3, 2);
			break;
		case 2:
			rotateVertex(_vertex[i], 'z', 2 * PI / 5);
			initColor(1, 4, 3);
			break;
		case 3:
			rotateVertex(_vertex[i], 'z', 4 * PI / 5);
			initColor(1, 5, 4);
			break;
		case 4:
			rotateVertex(_vertex[i], 'z', 6 * PI / 5);
			initColor(1, 6, 5);
			break;
		case 5:
			rotateVertex(_vertex[i], 'z', 8 * PI / 5);
			initColor(1, 2, 6);
			break;
		case 6:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			initColor(2, 3, 11);
			break;
		case 7:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 2 * PI / 5);
			initColor(3, 4, 12);
			break;
		case 8:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 4 * PI / 5);
			initColor(4, 5, 8);
			break;
		case 9:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 6 * PI / 5);
			initColor(5, 6, 9);
			break;
		case 10:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 8 * PI / 5);
			initColor(6, 2, 10);
			break;
		case 11:
			rotateVertex(_vertex[i], 'x', PI);
			initColor(7, 12, 8);
			break;
		case 12:
			rotateVertex(_vertex[i], 'x', PI);
			rotateVertex(_vertex[i], 'z', 2 * PI / 5);
			initColor(7, 8, 9);
			break;
		case 13:
			rotateVertex(_vertex[i], 'x', PI);
			rotateVertex(_vertex[i], 'z', 4 * PI / 5);
			initColor(7, 9, 10);
			break;
		case 14:
			rotateVertex(_vertex[i], 'x', PI);
			rotateVertex(_vertex[i], 'z', 6 * PI / 5);
			initColor(7, 10, 11);
			break;
		case 15:
			rotateVertex(_vertex[i], 'x', PI);
			rotateVertex(_vertex[i], 'z', 8 * PI / 5);
			initColor(7, 11, 12);
			break;
		case 16:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'x', PI);
			initColor(8, 12, 4);
			break;
		case 17:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 2 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI);
			initColor(12, 11, 3);
			break;
		case 18:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 4 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI);
			initColor(11, 10, 2);
			break;
		case 19:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 6 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI);
			initColor(10, 9, 6);
			break;
		case 20:
			rotateVertex(_vertex[i], 'z', 1 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 8 * PI / 5);
			rotateVertex(_vertex[i], 'x', PI);
			initColor(9, 8, 5);
			break;
		}
	}
	inited = true;
}

void Corner::initColor(int a, int b, int c)
{
	for (int i = 0; i < 3; ++i)
	{
		int k;
		if (i == 0) k = a;
		if (i == 1) k = b;
		if (i == 2) k = c;

		switch (k)
		{
		case 1:
			_color[i][0] = 1.0;
			_color[i][1] = 1.0;
			_color[i][2] = 1.0;
			break;
		case 2:
			_color[i][0] = 0.0;
			_color[i][1] = 0.0;
			_color[i][2] = 1.0;
			break;
		case 3:
			_color[i][0] = 1.0;
			_color[i][1] = 0.0;
			_color[i][2] = 0.0;
			break;
		case 4:
			_color[i][0] = 0.0;
			_color[i][1] = 0.5;
			_color[i][2] = 0.0;
			break;
		case 5:
			_color[i][0] = 0.5;
			_color[i][1] = 0.0;
			_color[i][2] = 1.0;
			break;
		case 6:
			_color[i][0] = 1.0;
			_color[i][1] = 1.0;
			_color[i][2] = 0.0;
			break;
		case 7:
			_color[i][0] = 0.5;
			_color[i][1] = 0.5;
			_color[i][2] = 0.5;
			break;
		case 8:
			_color[i][0] = 0.2;
			_color[i][1] = 0.5;
			_color[i][2] = 1.0;
			break;
		case 9:
			_color[i][0] = 1.0;
			_color[i][1] = 0.4;
			_color[i][2] = 0.1;
			break;
		case 10:
			_color[i][0] = 0.3;
			_color[i][1] = 1.0;
			_color[i][2] = 0.3;
			break;
		case 11:
			_color[i][0] = 0.9;
			_color[i][1] = 0.4;
			_color[i][2] = 1.0;
			break;
		case 12:
			_color[i][0] = 1.0;
			_color[i][1] = 1.0;
			_color[i][2] = 0.3;
			break;
		}
	}
}

Corner::~Corner()
{

}

void Corner::render()
{
	if (turn)
	{
		glPushMatrix();
		glRotated(angle, axis[0], axis[1], axis[2]);
	}
	glColor3dv(_color[0]);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; ++i)
	{
		glVertex3dv(_vertex[i]);
	}
	glEnd();
	glColor3dv(_color[1]);
	glBegin(GL_POLYGON);
	for (int i = 2; i < 6; ++i)
	{
		glVertex3dv(_vertex[i]);
	}
	glEnd();
	glColor3dv(_color[2]);
	glBegin(GL_POLYGON);
	glVertex3dv(_vertex[2]);
	glVertex3dv(_vertex[5]);
	glVertex3dv(_vertex[6]);
	glVertex3dv(_vertex[1]);
	glEnd();

	glColor3d(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 4; ++i)
	{
		// glVertex3dv(_vertex[i]);
		glVertex3d(_vertex[i][0] * 1.005, _vertex[i][1] * 1.005, _vertex[i][2] * 1.005);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 2; i < 6; ++i)
	{
		// glVertex3dv(_vertex[i]);
		glVertex3d(_vertex[i][0] * 1.005, _vertex[i][1] * 1.005, _vertex[i][2] * 1.005);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	// glVertex3dv(_vertex[2]);
	// glVertex3dv(_vertex[5]);
	// glVertex3dv(_vertex[6]);
	// glVertex3dv(_vertex[1]);
	glVertex3d(_vertex[2][0] * 1.005, _vertex[2][1] * 1.005, _vertex[2][2] * 1.005);
	glVertex3d(_vertex[5][0] * 1.005, _vertex[5][1] * 1.005, _vertex[5][2] * 1.005);
	glVertex3d(_vertex[6][0] * 1.005, _vertex[6][1] * 1.005, _vertex[6][2] * 1.005);
	glVertex3d(_vertex[1][0] * 1.005, _vertex[1][1] * 1.005, _vertex[1][2] * 1.005);
	glEnd();
}

double* Corner::color()
{
	return &_color[0][0];
}

void Corner::flip()
{
	double buf[3];
	for (int i = 0; i < 3; ++i) buf[i] = _color[0][i];
	for (int i = 0; i < 3; ++i) _color[0][i] = _color[1][i];
	for (int i = 0; i < 3; ++i) _color[1][i] = buf[i];
	for (int i = 0; i < 3; ++i) buf[i] = _color[1][i];
	for (int i = 0; i < 3; ++i) _color[1][i] = _color[2][i];
	for (int i = 0; i < 3; ++i) _color[2][i] = buf[i];
}

void Corner::flipBack()
{
	flip();
	flip();
}