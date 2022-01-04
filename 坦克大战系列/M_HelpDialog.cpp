// M_HelpDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战系列.h"
#include "M_HelpDialog.h"
#include "afxdialogex.h"


// M_HelpDialog 对话框

IMPLEMENT_DYNAMIC(M_HelpDialog, CDialogEx)

M_HelpDialog::M_HelpDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(M_HelpDialog::IDD, pParent)
{

}

M_HelpDialog::~M_HelpDialog()
{
}

void M_HelpDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(M_HelpDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &M_HelpDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &M_HelpDialog::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &M_HelpDialog::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &M_HelpDialog::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &M_HelpDialog::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &M_HelpDialog::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &M_HelpDialog::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &M_HelpDialog::OnBnClickedButton8)
END_MESSAGE_MAP()


// M_HelpDialog 消息处理程序


BOOL M_HelpDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	f.CreatePointFont(200, "宋体");
	CDC* pDC = GetDC();
	pDC->SetBkMode(TRANSPARENT);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void M_HelpDialog::OnBnClickedButton1()
{
	CDC* pDC = GetDC();
	pDC->SelectObject(&f);
	pDC->FillSolidRect(0, 0, 570, 600, RGB(240, 240, 240));
	pDC->TextOutA(40, 15, "胜利条件");
	pDC->TextOutA(40, 55, "通通射爆 消灭全部敌军");
	pDC->TextOutA(40, 95, "坚持就是胜利 坚持指定时间");
	pDC->TextOutA(40, 135, "擒贼擒王 消灭关键敌人（紫色）");
	pDC->TextOutA(40, 175, "杀鸡儆猴 消灭一定数目的敌军");
	pDC->TextOutA(40, 235, "失败条件");
	pDC->TextOutA(40, 275, "默认：玩家坦克被摧毁");
	pDC->TextOutA(40, 315, "射的时候要小心 发射炮弹超过指定数量");
	pDC->TextOutA(40, 355, "时间就是金钱 关卡用时超过指定时间");
	pDC->TextOutA(40, 395, "保护目标 关键目标（黄色）被摧毁");


	// TODO: 在此添加控件通知处理程序代码
}


void M_HelpDialog::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDC* pDC = GetDC();
	pDC->SelectObject(&f);
	pDC->FillSolidRect(0, 0, 570, 600, RGB(240, 240, 240));
	pDC->TextOutA(40, 15, "方向控制");
	pDC->TextOutA(40, 55, "上下左右持续按下操作 注意坦克有惯性");
	pDC->TextOutA(40, 95, "同时按住多个键将按上下左右优先覆盖");
	pDC->TextOutA(40, 155, "开炮 炮弹失效或命中 且 装好");
	pDC->TextOutA(40, 195, "才能开炮  按下空格键 ");
	pDC->TextOutA(40, 255, "小队指令");
	pDC->TextOutA(40, 295, "数字键");
	pDC->TextOutA(40, 335, "1 随行 2 伏击 3 进攻 4 牵制");
	pDC->TextOutA(40, 395, "主炮再装填");
	pDC->TextOutA(40, 435, "R 键");
}


void M_HelpDialog::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CDC* pDC = GetDC();
	pDC->SelectObject(&f);
	pDC->FillSolidRect(0, 0, 570, 600, RGB(240, 240, 240));
	pDC->TextOutA(40, 15, "引擎过载 第七关后解锁");
	pDC->TextOutA(40, 55, "被动 不转向 1秒后 最大速度 提高 50%");
	pDC->TextOutA(40, 115, "小队指令 第十二关后解锁");
	pDC->TextOutA(40, 155, "主动 按 1-4 操作");
	pDC->TextOutA(40, 215, "复苏之风 （单人挑战关解锁）");
	pDC->TextOutA(40, 255, "被动 恢复生命上限 生命越低恢复越快");
	pDC->TextOutA(40, 315, "主炮再装填 第三关后解锁");
	pDC->TextOutA(40, 355, "主动 I键 使用期间 炮弹装填时间降低一半");
	pDC->TextOutA(40, 435, "护盾 游戏开始时自带");
	pDC->TextOutA(40, 475, "被动 关卡开始前4秒无敌");
}


void M_HelpDialog::OnBnClickedButton3()
{
	CDC* pDC = GetDC();
	pDC->SelectObject(&f);
	pDC->FillSolidRect(0, 0, 570, 600, RGB(240, 240, 240));
	pDC->TextOutA(40, 15, "受击方向与穿深");
	pDC->TextOutA(40, 55, "被击穿受大量伤害  未击穿受少量伤害 ");
	pDC->TextOutA(40, 95, "击穿受穿深 距离 方向影响 前装甲最厚");
	pDC->TextOutA(40, 135, "背装甲最薄  此外伤害还和命中的精度");
	pDC->TextOutA(40, 175, "以及炮弹存速有关（炮弹飞行有阻力减速）");

	pDC->TextOutA(40, 235, "移动 和 转向");
	pDC->TextOutA(40, 275, "移动需要逐步加速 转向有转向间隔");

	pDC->TextOutA(40, 335, "殉爆机制");
	pDC->TextOutA(40, 375, "弱小单位被击穿有概率殉爆");
	pDC->TextOutA(40, 415, "命中精度高距离近几率更大BOSS和你不会殉爆");

	pDC->TextOutA(40, 475, "部件受损");
	pDC->TextOutA(40, 515, "正面被穿大概率损坏主炮降低射速和伤害");
	pDC->TextOutA(40, 555, "背面被穿大概率损坏引擎 降低速度 转向");


	// TODO: 在此添加控件通知处理程序代码
}
//136


void M_HelpDialog::OnBnClickedButton5()
{
	HINSTANCE h = ShellExecuteA(NULL,"open","presence1.mp4",NULL,"",SW_SHOW);
}


void M_HelpDialog::OnBnClickedButton6()
{
	HINSTANCE h = ShellExecuteA(NULL,"open","presence2.mp4",NULL,"",SW_SHOW);
}


void M_HelpDialog::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	HINSTANCE h = ShellExecuteA(NULL,"open","presence3.mp4",NULL,"",SW_SHOW);
}


void M_HelpDialog::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	HINSTANCE h = ShellExecuteA(NULL,"open","presence4.mp4",NULL,"",SW_SHOW);

}
