#pragma once


// MQuestDialog �Ի���

class MQuestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MQuestDialog)

public:
	MQuestDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~MQuestDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
public:
	int type; // �ʴ�������  1  ��Ϸ����
	int current_quest; // ��ǰ������
	CFont f;


	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();

	void show_quest(void);
};
//32
