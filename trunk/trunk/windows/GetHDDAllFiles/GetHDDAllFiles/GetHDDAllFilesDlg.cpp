/*
* Copyright (c) 2011,���ɹ��ȼ��Ź�˾���������
* All rights reserved.
*
* �ļ����ƣ�GetHDDAllFilesDlg.cpp
* �ļ���ʶ��
* ժ    Ҫ����Ҫ�������ļ�������
*
* ��ǰ�汾��1.0
* ��    �ߣ�Masterr
* ������ڣ�2011�� �� ��
*/

#include "stdafx.h"
#include "GetHDDAllFiles.h"
#include "GetHDDAllFilesDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CGetHDDAllFilesDlg �Ի���




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


// CGetHDDAllFilesDlg ��Ϣ�������

BOOL CGetHDDAllFilesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_oFileListArray.InsertColumn(0, _T("�ļ���"),	LVCFMT_LEFT, 130);
	m_oFileListArray.InsertColumn(1, _T("·��"),	LVCFMT_LEFT, 325);
	m_oFileListArray.InsertColumn(2, _T("����ʱ��"),LVCFMT_LEFT, 130);
	m_oFileListArray.InsertColumn(3, _T("��С"),	LVCFMT_LEFT, 90);
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGetHDDAllFilesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CGetHDDAllFilesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/************************************************************************
�������ƣ�GetAllFiles
�������ܣ���ȡstrFilePathĿ¼�µ������ļ�
���������
		  strFilePath	Ҫ���ҵ��ļ�·��
�����������
�� �� ֵ��
		  ERR_NEW_RAM	�ڴ�����ʧ��
		  TRUE			�����˳�
����ʱ�䣺2011-26-10   22:33
�޸���ʷ��
1���� �ڣ�
�޸����ݣ�
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

		m_lSubFileSize += m_pFileInfo->m_lFileLength;	//������һ����Ŀ¼��С��Ԥ��
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

		if(m_pFileInfo->m_bDirectory)		//��һ��δ���ҹ����ļ���
		{
			m_iFileBegin = i;
			strFilePath = m_pFileInfo->m_strFilePath;		//��һ�β��ҵ��ļ���
			break;
		}
		m_iExit++;
	}
	if(m_iExit == m_pArrFileInfo.GetCount()-m_iFileBegin-1)
	{
		return TRUE;	//���ҽ����������˳�
	}

	//m_lSubFileCount = m_pArrFileInfo.GetCount();	//Ŀ¼���ļ�����

	GetAllFiles(strFilePath);
}


/************************************************************************
�������ƣ�OnBnClickedBtnFindBegin
�������ܣ���ʼ�����ļ�
�����������
�����������
�� �� ֵ����
����ʱ�䣺2011-26-10   22:37
�޸���ʷ��
1���� �ڣ�
�޸����ݣ�
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnFindBegin()
{
	GetAllFiles(_T("c:"));
	UpdateDispList();
}


/************************************************************************
�������ƣ�OnBnClickedBtnLoadExist
�������ܣ������Ѳ��ҵĽ��
�����������
�����������
�� �� ֵ����
����ʱ�䣺2011-26-10   22:38
�޸���ʷ��
1���� �ڣ�
�޸����ݣ�
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnLoadExist()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


/************************************************************************
�������ƣ�OnBnClickedBtnFindPicture
�������ܣ�����ͼƬ
�����������
�����������
�� �� ֵ����
����ʱ�䣺2011-26-10   22:39
�޸���ʷ��
1���� �ڣ�
�޸����ݣ�
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnFindPicture()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


/************************************************************************
�������ƣ�OnBnClickedBtnFindMusic
�������ܣ���������
�����������
�����������
�� �� ֵ����
����ʱ�䣺2011-26-10   22:39
�޸���ʷ��
1���� �ڣ�
�޸����ݣ�
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnFindMusic()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


/************************************************************************
�������ƣ�OnBnClickedBtnFindVideo
�������ܣ�������Ƶ
�����������
�����������
�� �� ֵ����
����ʱ�䣺2011-26-10   22:39
�޸���ʷ��
1���� �ڣ�
�޸����ݣ�
************************************************************************/
void CGetHDDAllFilesDlg::OnBnClickedBtnFindVideo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


/************************************************************************
�������ƣ�UpdateDispList
�������ܣ���ʾ�ļ��б�
�����������
�����������
�� �� ֵ��
		  ERR_NOFILE	û���ļ�
		  TRUE			�����˳�
����ʱ�䣺2011-26-10   22:39
�޸���ʷ��
1���� �ڣ�
�޸����ݣ�
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