#include "pch.h"
#include "shapeRectangle.h"
#include "stdafx.h"

IMPLEMENT_SERIAL(shapeRectangle, baseShape, 1)



void shapeRectangle::draw(CDC& dc)
{
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* oldBrush = dc.SelectObject(&brush);
	dc.Rectangle(begin.x, begin.y, end.x, end.y);

}

BOOL shapeRectangle::InArea(int x, int y) const
{

	CRect temp;
	if (end.x > begin.x && end.y > begin.y)  temp.SetRect(begin.x, begin.y, end.x, end.y);
	else if (end.x < begin.x && end.y < begin.y)  temp.SetRect(end.x, end.y, begin.x, begin.y);
	else if (begin.x <end.x && begin.y> end.y) temp.SetRect(begin.x, end.y, end.x, begin.y);
	else if (begin.x > end.x && begin.y < end.y) temp.SetRect(end.x, begin.y, begin.x, end.y);
	CPoint point(x, y);
	return temp.PtInRect(point);
}

COLORREF shapeRectangle::getPenColor()
{
	return this->penColor;
}

COLORREF shapeRectangle::getBackColor()
{
	return this->backColor;
}