// GetHDDAllFiles.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CGetHDDAllFilesApp:
// �йش����ʵ�֣������ GetHDDAllFiles.cpp
//

class CGetHDDAllFilesApp : public CWinApp
{
public:
	CGetHDDAllFilesApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CGetHDDAllFilesApp theApp;