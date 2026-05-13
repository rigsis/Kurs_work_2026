#pragma once
#include "CGraph.h"
#include "Scale.h"
#include <vector>
#include "MyDraw.h"

// Диалоговое окно CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
	// Создание
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


	// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
protected:
	// graphik pan
	CGraph m_graph;
public:
	afx_msg void OnEnChangeEditPhi();
	double m_phi;

	//afx_msg void OnStnClickedEditPhi();




	//void CalcPoints();
	//size_t GetPoints(std::vector<CPoint>& vec);
	//std::vector<CPoint> m_vecPt;
	//CScale m_BackEnd;
public:
	// draw graph
	CMyDraw m_mydraw;
	CEdit m_EditA;
	afx_msg void OnEnChangeEditA();
	void CalcPoints();
	size_t GetPoints(std::vector<CPoint>& vec);
protected:
	CScale m_BackEnd;
	std::vector<CPoint> m_vecPt;
	double m_A;
	bool b_ready = false;
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
