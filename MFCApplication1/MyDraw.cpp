#include "pch.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "MyDraw.h"



// CMyDraw

IMPLEMENT_DYNAMIC(CMyDraw, CStatic)

CMyDraw::CMyDraw()
{

}

CMyDraw::~CMyDraw()
{
}


BEGIN_MESSAGE_MAP(CMyDraw, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// обработчики сообщений CMyDraw




void CMyDraw::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CStatic::OnPaint() for painting messages
	CRect rc;
	GetClientRect(&rc);
	dc.FillSolidRect(&rc, RGB(111, 175, 223));
	CPen penO;
	penO.CreatePen(PS_SOLID, 1, RGB(111, 111, 111));
	HGDIOBJ po = dc.SelectObject(penO);
	dc.MoveTo(rc.left + BORDER_W, rc.CenterPoint().y);
	dc.LineTo(rc.right - BORDER_W, rc.CenterPoint().y);
	CPen penA;
	penA.CreatePen(PS_SOLID, 2, RGB(0, 0, 128));
	dc.MoveTo(rc.CenterPoint());
	dc.SelectObject(penA);
	//dc.LineTo(rc.right - BORDER_W, rc.CenterPoint().y-(rc.CenterPoint().x - BORDER_W)*tan(M_PI/6));

	dc.SetPixel(rc.CenterPoint(), RGB(200, 20, 30));

	CMFCApplication1Dlg* pMain = (CMFCApplication1Dlg*)AfxGetMainWnd();
	if (pMain)
	{
		std::vector<CPoint> vecP;
		size_t sz = pMain->GetPoints(vecP);
		if (sz)
		{
			dc.MoveTo(vecP[0]);
			for (auto Pt : vecP)
				dc.LineTo(Pt);
		}

	}

	dc.SelectObject(po);
}
