/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp.c
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        ���������
* @details      
* @par History  ������˵��
*                 
* version:	liusen_20170717
*/


#include "bsp.h"
#include "stdio.h"
#include "bsp_buzzer.h"
/**
* Function       bsp_init
* @author        liusen
* @date          2015.01.03    
* @brief         Ӳ���豸��ʼ��
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void bsp_init(void)
{
	delay_init();
	
	Colorful_GPIO_Init();				/*�߲�̽�յ�*/
	Colorful_PWM_Init(1000,0, 1000,0, 1000,0); /*RGB PWM*/
	MOTOR_GPIO_Init();  				/*���GPIO��ʼ��*/
	Motor_PWM_Init(7200, 0, 7200, 0);	/*����Ƶ��PWMƵ�� 72000000/7200=10khz	  */
	Servo_GPIO_Init();				    /*����ӿ�GPIO��ʼ��*/	
	TIM1_Int_Init(9, 72);				/*100Khz�ļ���Ƶ�ʣ�������10Ϊ10us  */ 
	LineWalking_GPIO_Init();			/*Ѳ�ߴ�����GPIO��ʼ��*/
	IRAvoid_GPIO_Init();				/*������ϴ�����GPIO��ʼ��*/
	LightSeeking_GPIO_Init();			/*Ѱ��GPIO��ʼ��*/
	Ultrasonic_GPIO_Init();				/*������GPIO��ʼ��*/
	bsp_Ultrasonic_Timer2_Init();		/*������TIM2��ʼ��*/
	//Uart1_init(9600);					/*���Խӿڴ��� */
	Uart2_init(9600);					/*Э�鴦��ӿ� */
	Adc_Init();	   						/*��ѹ����ADC��ʼ��*/
	Buzzer_GPIO_Init();					/*������GPIO��ʼ��*/
	Buzzer_Control(OFF); 				/*�ȹرշ�����*/
	Fire_GPIO_Init();					/*���GPIO��ʼ��*/
	Fire_Control(OFF);				    /*���ر�*/
	bsp_GS_Init();						/*�Ҷȴ�������ʼ��*/
	Angle_J1 = 90;						/*��ʼ�������̨����ǰ*/
	printf("init ok!");
}
