#pragma once
#include "baseShape.h"
class shapeCircle :public baseShape
{
public:
	DECLARE_SERIAL(shapeCircle)
	shapeCircle() {}
	shapeCircle(CPoint &start, CPoint &finish);
	void draw(CDC& other);
	BOOL InArea(int x, int y) const;
	COLORREF getPenColor();
	COLORREF getBackColor();
};

