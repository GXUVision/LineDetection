
// MFCApplication12-4Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CMFCApplication124Dlg �Ի���
class CMFCApplication124Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication124Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION124_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton m_ctrlButton1;
	afx_msg void OnBnClickedButton1();
	CStatic m_ctrlPic1;
	CButton m_ctrlButton2;
	CButton m_ctrlButton3;
	CButton m_ctrlButton4;
	afx_msg void OnBnClickedButton2();
	CStatic m_ctrlPic2;
	CStatic m_ctrlPic3;
	CStatic m_ctrlPic4;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CStatic m_ctrlPic5;
	CButton m_ctrlButton5;
	afx_msg void OnBnClickedButton5();
	CListBox m_ctrlList1;

	CTabCtrl m_tab;
	CComboBox m_ctrlCombo1;
};
