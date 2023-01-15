#pragma once
#include "baseShape.h"
class shapeLine :
	public baseShape
{
public:
	DECLARE_SERIAL(shapeLine)
	void draw(CDC& dc);
	BOOL InArea(int x, int y) const;
	COLORREF getPenColor();
	COLORREF getBackColor();

};

