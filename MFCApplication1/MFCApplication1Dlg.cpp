
// MFCApplication1Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "Resource.h" 


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	// Реализация
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


// Диалоговое окно CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT_PHI, &CMFCApplication1Dlg::OnEnChangeEditA)  // OnEnChangeEditPhi
	//ON_STN_CLICKED(IDC_EDIT_PHI, &CMFCApplication1Dlg::OnStnClickedEditPhi)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	SetWindowText(L"Курсовой расчет 5181");
	//m_graph.SubclassDlgItem(IDC_STATIC_GRAPH, this);  // IDC_STATIC_GRAPH - ID 
	m_mydraw.SubclassDlgItem(IDC_STATIC_GRAPH, this);
	m_EditA.SubclassDlgItem(IDC_EDIT_PHI, this);  // Привязка для поля фи (а)
	b_ready = true;

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCApplication1Dlg::OnBnClickedButton1()
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

/*

void CMFCApplication1Dlg::OnEnChangeEditPhi()
{
	UpdateData();
	double a = m_phi;
}
*/
/*
void CMFCApplication1Dlg::OnStnClickedEditPhi()
{
	// TODO: добавьте свой код обработчика уведомлений
}
*/


void CMFCApplication1Dlg::CalcPoints()
{

	

	m_vecPt.clear();
	CRect rc;

	m_mydraw.GetClientRect(&rc);
	m_BackEnd.SetWinPar(rc.Width(), rc.Height());
	m_BackEnd.CalcArgStep(rc.Width() - 2 * BORDER_W);
	m_BackEnd.GetPoints(m_vecPt, Par_s(m_A, 0));
}
// vvvvvvvvvvvv Для запроса точек из ф - ции рисования vvvvvvvvvvvvvvvv
size_t CMFCApplication1Dlg::GetPoints(std::vector<CPoint>&vec)
{
	vec = m_vecPt;
	return m_vecPt.size();
}

//vvvvvvvvvvvv Когда Dialog меняет размеры vvvvvvvvvvvvvvv
//в ресурсах свойства диалога дб изменяемые размеры
void CMFCApplication1Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	OnEnChangeEditA();
}

void CMFCApplication1Dlg::OnEnChangeEditA()
{
	if (!b_ready)
		return;
	//вариант без элемента Value-type привязанного к полю ввода 
	CString strA;
	m_EditA.GetWindowTextW(strA);
	m_A = _wtof(strA);

	//vvvvv Интерактивность vvvvvvv

	CalcPoints();// расчет новых точек тк A изменилось  

	// послать запрос на перерисовку окна графика OnPaint
	m_mydraw.RedrawWindow();

	//^^^ Интерактивность ^^^^^^^
}