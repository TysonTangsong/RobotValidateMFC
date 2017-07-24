
// RobotValidateMFCDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#include "DLLSample.h"
#include <fstream>
#include <iostream>

using namespace std;

// CRobotValidateMFCDlg �Ի���
class CRobotValidateMFCDlg : public CDialogEx
{
// ����
public:
	CRobotValidateMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ROBOTVALIDATEMFC_DIALOG };

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
	// �ٶȱ���
	double m_dbSpeedRate;
	// ���Ʊ���
	double m_dbLimitRate;
	// ĩ������ٶ�
	double m_dbMaxSpeed;
	// ĩ�������ٶ�
	double m_dbMaxAcc;
	// ��ʼ��x����
	float m_flStartX;
	// ��ʼ��Y����
	float m_flStartY;
	// ��ʼ��Z����
	float m_flStartZ;
	// ��ʼ��R
	float m_flStartR;
	// �м��X����
	float m_flMidX;
	float m_flMidY;
	// �м��Z����
	float m_flMidZ;
	// �м��R
	float m_flMidR;
	// Ŀ���X
	float m_flTargetX;
	// Ŀ���Y
	float m_flTartgetY;
	// Ŀ���Z
	float m_flTargetZ;
	// Ŀ���R
	float m_flTargetR;
	// L1
	float m_flArmOne;
	// L2
	float m_flArmTwo;
	// ����������
	CComboBox m_cbRobotType;
	// ���Գ���
	CComboBox m_cbTestMode;
	afx_msg void OnBnClickedStartTest();


	afx_msg void OnCbnSelchangeCombo1();
	// SCARA S�ͼӼ��٣�PTP�����Գ���
	bool OnScara_S_Line_Test(void);
	// SCARAֱ�߲岹
	bool OnScara_Straight_Line_Test(void);
	// ���ſ˱��㷨
	bool OnScara_InverseJacobian(void);
	// deleta s�ͼӼ���
	bool OnDelta_S_Line_Test(void);
};
