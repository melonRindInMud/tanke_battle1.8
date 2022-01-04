// M_HelpDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "̹�˴�սϵ��.h"
#include "M_HelpDialog.h"
#include "afxdialogex.h"


// M_HelpDialog �Ի���

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


// M_HelpDialog ��Ϣ�������


BOOL M_HelpDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	f.CreatePointFont(200, "����");
	CDC* pDC = GetDC();
	pDC->SetBkMode(TRANSPARENT);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void M_HelpDialog::OnBnClickedButton1()
{
	CDC* pDC = GetDC();
	pDC->SelectObject(&f);
	pDC->FillSolidRect(0, 0, 570, 600, RGB(240, 240, 240));
	pDC->TextOutA(40, 15, "ʤ������");
	pDC->TextOutA(40, 55, "ͨͨ�䱬 ����ȫ���о�");
	pDC->TextOutA(40, 95, "��־���ʤ�� ���ָ��ʱ��");
	pDC->TextOutA(40, 135, "�������� ����ؼ����ˣ���ɫ��");
	pDC->TextOutA(40, 175, "ɱ���Ӻ� ����һ����Ŀ�ĵо�");
	pDC->TextOutA(40, 235, "ʧ������");
	pDC->TextOutA(40, 275, "Ĭ�ϣ����̹�˱��ݻ�");
	pDC->TextOutA(40, 315, "���ʱ��ҪС�� �����ڵ�����ָ������");
	pDC->TextOutA(40, 355, "ʱ����ǽ�Ǯ �ؿ���ʱ����ָ��ʱ��");
	pDC->TextOutA(40, 395, "����Ŀ�� �ؼ�Ŀ�꣨��ɫ�����ݻ�");


	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void M_HelpDialog::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDC* pDC = GetDC();
	pDC->SelectObject(&f);
	pDC->FillSolidRect(0, 0, 570, 600, RGB(240, 240, 240));
	pDC->TextOutA(40, 15, "�������");
	pDC->TextOutA(40, 55, "�������ҳ������²��� ע��̹���й���");
	pDC->TextOutA(40, 95, "ͬʱ��ס��������������������ȸ���");
	pDC->TextOutA(40, 155, "���� �ڵ�ʧЧ������ �� װ��");
	pDC->TextOutA(40, 195, "���ܿ���  ���¿ո�� ");
	pDC->TextOutA(40, 255, "С��ָ��");
	pDC->TextOutA(40, 295, "���ּ�");
	pDC->TextOutA(40, 335, "1 ���� 2 ���� 3 ���� 4 ǣ��");
	pDC->TextOutA(40, 395, "������װ��");
	pDC->TextOutA(40, 435, "R ��");
}


void M_HelpDialog::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDC* pDC = GetDC();
	pDC->SelectObject(&f);
	pDC->FillSolidRect(0, 0, 570, 600, RGB(240, 240, 240));
	pDC->TextOutA(40, 15, "������� ���߹غ����");
	pDC->TextOutA(40, 55, "���� ��ת�� 1��� ����ٶ� ��� 50%");
	pDC->TextOutA(40, 115, "С��ָ�� ��ʮ���غ����");
	pDC->TextOutA(40, 155, "���� �� 1-4 ����");
	pDC->TextOutA(40, 215, "����֮�� ��������ս�ؽ�����");
	pDC->TextOutA(40, 255, "���� �ָ��������� ����Խ�ͻָ�Խ��");
	pDC->TextOutA(40, 315, "������װ�� �����غ����");
	pDC->TextOutA(40, 355, "���� I�� ʹ���ڼ� �ڵ�װ��ʱ�併��һ��");
	pDC->TextOutA(40, 435, "���� ��Ϸ��ʼʱ�Դ�");
	pDC->TextOutA(40, 475, "���� �ؿ���ʼǰ4���޵�");
}


void M_HelpDialog::OnBnClickedButton3()
{
	CDC* pDC = GetDC();
	pDC->SelectObject(&f);
	pDC->FillSolidRect(0, 0, 570, 600, RGB(240, 240, 240));
	pDC->TextOutA(40, 15, "�ܻ������봩��");
	pDC->TextOutA(40, 55, "�������ܴ����˺�  δ�����������˺� ");
	pDC->TextOutA(40, 95, "�����ܴ��� ���� ����Ӱ�� ǰװ�����");
	pDC->TextOutA(40, 135, "��װ���  �����˺��������еľ���");
	pDC->TextOutA(40, 175, "�Լ��ڵ������йأ��ڵ��������������٣�");

	pDC->TextOutA(40, 235, "�ƶ� �� ת��");
	pDC->TextOutA(40, 275, "�ƶ���Ҫ�𲽼��� ת����ת����");

	pDC->TextOutA(40, 335, "ѳ������");
	pDC->TextOutA(40, 375, "��С��λ�������и���ѳ��");
	pDC->TextOutA(40, 415, "���о��ȸ߾�������ʸ���BOSS���㲻��ѳ��");

	pDC->TextOutA(40, 475, "��������");
	pDC->TextOutA(40, 515, "���汻������������ڽ������ٺ��˺�");
	pDC->TextOutA(40, 555, "���汻������������� �����ٶ� ת��");


	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HINSTANCE h = ShellExecuteA(NULL,"open","presence3.mp4",NULL,"",SW_SHOW);
}


void M_HelpDialog::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HINSTANCE h = ShellExecuteA(NULL,"open","presence4.mp4",NULL,"",SW_SHOW);

}
