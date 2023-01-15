#include "pch.h"
#include "shapeTrapez.h"
#include "stdafx.h"


IMPLEMENT_SERIAL(shapeTrapez, shapeTriangle, 1)



void shapeTrapez::draw(CDC& dc)
{
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* oldBrush = dc.SelectObject(&brush);
	this->setMidPoint((begin.x - (end.x - begin.x)), end.y);

	this->topPoint.x = (this->getMID())->x;
	this->topPoint.y = begin.y;
	

	CPoint arr[4] = { begin,this->topPoint ,*(this->getMID()),end };

	
	dc.Polygon(arr, 4);

}

BOOL  shapeTrapez::InArea(int x, int y) const
{

//	// Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2
//
//	/*double tArea = ((this->begin.x * (this->midPoint.y - this->end.y) +
//		this->midPoint.x * (this->end.y - this->begin.y) +
//		this->end.x * (this->begin.y - this->midPoint.y)) / 2);
//
//	double tempCurrentPointArea = (((x * (this->midPoint.y - this->end.y) +
//		this->midPoint.x * (this->end.y - y) +
//		this->end.x * (y - this->midPoint.y)) / 2) +
//		((this->begin.x * (y - this->end.y) +
//			x * (this->end.y - this->begin.y) +
//			this->end.x * (this->begin.y - y)) / 2) +
//		((this->begin.x * (this->midPoint.y - y) +
//			this->midPoint.x * (y - this->begin.y) +
//			x * (this->begin.y - this->midPoint.y)) / 2));
//
//	if (tArea == tempCurrentPointArea)
//		return true;
//	else
//		return false;*/
//
//
	CRect temp;
	int tempX = x - begin.x;
	int tempY = y - begin.y;

	if (begin.x > getMIDVAL().x && end.y > begin.y)  temp.SetRect(getMIDVAL().x, begin.y, begin.x, end.y);
	else if (begin.x < getMIDVAL().x && end.y < begin.y)  temp.SetRect(begin.x, end.y, getMIDVAL().x, begin.y);
	else if (getMIDVAL().x <begin.x && begin.y> end.y) temp.SetRect(getMIDVAL().x, end.y, begin.x, begin.y);
	else if (getMIDVAL().x > begin.x && begin.y < end.y) temp.SetRect(begin.x, begin.y, getMIDVAL().x, end.y);
	CPoint point(x, y);

	if (temp.PtInRect(point) == true)
		return temp.PtInRect(point);

	bool CHECKER = (getMIDVAL().x - begin.x) * tempY - (getMIDVAL().y - begin.y) * tempX > 0;

	if ((end.x - begin.x) * tempY - (end.y - begin.y) * tempX > 0 == CHECKER) return FALSE;

	if ((end.x - getMIDVAL().x) * (y - getMIDVAL().y) - (end.y - getMIDVAL().y) * (x - getMIDVAL().x) > 0 != CHECKER) return FALSE;


	return TRUE;
}

COLORREF shapeTrapez::getPenColor()
{
	return this->penColor;
}

COLORREF shapeTrapez::getBackColor()
{
	return this->backColor;
}