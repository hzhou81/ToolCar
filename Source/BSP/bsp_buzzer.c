/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_colorful.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        七彩探照灯驱动
* @details      
* @par History  见如下说明
*                 
* version:		liusen_20170717
*/

#include "bsp_buzzer.h"
#include "sys.h"
#include "bsp_gpio.h"




/**
* Function       Buzzer_Control
* @author        liusen
* @date          2015.01.03    
* @brief         蜂鸣器控制
* @param[in]     v_RedOnOff : 蜂鸣器开关
* @param[out]    void
* @retval        void
* @par History   
*/
void Buzzer_Control(int v_OnOff)
{
	
	Buzzer_GPIO_Init();

	if(v_OnOff == OFF) //关闭蜂鸣器
	{
		GPIO_SetBits(Buzzer_PORT, Buzzer_PIN);
	}
	else
	{
		GPIO_ResetBits(Buzzer_PORT, Buzzer_PIN);
	}

}
