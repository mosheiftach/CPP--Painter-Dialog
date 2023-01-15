#pragma once
#include <cmath>
#include "stdafx.h"
class baseShape :public CObject
{
public:
	DECLARE_SERIAL(baseShape)
	baseShape();
	virtual ~baseShape();
	void setBegin(CPoint point);
	void setEnd(CPoint point);
	CPoint getBegin()const;
	CPoint getEnd()const;
	virtual void draw(CDC& other);
	virtual void clear(CDC& other);
	void setPenSize(int penS);
	virtual BOOL InArea(int, int) const;
	const baseShape& operator= (const baseShape&);
	int getPenSize();
	void setPenColor(COLORREF& color);
	void setBackColor(COLORREF& color);
	void Serialize(CArchive& ar);
	void setTYPEID(int ID);
	int getTYPEID() const;
	virtual COLORREF getPenColor();
	virtual COLORREF getBackColor();
	
protected:
	int typeID;
	int penSize;
	CPoint begin, end;
	COLORREF penColor;
	COLORREF backColor;
	
};

