
// OurProjectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "OurProject.h"
#include "OurProjectDlg.h"
#include "afxdialogex.h"
#include "shapeCircle.h"
#include "baseShape.h"
#include "shapeLine.h"
#include "shapeRectangle.h"
#include "shapeTriangle.h"
#include "shapeDavidStar.h"
#include "shapeDiamond.h"
#include "shapeTrapez.h"
#include <typeinfo>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// COurProjectDlg dialog



COurProjectDlg::COurProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OURPROJECT_DIALOG, pParent)
	, isPressed(FALSE)
	, currentShape(NULL)
	, selectedShape(-1)
	, penSize(3)
	, selectCOLOR1(RGB(255, 255, 255))
	, selectCOLOR2(RGB(0, 0, 0))
	, _isRectangleChecked(FALSE)
	, _isTriangleChecked(FALSE)
	, _isCircleChecked(FALSE)
	, _isLineChecked(FALSE)
	, _isDavidStarChecked(FALSE)
	, _isDiamondChecked(FALSE)
	, _clearPageChecker(FALSE)
	//, _isPenSizeSmallChecked(FALSE)
	, isPenSizeSmallChecked(FALSE)
	, _isPenSizeMediumChecked(FALSE)
	, _isPenSizeLargeChecked(FALSE)
	, _isWhitePenChecked(FALSE)
	, _isBlackPenChecked(FALSE)
	, _isRedPenChecked(FALSE)
	, _isGreenPenCHecked(FALSE)
	, _isBluePenCHecked(FALSE)
	, _isBrushWhiteChecked(FALSE)
	, _isBrushBlackChecked(FALSE)
	, _isBrushRedChecked(FALSE)
	, _isBrushGreenChecked(FALSE)
	, _isBrushBlueChecked(FALSE)
	, _isNintyDegreeTrapezChecked(FALSE)
	, _isRclickPressed(FALSE)
	, rClickPoint(0, 0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void COurProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK4, _isRectangleChecked);
	DDX_Check(pDX, IDC_CHECK3, _isTriangleChecked);
	DDX_Check(pDX, IDC_CHECK2, _isCircleChecked);
	DDX_Check(pDX, IDC_CHECK1, _isLineChecked);
	DDX_Check(pDX, IDC_CHECK5, _isDavidStarChecked);
	DDX_Check(pDX, IDC_CHECK6, _isDiamondChecked);
	DDX_Check(pDX, IDC_CHECK7, isPenSizeSmallChecked);
	DDX_Check(pDX, IDC_CHECK8, _isPenSizeMediumChecked);
	DDX_Check(pDX, IDC_CHECK9, _isPenSizeLargeChecked);
	//DDX_Radio(pDX, IDC_RADIO1, _isPenSizeSmallChecked);

	DDX_Check(pDX, IDC_CHECK10, _isWhitePenChecked);
	DDX_Check(pDX, IDC_CHECK11, _isBlackPenChecked);
	DDX_Check(pDX, IDC_CHECK12, _isRedPenChecked);
	DDX_Check(pDX, IDC_CHECK13, _isGreenPenCHecked);
	DDX_Check(pDX, IDC_CHECK14, _isBluePenCHecked);
	DDX_Check(pDX, IDC_CHECK15, _isBrushWhiteChecked);
	DDX_Check(pDX, IDC_CHECK16, _isBrushBlackChecked);
	DDX_Check(pDX, IDC_CHECK17, _isBrushRedChecked);
	DDX_Check(pDX, IDC_CHECK18, _isBrushGreenChecked);
	DDX_Check(pDX, IDC_CHECK19, _isBrushBlueChecked);
	DDX_Check(pDX, IDC_CHECK20, _isNintyDegreeTrapezChecked);
}

BEGIN_MESSAGE_MAP(COurProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_CHECK2, &COurProjectDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK1, &COurProjectDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK3, &COurProjectDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &COurProjectDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &COurProjectDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &COurProjectDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_BUTTON1, &COurProjectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &COurProjectDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &COurProjectDlg::OnBnClickedButton3)
	//ON_BN_CLICKED(IDC_RADIO1, &COurProjectDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_CHECK7, &COurProjectDlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &COurProjectDlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &COurProjectDlg::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &COurProjectDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &COurProjectDlg::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK12, &COurProjectDlg::OnBnClickedCheck12)
	ON_BN_CLICKED(IDC_CHECK13, &COurProjectDlg::OnBnClickedCheck13)
	ON_BN_CLICKED(IDC_CHECK14, &COurProjectDlg::OnBnClickedCheck14)
	ON_BN_CLICKED(IDC_CHECK15, &COurProjectDlg::OnBnClickedCheck15)
	ON_BN_CLICKED(IDC_CHECK16, &COurProjectDlg::OnBnClickedCheck16)
	ON_BN_CLICKED(IDC_CHECK17, &COurProjectDlg::OnBnClickedCheck17)
	ON_BN_CLICKED(IDC_CHECK18, &COurProjectDlg::OnBnClickedCheck18)
	ON_BN_CLICKED(IDC_CHECK19, &COurProjectDlg::OnBnClickedCheck19)
	ON_BN_CLICKED(IDC_BUTTON4, &COurProjectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &COurProjectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_CHECK20, &COurProjectDlg::OnBnClickedCheck20)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()


// COurProjectDlg message handlers

BOOL COurProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COurProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COurProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CDialogEx::OnPaint();
		if(this->_clearPageChecker==false)
		      drawAllShapes(dc);
		this->_clearPageChecker = false;
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COurProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COurProjectDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (selectedShape != (-1))
	{
		
			this->isPressed = TRUE;

		UpdateData(TRUE);
		switch (selectedShape)
		{
		case 0:
			currentShape = new shapeLine;
			break;
		case 1:
			currentShape = new shapeRectangle;
			break;
		case 2:
			currentShape = new shapeCircle;
			break;
		case 3:
			currentShape = new shapeTriangle;
			break;
		case 4:
			currentShape = new shapeDavidStar;
			break;
		case 5:
			currentShape = new shapeDiamond;
			break;
		case 6:
			currentShape = new shapeTrapez;
			break;
		}
		currentShape->setPenSize(penSize);
		currentShape->setPenColor(selectCOLOR1);
		currentShape->setBackColor(selectCOLOR2);
		currentShape->setTYPEID(selectedShape);

		currentShape->setBegin(CPoint(point.x, point.y));
		currentShape->setEnd(CPoint(point.x, point.y));
		isPressed = true;
	}

	CDialogEx::OnLButtonDown(nFlags, point);

	//CDialogEx::OnLButtonDown(nFlags, point);
}


void COurProjectDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (this->isPressed) {
		CClientDC dc(this);
		currentShape->setEnd(point);
		shapes.Add(currentShape);
		drawAllShapes(dc);
	}
	
	this->isPressed = FALSE;
	CDialogEx::OnLButtonUp(nFlags, point);

	//CDialogEx::OnLButtonUp(nFlags, point);
}

void COurProjectDlg::drawAllShapes(CDC& other)
{
	int max = shapes.GetCount();
	for (int i = 0; i < max; i++) {
		baseShape* tShape = shapes[i];
		tShape->draw(other);
	}
}

void COurProjectDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	
	if (this->isPressed) {
		//set the end point of the line to the point of the mouse
		CClientDC dc(this);
		currentShape->clear(dc);
		currentShape->setEnd(point);
		drawAllShapes(dc);
		currentShape->draw(dc);
		Invalidate();
	}
	if (_isRclickPressed)
	{
		CClientDC dc(this);
		double tempX;
		double tempY;
		
		tempX = point.x - rClickPoint.x;
		tempY = point.y - rClickPoint.y;
		CPoint TEMPend(currentShape->getEnd().x+tempX, currentShape->getEnd().y+ tempY);
		CPoint TEMPbegin(currentShape->getBegin().x + tempX, currentShape->getBegin().y + tempY);
		currentShape->setEnd(TEMPend);
		currentShape->setBegin(TEMPbegin);
		drawAllShapes(dc);
		currentShape->draw(dc);
		rClickPoint = point;
		Invalidate();

	}
	CDialogEx::OnMouseMove(nFlags, point);
}

void COurProjectDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	this->selectedShape = 0;

	this->_isRectangleChecked = (FALSE);
	this->_isTriangleChecked = (FALSE);
	this->_isCircleChecked = (FALSE);
	this->_isLineChecked = (TRUE);
	this->_isDavidStarChecked = (FALSE);
	this->_isDiamondChecked = (FALSE);
	this->_isNintyDegreeTrapezChecked= (FALSE);

	UpdateData(false);

	//shapeLine
	
}

void COurProjectDlg::OnBnClickedCheck2()
{
	// TODO: Add your control notification handler code here
	this->selectedShape = 2;

	this->_isRectangleChecked = (FALSE);
	this->_isTriangleChecked = (FALSE);
	this->_isCircleChecked = (TRUE);
	this->_isLineChecked = (FALSE);
	this->_isDavidStarChecked = (FALSE);
	this->_isDiamondChecked = (FALSE);
	this->_isNintyDegreeTrapezChecked = (FALSE);

	UpdateData(false);

	//shapeCircle
}




void COurProjectDlg::OnBnClickedCheck3()
{
	// TODO: Add your control notification handler code here
	this->selectedShape = 3;
	this->_isRectangleChecked = (FALSE);
	this->_isTriangleChecked = (TRUE);
	this->_isCircleChecked = (FALSE);
	this->_isLineChecked = (FALSE);
	this->_isDavidStarChecked = (FALSE);
	this->_isDiamondChecked = (FALSE);
	this->_isNintyDegreeTrapezChecked = (FALSE);

	UpdateData(false);

	//shapeTriangle
}


void COurProjectDlg::OnBnClickedCheck4()
{
	// TODO: Add your control notification handler code here
	this->selectedShape = 1;

	this->_isRectangleChecked = (TRUE);
	this->_isTriangleChecked = (FALSE);
	this->_isCircleChecked = (FALSE);
	this->_isLineChecked = (FALSE);
	this->_isDavidStarChecked = (FALSE);
	this->_isDiamondChecked = (FALSE);
	this->_isNintyDegreeTrapezChecked = (FALSE);

	UpdateData(false);

	//shapeRectangle
}


void COurProjectDlg::OnBnClickedCheck5()
{
	// TODO: Add your control notification handler code here
	this->selectedShape = 4;

	this->_isRectangleChecked = (FALSE);
	this->_isTriangleChecked = (FALSE);
	this->_isCircleChecked = (FALSE);
	this->_isLineChecked = (FALSE);
	this->_isDavidStarChecked = (TRUE);
	this->_isDiamondChecked = (FALSE);
	this->_isNintyDegreeTrapezChecked = (FALSE);

	UpdateData(false);

	//shapeDavidStar

}


void COurProjectDlg::OnBnClickedCheck6()
{
	// TODO: Add your control notification handler code here

	this->selectedShape = 5;

	this->_isRectangleChecked = (FALSE);
	this->_isTriangleChecked = (FALSE);
	this->_isCircleChecked = (FALSE);
	this->_isLineChecked = (FALSE);
	this->_isDavidStarChecked = (FALSE);
	this->_isDiamondChecked = (TRUE);
	this->_isNintyDegreeTrapezChecked = (FALSE);

	UpdateData(false);

	//shapeDiamond
}


void COurProjectDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	const TCHAR czFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*.*)|*.*||");
	CFileDialog fDialog(FALSE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void COurProjectDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

	const TCHAR czFilter[] = _T("Shape files (*.shape)|*.shape|All Files (*.*)|*.*||");
	CFileDialog fDialog(TRUE, _T("shape"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, czFilter, this);

	if (fDialog.DoModal() == IDOK) {
		CString fileName = fDialog.GetPathName();
		CFile file(fileName, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		shapes.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void COurProjectDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	this->_clearPageChecker = true;
	shapes.RemoveAll();
	undoRedo.RemoveAll();
	Invalidate();
}

//
//void COurProjectDlg::OnBnClickedRadio1()
//{
//	this->penSize = 3;
//	// TODO: Add your control notification handler code here
//}


void COurProjectDlg::OnBnClickedCheck7()
{
	// TODO: Add your control notification handler code here
	this->penSize = 3;

	this->isPenSizeSmallChecked = (TRUE);
	this->_isPenSizeMediumChecked=(FALSE);
	this->_isPenSizeLargeChecked=(FALSE);

	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck8()
{
	// TODO: Add your control notification handler code here
	this->penSize = 9;
	this->isPenSizeSmallChecked = (FALSE);
	this->_isPenSizeMediumChecked = (TRUE);
	this->_isPenSizeLargeChecked = (FALSE);

	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck9()
{
	// TODO: Add your control notification handler code here
	this->penSize = 16;
	this->isPenSizeSmallChecked = (FALSE);
	this->_isPenSizeMediumChecked = (FALSE);
	this->_isPenSizeLargeChecked = (TRUE);

	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck10()
{
	this->_isWhitePenChecked = (TRUE);
	this->_isBlackPenChecked = (FALSE);
	this->_isRedPenChecked = (FALSE);
	this->_isGreenPenCHecked = (FALSE);
	this->_isBluePenCHecked = (FALSE);
	this->selectCOLOR1 = RGB(255, 255, 255);
	UpdateData(FALSE);
	// TODO: Add your control notification handler code here
}


void COurProjectDlg::OnBnClickedCheck11()
{
	// TODO: Add your control notification handler code here

	this->_isWhitePenChecked = (FALSE);
	this->_isBlackPenChecked = (TRUE);
	this->_isRedPenChecked = (FALSE);
	this->_isGreenPenCHecked = (FALSE);
	this->_isBluePenCHecked = (FALSE);
	this->selectCOLOR1 = RGB(0, 0, 0);
	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck12()
{
	// TODO: Add your control notification handler code here
	this->_isWhitePenChecked = (FALSE);
	this->_isBlackPenChecked = (FALSE);
	this->_isRedPenChecked = (TRUE);
	this->_isGreenPenCHecked = (FALSE);
	this->_isBluePenCHecked = (FALSE);
	this->selectCOLOR1 = RGB(255, 0, 0);
	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck13()
{
	// TODO: Add your control notification handler code here
	this->_isWhitePenChecked = (FALSE);
	this->_isBlackPenChecked = (FALSE);
	this->_isRedPenChecked = (FALSE);
	this->_isGreenPenCHecked = (TRUE);
	this->_isBluePenCHecked = (FALSE);
	this->selectCOLOR1 = RGB(0, 255, 0);
	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck14()
{
	// TODO: Add your control notification handler code here
	this->_isWhitePenChecked = (FALSE);
	this->_isBlackPenChecked = (FALSE);
	this->_isRedPenChecked = (FALSE);
	this->_isGreenPenCHecked = (FALSE);
	this->_isBluePenCHecked = (TRUE);
	this->selectCOLOR1 = RGB(0, 0, 255);
	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck15()
{
	// TODO: Add your control notification handler code here
	this->_isBrushWhiteChecked = (TRUE);
	this->_isBrushBlackChecked = (FALSE);
	this->_isBrushRedChecked = (FALSE);
	this->_isBrushGreenChecked = (FALSE);
	this->_isBrushBlueChecked = (FALSE);
	this->selectCOLOR2 = RGB(255, 255, 255);
	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck16()
{
	// TODO: Add your control notification handler code here
	this->_isBrushWhiteChecked = (FALSE);
	this->_isBrushBlackChecked = (TRUE);
	this->_isBrushRedChecked = (FALSE);
	this->_isBrushGreenChecked = (FALSE);
	this->_isBrushBlueChecked = (FALSE);
	this->selectCOLOR2 = RGB(0, 0, 0);
	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck17()
{
	// TODO: Add your control notification handler code here
	this->_isBrushWhiteChecked = (FALSE);
	this->_isBrushBlackChecked = (FALSE);
	this->_isBrushRedChecked = (TRUE);
	this->_isBrushGreenChecked = (FALSE);
	this->_isBrushBlueChecked = (FALSE);
	this->selectCOLOR2 = RGB(255, 0, 0);
	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck18()
{
	// TODO: Add your control notification handler code here
	this->_isBrushWhiteChecked = (FALSE);
	this->_isBrushBlackChecked = (FALSE);
	this->_isBrushRedChecked = (FALSE);
	this->_isBrushGreenChecked = (TRUE);
	this->_isBrushBlueChecked = (FALSE);
	this->selectCOLOR2 = RGB(0, 255, 0);
	UpdateData(FALSE);
}


void COurProjectDlg::OnBnClickedCheck19()
{
	// TODO: Add your control notification handler code here
	this->_isBrushWhiteChecked = (FALSE);
	this->_isBrushBlackChecked = (FALSE);
	this->_isBrushRedChecked = (FALSE);
	this->_isBrushGreenChecked = (FALSE);
	this->_isBrushBlueChecked = (TRUE);
	this->selectCOLOR2 = RGB(0, 0, 255);
	UpdateData(FALSE);
}




void COurProjectDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here

	if (shapes.GetSize() != 0)
	{
		undoRedo.Add(shapes[shapes.GetSize() - 1]);
		shapes.RemoveAt((shapes.GetSize() - 1));

		Invalidate();
	}
	else
		return;
}


void COurProjectDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	if (undoRedo.GetSize() != 0)
	{
		shapes.Add(undoRedo[undoRedo.GetSize() - 1]);
		undoRedo.RemoveAt((undoRedo.GetSize() - 1));
		Invalidate();
	}
	else
		return;
}


void COurProjectDlg::OnBnClickedCheck20()
{
	// TODO: Add your control notification handler code here

	this->selectedShape = 6;

	this->_isRectangleChecked = (FALSE);
	this->_isTriangleChecked = (FALSE);
	this->_isCircleChecked = (FALSE);
	this->_isLineChecked = (FALSE);
	this->_isDavidStarChecked = (FALSE);
	this->_isDiamondChecked = (FALSE);
	this->_isNintyDegreeTrapezChecked = (TRUE);

	UpdateData(false);

	//shape90Trapez
}


void COurProjectDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	for (int i = (shapes.GetSize()-1); i >= 0; i--)
	{
		if (shapes[i]->InArea(point.x, point.y))
		{
			this->rClickPoint = point;
			this->currentShape = shapes[i];
			_isRclickPressed = true;
			break;
		}

	}
	CDialogEx::OnRButtonDown(nFlags, point);
}


void COurProjectDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	_isRclickPressed = false;
	CDialogEx::OnRButtonUp(nFlags, point);
}


void COurProjectDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	for (int i = (shapes.GetSize() - 1); i >= 0; i--)
	{
		if (shapes[i]->InArea(point.x, point.y))
		{
			shapes.RemoveAt((shapes.GetSize() - 1));
			this->currentShape = shapes[i];
			this->currentShape->setPenColor(this->selectCOLOR1);
			this->currentShape->setBackColor(this->selectCOLOR2);
			this->currentShape->setPenSize(penSize);
			Invalidate();
			break;
		}
		
	}

	CDialogEx::OnLButtonDblClk(nFlags, point);
}




void COurProjectDlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	for (int i = (shapes.GetSize() - 1); i >= 0; i--)
	{
		if (shapes[i]->InArea(point.x, point.y))
		{
			switch (shapes[i]->getTYPEID())
			{
			case 0:
				currentShape = new shapeLine;
				break;
			case 1:
				currentShape = new shapeRectangle;
				break;
			case 2:
				currentShape = new shapeCircle;
				break;
			case 3:
				currentShape = new shapeTriangle;
				break;
			case 4:
				currentShape = new shapeDavidStar;
				break;
			case 5:
				currentShape = new shapeDiamond;
				break;
			case 6:
				currentShape = new shapeTrapez;
				break;
			}
			CPoint tempEND= shapes[i]->getEnd();
			CPoint tempBEGIN= shapes[i]->getBegin();

			COLORREF tempPen = shapes[i]->getPenColor();
			COLORREF tempBack= shapes[i]->getBackColor();
			tempEND.x += 8;
			tempEND.y += 8;
			tempBEGIN.x += 8;
			tempBEGIN.y += 8;
			this->currentShape->setEnd(tempEND);
			this->currentShape->setBegin(tempBEGIN);
			this->currentShape->setTYPEID(shapes[i]->getTYPEID());
			this->currentShape->setPenColor(tempPen);
			this->currentShape->setBackColor(tempBack);
			this->currentShape->setPenSize(shapes[i]->getPenSize());

			shapes.Add(this->currentShape);

			Invalidate();
			break;
		}

	}

	CDialogEx::OnRButtonDblClk(nFlags, point);
}
