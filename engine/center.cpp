#include <GL/glut.h>
#include <math.h>
#include "center.h"
#include "utils.h"

const double FI = (1 + sqrt(5)) / 2;
const double PI = acos(-1);
const double SIDE_ANGLE = 2 * atan(FI);
const double INS_SPHERE_RAD = 100 * sqrt(10 + 22 / sqrt(5)) / 4;
const double INS_CIRCLE_RAD = 100 / sqrt((5 - sqrt(5)) / 2);

Center::Center()
{
	_color[0] = 1;
	_color[1] = 1;
	_color[2] = 1;

	_vertex[0][0] = INS_CIRCLE_RAD * cos(PI * 2 / 5 * 0 + 3 * PI / 10) / 5 * 2;
	_vertex[0][1] = INS_CIRCLE_RAD * sin(PI * 2 / 5 * 0 + 3 * PI / 10) / 5 * 2;

	_vertex[1][0] = INS_CIRCLE_RAD * cos(PI * 2 / 5 * 1 + 3 * PI / 10) / 5 * 2;
	_vertex[1][1] = INS_CIRCLE_RAD * sin(PI * 2 / 5 * 1 + 3 * PI / 10) / 5 * 2;

	_vertex[2][0] = INS_CIRCLE_RAD * cos(PI * 2 / 5 * 2 + 3 * PI / 10) / 5 * 2;
	_vertex[2][1] = INS_CIRCLE_RAD * sin(PI * 2 / 5 * 2 + 3 * PI / 10) / 5 * 2;

	_vertex[3][0] = INS_CIRCLE_RAD * cos(PI * 2 / 5 * 3 + 3 * PI / 10) / 5 * 2;
	_vertex[3][1] = INS_CIRCLE_RAD * sin(PI * 2 / 5 * 3 + 3 * PI / 10) / 5 * 2;

	_vertex[4][0] = INS_CIRCLE_RAD * cos(PI * 2 / 5 * 4 + 3 * PI / 10) / 5 * 2;
	_vertex[4][1] = INS_CIRCLE_RAD * sin(PI * 2 / 5 * 4 + 3 * PI / 10) / 5 * 2;

	for (int i = 0; i < 5; ++i)
	{
		_vertex[i][2] = -INS_SPHERE_RAD;
	}
}

void Center::init(int n)
{
	for (int i = 0; i < 5; ++i)
	{
		switch (n + 1)
		{
		case 1:
			initColor(1);
			break;
		case 2:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			initColor(2);
			break;
		case 3:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 2 * PI / 5);
			initColor(3);
			break;
		case 4:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 4 * PI / 5);
			initColor(4);
			break;
		case 5:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 6 * PI / 5);
			initColor(5);
			break;
		case 6:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 8 * PI / 5);
			initColor(6);
			break;
		case 7:
			rotateVertex(_vertex[i], 'x', PI);
			initColor(7);
			break;
		case 8:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			initColor(8);
			break;
		case 9:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 2 * PI / 5);
			initColor(9);
			break;
		case 10:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 4 * PI / 5);
			initColor(10);
			break;
		case 11:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 6 * PI / 5);
			initColor(11);
			break;
		case 12:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 8 * PI / 5);
			initColor(12);
			break;
		}
	}
}


void Center::initColor(int a)
{
	switch (a)
	{
	case 1:
		_color[0] = 1.0;
		_color[1] = 1.0;
		_color[2] = 1.0;
		break;
	case 2:
		_color[0] = 0.0;
		_color[1] = 0.0;
		_color[2] = 1.0;
		break;
	case 3:
		_color[0] = 1.0;
		_color[1] = 0.0;
		_color[2] = 0.0;
		break;
	case 4:
		_color[0] = 0.0;
		_color[1] = 0.5;
		_color[2] = 0.0;
		break;
	case 5:
		_color[0] = 0.5;
		_color[1] = 0.0;
		_color[2] = 1.0;
		break;
	case 6:
		_color[0] = 1.0;
		_color[1] = 1.0;
		_color[2] = 0.0;
		break;
	case 7:
		_color[0] = 0.5;
		_color[1] = 0.5;
		_color[2] = 0.5;
		break;
	case 8:
		_color[0] = 0.2;
		_color[1] = 0.5;
		_color[2] = 1.0;
		break;
	case 9:
		_color[0] = 1.0;
		_color[1] = 0.4;
		_color[2] = 0.1;
		break;
	case 10:
		_color[0] = 0.3;
		_color[1] = 1.0;
		_color[2] = 0.3;
		break;
	case 11:
		_color[0] = 0.9;
		_color[1] = 0.4;
		_color[2] = 1.0;
		break;
	case 12:
		_color[0] = 1.0;
		_color[1] = 1.0;
		_color[2] = 0.3;
		break;
	}
}

Center::~Center()
{

}

void Center::render()
{
	glColor3dv(_color);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 5; ++i)
	{
		glVertex3dv(_vertex[i]);
	}
	glEnd();
	glLineWidth(3);
	glColor3d(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 5; ++i)
	{
		glVertex3dv(_vertex[i]);
	}
	glEnd();
}