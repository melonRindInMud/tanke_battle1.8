// MQuestDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "坦克大战系列.h"
#include "MQuestDialog.h"
#include "afxdialogex.h"


// MQuestDialog 对话框

IMPLEMENT_DYNAMIC(MQuestDialog, CDialogEx)

MQuestDialog::MQuestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(MQuestDialog::IDD, pParent)
{
	current_quest = 0;
	type = 0;

}

MQuestDialog::~MQuestDialog()
{
}

void MQuestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MQuestDialog, CDialogEx)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// MQuestDialog 消息处理程序


BOOL MQuestDialog::PreTranslateMessage(MSG* pMsg)
{
	static CDC* pDC = GetDC();
	// TODO: 在此添加专用代码和/或调用基类
	if(pMsg->message == WM_KEYDOWN)
	{
		if(pMsg->wParam == '1')
		{
			if(current_quest == 0)
			{
				type = 1;
				current_quest += 1;
				show_quest();
			}
		}
		else if(pMsg->wParam == 'Y')
		{
			show_quest();
		}

		else if(pMsg->wParam == 'A')
		{
			pDC->SelectObject(&f);
			pDC->FillSolidRect(100, 280, 180, 40, RGB(240, 240, 240));
			if(type == 1)
			{
				if(current_quest == 1)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 3)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 4)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 5)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 6)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 7)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 8)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 9)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 10)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
			}
			return TRUE;
		}
		else if(pMsg->wParam == 'B')
		{
			pDC->SelectObject(&f);
			pDC->FillSolidRect(100, 280, 180, 40, RGB(240, 240, 240));
			if(type == 1)
			{
				if(current_quest == 1)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 3)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 4)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 5)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 6)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 7)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 8)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 9)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 10)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
			}
			return TRUE;
		}
		else if(pMsg->wParam == 'C')
		{
			pDC->SelectObject(&f);
			pDC->FillSolidRect(100, 280, 180, 40, RGB(240, 240, 240));
			if(type == 1)
			{
				if(current_quest == 1)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 3)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 4)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 5)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 6)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 7)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 8)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 9)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 10)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					//AfxMessageBox("你已通过所有题目 返回 界面后再按 U 激活隐藏关");
					CDialog::OnOK();
				}
			}
			return TRUE;
		}
		else if(pMsg->wParam == 'D')
		{
			pDC->SelectObject(&f);
			pDC->FillSolidRect(100, 280, 180, 40, RGB(240, 240, 240));
			if(type == 1)
			{
				if(current_quest == 1)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 4)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 5)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 6)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 7)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 8)
				{
					pDC->TextOutA(100, 280, "答案正确	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 9)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
				else if(current_quest == 10)
				{
					pDC->TextOutA(100, 280, "答案错误	");
				}
			}
			return TRUE;
		}
		//return TRUE;
	}
	//return TRUE;
	return CDialogEx::PreTranslateMessage(pMsg);
}





BOOL MQuestDialog::OnInitDialog()
{

	CDialogEx::OnInitDialog();
	SetTimer(1, 150, NULL);
	f.CreatePointFont(180, "宋体");



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void MQuestDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	static CDC* pDC = GetDC();

	pDC->SelectObject(&f);
	pDC->TextOutA(100, 40, "欢迎来到奇葩知识问答 请选择一套题");
	pDC->TextOutA(100, 80, "1 游戏背景历史  （推荐）");
	pDC->TextOutA(100, 120, "2 游戏机制 和内容（如果你了解作者的话）");
	pDC->TextOutA(100, 160, "3 作者黑历史 （如果你了解作者的话）");
	pDC->TextOutA(100, 200, "4 作者世界观 （如果你了解作者的话）");
	pDC->TextOutA(100, 240, "5 作者的爱好 （如果你了解作者的话）");
	KillTimer(1);

	CDialogEx::OnTimer(nIDEvent);
}
void MQuestDialog::show_quest(void)
{
	static CDC* pDC = GetDC();
	if(current_quest == 0)
	{
		pDC->SelectObject(&f);
		//KillTimer(1);
		pDC->TextOutA(100, 40, "欢迎来到奇葩知识问答 请选择一套题");
		pDC->TextOutA(100, 80, "1 游戏背景历史  （推荐）");
		pDC->TextOutA(100, 120, "2 游戏机制 和内容（如果你了解作者的话）");
		pDC->TextOutA(100, 160, "3 作者黑历史 （如果你了解作者的话）");
		pDC->TextOutA(100, 200, "4 作者世界观 （如果你了解作者的话）");
		pDC->TextOutA(100, 240, "5 作者的爱好 （如果你了解作者的话）");
	}

	if(type == 1)
	{
		pDC->FillSolidRect(0, 0, 900, 500, RGB(240, 240, 240));
		pDC->SelectObject(&f);
		
		if(current_quest == 1)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第一题");
			pDC->TextOutA(100, 80, "主角 奥托 卡尔乌斯 是 哪国人？");
			pDC->TextOutA(100, 120, "A 巨熊帝国（苏维埃社会主义共和国联盟");
			pDC->TextOutA(100, 160, "B 我投降共和国（法兰西第三共和国）");
			pDC->TextOutA(100, 200, "C 小胡子帝国 （德意志第三帝国）");
			pDC->TextOutA(100, 240, "D 自由国 （美利坚合众国）");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
		else if(current_quest == 2)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第二题");
			pDC->TextOutA(100, 80, "巨熊帝国 是否参加了 入侵 希伯来联邦的计划？");
			pDC->TextOutA(100, 120, "A 没有参加");
			pDC->TextOutA(100, 160, "B 参加了 但主要是配合小胡子帝国作战");
			pDC->TextOutA(100, 200, "C 参加了 并且担任 主要攻击方");
			pDC->TextOutA(100, 240, "D 迫于小胡子帝国 的 威胁而参加");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
		else if(current_quest == 3)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第三题");
			pDC->TextOutA(100, 80, "著名的防线 万里长城（马奇诺防线）在战争中发挥的作用？");
			pDC->TextOutA(100, 120, "A 正面阻止了 小胡子军的前进 最后被小胡子军攻破");
			pDC->TextOutA(100, 160, "B 整场战役中毫无作用");
			pDC->TextOutA(100, 200, "C 被小胡子军绕后占领首都后 防线被合围瓦解");
			pDC->TextOutA(100, 240, "D 被小胡子军间谍瓦解");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
		else if(current_quest == 4)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第四题");
			pDC->TextOutA(100, 80, "我投降共和国的结局是？");
			pDC->TextOutA(100, 120, "A 与小胡子帝国战斗到最后一兵一卒后灭国");
			pDC->TextOutA(100, 160, "B 力量遭到分化制约和牵制 首都被破后投降灭国");
			pDC->TextOutA(100, 200, "C 被嘤嘤怪帝国出卖");
			pDC->TextOutA(100, 240, "D 表面配合嘤嘤怪帝国暗中帮助小胡子帝国 最后假装投降");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
		else if(current_quest == 5)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第五题");
			pDC->TextOutA(100, 80, "巨熊帝国（苏联）在和小胡子帝国（德国）作战初期状况时？");
			pDC->TextOutA(100, 120, "A 准备不足 战线土崩瓦解 大量有生力量被歼灭或俘虏");
			pDC->TextOutA(100, 160, "B 有来有回 和 敌人进行了可歌可泣的斗争");
			pDC->TextOutA(100, 200, "C 摧枯拉朽 迅速反推小胡子帝国");
			pDC->TextOutA(100, 240, "D 祸起萧墙 内部出现大量叛徒导致战线崩溃");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
		else if(current_quest == 6)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第六题");
			pDC->TextOutA(100, 80, "著名的伏特加战役（莫斯科战役）的结果？");
			pDC->TextOutA(100, 120, "A 小胡子军 古德里安 占领伏特加市全境");
			pDC->TextOutA(100, 160, "B 巨熊军   朱可夫  率部投降");
			pDC->TextOutA(100, 200, "C 小胡子军 古德里安 和 上级意见不合 撤退");
			pDC->TextOutA(100, 240, "D 巨熊军   朱可夫  顽强而艰难的守住了城市");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
		else if(current_quest == 7)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第七题");
			pDC->TextOutA(100, 80, "历史上 公认的 东线战场 的 转折点是 ？");
			pDC->TextOutA(100, 120, "A 熊二格勒战役（斯大林格勒战役）");
			pDC->TextOutA(100, 160, "B 瓜皮岛战役（瓜达尔卡纳尔岛战役）");
			pDC->TextOutA(100, 200, "C 库斯科尔会战（库尔斯克会战）");
			pDC->TextOutA(100, 240, "D 熊大格勒战役（列宁格勒战役）");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
		else if(current_quest == 8)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第八题");
			pDC->TextOutA(100, 80, "小胡子军在东线最后的胜利是 ？");
			pDC->TextOutA(100, 120, "A 基佬战役（基辅会战）");
			pDC->TextOutA(100, 160, "B 斯克名战役（明斯克战役）");
			pDC->TextOutA(100, 200, "C 南方要塞战役（塞瓦斯托波尔战役）");
			pDC->TextOutA(100, 240, "D 尔科夫哈战役（哈尔科夫战役）");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
		else if(current_quest == 9)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第九题");
			pDC->TextOutA(100, 80, "如何看待巨熊帝国（苏联）在二战中的表现（高度主观不喜勿喷）？");
			pDC->TextOutA(100, 120, "A 维护了世界的和平和正义 阻止了 法西斯的扩张");
			pDC->TextOutA(100, 160, "B 保护了国家尊严 帮助了其他被占领国的人民");
			pDC->TextOutA(100, 200, "C 打着保家卫国的旗号 趁机大肆侵略扩张 对被占领国无恶不作");
			pDC->TextOutA(100, 240, "D 中规中矩 并没有过多涉足");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
		else if(current_quest == 10)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "第十题");
			pDC->TextOutA(100, 80, "巨熊帝国（苏联） 最后的结局？");
			pDC->TextOutA(100, 120, "A 凭借被占领国的资源 进一步扩大优势 称霸全世界");
			pDC->TextOutA(100, 160, "B 和周围各国保持友好 互利互惠");
			pDC->TextOutA(100, 200, "C 内失民心 外树仇敌 最终在对手自由国（美国）的攻击下土崩瓦解");
			pDC->TextOutA(100, 240, "D 中规中矩 退回了占领的土地 自主发展 稳步推进");
			pDC->TextOutA(100, 280, "按 A B C D 作答");
		}
	}
}
//458