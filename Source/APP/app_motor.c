/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_motor.c
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        小车运动控制函数
* @details      
* @par History  见如下说明
*                 
* version:	liusen_20170717
*/
#include "app_motor.h"
#include "sys.h"
#include "bsp_motor.h"
#include "delay.h"
#include "bsp_lightseeking.h"
#include "bsp_linewalking.h"

#define  LeftMotor_Go()			{GPIO_SetBits(Motor_Port, Left_MotoA_Pin); GPIO_ResetBits(Motor_Port, Left_MotoB_Pin);}
#define  LeftMotor_Back()		{GPIO_ResetBits(Motor_Port, Left_MotoA_Pin); GPIO_SetBits(Motor_Port, Left_MotoB_Pin);}
#define  LeftMotor_Stop()		{GPIO_ResetBits(Motor_Port, Left_MotoA_Pin); GPIO_ResetBits(Motor_Port, Left_MotoB_Pin);}

#define  RightMotor_Go()		{GPIO_SetBits(Motor_Port, Right_MotoA_Pin); GPIO_ResetBits(Motor_Port, Right_MotoB_Pin);}
#define  RightMotor_Back()		{GPIO_ResetBits(Motor_Port, Right_MotoA_Pin); GPIO_SetBits(Motor_Port, Right_MotoB_Pin);}
#define  RightMotor_Stop()		{GPIO_ResetBits(Motor_Port, Right_MotoA_Pin); GPIO_ResetBits(Motor_Port, Right_MotoB_Pin);}

#define  LeftMotorPWM(Speed)	TIM_SetCompare2(TIM4, Speed);
#define  RightMotorPWM(Speed)	TIM_SetCompare1(TIM4, Speed);		



/**
* Function       Car_Run
* @author        liusen
* @date          2017.07.17    
* @brief         小车前进
* @param[in]     Speed  （0~7200） 速度范围
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Run(int Speed)
{
	LeftMotor_Go();
	RightMotor_Go();
	LeftMotorPWM(Speed);		  
	RightMotorPWM(Speed);	
}

/**
* Function       Car_Back
* @author        liusen
* @date          2017.07.17    
* @brief         小车后退
* @param[in]     Speed  （0~7200） 速度范围
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Back(int Speed)
{
	LeftMotor_Back();
	RightMotor_Back();

	LeftMotorPWM(Speed);		  
	RightMotorPWM(Speed);	
}

/**
* Function       Car_Left
* @author        liusen
* @date          2017.07.17    
* @brief         小车左转
* @param[in]     Speed  （0~7200） 速度范围
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Left(int Speed)
{
	LeftMotor_Stop();
	RightMotor_Go();

	LeftMotorPWM(0);		  
	RightMotorPWM(Speed);		
}

/**
* Function       Car_Right
* @author        liusen
* @date          2017.07.17    
* @brief         小车右转
* @param[in]     Speed  （0~7200） 速度范围
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Right(int Speed)
{
	LeftMotor_Go();
	RightMotor_Stop();

	LeftMotorPWM(Speed);		  
	RightMotorPWM(0);		
}

/**
* Function       Car_Stop
* @author        liusen
* @date          2017.07.17    
* @brief         小车刹车
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_Stop(void)
{
	LeftMotor_Stop();
	RightMotor_Stop();

	LeftMotorPWM(0);		  
	RightMotorPWM(0);		
}

/**
* Function       Car_SpinLeft
* @author        liusen
* @date          2017.07.17    
* @brief         小车左旋
* @param[in]     LeftSpeed：左电机速度  RightSpeed：右电机速度 取值范围：（0~7200）
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_SpinLeft(int LeftSpeed, int RightSpeed)
{
	LeftMotor_Back();
	RightMotor_Go();

	LeftMotorPWM(LeftSpeed);		  
	RightMotorPWM(RightSpeed);		
}

/**
* Function       Car_SpinRight
* @author        liusen
* @date          2017.07.17    
* @brief         小车右旋
* @param[in]     LeftSpeed：左电机速度  RightSpeed：右电机速度 取值范围：（0~7200）
* @param[out]    void
* @retval        void
* @par History   无
*/

void Car_SpinRight(int LeftSpeed, int RightSpeed)
{
	LeftMotor_Go();
	RightMotor_Back();

	LeftMotorPWM(LeftSpeed);		  
	RightMotorPWM(RightSpeed);		
}

/**
* Function       Car_TurnAround
* @author        孙汇洲
* @date          2023.12.18    
* @brief         小车顺车掉头后停止
* @param[in]     LeftSpeed：左电机速度  RightSpeed：右电机速度 取值范围：（0~7200）
* @param[out]    void
* @retval        void
* @par History   无
*/
void Car_TurnAround(int LeftSpeed,int RightSpeed)
{
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;
	//Car_Left(LeftSpeed);
	//delay_ms(1000);
	Car_SpinRight(LeftSpeed,RightSpeed);
	delay_ms(500);
	while(1){
		bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	 //获得黑线检测状态
		if(LineL2==LOW || LineR1==LOW) break;
		Car_SpinRight(LeftSpeed,RightSpeed);
		delay_ms(10);
	}
	Car_Stop();
}
