#pragma once


// CDlgImage ��ȭ �����Դϴ�.

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CDlgImage();

	CWnd* m_pParent;
	CImage m_image;
	CImage m_yimage;
	RGBQUAD m_Drgb;
	RGBQUAD* m_rgb;

	int m_color = 0;
	int m_nDataCount = 0;
	int m_Rad = 50;
	CPoint m_ptData;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnUpParent();
	virtual BOOL OnInitDialog();

private:
	void InitImage();
	void drawData(CDC* pDC, int Rad);
	
public:
	afx_msg void OnPaint();

};
