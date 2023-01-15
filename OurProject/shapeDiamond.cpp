#include "pch.h"
#include "shapeDiamond.h"

#include "stdafx.h"


IMPLEMENT_SERIAL(shapeDiamond, shapeTriangle, 1)



void shapeDiamond::draw(CDC& other)
{

	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = other.SelectObject(&pen);
	CBrush* oldBrush = other.SelectObject(&brush);
	this->setMidPoint((begin.x - (end.x - begin.x)), end.y);

	CPoint arr[3] = { begin,*(this->getMID()),end };

	other.Polygon(arr, 3);

	this->DHeadPoint.x = begin.x;
	this->DHeadPoint.y = (end.y + (end.y - begin.y));
	this->DBottomPoint1.x = end.x;
	this->DBottomPoint1.y = end.y;//(begin.y + (end.y - begin.y));
	this->DBottomPoint2.x = this->getMIDVAL().x;//(begin.x - ((end.x - begin.x)));
	this->DBottomPoint2.y = this->getMIDVAL().y;//(begin.y + (end.y - begin.y));

	CPoint arr2[3] = { DHeadPoint,DBottomPoint2,DBottomPoint1 };

	other.Polygon(arr2, 3);

}

BOOL  shapeDiamond::InArea(int x, int y) const
{
	int tempX = x - begin.x;
	int tempY = y - begin.y;

	bool CHECKER2 = (getMIDVAL().x - DHeadPoint.x) * (y - DHeadPoint.y) - (getMIDVAL().y - DHeadPoint.y) * (x - DHeadPoint.x) > 0;
	bool CHECKER = (getMIDVAL().x - begin.x) * tempY - (getMIDVAL().y - begin.y) * tempX > 0;

	if (((end.x - begin.x) * tempY - (end.y - begin.y) * tempX > 0 == CHECKER) || ((end.x - DHeadPoint.x) * (y - DHeadPoint.y) - (end.y - DHeadPoint.y) * (x - DHeadPoint.x) > 0 == CHECKER2)) return FALSE;

	if (((end.x - getMIDVAL().x) * (y - getMIDVAL().y) - (end.y - getMIDVAL().y) * (x - getMIDVAL().x) > 0 != CHECKER)&& ((end.x - getMIDVAL().x) * (y - getMIDVAL().y) - (end.y - getMIDVAL().y) * (x - getMIDVAL().x) > 0 != CHECKER2)) return FALSE;

	return TRUE;
}

COLORREF shapeDiamond::getPenColor()
{
	return this->penColor;
}

COLORREF shapeDiamond::getBackColor()
{
	return this->backColor;
}