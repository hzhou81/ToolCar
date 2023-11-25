/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_lightseeking.h
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        寻光驱动头文件
* @details      
* @par History  见如下说明
*                 
* version:	liusen_20170717
*/

/*

	从车身后面往前看： 左侧到右边	  对应原理图 IN6(PB15) || IN8(PB13)

*/

#ifndef __BSP_LIGHTSEEKING_H__
#define __BSP_LIGHTSEEKING_H__	



#define LightSeek_L1_RCC		RCC_APB2Periph_GPIOB
#define LightSeek_R1_RCC		RCC_APB2Periph_GPIOA

#define LightSeek_L1_PIN		GPIO_Pin_3
#define LightSeek_R1_PIN		GPIO_Pin_5

#define LightSeek_L1_PORT		GPIOB
#define LightSeek_R1_PORT		GPIOA



void bsp_GetLightSeeking(int *p_iL1, int *p_iR1);



#endif
