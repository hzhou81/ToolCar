/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_buzzer.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        Ѱ��ģʽ�˶�
* @details      
* @par History  ������˵��
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
* @brief         С������
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void whistle(void)
{
  Buzzer_Control(ON);   //������
  delay_ms(100);                  //��ʱ100ms
  Buzzer_Control(OFF);   //��������
  delay_ms(1);                    //��ʱ1ms

  Buzzer_Control(ON);   //������
  delay_ms(200);                  //��ʱ200ms
  Buzzer_Control(OFF);   //��������
  delay_ms(2);                    //��ʱ2ms
  return;
}

/**
* Function       BeepOnOffMode
* @author        liusen
* @date          2017.07.20    
* @brief         ģʽ�����ر�����
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void BeepOnOffMode(void)
{
	Buzzer_Control(ON);   //������
  	delay_ms(1000);     //��ʱ100ms
  	Buzzer_Control(OFF);   //��������
}

/**
* Function       ModeBEEP
* @author        liusen
* @date          2017.08.17
* @brief         ģʽָʾ����
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void ModeBEEP(int mode)
{
	int i;
	for (i = 0; i < mode + 1; i++)
	{
		Buzzer_Control(ON);   //������
		delay_ms(100);
		Buzzer_Control(OFF);   //��������
		delay_ms(100);
	}
	delay_ms(100);
	Buzzer_Control(OFF);   //������
}
