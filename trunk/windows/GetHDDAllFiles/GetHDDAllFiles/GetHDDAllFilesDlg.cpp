/*
* Copyright (c) 2011,自由国度集团公司软件开发部
* All rights reserved.
*
* 文件名称：GetHDDAllFilesDlg.cpp
* 文件标识：
* 摘    要：简要描述本文件的内容
*
* 当前版本：1.0
* 作    者：Masterr
* 完成日期：2011年 月 日
*/

#include "stdafx.h"
#include "GetHDDAllFiles.h"
#include "GetHDDAllFilesDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CGetHDDAllFilesDlg 对话框




CGetHDDAllFilesDlg::CGetHDDAllFilesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGetHDDAllFilesDlg::IDD, pParent)
	, m_pFileInfo(NULL)
	, m_iFileBegin(0)
	, m_lSubFileCount(0)
	, m_lSubFileSize(0)
	,m_iExit(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGetHDDAllFilesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_oFileListArray);
}

BEGIN_MESSAGE_MAP(CGetHDDAllFilesDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_FIND_BEGIN, &CGetHDDAllFilesDlg::OnBnClickedBtnFindBegin)
	ON_BN_CLICKED(IDC_BTN_LOAD_EXIST, &CGetHDDAllFilesDlg::OnBnClickedBtnLoadExist)
	ON_BN_CLICKED(IDC_BTN_FIND_PICTURE, &CGetHDDAllFilesDlg::OnBnClickedBtnFindPicture)
	ON_BN_CLICKED(IDC_BTN_FIND_MUSIC, &CGetHDDAllFilesDlg::OnBnClickedBtnFindMusic)
	ON_BN_CLICKED(IDC_BTN_FIND_VIDEO, &CGetHDDAllFilesDlg::OnBnClickedBtnFindVideo)
END_MESSAGE_MAP()


// CGetHDDAllFilesDlg 消息处理程序

BOOL CGetHDDAllFilesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	m_oFileListArray.InsertColumn(0, _T("文件名"),	LVCFMT_LEFT, 130);
	m_oFileListArray.InsertColumn(1, _T("路径"),	LVCFMT_LEFT, 325);
	m_oFileListArray.InsertColumn(2, _T("创建时间"),LVCFMT_LEFT, 130);
	m_oFileListArray.InsertColumn(3, _T("大小"),	LVCFMT_LEFT, 90);
	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGetHDDAllFilesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGetHDDAllFilesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CGetHDDAllFilesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/************************************************************************
函数名称：GetAllFiles
函数功能：获取strFilePath目录下的所有文件
输入参数：
		  strFilePath	要查找的文件路径
输出参数：无
返 回 值：
		  ERR_NEW_RAM	内存申请失败
		  TRUE			正常退出
创建时间：2011-26-10   22:33
修改历史：
1、日 期：
修改内容：
************************************************************************/
int CGetHDDAllFilesDlg::GetAllFiles(CString strFilePath)
{
	strFilePath.Append(_T("\\*.*"));

	CFileFind finder;
	BOOL bWorking = finder.FindFile(strFilePath);
	while (bWorking)
	{
		bWorking = finder.FindNextFile();

		m_pFileInfo = new FILEINFO;

		if (NULL == m_pFileInfo)
		{
			return ERR_NEW_RAM;
		}

		m_pFileInfo->m_strFileName = finder.GetFileName();
		m_pFileInfo->m_strFilePath = finder.GetFilePath();
		finder.GetCreationTime(m_pFileInfo->m_tmCreateTime);
		finder.GetLastAccessTime(m_pFileInfo->m_tmLastAcceessTime);
		finder.GetLastWriteTime(m_pFileInfo->m_tmLastWriteTime);
		m_pFileInfo->m_lFileLength = finder.GetLength();
		m_pFileInfo->m_bHidden = finder.IsHidden();
		m_pFileInfo->m_bReadOnly = finder.IsReadOnly();
		m_pFileInfo->m_bDirectory = finder.IsDirectory();
		m_pFileInfo->m_lSubFileCount = 0;
		m_pFileInfo->m_lSubFileSize = 0;

		if (!finder.IsDots())
		{
			m_pArrFileInfo.Add(m_pFileInfo);
		}

		m_lSubFileSize += m_pFileInfo->m_lFileLength;	//计算下一级子目录大小，预留
	}

	m_iExit = 0;
	for (int i=m_iFileBegin+1; i<m_pArrFileInfo.GetCount(); i++)
	{
		m_pFileInfo = new FILEINFO;

		if (NULL == m_pFileInfo)
		{
			return ERR_NEW_RAM;
		}
		m_pFileInfo = m_pArrFileInfo.GetAt(i);

		if(m_pFileInfo->m_bDirectory)		//第一个未查找过的文件夹
		{
			m_iFileBegin = i;
			strFilePath = m_pFileInfo->m_strFilePath;		//下一次查找的文件夹
			break;
		}
		m_iExit++;
	}
	if(m_iExit == m_pArrFileInfo.GetCount()-m_iFileBegin-1)
	{
		return TRUE;	//查找结束，正常退出
	}

	//m_lSubFileCount = m_pArrFileInfo.GetCount();	//目录下文件个数

	GetAllFiles(strFilePath);
}


/************************************************************************
函数名称：OnBnClickedBtnFindBegin
函数功能：开始查找文件
输入参数：无
输出参数：无
返 回 值：无
创建时间：2011-26-10   22:37
修改历史：
1、日 期：
修改内容：
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnFindBegin()
{
	GetAllFiles(_T("c:"));
	UpdateDispList();
}


/************************************************************************
函数名称：OnBnClickedBtnLoadExist
函数功能：加载已查找的结果
输入参数：无
输出参数：无
返 回 值：无
创建时间：2011-26-10   22:38
修改历史：
1、日 期：
修改内容：
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnLoadExist()
{
	// TODO: 在此添加控件通知处理程序代码
}


/************************************************************************
函数名称：OnBnClickedBtnFindPicture
函数功能：查找图片
输入参数：无
输出参数：无
返 回 值：无
创建时间：2011-26-10   22:39
修改历史：
1、日 期：
修改内容：
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnFindPicture()
{
	// TODO: 在此添加控件通知处理程序代码
}


/************************************************************************
函数名称：OnBnClickedBtnFindMusic
函数功能：查找音乐
输入参数：无
输出参数：无
返 回 值：无
创建时间：2011-26-10   22:39
修改历史：
1、日 期：
修改内容：
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnFindMusic()
{
	// TODO: 在此添加控件通知处理程序代码
}


/************************************************************************
函数名称：OnBnClickedBtnFindVideo
函数功能：查找视频
输入参数：无
输出参数：无
返 回 值：无
创建时间：2011-26-10   22:39
修改历史：
1、日 期：
修改内容：
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnFindVideo()
{
	// TODO: 在此添加控件通知处理程序代码
}


/************************************************************************
函数名称：UpdateDispList
函数功能：显示文件列表
输入参数：无
输出参数：无
返 回 值：
		  ERR_NOFILE	没有文件
		  TRUE			正常退出
创建时间：2011-26-10   22:39
修改历史：
1、日 期：
修改内容：
************************************************************************/
int CGetHDDAllFilesDlg::UpdateDispList(void)
{
	if (0 == m_pArrFileInfo.GetCount())
	{
		return ERR_NOFILE;
	}

	for (int i=0; i<m_pArrFileInfo.GetCount(); i++)
	{
		m_pFileInfo = m_pArrFileInfo.GetAt(i);

		CString strCreateTime;
		TCHAR bufFileLength[64];
		TCHAR bufSubFileCount[64];
		strCreateTime.Format(_T("%04d-%02d-%02d %02d:%02d:%02d"),
							 m_pFileInfo->m_tmCreateTime.GetYear(),	\
							 m_pFileInfo->m_tmCreateTime.GetMonth(),	\
							 m_pFileInfo->m_tmCreateTime.GetDay(),	\
							 m_pFileInfo->m_tmCreateTime.GetHour(),	\
							 m_pFileInfo->m_tmCreateTime.GetMinute(),\
							 m_pFileInfo->m_tmCreateTime.GetSecond()); 

		_ltot(m_pFileInfo->m_lFileLength, bufFileLength, 10);
		_ltot(m_pFileInfo->m_lSubFileCount, bufSubFileCount, 10);
		
		
		m_oFileListArray.InsertItem(i, m_pFileInfo->m_strFileName);

		m_oFileListArray.SetItemText(i, 0, m_pFileInfo->m_strFileName);
		m_oFileListArray.SetItemText(i, 1, m_pFileInfo->m_strFilePath);		
		m_oFileListArray.SetItemText(i, 2, strCreateTime);		
		m_oFileListArray.SetItemText(i, 3, bufFileLength);
	} // end of for

	return TRUE;
}


void CGetHDDAllFilesDlg::OnDestroy()
{
	CDialog::OnDestroy();

	long nCount = m_pArrFileInfo.GetCount();
	for (int i=0; i<nCount; i++)
	{
		if (NULL == m_pFileInfo)
		{
			delete m_pFileInfo;
			m_pFileInfo = NULL;
		}
	}
}