#ifndef __CORNER_H__
#define __CORNER_H__

class Corner
{
public:
	Corner();
	void init(int);
	void initColor(int, int, int);
	~Corner();

	void render();

	double* color();
	void flip();
	void flipBack();

private:

	double _color[3][3];
	double _vertex[7][3];
	bool inited;
	bool turn;
	double angle;
	double axis[3];
};

#endif