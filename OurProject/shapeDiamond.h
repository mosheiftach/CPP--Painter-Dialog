#pragma once
#include "shapeTriangle.h"
class shapeDiamond :public shapeTriangle
{
public:
	DECLARE_SERIAL(shapeDiamond)
	void draw(CDC& other);
	BOOL InArea(int x, int y) const;
	COLORREF getPenColor();
	COLORREF getBackColor();
private:
	CPoint DBottomPoint1;
	CPoint DBottomPoint2;
	CPoint DHeadPoint;
};
