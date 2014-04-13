#ifndef __CORNER_H__
#define __CORNER_H__

#include "part.h"

class Corner : public Part
{
public:
	Corner();
	~Corner();



private:
	double vertices[8]; // 4 - top, 4 - bottom
	
};

#endif