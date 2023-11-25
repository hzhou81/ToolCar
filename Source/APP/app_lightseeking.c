/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_lightseeking.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        寻光模式运动
* @details      
* @par History  见如下说明
*                 
* version:		liusen_20170717
*/

#include "app_lightseeking.h"
#include "bsp_lightseeking.h"
#include "sys.h"
#include "app_motor.h"
#include "delay.h"



/**
* Function       app_LightSeeking
* @author        liusen
* @date          2017.07.20    
* @brief         寻光运动
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void app_LightSeeking(void)
{
	int L1 = 1, R1 = 1;

	bsp_GetLightSeeking(&L1, &R1);
  	if( L1 == LOW && R1 == HIGH)
    {
		Car_SpinRight(6000, 5000);
    }
    else if ( L1 == HIGH && R1 == LOW)
    {
      	Car_SpinLeft(5000, 6000);
    }  
    else if(L1 == HIGH && R1 == HIGH) 
    {  
		Car_Run(7200);
	}
	else if (L1 == LOW && R1 == LOW)
    {   
		Car_Stop();
	}	
}
