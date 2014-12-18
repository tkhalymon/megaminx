#include <math.h>
#include "utils.h"

void rotateVertex(double &vx, double &vy, double angle)
{
	static double PI = acos(-1);
	double r = sqrt(vx * vx + vy * vy);
	double a = vy > 0 ? acos(vx / r) : 2 * PI - acos(vx / r);
	a += angle;
	vx = r * cos(a);
	vy = r * sin(a);
}

void rotateVertex(double *vertex, char axis, double angle)
{
	switch (axis)
	{
	case 'x':
		rotateVertex(vertex[1], vertex[2], angle);
		break;
	case 'y':
		rotateVertex(vertex[0], vertex[2], angle);
		break;
	case 'z':
		rotateVertex(vertex[0], vertex[1], angle);
		break;
	}
}