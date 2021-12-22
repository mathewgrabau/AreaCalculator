#pragma once

#include <afxwin.h>

class CMainFrame : public CFrameWnd
{
private:
	CString mStringLength;
	CString mStringWidth;
	CString mStringArea;

	CPoint mPointLength;
	CPoint mPointWidth;
	CPoint mPointArea;

	CRect mRectLength;
	CRect mRectWidth;
	CRect mRectArea;

	char mCurrentString;	// Which string is currently active (L/W)

public:
	CMainFrame();

	// window message handlers
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT nChar, UINT nRep, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	DECLARE_MESSAGE_MAP();
};