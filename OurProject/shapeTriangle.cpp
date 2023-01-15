#include "pch.h"
#include "shapeTriangle.h"
#include "stdafx.h"


IMPLEMENT_SERIAL(shapeTriangle, baseShape, 1)



void shapeTriangle::draw(CDC& dc)
{
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* oldBrush = dc.SelectObject(&brush);
	midPoint.y = end.y;
	midPoint.x = begin.x - (end.x - begin.x);

	CPoint arr[3] = { begin,midPoint,end };

	dc.Polygon(arr, 3);

	
}

BOOL  shapeTriangle::InArea(int x, int y) const
{

	// Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2

	//double tArea = ((this->begin.x * (this->midPoint.y - this->end.y) +
	//	this->midPoint.x * (this->end.y - this->begin.y) + 
	//	this->end.x * (this->begin.y - this->midPoint.y)) / 2);

	//double tempCurrentPointArea= (((x * (this->midPoint.y - this->end.y) +
	//	this->midPoint.x * (this->end.y - y) +
	//	this->end.x * (y - this->midPoint.y)) / 2)+
	//	((this->begin.x * (y - this->end.y) +
	//		x * (this->end.y - this->begin.y) +
	//		this->end.x * (this->begin.y - y)) / 2)+
	//	((this->begin.x * (this->midPoint.y - y) +
	//		this->midPoint.x * (y - this->begin.y) +
	//		x * (this->begin.y - this->midPoint.y)) / 2));

	//if (tArea == tempCurrentPointArea)
	//	return true;
	//else
	//	return false;

	
	int tempX = x - begin.x;
	int tempY = y - begin.y;

	bool CHECKER = (midPoint.x - begin.x) * tempY - (midPoint.y - begin.y) * tempX > 0;

	if ((end.x - begin.x) * tempY - (end.y - begin.y) * tempX > 0 == CHECKER) return FALSE;

	if ((end.x - midPoint.x) * (y - midPoint.y) - (end.y - midPoint.y) * (x - midPoint.x) > 0 != CHECKER) return FALSE;

	return TRUE;
}

void shapeTriangle::setMidPoint(double tempX, double tempY)
{
	this->midPoint.x = tempX;
	this->midPoint.y = tempY;
}

CPoint* shapeTriangle::getMID()
{
	return (&this->midPoint);
}

CPoint shapeTriangle::getMIDVAL() const
{
	return this->midPoint;
}

COLORREF shapeTriangle::getPenColor()
{
	return this->penColor;
}

COLORREF shapeTriangle::getBackColor()
{
	return this->backColor;
}