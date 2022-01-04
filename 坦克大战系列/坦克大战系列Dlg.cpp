
// 坦克大战系列Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战系列.h"
#include "坦克大战系列Dlg.h"
#include "afxdialogex.h"
#include "my_resource.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// C坦克大战系列Dlg 对话框



//标准构造函数 系统自行进行调用
C坦克大战系列Dlg::C坦克大战系列Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C坦克大战系列Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
	g_wTimerID = -1;
}

void C坦克大战系列Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C坦克大战系列Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// C坦克大战系列Dlg 消息处理程序

//对话框初始化函数 自动调用
BOOL C坦克大战系列Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	

	//设置图像初始化 （并且不加入循环中
	//SetTimer(2, 100, NULL);
	//dlg.Create(IDD_DIALOG2, this);

	//调整窗口大小
#ifdef LOW_DENSITY
	SetWindowPos(&wndTop, 0, 0, 1266, 693, SWP_SHOWWINDOW);
#else
	SetWindowPos(&wndTop, 0, 0, DIALOG_WIDTH, DIALOG_HEIGHT, SWP_SHOWWINDOW);
#endif

	current_stage = 1;
	instruct = 0;
	process = Prepare;
	//初始化多媒体
	init_multi_media();
	immune_to = 0;

	//隐藏光标
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
	
	//设置stretch 模式
	SetStretchBltMode(pDC->m_hDC, HALFTONE);

	//设置输入法语言
	my_old_layout = GetKeyboardLayout(0);
	LoadKeyboardLayout("0x409", KLF_ACTIVATE | KLF_SETFORPROCESS);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE

}


// 对话框接受系统消息的函数 自动生成的 具体是什么作用不用管 
void C坦克大战系列Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

// 对话框 对于  用 设计 构造的界面  每次 进行 页面更新时 进行调用  这里使用 覆盖更新 因此 不使用这个方法
void C坦克大战系列Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。

// 对话框图标初始化 -- 没什么太大用处
HCURSOR C坦克大战系列Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
// 184行
