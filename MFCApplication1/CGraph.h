#pragma once
#include <afxwin.h>

class CGraph : public CStatic
{
	DECLARE_DYNAMIC(CGraph)

public:
	CGraph();
	virtual ~CGraph();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


