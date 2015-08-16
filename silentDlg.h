
// silentDlg.h : 头文件
//

#pragma once

#include <cstringt.h>

#include "headset.h"
#include "sound.h"

// CsilentDlg 对话框
class CsilentDlg : public CDialogEx
{
// 构造
public:
	CsilentDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SILENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
