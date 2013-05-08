// 全局变量

#pragma once

// 文件信息
typedef struct _tagFileInfo	//拟大小平均200B
{
	CString	m_strFileName;			// 文件名
	CString	m_strFilePath;			// 文件路径
	CTime	m_tmCreateTime;			// 文件创建时间
	CTime	m_tmLastAcceessTime;	// 文件最后一次打开时间
	CTime	m_tmLastWriteTime;		// 文件最近一次写入时间
	bool	m_bHidden;				// 文件具有“隐藏”属性
	bool	m_bReadOnly;			// 文件具有“只读”属性
	bool	m_bDirectory;			// 文件是文件夹
	long	m_lFileLength;			// 文件长度，以b为单位
	long	m_lSubFileCount;		// 文件的子文件个数
	long	m_lSubFileSize;			// 文件的子文件大小，以b为单位
}FILEINFO, *LPFILEINFO;


// 错误类型定义
enum
{
	ERR_FILE_OPEN = 1,		// 文件打不开
	ERR_NEW_RAM,			// 申请内存失败
	ERR_NOFILE				// 找不到文件
};

#define IsNotFolder	false	// 不是文件夹