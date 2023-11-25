/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_ultrasonic.C
* @author       liusen
* @version      V1.0
* @date         2017.07.21
* @brief        ������������ͷ�ļ�
* @details      
* @par History  ������˵��
*                 
* version:	liusen_20170717
*/

#include "bsp_ultrasonic.h"
#include "stm32f10x.h"
#include "delay.h"


/*��¼��ʱ���������*/
unsigned int overcount = 0;


/**
* Function       bsp_getUltrasonicDistance
* @author        liusen
* @date          2017.07.20    
* @brief         ��ȡ��������
* @param[in]     void
* @param[out]    void
* @return        ���븡��ֵ
* @par History   ��
*/

float bsp_getUltrasonicDistance(void)
{
	float length = 0, sum = 0;
	u16 tim;
	unsigned int  i = 0;

	/*��5�����ݼ���һ��ƽ��ֵ*/
	while(i != 5)
	{
		GPIO_SetBits(TRIG_PORT, TRIG_PIN);  //�����źţ���Ϊ�����ź�
		delay_us(20);  						//�ߵ�ƽ�źų���10us
		GPIO_ResetBits(TRIG_PORT, TRIG_PIN);

		/*�ȴ������ź�*/
		while(GPIO_ReadInputDataBit(ECHO_PORT, ECHO_PIN) == RESET);
		TIM_Cmd(TIM2,ENABLE);//�����źŵ�����������ʱ������
		
		i+=1; //ÿ�յ�һ�λ����ź�+1���յ�5�ξͼ����ֵ
		while(GPIO_ReadInputDataBit(ECHO_PORT, ECHO_PIN) == SET);//�����ź���ʧ
		TIM_Cmd(TIM2, DISABLE);//�رն�ʱ��
		
		tim = TIM_GetCounter(TIM2);//��ȡ��TIM2���Ĵ����еļ���ֵ��һ�߼�������ź�ʱ��
		
		length = (tim + overcount * 1000) / 58.0;//ͨ�������źż������
		
		sum = length + sum;
		TIM2->CNT = 0;  //��TIM2�����Ĵ����ļ���ֵ����
		overcount = 0;  //�ж������������
		delay_ms(1);
	}
	length = sum / 5;
	return length;		//������Ϊ��������ֵ
}

/**
* Function       bsp_Ultrasonic_Timer2_Init
* @author        liusen
* @date          2017.07.21    
* @brief         ��ʼ����ʱ��TIM2
* @param[in]     void
* @param[out]    void
* @return        ���븡��ֵ
* @par History   ��
*/

void bsp_Ultrasonic_Timer2_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructer;
	NVIC_InitTypeDef NVIC_InitStructer;


	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	/*��ʱ��TIM2��ʼ��*/
	TIM_DeInit(TIM2);
	TIM_TimeBaseInitStructer.TIM_Period = 999;//��ʱ����Ϊ1000
	TIM_TimeBaseInitStructer.TIM_Prescaler = 71; //��Ƶϵ��72
	TIM_TimeBaseInitStructer.TIM_ClockDivision = TIM_CKD_DIV1;//����Ƶ
	TIM_TimeBaseInitStructer.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructer);
	
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//���������ж�

	/*��ʱ���жϳ�ʼ��*/
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructer.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructer.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructer.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructer.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructer);
	TIM_Cmd(TIM2, DISABLE);//�رն�ʱ��ʹ��

}

void TIM2_IRQHandler(void) //�жϣ��������źźܳ��ǣ�����ֵ������ظ����������ж��������������
{
	if(TIM_GetITStatus(TIM2,TIM_IT_Update) != RESET)
	{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);//����жϱ�־
		overcount++;	
	}
}
