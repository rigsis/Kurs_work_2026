#pragma once


// CMyDraw

class CMyDraw : public CStatic
{
	DECLARE_DYNAMIC(CMyDraw)

public:
	CMyDraw();
	virtual ~CMyDraw();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


