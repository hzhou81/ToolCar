/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_ultrasonic.c
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        超声波避障模式源文件
* @details      
* @par History  见如下说明
*                 
* version:	liusen_20170717
*/

#include "app_ultrasonic.h"
#include "bsp_ultrasonic.h"
#include "bsp_servo.h"
#include "sys.h"
#include "app_motor.h"
#include "delay.h"



/**
* Function       app_ultrasonic_mode
* @author        liusen
* @date          2017.07.20    
* @brief         超声波避障
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void app_ultrasonic_mode(void)
{
	int Len = 0;

	Len = bsp_getUltrasonicDistance(); 
	
	//printf("CSB:%d", Len);  	

	if(Len < 25)//数值为碰到障碍物的距离，可以按实际情况设置   
    { 
	  Len = (u16)bsp_getUltrasonicDistance();
      while(Len < 25)//再次判断是否有障碍物，若有则转动方向后，继续判断
      {    
	  	Car_Stop();//停车   
        Car_SpinRight(3000, 3000);
		delay_ms(300);
        Len = (u16)bsp_getUltrasonicDistance();
      }
    }
    else 
	{
		Car_Run(3000); //无障碍物，直行  		
	}
	
}

/**
* Function       app_ultrasonic_servo_mode
* @author        liusen
* @date          2017.07.20    
* @brief         超声波避障
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void app_ultrasonic_servo_mode(void)
{
	int Len = 0;
	int LeftDistance = 0, RightDistance = 0;

	Len = (u16)bsp_getUltrasonicDistance();

    if(Len <= 30)//当遇到障碍物时
    {

		Car_Stop();//停下来做测距
		
		Angle_J1 = 180;		// 左边
		delay_ms(500); //等待舵机到位
		Len = bsp_getUltrasonicDistance();			
		LeftDistance = Len;	  
	 
		Angle_J1 = 0;		// 右边
		delay_ms(500); //等待舵机到位
		Len = bsp_getUltrasonicDistance();					
		RightDistance = Len;


		Angle_J1 = 90;		//归位
		delay_ms(500); //等待舵机到位

		if((LeftDistance < 22 ) &&( RightDistance < 22 ))//当左右两侧均有障碍物靠得比较近
		{
			Car_SpinRight(3000, 2000);//旋转掉头
			delay_ms(500); //等待舵机到位
		}
		else if(LeftDistance >= RightDistance)//左边比右边空旷
		{      
			Car_SpinLeft(3000, 2000);//左转
			delay_ms(500); //等待舵机到位
		}
		else//右边比左边空旷
		{
			Car_SpinRight(3000, 2000); //右转
			delay_ms(500); //等待舵机到位
		}
    }
    else if(Len > 30)//当遇到障碍物时
    {
		Car_Run(3000); 	 //无障碍物，直行     
    }
}
