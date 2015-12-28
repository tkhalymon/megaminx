#ifndef __EDGE_H__
#define __EDGE_H__

class Edge
{
public:
	Edge();
	void init(int);
	void initColor(int, int);
	~Edge();

	void render();

	double* color();

	void flip();

private:

	double _color[2][3];
	double _vertex[6][3];
};

#endif 	