
// silentDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "silent.h"
#include "silentDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsilentDlg �Ի���



CsilentDlg::CsilentDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CsilentDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CsilentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CsilentDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CsilentDlg ��Ϣ�������

BOOL CsilentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	_sound.keepSilent();
	_headset.setHeadset(checkHeadset());
	SetTimer(TIMER, 300, 0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CsilentDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CsilentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CsilentDlg::OnTimer(UINT_PTR nIDEvent){
	switch (nIDEvent)
	{
	case TIMER:
		bool ishave = checkHeadset();
		if (ishave == _headset.getHeadset())break;
		
		_headset.setHeadset(ishave);

		//pull out the headset
		if(!ishave){
			_sound.keepSilent();
			setSound();
		}

		//The headset is plugged
		else{
			_sound.restore();
			setSound();
		}
		break;
	default:
		CString tmp;
		tmp.Format("There is not anything setting timer for this %d", nIDEvent);
		MessageBox(tmp, CString("Error"));
		break;
	}

	CsilentDlg::OnTimer(nIDEvent);
}



void CsilentDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	KillTimer(TIMER);
	CDialogEx::OnClose();
}
