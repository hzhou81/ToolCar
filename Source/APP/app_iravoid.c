/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_iravoid.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        ��������˶�
* @details      
* @par History  ������˵��
*                 
* version:		liusen_20170717
*/

#include "app_iravoid.h"
#include "bsp_iravoid.h"
#include "sys.h"
#include "app_motor.h"
#include "delay.h"
#include "bsp_servo.h"
#include "bsp_colorful.h"

/**
* Function       app_IRAvoid
* @author        liusen
* @date          2017.07.20    
* @brief         ����ģʽ�˶� ����������߲ʵ�
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void app_IRAvoid(void)
{
	int IRL1 = 1, IRR1 = 1;

	bsp_GetIRavoid(&IRL1, &IRR1);
  	if( IRL1 == HIGH && IRR1 == LOW)
    {
      	Car_SpinLeft(7200, 7200);
		Angle_J1 = 180;
		bsp_Colorful_Control(0, 1, 0);
    }
    else if ( IRL1 == LOW && IRR1 == HIGH)
    {
      	Car_SpinRight(7200, 7200);
		Angle_J1 = 0;
		bsp_Colorful_Control(0, 0, 1);
    }  
    else if (IRL1 == HIGH && IRR1 == HIGH)
    {   
		Car_Run(7200);
		Angle_J1 = 90;
		bsp_Colorful_Control(1, 1, 1);
	}
    else if(IRL1 == LOW && IRR1 == LOW) 
    {  
		Car_SpinRight(7200, 7200);
		Angle_J1 = 0;
		bsp_Colorful_Control(1, 0, 0);
		delay_ms(500);
	}	
}

/**
* Function       app_IRFollow
* @author        liusen
* @date          2017.07.20    
* @brief         ����ģʽ�˶� 
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void app_IRFollow(void)	   
{
	int IRL1 = 1, IRR1 = 1;

	bsp_GetIRavoid(&IRL1, &IRR1);
  	if( IRL1 == HIGH && IRR1 == LOW)
    {
      	Car_SpinRight(7200, 7200);
		bsp_Colorful_Control(0, 1, 0);
    }
    else if ( IRL1 == LOW && IRR1 == HIGH)
    {
      	Car_SpinLeft(7200, 7200);
		bsp_Colorful_Control(0, 0, 1);
    }  
    else if (IRL1 == HIGH && IRR1 == HIGH)
    {   
		Car_Stop();
		bsp_Colorful_Control(1, 0, 0);
	}
    else if(IRL1 == LOW && IRR1 == LOW) 
    {  
		Car_Run(7200);
		Angle_J1 = 0;
		bsp_Colorful_Control(1, 1, 1);
		delay_ms(500);
	}	
}
