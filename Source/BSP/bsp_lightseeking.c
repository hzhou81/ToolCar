/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_iravoid.c
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        红外避障驱动源文件
* @details      
* @par History  见如下说明
*                 
* version:	liusen_20170717
*/

#include "bsp_lightseeking.h"
#include "stm32f10x.h"

/**
* Function       bsp_GetLightSeeking
* @author        liusen
* @date          2017.07.20    
* @brief         获取寻光状态
* @param[in]     int *p_iL1, int *p_iR1 赋值指针对应地址的状态值
* @param[out]    指针值
* @return        void
* @par History   无
*/

void bsp_GetLightSeeking(int *p_iL1, int *p_iR1)
{
	*p_iL1 = GPIO_ReadInputDataBit(LightSeek_L1_PORT, LightSeek_L1_PIN);
	*p_iR1 = GPIO_ReadInputDataBit(LightSeek_R1_PORT, LightSeek_R1_PIN);	
}
