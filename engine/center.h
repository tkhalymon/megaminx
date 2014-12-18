#ifndef __CENTER_H__
#define __CENTER_H__

class Center
{
public:
	Center();
	void init(int);
	void initColor(int);
	~Center();

	void render();

private:

	double _color[3];
	double _vertex[5][3];
};

#endif