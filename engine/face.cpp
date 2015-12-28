#include <GL/glut.h>
#include <math.h>
#include "face.h"
#include "utils.h"

#include <iostream>

const double FI = (1 + sqrt(5)) / 2;
const double PI = acos(-1);
const double SIDE_ANGLE = 2 * atan(FI);
const double INS_SPHERE_RAD = 100 * sqrt(10 + 22 / sqrt(5)) / 4;
const double INS_CIRCLE_RAD = 100 / sqrt((5 - sqrt(5)) / 2);

Face::Face()
{
	_rotate = false;
	angle = 0;
	axis[0] = 0;
	axis[1] = 0.001;
	axis[2] = -1;
}

void Face::initEdge(Edge *a, Edge *b, Edge *c, Edge *d, Edge *e)
{
	edge[0] = a;
	edge[1] = b;
	edge[2] = c;
	edge[3] = d;
	edge[4] = e;
}

void Face::initCorner(Corner *a, Corner *b, Corner *c, Corner *d, Corner *e)
{
	corner[0] = a;
	corner[1] = b;
	corner[2] = c;
	corner[3] = d;
	corner[4] = e;
}

void Face::initNum(int num)
{
	thisNum = num;
}

void Face::initCenter(Center *a)
{
	center = a;
	for (int i = 0; i < 5; ++i)
	{
		_vertex[i][0] = -INS_CIRCLE_RAD * cos(3 * PI / 10) + 100 / sin(2 * PI / 5) * 2 / 5;
		_vertex[i][1] = -INS_CIRCLE_RAD * sin(3 * PI / 10);
		_vertex[i][2] = -INS_SPHERE_RAD;
		rotateVertex(_vertex[i], 'z', 2  * PI / 5);
		rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
		rotateVertex(_vertex[i], 'z', 2 * i * PI / 5);
		_vertex[i][0] *= 1.02;
		_vertex[i][1] *= 1.02;
	}
}

void Face::initAxis(int n)
{
	switch (n + 1)
	{
	case 2:
		rotateVertex(axis, 'z', 2 * PI / 10);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		break;
	case 3:
		rotateVertex(axis, 'z', 2 * PI / 10);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		rotateVertex(axis, 'z', 2 * PI / 5);
		break;
	case 4:
		rotateVertex(axis, 'z', 2 * PI / 10);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		rotateVertex(axis, 'z', 4 * PI / 5);
		break;
	case 5:
		rotateVertex(axis, 'z', 2 * PI / 10);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		rotateVertex(axis, 'z', 6 * PI / 5);
		break;
	case 6:
		rotateVertex(axis, 'z', 2 * PI / 10);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		rotateVertex(axis, 'z', 8 * PI / 5);
		break;
	case 7:
		rotateVertex(axis, 'x', PI);
		break;
	case 8:
		rotateVertex(axis, 'y', PI);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		break;
	case 9:
		rotateVertex(axis, 'y', PI);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		rotateVertex(axis, 'z', 2 * PI / 5);
		break;
	case 10:
		rotateVertex(axis, 'y', PI);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		rotateVertex(axis, 'z', 4 * PI / 5);
		break;
	case 11:
		rotateVertex(axis, 'y', PI);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		rotateVertex(axis, 'z', 6 * PI / 5);
		break;
	case 12:
		rotateVertex(axis, 'y', PI);
		rotateVertex(axis, 'x', PI - SIDE_ANGLE);
		rotateVertex(axis, 'z', 8 * PI / 5);
		break;
	}
	for (int i = 0; i < 5; ++i)
	{

		switch (n + 1)
		{
		case 2:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			break;
		case 3:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 2 * PI / 5);
			break;
		case 4:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 4 * PI / 5);
			break;
		case 5:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 6 * PI / 5);
			break;
		case 6:
			rotateVertex(_vertex[i], 'z', 2 * PI / 10);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 8 * PI / 5);
			break;
		case 7:
			rotateVertex(_vertex[i], 'x', PI);
			break;
		case 8:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			break;
		case 9:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 2 * PI / 5);
			break;
		case 10:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 4 * PI / 5);
			break;
		case 11:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 6 * PI / 5);
			break;
		case 12:
			rotateVertex(_vertex[i], 'y', PI);
			rotateVertex(_vertex[i], 'x', PI - SIDE_ANGLE);
			rotateVertex(_vertex[i], 'z', 8 * PI / 5);
			break;
		}
	}
}

Face::~Face()
{

}

void Face::placeParts(int dir)
{
	if (dir == 1)
	{
		switch(thisNum)
		{
		case 0:
			swapCorners(0, 1);
			swapCorners(1, 2);
			swapCorners(2, 3);
			swapCorners(3, 4);
			swapEdges(0, 1);
			swapEdges(1, 2);
			swapEdges(2, 3);
			swapEdges(3, 4);
			break;
		case 1:
			corner[0]->flipBack();
			corner[1]->flipBack();
			corner[2]->flip();
			corner[4]->flip();
			swapCorners(4, 0);
			swapCorners(4, 2);
			swapCorners(0, 3);
			swapCorners(0, 1);
			swapEdges(4, 1);
			swapEdges(1, 3);
			swapEdges(0, 1);
			swapEdges(0, 2);
			edge[1]->flip();
			edge[2]->flip();
			break;
		case 2:
			edge[0]->flip();
			edge[3]->flip();
			swapEdges(1, 0);
			swapEdges(1, 2);
			swapEdges(1, 3);
			swapEdges(3, 4);
			corner[0]->flipBack();
			corner[1]->flipBack();
			corner[3]->flip();
			corner[4]->flip();
			swapCorners(0, 1);
			swapCorners(0, 2);
			swapCorners(2, 3);
			swapCorners(2, 4);
			break;
		case 3:
			swapEdges(3, 2);
			swapEdges(4, 3);
			swapEdges(0, 1);
			swapEdges(1, 2);
			edge[1]->flip();
			edge[2]->flip();
			swapCorners(3, 4);
			swapCorners(1, 3);
			swapCorners(1, 2);
			swapCorners(0, 1);
			corner[1]->flipBack();
			corner[2]->flip();
			corner[3]->flipBack();
			corner[4]->flip();
			break;
		case 4:
			swapEdges(0, 1);
			swapEdges(1, 2);
			swapEdges(1, 3);
			swapEdges(3, 4);

			edge[1]->flip();
			edge[2]->flip();

			swapCorners(0, 1);
			swapCorners(0, 3);
			swapCorners(0, 4);
			swapCorners(0, 2);
			corner[1]->flipBack();
			corner[2]->flip();
			corner[3]->flipBack();
			corner[4]->flip();
			break;
		case 5:
			swapEdges(2, 4);
			swapEdges(2, 3);
			swapEdges(0, 2);
			swapEdges(0, 1);
			edge[1]->flip();
			edge[2]->flip();
			swapCorners(1, 3);
			swapCorners(1, 4);
			swapCorners(1, 2);
			swapCorners(0, 1);
			corner[1]->flipBack();
			corner[2]->flip();
			corner[3]->flipBack();
			corner[4]->flip();
			break;
		case 6:
			swapCorners(0, 1);
			swapCorners(4, 0);
			swapCorners(3, 4);
			swapCorners(2, 3);
			swapEdges(0, 1);
			swapEdges(4, 0);
			swapEdges(3, 4);
			swapEdges(2, 3);
			break;
		case 7:
			swapEdges(0, 3);
			swapEdges(0, 4);
			swapEdges(0, 2);
			swapEdges(0, 1);
			edge[3]->flip();
			edge[4]->flip();
			swapCorners(0, 4);
			swapCorners(0, 2);
			swapCorners(0, 1);
			swapCorners(0, 3);
			corner[0]->flip();
			corner[1]->flipBack();
			corner[3]->flipBack();
			corner[4]->flip();
			break;
		case 8:
			swapEdges(0, 1);
			swapEdges(1, 2);
			swapEdges(2, 4);
			swapEdges(3, 4);
			edge[3]->flip();
			edge[4]->flip();
			swapCorners(0, 4);
			swapCorners(1, 4);
			swapCorners(1, 2);
			swapCorners(2, 3);
			corner[0]->flip();
			corner[1]->flipBack();
			corner[3]->flip();
			corner[4]->flipBack();
			break;
		case 9:
			swapEdges(0, 1);
			swapEdges(1, 2);
			swapEdges(2, 4);
			swapEdges(3, 4);
			edge[3]->flip();
			edge[4]->flip();
			swapCorners(0, 4);
			swapCorners(1, 4);
			swapCorners(1, 2);
			swapCorners(2, 3);
			corner[0]->flip();
			corner[1]->flipBack();
			corner[3]->flip();
			corner[4]->flipBack();
			break;
		case 10:
			swapEdges(0, 1);
			swapEdges(1, 3);
			swapEdges(3, 4);
			swapEdges(2, 4);
			edge[2]->flip();
			edge[4]->flip();
			swapCorners(0, 4);
			swapCorners(1, 4);
			swapCorners(1, 2);
			swapCorners(2, 3);
			corner[0]->flip();
			corner[1]->flipBack();
			corner[3]->flip();
			corner[4]->flipBack();
			break;
		case 11:
			swapEdges(0, 3);
			swapEdges(0, 4);
			swapEdges(0, 2);
			swapEdges(0, 1);
			edge[3]->flip();
			edge[4]->flip();
			swapCorners(0, 3);
			swapCorners(0, 1);
			swapCorners(0, 2);
			swapCorners(0, 4);
			corner[0]->flip();
			corner[2]->flipBack();
			corner[3]->flip();
			corner[4]->flipBack();
			break;
		}
	}
	else
	{
		switch (thisNum)
		{
		case 0:
			swapCorners(0, 1);
			swapCorners(4, 0);
			swapCorners(3, 4);
			swapCorners(2, 3);
			swapEdges(0, 1);
			swapEdges(4, 0);
			swapEdges(3, 4);
			swapEdges(2, 3);
			break;
		case 1:
			corner[0]->flip();
			corner[2]->flip();
			corner[3]->flipBack();
			corner[4]->flipBack();
			swapCorners(0, 1);
			swapCorners(0, 3);
			swapCorners(4, 2);
			swapCorners(4, 0);
			swapEdges(0, 2);
			swapEdges(0, 1);
			swapEdges(1, 3);
			swapEdges(4, 1);
			edge[0]->flip();
			edge[3]->flip();
			break;
		case 2:
			edge[1]->flip();
			edge[2]->flip();
			swapEdges(3, 4);
			swapEdges(1, 3);
			swapEdges(1, 2);
			swapEdges(1, 0);
			corner[1]->flip();
			corner[2]->flipBack();
			corner[3]->flip();
			corner[4]->flipBack();
			swapCorners(2, 4);
			swapCorners(2, 3);
			swapCorners(0, 2);
			swapCorners(0, 1);
			break;
		case 3:
			swapEdges(1, 2);
			swapEdges(0, 1);
			swapEdges(4, 3);
			swapEdges(3, 2);
			edge[0]->flip();
			edge[3]->flip();
			swapCorners(0, 1);
			swapCorners(1, 2);
			swapCorners(1, 3);
			swapCorners(3, 4);
			corner[0]->flip();
			corner[1]->flip();
			corner[3]->flipBack();
			corner[4]->flipBack();
			break;
		case 4:
			swapEdges(3, 4);
			swapEdges(1, 3);
			swapEdges(1, 2);
			swapEdges(0, 1);

			edge[0]->flip();
			edge[3]->flip();

			swapCorners(0, 2);
			swapCorners(0, 4);
			swapCorners(0, 3);
			swapCorners(0, 1);
			corner[0]->flip();
			corner[1]->flip();
			corner[3]->flipBack();
			corner[4]->flipBack();
			break;
		case 5:
			swapEdges(0, 1);
			swapEdges(0, 2);
			swapEdges(2, 3);
			swapEdges(2, 4);
			edge[3]->flip();
			edge[0]->flip();
			swapCorners(0, 1);
			swapCorners(1, 2);
			swapCorners(1, 4);
			swapCorners(1, 3);
			corner[0]->flip();
			corner[1]->flip();
			corner[3]->flipBack();
			corner[4]->flipBack();
			break;
		case 6:
			swapCorners(0, 1);
			swapCorners(1, 2);
			swapCorners(2, 3);
			swapCorners(3, 4);
			swapEdges(0, 1);
			swapEdges(1, 2);
			swapEdges(2, 3);
			swapEdges(3, 4);
			break;
		case 7:
			swapEdges(0, 1);
			swapEdges(0, 2);
			swapEdges(0, 4);
			swapEdges(0, 3);
			edge[0]->flip();
			edge[3]->flip();
			swapCorners(0, 3);
			swapCorners(0, 1);
			swapCorners(0, 2);
			swapCorners(0, 4);
			corner[0]->flipBack();
			corner[1]->flip();
			corner[2]->flip();
			corner[3]->flipBack();
			break;
		case 8:
			swapEdges(3, 4);
			swapEdges(2, 4);
			swapEdges(1, 2);
			swapEdges(0, 1);
			edge[0]->flip();
			edge[3]->flip();
			swapCorners(2, 3);
			swapCorners(1, 2);
			swapCorners(1, 4);
			swapCorners(0, 4);
			corner[0]->flipBack();
			corner[1]->flip();
			corner[2]->flip();
			corner[4]->flipBack();
			break;
		case 9:
			swapEdges(3, 4);
			swapEdges(2, 4);
			swapEdges(1, 2);
			swapEdges(0, 1);
			edge[0]->flip();
			edge[3]->flip();
			swapCorners(2, 3);
			swapCorners(1, 2);
			swapCorners(1, 4);
			swapCorners(0, 4);
			corner[0]->flipBack();
			corner[1]->flip();
			corner[2]->flip();
			corner[4]->flipBack();
			break;
		case 10:
			swapEdges(2, 4);
			swapEdges(3, 4);
			swapEdges(1, 3);
			swapEdges(0, 1);
			edge[0]->flip();
			edge[2]->flip();
			swapCorners(2, 3);
			swapCorners(1, 2);
			swapCorners(1, 4);
			swapCorners(0, 4);
			corner[0]->flipBack();
			corner[1]->flip();
			corner[2]->flip();
			corner[4]->flipBack();
			break;
		case 11:
			swapEdges(0, 1);
			swapEdges(0, 2);
			swapEdges(0, 4);
			swapEdges(0, 3);
			edge[0]->flip();
			edge[3]->flip();
			swapCorners(0, 4);
			swapCorners(0, 2);
			swapCorners(0, 1);
			swapCorners(0, 3);
			corner[0]->flipBack();
			corner[1]->flip();
			corner[2]->flip();
			corner[4]->flipBack();
			break;
		}
	}
}

bool Face::render()
{
	if (_rotate) angle += turnDir * 5;
	glPushMatrix();
	glRotated(angle, axis[0], axis[1], axis[2]);

	for (int i = 0; i < 5; ++i)
	{
		corner[i]->render();
		edge[i]->render();
	}
	center->render();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 5; ++i)
	{
		glVertex3dv(_vertex[i]);
	}
	glEnd();

	glPopMatrix();

	glBegin(GL_POLYGON);
	for (int i = 0; i < 5; ++i)
	{
		glVertex3dv(_vertex[i]);
	}
	glEnd();

	if (turnDir == 1)
	{
		if (angle >= 69)
		{
			angle = 0;
			_rotate = false;
			placeParts(1);
			return true;
		}
	}
	else
	{
		if (angle <= -69)
		{
			angle = 0;
			_rotate = false;
			placeParts(-1);
			return true;
		}
	}
	return false;
}

void Face::rotate(int _turnDir)
{
	_rotate = true;
	turnDir = _turnDir;
}

void Face::swapCorners(int n, int k)
{
	double buf;
	for (int i = 0; i < 9; ++i)
	{
		buf = corner[n]->color()[i];
		corner[n]->color()[i] = corner[k]->color()[i];
		corner[k]->color()[i] = buf;
	}
}

void Face::swapEdges(int n , int k)
{
	double buf;
	for (int i = 0; i < 6; ++i)
	{
		buf = edge[n]->color()[i];
		edge[n]->color()[i] = edge[k]->color()[i];
		edge[k]->color()[i] = buf;
	}
}