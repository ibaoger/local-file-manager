// ȫ�ֱ���

#pragma once

// �ļ���Ϣ
typedef struct _tagFileInfo	//���Сƽ��200B
{
	CString	m_strFileName;			// �ļ���
	CString	m_strFilePath;			// �ļ�·��
	CTime	m_tmCreateTime;			// �ļ�����ʱ��
	CTime	m_tmLastAcceessTime;	// �ļ����һ�δ�ʱ��
	CTime	m_tmLastWriteTime;		// �ļ����һ��д��ʱ��
	bool	m_bHidden;				// �ļ����С����ء�����
	bool	m_bReadOnly;			// �ļ����С�ֻ��������
	bool	m_bDirectory;			// �ļ����ļ���
	long	m_lFileLength;			// �ļ����ȣ���bΪ��λ
	long	m_lSubFileCount;		// �ļ������ļ�����
	long	m_lSubFileSize;			// �ļ������ļ���С����bΪ��λ
}FILEINFO, *LPFILEINFO;


// �������Ͷ���
enum
{
	ERR_FILE_OPEN = 1,		// �ļ��򲻿�
	ERR_NEW_RAM,			// �����ڴ�ʧ��
	ERR_NOFILE				// �Ҳ����ļ�
};

#define IsNotFolder	false	// �����ļ���