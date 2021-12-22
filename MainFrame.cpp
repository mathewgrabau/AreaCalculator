#include "MainFrame.h"

#define VALUE_RECT_WIDTH 120
#define VALUE_RECT_HORZ_SPACE 10
#define VALUE_RECT_HEIGHT 40
#define VALUE_RECT_LABEL_VERT_OFFSET 20

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

CMainFrame::CMainFrame()
{
	Create(NULL, _T("Area Calculator"), WS_OVERLAPPEDWINDOW, CRect(20, 30, 600, 400));

	mStringLength = _T("0");

	mPointLength = CPoint(10, 30);
	mRectLength = CRect(mPointLength, mPointLength + CPoint(VALUE_RECT_WIDTH, VALUE_RECT_HEIGHT));

	mPointWidth = CPoint(mRectLength.right + VALUE_RECT_HORZ_SPACE, 30);
	mRectWidth = CRect(mPointWidth, mPointWidth + CPoint(VALUE_RECT_WIDTH, VALUE_RECT_HEIGHT));

	mPointArea = CPoint(mRectWidth.right + VALUE_RECT_HORZ_SPACE, 30);
	mRectArea = CRect(mPointArea, mPointArea + CPoint(VALUE_RECT_WIDTH, VALUE_RECT_HEIGHT));

	mStringWidth = _T("0");
}

void CMainFrame::OnPaint()
{
	CPaintDC dc(this);

	// Draw empty rectangle
	dc.SelectStockObject(NULL_BRUSH);
	dc.Rectangle(mRectLength);
	dc.Rectangle(mRectWidth);
	dc.Rectangle(mRectArea);

	// Display rectangle captions
	dc.TextOut(mPointLength.x, mPointLength.y - VALUE_RECT_LABEL_VERT_OFFSET, _T("Length "));
	dc.TextOut(mPointWidth.x - 10, mPointLength.y - VALUE_RECT_LABEL_VERT_OFFSET, _T("* Width"));
	dc.TextOut(mPointArea.x - 10, mPointLength.y - VALUE_RECT_LABEL_VERT_OFFSET, _T("= Area"));
}


void CMainFrame::OnChar(UINT nChar, UINT nRep, UINT nFlags)
{
	TRACE(_T("Ascii code of char: %d\n"), nChar);

	switch (mStringActive)
	{
	case 'L':
		break;

	case 'W':
		break;

	default:
		break;
	}
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
}

