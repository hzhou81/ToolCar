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

#include "bsp_iravoid.h"
#include "stm32f10x.h"


/**
* Function       bsp_GetIRavoid
* @author        liusen
* @date          2017.08.10    
* @brief         避障传感器获取状态
* @param[in]     int *p_iL1, int *p_iR1 左右变量指针
* @param[out]    void
* @retval        void
* @par History   无
*/

void bsp_GetIRavoid(int *p_iL1, int *p_iR1)
{
	*p_iL1 = GPIO_ReadInputDataBit(IRAvoid_L1_PORT, IRAvoid_L1_PIN);
	*p_iR1 = GPIO_ReadInputDataBit(IRAvoid_R1_PORT, IRAvoid_R1_PIN);	
}

/**
* Function       bsp_GetIRavoid_Data
* @author        liusen
* @date          2017.07.10    
* @brief         避障传感器获取状态上报调用
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/

int bsp_GetIRavoid_Data(void)
{
	int L1,R1,ReturnValue;
	L1 = GPIO_ReadInputDataBit(IRAvoid_L1_PORT, IRAvoid_L1_PIN);
	R1 = GPIO_ReadInputDataBit(IRAvoid_R1_PORT, IRAvoid_R1_PIN);
	ReturnValue = (L1 == 0 ? 10 : 0);
	ReturnValue += (R1 == 0 ? 1 : 0);
	return ReturnValue;
}

