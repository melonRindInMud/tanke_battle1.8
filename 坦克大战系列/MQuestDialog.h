#pragma once


// MQuestDialog 对话框

class MQuestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(MQuestDialog)

public:
	MQuestDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MQuestDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
public:
	int type; // 问答题种类  1  游戏内容
	int current_quest; // 当前问题标号
	CFont f;


	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();

	void show_quest(void);
};
//32
