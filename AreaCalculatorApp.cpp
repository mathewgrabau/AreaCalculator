#include "AreaCalculatorApp.h"
#include "MainFrame.h"

BOOL CAreaCalculateApp::InitInstance()
{
	CMainFrame* pMainFrame = new CMainFrame();

	m_pMainWnd = pMainFrame;
	pMainFrame->ShowWindow(SW_SHOW);
	pMainFrame->UpdateWindow();

	return TRUE;
}
