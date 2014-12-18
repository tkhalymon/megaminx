#ifndef __FACE_H__
#define __FACE_H__

#include "center.h"
#include "edge.h"
#include "corner.h"

enum FaceTurnDir { Clockwise, CounterClockwise };

class Face
{
public:
	Face();
	void initEdge(Edge*, Edge*, Edge*, Edge*, Edge*);
	void initCorner(Corner*, Corner*, Corner*, Corner*, Corner*);
	void initCenter(Center*);
	void initAxis(int n);
	void initNum(int);
	~Face();

	bool render();
	void rotate(int);

	Corner *corner[5];
	Edge *edge[5];
	Center *center;

private:

	void placeParts(int dir);
	void swapCorners(int, int);
	void swapEdges(int, int);

	int turnDir;
	double _vertex[5][3];

	bool _rotate;
	double angle;
	double axis[3];
	int thisNum;
};

#endif