// MQuestDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "̹�˴�սϵ��.h"
#include "MQuestDialog.h"
#include "afxdialogex.h"


// MQuestDialog �Ի���

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


// MQuestDialog ��Ϣ�������


BOOL MQuestDialog::PreTranslateMessage(MSG* pMsg)
{
	static CDC* pDC = GetDC();
	// TODO: �ڴ����ר�ô����/����û���
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
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 3)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 4)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 5)
				{
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 6)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 7)
				{
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 8)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 9)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 10)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
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
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 3)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 4)
				{
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 5)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 6)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 7)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 8)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 9)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 10)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
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
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 3)
				{
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 4)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 5)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 6)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 7)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 8)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 9)
				{
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 10)
				{
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					//AfxMessageBox("����ͨ��������Ŀ ���� ������ٰ� U �������ع�");
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
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 2)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 4)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 5)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 6)
				{
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 7)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 8)
				{
					pDC->TextOutA(100, 280, "����ȷ	");
					Sleep(1000);
					current_quest += 1;
					show_quest();
				}
				else if(current_quest == 9)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
				}
				else if(current_quest == 10)
				{
					pDC->TextOutA(100, 280, "�𰸴���	");
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
	f.CreatePointFont(180, "����");



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
void MQuestDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	static CDC* pDC = GetDC();

	pDC->SelectObject(&f);
	pDC->TextOutA(100, 40, "��ӭ��������֪ʶ�ʴ� ��ѡ��һ����");
	pDC->TextOutA(100, 80, "1 ��Ϸ������ʷ  ���Ƽ���");
	pDC->TextOutA(100, 120, "2 ��Ϸ���� �����ݣ�������˽����ߵĻ���");
	pDC->TextOutA(100, 160, "3 ���ߺ���ʷ ��������˽����ߵĻ���");
	pDC->TextOutA(100, 200, "4 ��������� ��������˽����ߵĻ���");
	pDC->TextOutA(100, 240, "5 ���ߵİ��� ��������˽����ߵĻ���");
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
		pDC->TextOutA(100, 40, "��ӭ��������֪ʶ�ʴ� ��ѡ��һ����");
		pDC->TextOutA(100, 80, "1 ��Ϸ������ʷ  ���Ƽ���");
		pDC->TextOutA(100, 120, "2 ��Ϸ���� �����ݣ�������˽����ߵĻ���");
		pDC->TextOutA(100, 160, "3 ���ߺ���ʷ ��������˽����ߵĻ���");
		pDC->TextOutA(100, 200, "4 ��������� ��������˽����ߵĻ���");
		pDC->TextOutA(100, 240, "5 ���ߵİ��� ��������˽����ߵĻ���");
	}

	if(type == 1)
	{
		pDC->FillSolidRect(0, 0, 900, 500, RGB(240, 240, 240));
		pDC->SelectObject(&f);
		
		if(current_quest == 1)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "��һ��");
			pDC->TextOutA(100, 80, "���� ���� ������˹ �� �Ĺ��ˣ�");
			pDC->TextOutA(100, 120, "A ���ܵ۹�����ά��������干�͹�����");
			pDC->TextOutA(100, 160, "B ��Ͷ�����͹����������������͹���");
			pDC->TextOutA(100, 200, "C С���ӵ۹� ������־�����۹���");
			pDC->TextOutA(100, 240, "D ���ɹ� ����������ڹ���");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
		else if(current_quest == 2)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "�ڶ���");
			pDC->TextOutA(100, 80, "���ܵ۹� �Ƿ�μ��� ���� ϣ��������ļƻ���");
			pDC->TextOutA(100, 120, "A û�вμ�");
			pDC->TextOutA(100, 160, "B �μ��� ����Ҫ�����С���ӵ۹���ս");
			pDC->TextOutA(100, 200, "C �μ��� ���ҵ��� ��Ҫ������");
			pDC->TextOutA(100, 240, "D ����С���ӵ۹� �� ��в���μ�");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
		else if(current_quest == 3)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "������");
			pDC->TextOutA(100, 80, "�����ķ��� ���ﳤ�ǣ�����ŵ���ߣ���ս���з��ӵ����ã�");
			pDC->TextOutA(100, 120, "A ������ֹ�� С���Ӿ���ǰ�� ���С���Ӿ�����");
			pDC->TextOutA(100, 160, "B ����ս���к�������");
			pDC->TextOutA(100, 200, "C ��С���Ӿ��ƺ�ռ���׶��� ���߱���Χ�߽�");
			pDC->TextOutA(100, 240, "D ��С���Ӿ�����߽�");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
		else if(current_quest == 4)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "������");
			pDC->TextOutA(100, 80, "��Ͷ�����͹��Ľ���ǣ�");
			pDC->TextOutA(100, 120, "A ��С���ӵ۹�ս�������һ��һ������");
			pDC->TextOutA(100, 160, "B �����⵽�ֻ���Լ��ǣ�� �׶����ƺ�Ͷ�����");
			pDC->TextOutA(100, 200, "C �����ӹֵ۹�����");
			pDC->TextOutA(100, 240, "D ����������ӹֵ۹����а���С���ӵ۹� ����װͶ��");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
		else if(current_quest == 5)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "������");
			pDC->TextOutA(100, 80, "���ܵ۹����������ں�С���ӵ۹����¹�����ս����״��ʱ��");
			pDC->TextOutA(100, 120, "A ׼������ ս�������߽� ��������������������²");
			pDC->TextOutA(100, 160, "B �����л� �� ���˽����˿ɸ�����Ķ���");
			pDC->TextOutA(100, 200, "C �ݿ����� Ѹ�ٷ���С���ӵ۹�");
			pDC->TextOutA(100, 240, "D ������ǽ �ڲ����ִ�����ͽ����ս�߱���");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
		else if(current_quest == 6)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "������");
			pDC->TextOutA(100, 80, "�����ķ��ؼ�ս�ۣ�Ī˹��ս�ۣ��Ľ����");
			pDC->TextOutA(100, 120, "A С���Ӿ� �ŵ��ﰲ ռ����ؼ���ȫ��");
			pDC->TextOutA(100, 160, "B ���ܾ�   ��ɷ�  �ʲ�Ͷ��");
			pDC->TextOutA(100, 200, "C С���Ӿ� �ŵ��ﰲ �� �ϼ�������� ����");
			pDC->TextOutA(100, 240, "D ���ܾ�   ��ɷ�  ��ǿ�����ѵ���ס�˳���");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
		else if(current_quest == 7)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "������");
			pDC->TextOutA(100, 80, "��ʷ�� ���ϵ� ����ս�� �� ת�۵��� ��");
			pDC->TextOutA(100, 120, "A �ܶ�����ս�ۣ�˹���ָ���ս�ۣ�");
			pDC->TextOutA(100, 160, "B ��Ƥ��ս�ۣ��ϴ�����ɶ���ս�ۣ�");
			pDC->TextOutA(100, 200, "C ��˹�ƶ���ս�����˹�˻�ս��");
			pDC->TextOutA(100, 240, "D �ܴ����ս�ۣ���������ս�ۣ�");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
		else if(current_quest == 8)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "�ڰ���");
			pDC->TextOutA(100, 80, "С���Ӿ��ڶ�������ʤ���� ��");
			pDC->TextOutA(100, 120, "A ����ս�ۣ�������ս��");
			pDC->TextOutA(100, 160, "B ˹����ս�ۣ���˹��ս�ۣ�");
			pDC->TextOutA(100, 200, "C �Ϸ�Ҫ��ս�ۣ�����˹�в���ս�ۣ�");
			pDC->TextOutA(100, 240, "D ���Ʒ��ս�ۣ������Ʒ�ս�ۣ�");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
		else if(current_quest == 9)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "�ھ���");
			pDC->TextOutA(100, 80, "��ο������ܵ۹����������ڶ�ս�еı��֣��߶����۲�ϲ���磩��");
			pDC->TextOutA(100, 120, "A ά��������ĺ�ƽ������ ��ֹ�� ����˹������");
			pDC->TextOutA(100, 160, "B �����˹������� ������������ռ���������");
			pDC->TextOutA(100, 200, "C ���ű������������ �û������������� �Ա�ռ����޶���");
			pDC->TextOutA(100, 240, "D �й��о� ��û�й�������");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
		else if(current_quest == 10)
		{
			//Invalidate(TRUE);
			pDC->TextOutA(100, 40, "��ʮ��");
			pDC->TextOutA(100, 80, "���ܵ۹��������� ���Ľ�֣�");
			pDC->TextOutA(100, 120, "A ƾ�豻ռ�������Դ ��һ���������� �ư�ȫ����");
			pDC->TextOutA(100, 160, "B ����Χ���������Ѻ� ��������");
			pDC->TextOutA(100, 200, "C ��ʧ���� ������� �����ڶ������ɹ����������Ĺ����������߽�");
			pDC->TextOutA(100, 240, "D �й��о� �˻���ռ������� ������չ �Ȳ��ƽ�");
			pDC->TextOutA(100, 280, "�� A B C D ����");
		}
	}
}
//458