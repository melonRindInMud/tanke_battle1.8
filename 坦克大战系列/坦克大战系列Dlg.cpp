
// ̹�˴�սϵ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "̹�˴�սϵ��.h"
#include "̹�˴�սϵ��Dlg.h"
#include "afxdialogex.h"
#include "my_resource.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C̹�˴�սϵ��Dlg �Ի���



//��׼���캯�� ϵͳ���н��е���
C̹�˴�սϵ��Dlg::C̹�˴�սϵ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C̹�˴�սϵ��Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	g_wTimerID = -1;
}

void C̹�˴�սϵ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C̹�˴�սϵ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C̹�˴�սϵ��Dlg ��Ϣ�������

//�Ի����ʼ������ �Զ�����
BOOL C̹�˴�սϵ��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������


	

	//����ͼ���ʼ�� �����Ҳ�����ѭ����
	//SetTimer(2, 100, NULL);
	//dlg.Create(IDD_DIALOG2, this);

	//�������ڴ�С
#ifdef LOW_DENSITY
	SetWindowPos(&wndTop, 0, 0, 1266, 693, SWP_SHOWWINDOW);
#else
	SetWindowPos(&wndTop, 0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, SWP_SHOWWINDOW);
#endif

	current_stage = 1;
	instruct = 0;
	process = Prepare;
	//��ʼ����ý��
	init_multi_media();
	immune_to = 0;

	//���ع��
	ShowCursor(FALSE);


	spDC = &supportDC;
	tempDC.CreateCompatibleDC(spDC);
	NUM_OF_TEAMMATE = 0;
	buy_free_access = 0;

	
#ifdef OP_CG
	SetTimer(999, 100, NULL);
#else
	SetTimer(4, 100, NULL);
#endif
	
	//����stretch ģʽ
	SetStretchBltMode(pDC->m_hDC, HALFTONE);

	//�������뷨����
	my_old_layout = GetKeyboardLayout(0);
	LoadKeyboardLayout("0x409", KLF_ACTIVATE | KLF_SETFORPROCESS);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE

}


// �Ի������ϵͳ��Ϣ�ĺ��� �Զ����ɵ� ������ʲô���ò��ù� 
void C̹�˴�սϵ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

// �Ի��� ����  �� ��� ����Ľ���  ÿ�� ���� ҳ�����ʱ ���е���  ����ʹ�� ���Ǹ��� ��� ��ʹ���������
void C̹�˴�սϵ��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��

// �Ի���ͼ���ʼ�� -- ûʲô̫���ô�
HCURSOR C̹�˴�սϵ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
// 184��
