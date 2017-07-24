#ifndef _DLL_SAMPLE_H
#define _DLL_SAMPLE_H


#ifdef __cplusplus
extern "C" {
#endif

#define DLL_SAMPLE_API_IM __declspec(dllimport)

typedef struct
    {
     double speed_rate; //速度比例，为运动的实时速度比例，格式为：0.01，表示1%的速度
     double limit_rate; //限制比例，在实时最大速度的基础上在进行限制，格式：0.95，表示最大速度的95%为此时最大速度
	 double Speed_end_effector;			//末端执行器最大速度
     double Acc_end_effector;				//末端执行器最大加加速度
}S_Line_Fix_Type;

typedef struct
    {
     double x_pre;//起始点坐标
     double y_pre;
     double z_pre;
     double c_pre;//绕X轴旋转角度
     double x_now;//目标点坐标
     double y_now;
     double z_now;
     double c_now;
}POSE_DECARE_Type;



typedef struct
    {
     double arm_one;
     double arm_two;
//	 AXIS_RANGE_Type axis_range;         //运动范围
}DH_PARAMETER_Type;


typedef struct
{
	float Max;
	float Min;
}RANGE_Type;

typedef struct
    {
     float theta_J1_now;
     float theta_J2_now;
     float theta_J3_now;
     float theta_J4_now;
     float theta_J5_now;
     float theta_J6_now;
     float Point_Speed_Persent; 
}THETA_JOINT_Type;

typedef struct
   {
	double J1_ARR[10000];
    double J2_ARR[10000];
    double J3_ARR[10000];
    double J4_ARR[10000];
    int  Dir_J1_Arr[10000];
    int  Dir_J2_Arr[10000];
    int  Dir_J3_Arr[10000];
    int  Dir_J4_Arr[10000];
}Inverse_Kinematics_Type;

typedef struct
    {
     double Speed_J1_Arr[10000];      //一轴速度插补数组
     double Offset_J1_Arr[10000];     //一轴位移插补数组
     double Speed_J2_Arr[10000];
     double Offset_J2_Arr[10000];
     double Speed_J3_Arr[10000];
     double Offset_J3_Arr[10000];
     double Speed_J4_Arr[10000];
     double Offset_J4_Arr[10000];
	 int Runin_Cnt1;
}S_Line_J_Runin;

typedef struct
   {
     double X_end_effector_Arr[10000];	//x坐标插补数组
     double Y_end_effector_Arr[10000];	//y坐标插补数组
     double Z_end_effector_Arr[10000];	//z坐标插补数组
     double C_end_effector_Arr[10000];	//姿态c插补数组
     double Vx_Joint_Arr[10000];			//末端速度x方向的插补分速度
     double Vy_Joint_Arr[10000];			//末端速度y方向的插补分速度
     double Vz_Joint_Arr[10000];			//末端速度z方向的插补分速度
     double Vc_Joint_Arr[10000];			//末端速度r方向的插补分速度
}T_Line_end_effector_Type;


// 导出/导入函数声明
DLL_SAMPLE_API_IM int SCARA_S_Line(S_Line_Fix_Type *S_Line_Fix,POSE_DECARE_Type* Decare_Point,S_Line_J_Runin *S_Line_Runin);

DLL_SAMPLE_API_IM int Delta_S_line(S_Line_Fix_Type *S_Line_Fix,POSE_DECARE_Type* Decare_Point,S_Line_J_Runin *S_Line_Runin);

DLL_SAMPLE_API_IM int SCARA_Straight_Line(POSE_DECARE_Type* Decare_Point,S_Line_Fix_Type *S_Line_Fix,S_Line_J_Runin *S_Line_Runin,T_Line_end_effector_Type *T_Line_end_effector);

DLL_SAMPLE_API_IM int SCARA_Inverse_Jacobian(DH_PARAMETER_Type* SCARA_This,POSE_DECARE_Type* Decare_Point,THETA_JOINT_Type* Theta_Hand,POSE_DECARE_Type* Decare_Hand,S_Line_Fix_Type *S_Line_Fix,THETA_JOINT_Type* Theta_Point,T_Line_end_effector_Type *T_Line_end_effector,Inverse_Kinematics_Type* Inverse_Kinematics,S_Line_J_Runin *S_Line_Runin);

DLL_SAMPLE_API_IM int Inverse_Kinematics_SCARA(DH_PARAMETER_Type* SCARA_This,POSE_DECARE_Type* Decare_Hand, THETA_JOINT_Type* Theta_Hand );

#undef DLL_SAMPLE_API_IM

#ifdef __cplusplus
}
#endif

#endif
