/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_buzzer.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        寻光模式运动
* @details      
* @par History  见如下说明
*                 
* version:		liusen_20170717
*/

#include "app_buzzer.h"
#include "bsp_buzzer.h"
#include "sys.h"
#include "delay.h"

/**
* Function       whistle
* @author        liusen
* @date          2017.07.25
* @brief         小车鸣笛
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void whistle(void)
{
  Buzzer_Control(ON);   //发声音
  delay_ms(100);                  //延时100ms
  Buzzer_Control(OFF);   //不发声音
  delay_ms(1);                    //延时1ms

  Buzzer_Control(ON);   //发声音
  delay_ms(200);                  //延时200ms
  Buzzer_Control(OFF);   //不发声音
  delay_ms(2);                    //延时2ms
  return;
}

/**
* Function       BeepOnOffMode
* @author        liusen
* @date          2017.07.20    
* @brief         模式启动关闭声音
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void BeepOnOffMode(void)
{
	Buzzer_Control(ON);   //发声音
  	delay_ms(1000);     //延时100ms
  	Buzzer_Control(OFF);   //不发声音
}

/**
* Function       ModeBEEP
* @author        liusen
* @date          2017.08.17
* @brief         模式指示声音
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void ModeBEEP(int mode)
{
	int i;
	for (i = 0; i < mode + 1; i++)
	{
		Buzzer_Control(ON);   //发声音
		delay_ms(100);
		Buzzer_Control(OFF);   //不发声音
		delay_ms(100);
	}
	delay_ms(100);
	Buzzer_Control(OFF);   //发声音
}
