#include "pch.h"
#include "shapeCircle.h"
#include "stdafx.h"


IMPLEMENT_SERIAL(shapeCircle, baseShape, 1)

shapeCircle::shapeCircle(CPoint& start, CPoint& finish)
{
	this->begin = start;
	this->end = finish;
}

void shapeCircle::draw(CDC& other)
{
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = other.SelectObject(&pen);
	CBrush* oldBrush = other.SelectObject(&brush);
	other.Ellipse(begin.x, begin.y, end.x, end.y);

}

BOOL shapeCircle::InArea(int x, int y) const
{
	double xRadius = (end.x - begin.x) / 2.0;
	double yRadius = (begin.y - end.y) / 2.0;
	double xCentre = begin.x + xRadius;
	double yCentre = end.y + yRadius;
	double result;
	result = pow((x - xCentre), 2.0) / pow(xRadius, 2.0) + pow(y - yCentre, 2.0) / pow(yRadius, 2.0);
	return  (BOOL)(result <= 1.0);
}


COLORREF shapeCircle::getPenColor()
{
	return this->penColor;
}

COLORREF shapeCircle::getBackColor()
{
	return this->backColor;
}