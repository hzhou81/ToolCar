/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_iravoid.c
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        �����������Դ�ļ�
* @details      
* @par History  ������˵��
*                 
* version:	liusen_20170717
*/

#include "bsp_lightseeking.h"
#include "stm32f10x.h"

/**
* Function       bsp_GetLightSeeking
* @author        liusen
* @date          2017.07.20    
* @brief         ��ȡѰ��״̬
* @param[in]     int *p_iL1, int *p_iR1 ��ֵָ���Ӧ��ַ��״ֵ̬
* @param[out]    ָ��ֵ
* @return        void
* @par History   ��
*/

void bsp_GetLightSeeking(int *p_iL1, int *p_iR1)
{
	*p_iL1 = GPIO_ReadInputDataBit(LightSeek_L1_PORT, LightSeek_L1_PIN);
	*p_iR1 = GPIO_ReadInputDataBit(LightSeek_R1_PORT, LightSeek_R1_PIN);	
}
