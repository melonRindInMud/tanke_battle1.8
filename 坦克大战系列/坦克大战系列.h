
// ̹�˴�սϵ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

// C̹�˴�սϵ��App:
// �йش����ʵ�֣������ ̹�˴�սϵ��.cpp
//

class C̹�˴�սϵ��App : public CWinApp
{
public:
	C̹�˴�սϵ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C̹�˴�սϵ��App theApp;
//33��