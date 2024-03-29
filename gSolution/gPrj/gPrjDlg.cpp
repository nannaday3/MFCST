
// gPrjDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "gPrj.h"
#include "gPrjDlg.h"
#include "afxdialogex.h"

#include <iostream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CgPrjDlg 대화 상자



CgPrjDlg::CgPrjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GPRJ_DIALOG, pParent)
	, RAD(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgPrjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ED_RD, RAD);
}

BEGIN_MESSAGE_MAP(CgPrjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_TEST, &CgPrjDlg::OnBnClickedBtnTest)
END_MESSAGE_MAP()


// CgPrjDlg 메시지 처리기

BOOL CgPrjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	//ShowWindow(SW_SHOWMAXIMIZED);
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CgPrjDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CgPrjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CgPrjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CgPrjDlg::OnBnClickedBtnDlg()
//{
//	m_pDlgImage->ShowWindow(SW_SHOW);
//}


void CgPrjDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if(m_pDlgImage)		delete m_pDlgImage;
}

void CgPrjDlg::callFunc(int n)
{
	std::cout << n << std::endl;
}

void CgPrjDlg::OnBnClickedBtnTest()
{
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();
	int nPitch = m_pDlgImage->m_image.GetPitch();
	int color = 0;

	//m_pDlgImage->m_flag = TRUE;

	//unsigned char* yfm = (unsigned char*)m_pDlgImage->m_yimage.GetBits();
	//int nyWidth = m_pDlgImage->m_yimage.GetWidth();
	//int nyHeight = m_pDlgImage->m_yimage.GetHeight();
	//int nyPitch = m_pDlgImage->m_yimage.GetPitch();

	memset(fm, 0xff, nWidth*nHeight);

	m_pDlgImage->m_Rad = GetDlgItemInt(IDC_ED_RD);

	int x = m_pDlgImage->m_Rad +(rand() % (nWidth - m_pDlgImage->m_Rad*2-5));
	int y = m_pDlgImage->m_Rad +(rand() % (nHeight - m_pDlgImage->m_Rad*2-5));
	
	
	m_pDlgImage->m_ptData.x = x;
	m_pDlgImage->m_ptData.y = y;

	DrawCircle(fm, x - m_pDlgImage->m_Rad, y - m_pDlgImage->m_Rad, m_pDlgImage->m_Rad, color);

	color = 0xff;

	DrawCircle(fm, x - m_pDlgImage->m_Rad, y - m_pDlgImage->m_Rad, m_pDlgImage->m_Rad, color);

	m_pDlgImage->m_color = color;

	m_pDlgImage->Invalidate();



	Circenter(x, y, GetDlgItemInt(IDC_ED_RD));
}
using namespace std;
void CgPrjDlg::Circenter(int x, int y, int ED)
{
	cout << "반지름 : "<< ED << ",무게중심(" << x << "," << y << ")" << endl;
}

void CgPrjDlg::DrawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_pDlgImage->m_image.GetPitch();
	

	if (nGray == 0xff)
	{
		for (int j = y; j < y + nRadius * 2; j++) {
			for (int i = x; i < x + nRadius * 2; i++)
			{
				if (isInCircle(i, j, nCenterX, nCenterY, nRadius-1))
					fm[j * nPitch + i] = nGray;
			}
		}
		fm[nCenterY * nPitch + nCenterX] = 0;
		fm[(nCenterY-1) * nPitch + nCenterX] = 0;
		fm[(nCenterY+1) * nPitch + nCenterX] = 0;
		fm[nCenterY * nPitch + (nCenterX-1)] = 0;
		fm[nCenterY * nPitch + (nCenterX+1)] = 0;
		fm[(nCenterY - 2) * nPitch + nCenterX] = 0;
		fm[(nCenterY + 2) * nPitch + nCenterX] = 0;
		fm[nCenterY * nPitch + (nCenterX - 2)] = 0;
		fm[nCenterY * nPitch + (nCenterX + 2)] = 0;
	}
	else
	{
		for (int j = y; j < y + nRadius * 2; j++) {
			for (int i = x; i < x + nRadius * 2; i++)
			{
				if (isInCircle(i, j, nCenterX, nCenterY, nRadius))
				{
					fm[j * nPitch + i] = nGray;
				}
			}
		}
	}
}
bool CgPrjDlg::isInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius)
	{
		bRet = true;
	}

	return bRet;
}
