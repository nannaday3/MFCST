// DlgImage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "gPrj.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgImage::OnBnClickedBtnUpParent)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage �޽��� ó�����Դϴ�.

#include "gPrjDlg.h"
void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	static int n = 100;
	CgPrjDlg *pDlg = (CgPrjDlg*)m_pParent;
	pDlg->callFunc(n++);
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetWindowText(_T("Origin Image"));
	MoveWindow(0, 0, 640, 480);
	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void CDlgImage::InitImage()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	//int nyWidth = 640;
	//int nyHeight = 480;
	//int nyBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}


	//m_yimage.Create(nyWidth, -nyHeight, nyBpp);
	//if (nyBpp == 8) {
	//	static RGBQUAD yrgb[256];
	//	for (int j = 0; j < 256; j++)
	//	{
	//		yrgb[j].rgbRed = yrgb[j].rgbGreen = j;
	//		yrgb[j].rgbBlue = 0;
	//	}
	//	m_yimage.SetColorTable(0, 256, yrgb);
	//}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);
}


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.
	if (m_image)
	{
		m_image.Draw(dc, 0, 0);
	}
	//if (m_yimage)
	//{
	//	m_yimage.Draw(dc, m_ptData.x- m_Rad, m_ptData.y- m_Rad,m_Rad*2,m_Rad*2);
	//}


	//if (m_ptData.x != 0 && m_ptData.y != 0) // (m_ptData.x,m_ptData.y) �� (0,0)�� �׷����°� �ذ�
	//{
	//	drawData(&dc, m_Rad);
	//}
	
}

void CDlgImage::drawData(CDC* pDC, int Rad)
{
	

	//unsigned char* yfm = (unsigned char*)m_yimage.GetBits();
	//int nWidth = m_yimage.GetWidth();
	//int nHeight = m_yimage.GetHeight();
	//int nPitch = m_yimage.GetPitch();


	//for (int j = nHeight; j < nHeight + Rad * 2; j++) {
	//	for (int i = nWidth; i < nWidth + Rad * 2; i++)
	//	{
	//		if (isInCircle(i, j, m_ptData.x, m_ptData.y, Rad))
	//			yfm[j * nPitch + i] = 255;
	//	}
	//}



	//CPen pen;
	//pen.CreatePen(PS_SOLID, 3, RGB(0xff, 0xff, 0));
	//CPen* pOldPen = pDC->SelectObject(&pen);
	//
	//pDC->Ellipse(m_ptData.x-Rad, m_ptData.y-Rad, m_ptData.x + Rad, m_ptData.y + Rad);

	//pDC->SetPixel(m_ptData.x-1, m_ptData.y, RGB(0, 0, 0));
	//pDC->SetPixel(m_ptData.x+1, m_ptData.y, RGB(0, 0, 0));
	//pDC->SetPixel(m_ptData.x, m_ptData.y-1, RGB(0, 0, 0));
	//pDC->SetPixel(m_ptData.x, m_ptData.y+1, RGB(0, 0, 0)); // ���ڰ�

	//pDC->SelectObject(pOldPen);
}

