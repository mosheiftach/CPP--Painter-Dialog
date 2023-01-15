#include "pch.h"
#include "shapeDavidStar.h"
#include "stdafx.h"


IMPLEMENT_SERIAL(shapeDavidStar, shapeTriangle, 1)



void shapeDavidStar::draw(CDC& other)
{
	CPen pen(PS_SOLID, penSize, penColor);
	CBrush brush(backColor);
	CPen* oldPen = other.SelectObject(&pen);
	CBrush* oldBrush = other.SelectObject(&brush);
	this->setMidPoint((begin.x - (end.x - begin.x)), end.y);

	CPoint arr[3] = { begin,*(this->getMID()),end };

	other.Polygon(arr, 3);
	
	this->davidHeadPoint.x = begin.x;
	this->davidHeadPoint.y = (end.y +  (end.y-begin.y)/3);
	this->davidBottomPoint1.x = end.x;
	this->davidBottomPoint1.y = (begin.y+ (end.y - begin.y) / 3);
	this->davidBottomPoint2.x = (begin.x - ((end.x - begin.x)));
	this->davidBottomPoint2.y = (begin.y + (end.y - begin.y) / 3);

	CPoint arr2[3] = { davidHeadPoint,davidBottomPoint2,davidBottomPoint1 };

	other.Polygon(arr2, 3);

}

BOOL  shapeDavidStar::InArea(int x, int y) const
{

	int tempX = x - begin.x;
	int tempY = y - begin.y;

	

	bool CHECKER1 = (davidBottomPoint2.x - davidHeadPoint.x) * tempY - (davidBottomPoint2.y - davidHeadPoint.y) * tempX > 0;

	bool CHECKER = (getMIDVAL().x - begin.x) * tempY - (getMIDVAL().y - begin.y) * tempX > 0;

	if (((end.x - begin.x) * tempY - (end.y - begin.y) * tempX > 0 == CHECKER)&& ((davidBottomPoint1.x - davidHeadPoint.x) * tempY - (davidBottomPoint1.y - davidHeadPoint.y) * tempX > 0 == CHECKER1)) return FALSE;

	if (((end.x - getMIDVAL().x) * (y - getMIDVAL().y) - (end.y - getMIDVAL().y) * (x - getMIDVAL().x) > 0 != CHECKER)&& ((davidBottomPoint1.x - davidBottomPoint2.x) * (y - davidBottomPoint2.y) - (davidBottomPoint1.y - davidBottomPoint2.y) * (x - davidBottomPoint2.x) > 0 != CHECKER1)) return FALSE;



}

COLORREF shapeDavidStar::getPenColor()
{
	return this->penColor;
}

COLORREF shapeDavidStar::getBackColor()
{
	return this->backColor;
}