#pragma once
#include "baseShape.h"
class shapeTriangle :public baseShape
{
public:
	DECLARE_SERIAL(shapeTriangle)
	void draw(CDC& dc);
	BOOL InArea(int x, int y) const;
	void setMidPoint(double tempX,double tempY);
	CPoint * getMID();
	CPoint getMIDVAL() const;
    COLORREF getPenColor();
	COLORREF getBackColor();
private:
	CPoint midPoint;
};
