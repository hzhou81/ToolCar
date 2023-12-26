/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         main.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        主函数
* @details      
* @par History  
*                 
* version:		liusen_20170717
*/
#include "stm32f10x.h"
#include "app_motor.h"
#include "app_bluetooth.h"
#include "app_linewalking.h"
#include "bsp.h"
#include "sys.h"
#include "bsp_lightseeking.h"
#include "bsp_linewalking.h"
#include "bsp_gs.h"
#define CAR_SPEED 2000 //2000(OK) 3000(OK)
#define SPIN_SPEED 3160 //1400(OK) 2000(OK)
#define DELAY_LONG_TIME 500
#define DELAY_TIME 26

int main(void)
{	
	int L1_old=HIGH;
	int L1=HIGH;
	int R1=HIGH;//左光敏元器件和右光敏元器件的变量值
	int isRunning=0;	
	int iGs=0;
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;
	/*外设初始化*/
	bsp_init();

	while (1)
	{	
		if(isRunning==1){
			bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	 //获得黑线检测状态
			if( LineL1 == LOW && LineL2==LOW && LineR1==LOW && LineR2==HIGH)	   //左直角转弯
    		{  
				Car_SpinLeft(SPIN_SPEED, SPIN_SPEED);
				delay_ms(DELAY_TIME);
			}
    		else if ( LineR2 == LOW && LineR1==LOW && LineL2==LOW && LineL1==HIGH)  	//右直角转弯
    		{  
				Car_SpinRight(SPIN_SPEED, SPIN_SPEED);
				delay_ms(DELAY_TIME);
			}
		    else if (LineL2 == LOW && LineR1 == HIGH)	  //中间黑线上的传感器微调车左转
		    {   
				Car_Left(CAR_SPEED);   
			}
			else if (LineL2 == HIGH && LineR1 == LOW)	  //中间黑线上的传感器微调车右转
		    {   
				Car_Right(CAR_SPEED);   
			}
			else if(LineL1==LOW && LineL2==HIGH && LineR1==HIGH && LineR2==HIGH) //转弯过程中由于车子大幅度偏左了，调整车头左转
			{
				Car_Left(CAR_SPEED*1.1f);
			}
			else if(LineL1==HIGH && LineL2==HIGH && LineR1==HIGH && LineR2==LOW) //转弯过程中由于车子大幅度偏右了，调整车头右转
			{
				Car_Right(CAR_SPEED*1.1f);
			}
		    else if(LineL2 == LOW && LineR1 == LOW) // 直线前进
		    {  
				Car_Run(CAR_SPEED);
			}
		}

		iGs=Get_GS_Value();//从灰度传感器获取值
		if(iGs<2500){//遇到白色终点就调头
			isRunning=0;
			Car_TurnAround(SPIN_SPEED,SPIN_SPEED);
			//delay_ms(DELAY_LONG_TIME);
		}

		L1_old=L1;
		bsp_GetLightSeeking(&L1, &R1);//从驱动层获取值, 我把光敏元器件插在左，所以只有L1能读到数值
		if(L1!=L1_old){
			isRunning=1;
			delay_ms(DELAY_TIME);//光线变化后不要马上启动车子
		}
		
		//app_bluetooth_deal();
	}
}
