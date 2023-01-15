#pragma once
#include "baseShape.h"
class shapeRectangle :
    public baseShape
{
public:
	DECLARE_SERIAL(shapeRectangle)
	void draw(CDC& dc);
	BOOL InArea(int x, int y) const;
	COLORREF getPenColor();
	COLORREF getBackColor();
};

