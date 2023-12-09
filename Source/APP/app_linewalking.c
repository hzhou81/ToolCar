/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_linewalking.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        巡线模式运动
* @details      
* @par History  见如下说明
*                 
* version:		liusen_20170717
*/

#include "app_linewalking.h"
#include "bsp_linewalking.h"
#include "sys.h"
#include "app_motor.h"
#include "delay.h"

#define CAR_SPEED 3000	  //2000(OK) 3000(OK)
#define SPIN_SPEED 2000   //1400(OK) 2000(OK)
#define DELAY_TIME 10
/**
* Function       app_LineWalking
* @author        liusen
* @date          2017.07.20    
* @brief         巡线模式运动
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void app_LineWalking(void)
{
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;

	bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	 //获得黑线检测状态

	if( (LineL1 == LOW || LineL2 == LOW) && LineR2 == LOW)	  //左大弯
    {
      	Car_SpinLeft(3500, 3500);
		delay_ms(80);
    }
    else if ( LineL1 == LOW && (LineR1 == LOW || LineR2 == LOW))	 //右大弯
	{ 
      	Car_SpinRight(3500, 3500);
		delay_ms(80);
    }  
    else if( LineL1 == LOW )	   //左最外侧检测
    {  
		Car_SpinLeft(3000, 3000);
		delay_ms(10);
	}
    else if ( LineR2 == LOW)  	//右最外侧检测
    {  
		Car_SpinRight(3000, 3000);
		delay_ms(10);
	}
    else if (LineL2 == LOW && LineR1 == HIGH)	  //中间黑线上的传感器微调车左转
    {   
		Car_Left(2500);   
	}
	else if (LineL2 == HIGH && LineR1 == LOW)	  //中间黑线上的传感器微调车右转
    {   
		Car_Right(2500);   
	}
    else if(LineL2 == LOW && LineR1 == LOW) // 直线前进
    {  
		Car_Run(1500);
	}	
}

/**
* Function       app_LineWalking1
* @author        孙汇洲
* @date          2023.11.26    
* @brief         巡线模式运动(新的应用于二手车交易中心的模式)
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void app_LineWalking1(void)
{
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;

	bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	 //获得黑线检测状态
	/*
	if( (LineL1 == LOW || LineL2 == LOW) && LineR2 == LOW)	  //左大弯
    {
      	Car_SpinLeft(3500, 3500);
		delay_ms(80);
    }
    else if ( LineL1 == LOW && (LineR1 == LOW || LineR2 == LOW))	 //右大弯
	{ 
      	Car_SpinRight(3500, 3500);
		delay_ms(80);
    }  
    else */
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
    else if(LineL2 == LOW && LineR1 == LOW) // 直线前进
    {  
		Car_Run(CAR_SPEED);
	}	
}
