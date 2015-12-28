#include "megaminx.h"
#include <iostream>
#include <stdlib.h>

Megaminx::Megaminx()
{
	_rotate = false;
	n = 0;
	k = 0;
	
	for (int i = 0; i < 12; ++i)
	{
		face[i].initNum(i);
	}
	for (int i = 0; i < 12; ++i)
	{
		center[i].init(i);
	}
	for (int i = 0; i < 30; ++i)
	{
		edge[i].init(i);
	}
	for (int i = 0; i < 20; ++i)
	{
		corner[i].init(i);
	}

	face[0].initCenter(center);
	face[0].initEdge(edge, edge + 1, edge + 2, edge + 3, edge + 4);
	face[0].initCorner(corner, corner + 1, corner + 2, corner + 3, corner + 4);

	face[1].initCenter(center + 1);
	face[1].initEdge(edge + 0, edge + 5, edge + 9, edge + 10, edge + 15);
	face[1].initCorner(corner, corner + 4, corner + 5, corner + 9, corner + 17);

	face[2].initCenter(center + 2);
	face[2].initEdge(edge + 1, edge + 5, edge + 6, edge + 11, edge + 16);
	face[2].initCorner(corner, corner + 1, corner + 5, corner + 6, corner + 16);

	face[3].initCenter(center + 3);
	face[3].initEdge(edge + 2, edge + 6, edge + 7, edge + 12, edge + 17);
	face[3].initCorner(corner + 1, corner + 2, corner + 6, corner + 7, corner + 15);

	face[4].initCenter(center + 4);
	face[4].initEdge(edge + 3, edge + 7, edge + 8, edge + 13, edge + 18);
	face[4].initCorner(corner + 2, corner + 3, corner + 7, corner + 8, corner + 19);

	face[5].initCenter(center + 5);
	face[5].initEdge(edge + 4, edge + 8, edge + 9, edge + 14, edge + 19);
	face[5].initCorner(corner + 3, corner + 4, corner + 8, corner + 9, corner + 18);

	face[6].initCenter(center + 6);
	face[6].initEdge(edge + 25, edge + 26, edge + 27, edge + 28, edge + 29);
	face[6].initCorner(corner + 10, corner + 11, corner + 12, corner + 13, corner + 14);

	face[7].initCenter(center + 7);
	face[7].initEdge(edge + 13, edge + 17, edge + 21, edge + 22, edge + 25);
	face[7].initCorner(corner + 7, corner + 10, corner + 11, corner + 15, corner + 19);

	face[8].initCenter(center + 8);
	face[8].initEdge(edge + 14, edge + 18, edge + 22, edge + 23, edge + 26);
	face[8].initCorner(corner + 8, corner + 11, corner + 12, corner + 18, corner + 19);

	face[9].initCenter(center + 9);
	face[9].initEdge(edge + 10, edge + 19, edge + 23, edge + 24, edge + 27);
	face[9].initCorner(corner + 9, corner + 12, corner + 13, corner + 17, corner + 18);

	face[10].initCenter(center + 10);
	face[10].initEdge(edge + 11, edge + 15, edge + 20, edge + 24, edge + 28);
	face[10].initCorner(corner + 5, corner + 13, corner + 14, corner + 16, corner + 17);

	face[11].initCenter(center + 11);
	face[11].initEdge(edge + 12, edge + 16, edge + 20, edge + 21, edge + 29);
	face[11].initCorner(corner + 6, corner + 10, corner + 14, corner + 15, corner + 16);

	for (int i = 0; i < 12; ++i)
	{
		face[i].initAxis(i);
	}
}

Megaminx::~Megaminx()
{

}

void Megaminx::render()
{
	if (!_rotate)
	{
		for (int i = 0; i < 12; ++i)
		{
			center[i].render();
		}
		for (int i = 0; i < 30; ++i)
		{
			edge[i].render();
		}
		for (int i = 0; i < 20; ++i)
		{
			corner[i].render();
		}
	}
	else
	{
		int k = 0;
		for (int i = 0; i < 12; ++i)
		{
			if (&center[i] != face[rSide].center)
			{
				center[i].render();
			}
		}
		for (int i = 0; i < 30; ++i)
		{
			if (&edge[i] == face[rSide].edge[k])
			{
				k++;
			}
			else
			{
				edge[i].render();
			}
		}
		k = 0;
		for (int i = 0; i < 20; ++i)
		{
			if (&corner[i] == face[rSide].corner[k])
			{
				k++;
			}
			else
			{
				corner[i].render();
			}
		}
		if (face[rSide].render())
		{
			_rotate = false;
		}
	}
}

void Megaminx::rotate(int num, int dir)
{
	if (!_rotate)
	{
		_rotate = true;
		rSide = num;
		face[num].rotate(dir);
	}
}

void Megaminx::scramble()
{
	for (int i = 0; i < 50; ++i)
	{
		this->face[rand() % 12].placeParts(rand() % 2 * 2 - 1);
	}
}