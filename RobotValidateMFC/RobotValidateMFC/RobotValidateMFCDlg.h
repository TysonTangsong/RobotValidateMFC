
// RobotValidateMFCDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#include "DLLSample.h"
#include <fstream>
#include <iostream>

using namespace std;

// CRobotValidateMFCDlg 对话框
class CRobotValidateMFCDlg : public CDialogEx
{
// 构造
public:
	CRobotValidateMFCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ROBOTVALIDATEMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 速度比例
	double m_dbSpeedRate;
	// 限制比例
	double m_dbLimitRate;
	// 末端最大速度
	double m_dbMaxSpeed;
	// 末端最大加速度
	double m_dbMaxAcc;
	// 起始点x坐标
	float m_flStartX;
	// 起始点Y坐标
	float m_flStartY;
	// 起始点Z坐标
	float m_flStartZ;
	// 起始点R
	float m_flStartR;
	// 中间点X坐标
	float m_flMidX;
	float m_flMidY;
	// 中间点Z坐标
	float m_flMidZ;
	// 中间点R
	float m_flMidR;
	// 目标点X
	float m_flTargetX;
	// 目标点Y
	float m_flTartgetY;
	// 目标点Z
	float m_flTargetZ;
	// 目标点R
	float m_flTargetR;
	// L1
	float m_flArmOne;
	// L2
	float m_flArmTwo;
	// 机器人类型
	CComboBox m_cbRobotType;
	// 测试程序
	CComboBox m_cbTestMode;
	afx_msg void OnBnClickedStartTest();


	afx_msg void OnCbnSelchangeCombo1();
	// SCARA S型加减速（PTP）测试程序
	bool OnScara_S_Line_Test(void);
	// SCARA直线插补
	bool OnScara_Straight_Line_Test(void);
	// 逆雅克比算法
	bool OnScara_InverseJacobian(void);
	// deleta s型加减速
	bool OnDelta_S_Line_Test(void);
};
