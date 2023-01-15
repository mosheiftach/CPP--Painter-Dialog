
// OurProjectDlg.h : header file
//

#pragma once
#include "baseShape.h"
#include <stack>

// COurProjectDlg dialog
class COurProjectDlg : public CDialogEx
{
// Construction
	void drawAllShapes(CDC& other);
public:
	COurProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OURPROJECT_DIALOG };
#endif
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
private:
	CTypedPtrArray< CObArray, baseShape*> shapes,undoRedo;
	baseShape* currentShape;
	bool isPressed;
	int selectedShape;
	int penSize;
	bool _clearPageChecker;
	bool _isRclickPressed;
	CPoint rClickPoint;
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	COLORREF selectCOLOR1;
	COLORREF selectCOLOR2;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	BOOL _isRectangleChecked;
	BOOL _isTriangleChecked;
	BOOL _isCircleChecked;
	BOOL _isLineChecked;
	afx_msg void OnBnClickedCheck5();
	BOOL _isDavidStarChecked;
	afx_msg void OnBnClickedCheck6();
	BOOL _isDiamondChecked;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	//afx_msg void OnBnClickedRadio1();
	//BOOL _isPenSizeSmallChecked;
	afx_msg void OnBnClickedCheck7();
	BOOL isPenSizeSmallChecked;
	afx_msg void OnBnClickedCheck8();
	BOOL _isPenSizeMediumChecked;
	afx_msg void OnBnClickedCheck9();
	BOOL _isPenSizeLargeChecked;
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck12();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck14();
	BOOL _isWhitePenChecked;
	BOOL _isBlackPenChecked;
	BOOL _isRedPenChecked;
	BOOL _isGreenPenCHecked;
	BOOL _isBluePenCHecked;
	afx_msg void OnBnClickedCheck15();
	afx_msg void OnBnClickedCheck16();
	afx_msg void OnBnClickedCheck17();
	afx_msg void OnBnClickedCheck18();
	afx_msg void OnBnClickedCheck19();
	BOOL _isBrushWhiteChecked;
	BOOL _isBrushBlackChecked;
	BOOL _isBrushRedChecked;
	BOOL _isBrushGreenChecked;
	BOOL _isBrushBlueChecked;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedCheck20();
	BOOL _isNintyDegreeTrapezChecked;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
};
