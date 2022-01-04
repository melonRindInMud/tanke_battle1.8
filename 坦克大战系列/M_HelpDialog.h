#pragma once


// M_HelpDialog 对话框

class M_HelpDialog : public CDialogEx
{
	DECLARE_DYNAMIC(M_HelpDialog)

public:
	M_HelpDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~M_HelpDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()


public:

	CFont f;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
};//31
