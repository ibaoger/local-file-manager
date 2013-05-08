/*
* Copyright (c) 2011,���ɹ��ȼ��Ź�˾���������
* All rights reserved.
*
* �ļ����ƣ�GetHDDAllFilesDlg.h
* �ļ���ʶ��
* ժ    Ҫ����Ҫ�������ļ�������
*
* ��ǰ�汾��1.0
* ��    �ߣ�Masterr
* ������ڣ�2011�� �� ��
*/

#pragma once
#include "afxwin.h"
#include "afxtempl.h"
#include "afxcmn.h"
#include "global.h"



// CGetHDDAllFilesDlg �Ի���
class CGetHDDAllFilesDlg : public CDialog
{
// ����
public:
	CGetHDDAllFilesDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_GETHDDALLFILES_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedBtnFindBegin();				// ��ʼ����
	afx_msg void OnBnClickedBtnLoadExist();				// ���ز��ҽ��
	afx_msg void OnBnClickedBtnFindPicture();			// ����ͼƬ
	afx_msg void OnBnClickedBtnFindMusic();				// ��������
	afx_msg void OnBnClickedBtnFindVideo();				// ���ҵ�Ӱ
	afx_msg void OnDestroy();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	int GetAllFiles		(CString strFilePath);			// ���������ļ�
	int UpdateDispList	(void);							// ������ʾ�ļ��б�
	
private:
	int			m_iFileBegin;							// ѭ�����ҵ�λ��	
	int			m_iExit;								// �˳�ѭ�����ҵ�����	
	long		m_lSubFileCount;						// һ����Ŀ¼���ļ�����	
	long		m_lSubFileSize;							// һ����Ŀ¼���ļ���С�ܺ�
	CListCtrl	m_oFileListArray;						// ��ʾ�ļ���List����
	FILEINFO	*m_pFileInfo;							// �ļ���Ϣ

	CArray<FILEINFO*>	m_pArrFileInfo;					// ����ļ���Ϣ������
};
