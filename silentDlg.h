
// silentDlg.h : ͷ�ļ�
//

#pragma once

#include <cstringt.h>

#include "headset.h"
#include "sound.h"

// CsilentDlg �Ի���
class CsilentDlg : public CDialogEx
{
// ����
public:
	CsilentDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SILENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

protected:
	float checkVolume();
	bool checkHeadset();
	void setSound();

private:
	Cheadset _headset;
	Csound _sound;
};
