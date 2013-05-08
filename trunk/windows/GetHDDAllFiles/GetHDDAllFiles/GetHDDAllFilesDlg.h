/*
* Copyright (c) 2011,自由国度集团公司软件开发部
* All rights reserved.
*
* 文件名称：GetHDDAllFilesDlg.h
* 文件标识：
* 摘    要：简要描述本文件的内容
*
* 当前版本：1.0
* 作    者：Masterr
* 完成日期：2011年 月 日
*/

#pragma once
#include "afxwin.h"
#include "afxtempl.h"
#include "afxcmn.h"
#include "global.h"



// CGetHDDAllFilesDlg 对话框
class CGetHDDAllFilesDlg : public CDialog
{
// 构造
public:
	CGetHDDAllFilesDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_GETHDDALLFILES_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnBnClickedBtnFindBegin();				// 开始查找
	afx_msg void OnBnClickedBtnLoadExist();				// 加载查找结果
	afx_msg void OnBnClickedBtnFindPicture();			// 查找图片
	afx_msg void OnBnClickedBtnFindMusic();				// 查找音乐
	afx_msg void OnBnClickedBtnFindVideo();				// 查找电影
	afx_msg void OnDestroy();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	int GetAllFiles		(CString strFilePath);			// 查找所有文件
	int UpdateDispList	(void);							// 更新显示文件列表
	
private:
	int			m_iFileBegin;							// 循环查找的位置	
	int			m_iExit;								// 退出循环查找的条件	
	long		m_lSubFileCount;						// 一级子目录下文件个数	
	long		m_lSubFileSize;							// 一级子目录下文件大小总和
	CListCtrl	m_oFileListArray;						// 显示文件的List数组
	FILEINFO	*m_pFileInfo;							// 文件信息

	CArray<FILEINFO*>	m_pArrFileInfo;					// 存放文件信息的数组
};
