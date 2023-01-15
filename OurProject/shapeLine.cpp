#include "pch.h"
#include "shapeLine.h"
#include "stdafx.h"
IMPLEMENT_SERIAL(shapeLine, baseShape, 1)



void shapeLine::draw(CDC& dc)
{
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = dc.SelectObject(&pen);
	CBrush* oldBrush = dc.SelectObject(&brush);
	dc.MoveTo(begin.x, begin.y);
	dc.LineTo(end.x, end.y);

}

BOOL shapeLine::InArea(int x, int y) const
{
	float d1 = (float)((end.y - begin.y) * x - (end.x - begin.x) * y + (end.x * begin.y) - (end.y * begin.x));
	float d2 = (float)((end.y - begin.y) * (end.y - begin.y) + (end.x - begin.x) * (end.x - begin.x));
	float dist = abs(d1) / sqrt(d2);
	if ((dist <= 0 && dist >= -10) || (dist >= 0 && dist <= 10))
		return TRUE;

	return FALSE;
}

COLORREF shapeLine::getPenColor()
{
	return this->penColor;
}

COLORREF shapeLine::getBackColor()
{
	return this->backColor;
}