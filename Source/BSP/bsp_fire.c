										 /**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_fire.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        灭火驱动
* @details      
* @par History  见如下说明
*                 
* version:		liusen_20170717
*/

#include "bsp_fire.h"
#include "sys.h"
#include "bsp_gpio.h"





/**
* Function       Fire_Control
* @author        liusen
* @date          2015.01.03    
* @brief         蜂鸣器控制
* @param[in]     v_RedOnOff : 蜂鸣器开关
* @param[out]    void
* @retval        void
* @par History   
*/
void Fire_Control(int v_OnOff)
{

	Fire_GPIO_Init();
	if(v_OnOff == OFF) //关闭风扇
	{
		GPIO_SetBits(FIRE_PORT, FIRE_PIN);
	}
	else
	{
		GPIO_ResetBits(FIRE_PORT, FIRE_PIN);
	}

}
