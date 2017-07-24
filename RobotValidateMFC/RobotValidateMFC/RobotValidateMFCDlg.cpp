
// RobotValidateMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RobotValidateMFC.h"
#include "RobotValidateMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRobotValidateMFCDlg �Ի���




CRobotValidateMFCDlg::CRobotValidateMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRobotValidateMFCDlg::IDD, pParent)
	, m_dbSpeedRate(0.01)
	, m_dbLimitRate(0.01)
	, m_dbMaxSpeed(1)
	, m_dbMaxAcc(1)
	, m_flStartX(0)
	, m_flStartY(0)
	, m_flStartZ(0)
	, m_flStartR(0)
	, m_flMidX(0)
	, m_flMidY(0)
	, m_flMidZ(0)
	, m_flMidR(0)
	, m_flTargetX(0)
	, m_flTartgetY(0)
	, m_flTargetZ(0)
	, m_flTargetR(0)
	, m_flArmOne(0)
	, m_flArmTwo(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRobotValidateMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SPEED_RATE, m_dbSpeedRate);
	DDV_MinMaxDouble(pDX, m_dbSpeedRate, 0.01, 1);
	DDX_Text(pDX, IDC_EDIT_LIMIT_RATE, m_dbLimitRate);
	DDV_MinMaxDouble(pDX, m_dbLimitRate, 0.01, 1);
	DDX_Text(pDX, IDC_EDIT_MAX_SPEED, m_dbMaxSpeed);
	DDV_MinMaxDouble(pDX, m_dbMaxSpeed, 1, 100000);
	DDX_Text(pDX, IDC_EDIT_MAX_ACC, m_dbMaxAcc);
	DDV_MinMaxDouble(pDX, m_dbMaxAcc, 1, 100000);
	DDX_Text(pDX, IDC_EDIT_START_X, m_flStartX);
	DDX_Text(pDX, IDC_EDIT_START_Y, m_flStartY);
	DDX_Text(pDX, IDC_EDIT_START_Z, m_flStartZ);
	DDX_Text(pDX, IDC_EDIT_START_R, m_flStartR);
	DDX_Text(pDX, IDC_EDIT_MID_X, m_flMidX);
	DDX_Text(pDX, IDC_EDIT_MID_Y, m_flMidY);
	DDX_Text(pDX, IDC_EDIT_MID_Z, m_flMidZ);
	DDX_Text(pDX, IDC_EDIT_MID_R, m_flMidR);
	DDX_Text(pDX, IDC_EDIT_TAR_X, m_flTargetX);
	DDX_Text(pDX, IDC_EDIT_TAR_Y, m_flTartgetY);
	DDX_Text(pDX, IDC_EDIT_TAR_Z, m_flTargetZ);
	DDX_Text(pDX, IDC_EDIT_TAR_R, m_flTargetR);
	DDX_Text(pDX, IDC_EDIT1, m_flArmOne);
	DDX_Text(pDX, IDC_EDIT2, m_flArmTwo);
	DDX_Control(pDX, IDC_COMBO1, m_cbRobotType);
	DDX_Control(pDX, IDC_COMBO2, m_cbTestMode);
}

BEGIN_MESSAGE_MAP(CRobotValidateMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_START_TEST, &CRobotValidateMFCDlg::OnBnClickedStartTest)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CRobotValidateMFCDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CRobotValidateMFCDlg ��Ϣ�������

BOOL CRobotValidateMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//ShowWindow(SW_MAXIMIZE);

	m_cbRobotType.SetCurSel(0);
	m_cbTestMode.SetCurSel(0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRobotValidateMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRobotValidateMFCDlg::OnPaint()
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
HCURSOR CRobotValidateMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//��ʼ����
void CRobotValidateMFCDlg::OnBnClickedStartTest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if(m_cbRobotType.GetCurSel() == 0)
	{
		//SCARA��������ز���
		if (m_cbTestMode.GetCurSel() == 0)
		{
			//s�ͼӼ���
			OnScara_S_Line_Test();

		}else if (m_cbTestMode.GetCurSel() == 1)
		{
			//ֱ�߲岹
			OnScara_Straight_Line_Test();

		}else
		{
			//���ſ˱��㷨
			OnScara_InverseJacobian();
		}

	}else
	{
		//delta��������ز���

		OnDelta_S_Line_Test();
	}


	AfxMessageBox(_T("���в�����ɣ�"),MB_ICONINFORMATION | MB_OK);
	////��Ҫ������ļ�   
	//ifstream iFile("scoresheet.csv");  
	//string   readStr((std::istreambuf_iterator<char>(iFile)),  std::istreambuf_iterator<char>());   
	//cout <<  readStr.c_str(); 
}


void CRobotValidateMFCDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//AfxMessageBox(_T("g"));
	int nIndex = m_cbRobotType.GetCurSel();
	
	if (nIndex == 0)//SCARA
	{
		//m_cbTestMode.Clear();
		for (int i=m_cbTestMode.GetCount(); i>=0; i--)
		{
			m_cbTestMode.DeleteString(i);
		}
		
		m_cbTestMode.AddString(_T("S�ͼӼ��٣�PTP��"));
		m_cbTestMode.AddString(_T("ֱ�߲岹����"));
		m_cbTestMode.AddString(_T("���ſ˱��㷨"));
	}else
	{
		for (int i=m_cbTestMode.GetCount(); i>=0; i--)
		{
			m_cbTestMode.DeleteString(i);
		}
		m_cbTestMode.AddString(_T("S�ͼӼ��٣�PTP��"));
	}
	m_cbTestMode.SetCurSel(0);
}


// SCARA S�ͼӼ��٣�PTP�����Գ���
bool CRobotValidateMFCDlg::OnScara_S_Line_Test(void)
{
	//S_Line_Fix_Type *S_Line_Fix,POSE_DECARE_Type* Decare_Point,S_Line_J_Runin *S_Line_Runin
	//1.��ʼ���ṹ���ֵ
	//���Խṹ��
	//����ṹ��
	S_Line_Fix_Type *S_Line_Fix;
	POSE_DECARE_Type* Decare_Point;
	//����ṹ��
	S_Line_J_Runin *S_Line_Runin;

	S_Line_Fix = new S_Line_Fix_Type();
	S_Line_Fix->speed_rate = m_dbSpeedRate;
	S_Line_Fix->limit_rate = m_dbLimitRate;
	S_Line_Fix->Acc_end_effector = m_dbMaxAcc;
	S_Line_Fix->Speed_end_effector = m_dbMaxSpeed;

	Decare_Point = new POSE_DECARE_Type();
	Decare_Point->x_pre = m_flStartX;
	Decare_Point->y_pre = m_flStartY;
	Decare_Point->z_pre = m_flStartZ;
	Decare_Point->c_pre = m_flStartR;

	Decare_Point->x_now = m_flTargetX;
	Decare_Point->y_now = m_flTartgetY;
	Decare_Point->z_now = m_flTargetZ;
	Decare_Point->c_now = m_flTargetR;

	S_Line_Runin = new S_Line_J_Runin();

	//2.�������Գ���
	int ret = SCARA_S_Line(S_Line_Fix,Decare_Point,S_Line_Runin);


	//3.��������,�����ݴ浽�����ļ�
	//�����ļ������   
	ofstream oFile;   

	//��Ҫ������ļ�   
	oFile.open("SCARA_S_Line_ResultData.csv", ios::out | ios::trunc);    // �����ͺ����׵����һ����Ҫ��excel �ļ�  
	oFile << "Speed_J1" << "," << "Offset_J1" << "," 
		<< "Speed_J2" << "," << "Offset_J2" << "," 
		<< "Speed_J3" << "," << "Offset_J3" << "," 
		<< "Speed_J4" << "," << "Offset_J4" << endl;   

	for (int i=0; i<ret; i++)
	{
		oFile << S_Line_Runin->Speed_J1_Arr[i] << "," << S_Line_Runin->Offset_J1_Arr[i] << "," 
			<< S_Line_Runin->Speed_J2_Arr[i] << "," << S_Line_Runin->Offset_J2_Arr[i] << "," 
			<< S_Line_Runin->Speed_J3_Arr[i] << "," << S_Line_Runin->Offset_J3_Arr[i] << "," 
			<< S_Line_Runin->Speed_J4_Arr[i] << "," << S_Line_Runin->Offset_J4_Arr[i] << endl;   
	}

	oFile.close();   

	//�ͷ���Դ
	delete S_Line_Fix;
	delete Decare_Point;
	delete S_Line_Runin;
	return true;
}


// SCARAֱ�߲岹
bool CRobotValidateMFCDlg::OnScara_Straight_Line_Test(void)
{
	//int SCARA_Straight_Line
	//(POSE_DECARE_Type* Decare_Point,
	//S_Line_Fix_Type *S_Line_Fix,
	//S_Line_J_Runin *S_Line_Runin,
	//T_Line_end_effector_Type *T_Line_end_effector);

	//1.��ʼ������
	POSE_DECARE_Type* Decare_Point = new POSE_DECARE_Type();
	S_Line_Fix_Type *S_Line_Fix = new S_Line_Fix_Type();
	S_Line_J_Runin *S_Line_Runin = new S_Line_J_Runin();
	T_Line_end_effector_Type *T_Line_end_effector = new T_Line_end_effector_Type();

	Decare_Point->x_pre = m_flStartX;
	Decare_Point->y_pre = m_flStartY;
	Decare_Point->z_pre = m_flStartZ;
	Decare_Point->c_pre = m_flStartR;

	Decare_Point->x_now = m_flTargetX;
	Decare_Point->y_now = m_flTartgetY;
	Decare_Point->z_now = m_flTargetZ;
	Decare_Point->c_now = m_flTargetR;

	S_Line_Fix->speed_rate = m_dbSpeedRate;
	S_Line_Fix->limit_rate = m_dbLimitRate;
	S_Line_Fix->Acc_end_effector = m_dbMaxAcc;
	S_Line_Fix->Speed_end_effector = m_dbMaxSpeed;

	//2.���в���

	int ret = SCARA_Straight_Line(Decare_Point,S_Line_Fix,S_Line_Runin,T_Line_end_effector);


	//3.��������
	//�����ļ������   
	ofstream oFile;   

	//��Ҫ������ļ�   
	oFile.open("SCARA_Straight_Line_ResultData.csv", ios::out | ios::trunc);    // �����ͺ����׵����һ����Ҫ��excel �ļ�  
	oFile << "Speed_J1" << "," << "Offset_J1" << "," 
		<< "Speed_J2" << "," << "Offset_J2" << "," 
		<< "Speed_J3" << "," << "Offset_J3" << "," 
		<< "Speed_J4" << "," << "Offset_J4" << "," 
		<< "X_end_effector" << "," << "Y_end_effector" << ","
		<< "Z_end_effector" << "," << "C_end_effector" << ","
		<< "Vx_Joint" << "," << "Vy_Joint" << ","
		<< "Vz_Joint" << "," << "Vc_Joint" << endl;   

	for (int i=0; i<ret; i++)
	{
		oFile << S_Line_Runin->Speed_J1_Arr[i] << "," << S_Line_Runin->Offset_J1_Arr[i] << "," 
			<< S_Line_Runin->Speed_J2_Arr[i] << "," << S_Line_Runin->Offset_J2_Arr[i] << "," 
			<< S_Line_Runin->Speed_J3_Arr[i] << "," << S_Line_Runin->Offset_J3_Arr[i] << "," 
			<< S_Line_Runin->Speed_J4_Arr[i] << "," << S_Line_Runin->Offset_J4_Arr[i] << ","
			
			<< T_Line_end_effector->X_end_effector_Arr[i] << "," << T_Line_end_effector->Y_end_effector_Arr[i] << ","
			<< T_Line_end_effector->Z_end_effector_Arr[i] << "," << T_Line_end_effector->C_end_effector_Arr[i] << ","
			<< T_Line_end_effector->Vx_Joint_Arr[i] << "," << T_Line_end_effector->Vy_Joint_Arr[i] << ","
			<< T_Line_end_effector->Vz_Joint_Arr[i] << "," << T_Line_end_effector->Vc_Joint_Arr[i] << endl;   
	}

	oFile.close();   

	//�ͷ���Դ
	delete Decare_Point;
	delete S_Line_Fix;
	delete S_Line_Runin;
	delete T_Line_end_effector;


	return true;
}


// ���ſ˱��㷨
bool CRobotValidateMFCDlg::OnScara_InverseJacobian(void)
{
	//int SCARA_Inverse_Jacobian
	//(DH_PARAMETER_Type* SCARA_This,
	//POSE_DECARE_Type* Decare_Point,
	//THETA_JOINT_Type* Theta_Hand,
	//POSE_DECARE_Type* Decare_Hand,
	//S_Line_Fix_Type *S_Line_Fix,
	//THETA_JOINT_Type* Theta_Point,
	//T_Line_end_effector_Type *T_Line_end_effector,
	//Inverse_Kinematics_Type* Inverse_Kinematics,
	//S_Line_J_Runin *S_Line_Runin);

	//1.����ռ�
	DH_PARAMETER_Type* SCARA_This = new DH_PARAMETER_Type();
	POSE_DECARE_Type* Decare_Point = new POSE_DECARE_Type();
	THETA_JOINT_Type* Theta_Hand = new THETA_JOINT_Type();
	POSE_DECARE_Type* Decare_Hand = new POSE_DECARE_Type();
	S_Line_Fix_Type *S_Line_Fix = new S_Line_Fix_Type();
	THETA_JOINT_Type* Theta_Point = new THETA_JOINT_Type();

	T_Line_end_effector_Type *T_Line_end_effector = new T_Line_end_effector_Type();
	Inverse_Kinematics_Type* Inverse_Kinematics = new Inverse_Kinematics_Type();
	S_Line_J_Runin *S_Line_Runin = new S_Line_J_Runin();

	//2.��ʼ������
	SCARA_This->arm_one = m_flArmOne;
	SCARA_This->arm_two = m_flArmTwo;

	Decare_Point->x_pre = m_flStartX;
	Decare_Point->y_pre = m_flStartY;
	Decare_Point->z_pre = m_flStartZ;
	Decare_Point->c_pre = m_flStartR;

	Decare_Point->x_now = m_flTargetX;
	Decare_Point->y_now = m_flTartgetY;
	Decare_Point->z_now = m_flTargetZ;
	Decare_Point->c_now = m_flTargetR;

	Decare_Hand->x_pre = m_flStartX;
	Decare_Hand->y_pre = m_flStartY;
	Decare_Hand->z_pre = m_flStartZ;
	Decare_Hand->c_pre = m_flStartR;

	Decare_Hand->x_now = m_flTargetX;
	Decare_Hand->y_now = m_flTartgetY;
	Decare_Hand->z_now = m_flTargetZ;
	Decare_Hand->c_now = m_flTargetR;

	S_Line_Fix->Acc_end_effector = m_dbMaxAcc;
	S_Line_Fix->limit_rate = m_dbLimitRate;
	S_Line_Fix->speed_rate = m_dbSpeedRate;
	S_Line_Fix->Speed_end_effector = m_dbMaxSpeed;
	//Theta_Point->
	//3.���в���
	int ret = SCARA_Inverse_Jacobian(SCARA_This,Decare_Point,Theta_Hand,Decare_Hand,S_Line_Fix,Theta_Point,
		T_Line_end_effector,Inverse_Kinematics,S_Line_Runin);

	//4.������
	//�����ļ������   
	ofstream oFile;   

	//��Ҫ������ļ�   
	oFile.open("SCARA_Inverse_Jacobian_ResultData.csv", ios::out | ios::trunc);    // �����ͺ����׵����һ����Ҫ��excel �ļ�  
	oFile << "Speed_J1" << "," << "Offset_J1" << "," 
		<< "Speed_J2" << "," << "Offset_J2" << "," 
		<< "Speed_J3" << "," << "Offset_J3" << "," 
		<< "Speed_J4" << "," << "Offset_J4" << "," 
		<< "J1" << "," << "J2" << ","
		<< "J3" << "," << "J4" << ","
		<< "Dir_J1" << "," << "Dir_J2" << ","
		<< "Dir_J3" << "," << "Dir_J4" << endl;   
	
	for (int i=0; i<ret-1; i++)
	{
		oFile << S_Line_Runin->Speed_J1_Arr[i] << "," << S_Line_Runin->Offset_J1_Arr[i] << "," 
			<< S_Line_Runin->Speed_J2_Arr[i] << "," << S_Line_Runin->Offset_J2_Arr[i] << "," 
			<< S_Line_Runin->Speed_J3_Arr[i] << "," << S_Line_Runin->Offset_J3_Arr[i] << "," 
			<< S_Line_Runin->Speed_J4_Arr[i] << "," << S_Line_Runin->Offset_J4_Arr[i] << ","

			<< Inverse_Kinematics->J1_ARR[i] << "," << Inverse_Kinematics->J2_ARR[i] << ","
			<< Inverse_Kinematics->J3_ARR[i] << "," << Inverse_Kinematics->J4_ARR[i] << ","
			<< Inverse_Kinematics->Dir_J1_Arr[i] << "," << Inverse_Kinematics->Dir_J2_Arr[i] << ","
			<< Inverse_Kinematics->Dir_J3_Arr[i] << "," << Inverse_Kinematics->Dir_J4_Arr[i] << endl;   
	}

	oFile.close();   

	//5.�ͷ���Դ
	delete Theta_Point;
	delete Decare_Point;
	delete S_Line_Fix;
	delete SCARA_This;
	delete Theta_Hand;
	delete Decare_Hand;
	
	delete S_Line_Runin;
	delete Inverse_Kinematics;
	delete T_Line_end_effector;

	return true;
}


// deleta s�ͼӼ���
bool CRobotValidateMFCDlg::OnDelta_S_Line_Test(void)
{
	//����ṹ��
	S_Line_Fix_Type *S_Line_Fix;
	POSE_DECARE_Type* Decare_Point;
	//����ṹ��
	S_Line_J_Runin *S_Line_Runin;
	//1.��ʼ���ṹ���ֵ
	S_Line_Fix = new S_Line_Fix_Type();
	S_Line_Fix->speed_rate = m_dbSpeedRate;
	S_Line_Fix->limit_rate = m_dbLimitRate;

	Decare_Point = new POSE_DECARE_Type();
	Decare_Point->x_pre = m_flStartX;
	Decare_Point->y_pre = m_flStartY;
	Decare_Point->z_pre = m_flStartZ;
	Decare_Point->c_pre = m_flStartR;

	Decare_Point->x_now = m_flTargetX;
	Decare_Point->y_now = m_flTartgetY;
	Decare_Point->z_now = m_flTargetZ;
	Decare_Point->c_now = m_flTargetR;

	S_Line_Runin = new S_Line_J_Runin();

	//2.delta_s_line_test
	int ret = Delta_S_line(S_Line_Fix,Decare_Point,S_Line_Runin);

	//3.��������
	//�����ļ������   
	ofstream oFile;   

	//��Ҫ������ļ�   
	oFile.open("Delta_S_line_ResultData.csv", ios::out | ios::trunc);    // �����ͺ����׵����һ����Ҫ��excel �ļ�  
	oFile << "Speed_J1" << "," << "Offset_J1" << "," 
		<< "Speed_J2" << "," << "Offset_J2" << "," 
		<< "Speed_J3" << "," << "Offset_J3" << "," 
		<< "Speed_J4" << "," << "Offset_J4" << endl;   

	for (int i=0; i<ret; i++)
	{
		oFile << S_Line_Runin->Speed_J1_Arr[i] << "," << S_Line_Runin->Offset_J1_Arr[i] << "," 
			<< S_Line_Runin->Speed_J2_Arr[i] << "," << S_Line_Runin->Offset_J2_Arr[i] << "," 
			<< S_Line_Runin->Speed_J3_Arr[i] << "," << S_Line_Runin->Offset_J3_Arr[i] << "," 
			<< S_Line_Runin->Speed_J4_Arr[i] << "," << S_Line_Runin->Offset_J4_Arr[i] << endl;   
	}

	oFile.close();   

	//4.�ͷ���Դ
	delete S_Line_Fix;
	delete Decare_Point;
	delete S_Line_Runin;


	return true;
}
