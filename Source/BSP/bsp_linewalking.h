/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_linewalking.h
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        巡线驱动头文件
* @details      
* @par History  见如下说明
*                 
* version:	liusen_20170717
*/

/*

	从车身后面往前看： 左侧到右边巡线传感器顺序为  L1 L2 |黑线| R1  R2	  对应原理图 IN2 IN1 |黑线| IN3 IN4

*/

#ifndef __BSP_LINEWALKING_H__
#define __BSP_LINEWALKING_H__	


#define LineWalk_L1_RCC		RCC_APB2Periph_GPIOC
#define LineWalk_L2_RCC		RCC_APB2Periph_GPIOC
#define LineWalk_R1_RCC    	RCC_APB2Periph_GPIOC
#define LineWalk_R2_RCC		RCC_APB2Periph_GPIOB

#define LineWalk_L1_PIN		GPIO_Pin_14
#define LineWalk_L2_PIN		GPIO_Pin_13
#define LineWalk_R1_PIN		GPIO_Pin_15
#define LineWalk_R2_PIN		GPIO_Pin_12

#define LineWalk_L1_PORT	GPIOC
#define LineWalk_L2_PORT	GPIOC
#define LineWalk_R1_PORT	GPIOC
#define LineWalk_R2_PORT	GPIOB


void bsp_GetLineWalking(int *p_iL1, int *p_iL2, int *p_iR1, int *p_iR2);
int bsp_GetLineWalking_Data(void);


#endif
