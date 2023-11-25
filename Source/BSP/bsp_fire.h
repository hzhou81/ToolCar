/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_colorful.h
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        蜂鸣器驱动
* @details      
* @par History  见如下说明
*                 
* version:		liusen_20170717
*/

#ifndef __BSP_FIRE_H__
#define __BSP_FIRE_H__

#include "stm32f10x.h"


#define FIRE_PIN	GPIO_Pin_1
#define FIRE_PORT	GPIOA
#define FIRE_RCC	RCC_APB2Periph_GPIOA



void Fire_Control(int v_OnOff);



#endif


