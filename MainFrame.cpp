#include "MainFrame.h"

#define VALUE_RECT_WIDTH 120
#define VALUE_RECT_HORZ_SPACE 10
#define VALUE_RECT_HEIGHT 40
#define VALUE_RECT_LABEL_VERT_OFFSET 20
#define VALUE_PADDING 2

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

	mStringWidth = _T("0");
	mPointWidth = CPoint(mRectLength.right + VALUE_RECT_HORZ_SPACE, 30);
	mRectWidth = CRect(mPointWidth, mPointWidth + CPoint(VALUE_RECT_WIDTH, VALUE_RECT_HEIGHT));

	mStringArea = _T("click for result");
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

	// Values
	dc.TextOut(mPointLength.x + VALUE_PADDING, mPointLength.y + VALUE_PADDING, mStringLength);
	dc.TextOut(mPointWidth.x + VALUE_PADDING, mPointWidth.y + VALUE_PADDING, mStringWidth);
	dc.TextOut(mPointArea.x + VALUE_PADDING, mPointArea.y + VALUE_PADDING, mStringArea);
}


void CMainFrame::OnChar(UINT nChar, UINT nRep, UINT nFlags)
{
	TRACE(_T("Ascii code of char: %d\n"), nChar);

	switch (mCurrentString)
	{
	case 'L':
		mStringLength = mStringLength + (char)nChar;
		break;

	case 'W':
		mStringWidth = mStringWidth + (char)nChar;
		break;

	default:
		break;
	}

	Invalidate();
}

void CMainFrame::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (mRectLength.PtInRect(point))
	{
		mStringLength = "";
		mCurrentString = 'L';
		mStringArea = "click for result";
	}

	if (mRectWidth.PtInRect(point))
	{
		mStringWidth = "";
		mCurrentString = 'W';
		mStringArea = "click for result";
	}

	if (mRectArea.PtInRect(point))
	{
		// Note we need to use the _t variants of these functions.
		double area = _ttof(mStringLength) * _ttof(mStringWidth);
		mStringArea.Format(_T("%10.3f"), area);
		mCurrentString = 'A';
	}

	Invalidate();
}

