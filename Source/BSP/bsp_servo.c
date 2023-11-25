/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         bsp_servo.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        6�������������Դ�ļ�
* @details      
* @par History  ������˵��
*                 
* version:		liusen_20170717
*/

#include "bsp_servo.h"
#include "delay.h"


/*�Ƕȷ�Χ 0~180*/
int Angle_J1 = 0;
int Angle_J2 = 0;
int Angle_J3 = 0;
int Angle_J4 = 0;
int Angle_J5 = 0;
int Angle_J6 = 0;


/**
* Function       Servo_J1
* @author        liusen
* @date          2017.07.17    
* @brief         ���1���ƺ���
* @param[in]     v_iAngle �Ƕȣ�0~180��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void Servo_J1(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J1_PORT, Servo_J1_PIN );		//������ӿڵ�ƽ�ø�
	delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J1_PORT, Servo_J1_PIN );	//������ӿڵ�ƽ�õ�
	delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}

/**
* Function       Servo_J2
* @author        liusen
* @date          2017.07.17    
* @brief         ���2���ƺ���
* @param[in]     v_iAngle �Ƕȣ�0~180��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void Servo_J2(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J2_PORT, Servo_J2_PIN );		//������ӿڵ�ƽ�ø�
	delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J2_PORT, Servo_J2_PIN );	//������ӿڵ�ƽ�õ�
	delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}

/**
* Function       Servo_J3
* @author        liusen
* @date          2017.07.17    
* @brief         ���3���ƺ���
* @param[in]     v_iAngle �Ƕȣ�0~180��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void Servo_J3(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J3_PORT, Servo_J3_PIN );		//������ӿڵ�ƽ�ø�
	delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J3_PORT, Servo_J3_PIN );	//������ӿڵ�ƽ�õ�
	delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}

/**
* Function       Servo_J4
* @author        liusen
* @date          2017.07.17    
* @brief         ���4���ƺ���
* @param[in]     v_iAngle �Ƕȣ�0~180��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void Servo_J4(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J4_PORT, Servo_J4_PIN );		//������ӿڵ�ƽ�ø�
	delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J4_PORT, Servo_J4_PIN );	//������ӿڵ�ƽ�õ�
	delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}

/**
* Function       Servo_J5
* @author        liusen
* @date          2017.07.17    
* @brief         ���5���ƺ���
* @param[in]     v_iAngle �Ƕȣ�0~180��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void Servo_J5(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J5_PORT, Servo_J5_PIN );		//������ӿڵ�ƽ�ø�
	delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J5_PORT, Servo_J5_PIN );	//������ӿڵ�ƽ�õ�
	delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}

/**
* Function       Servo_J6
* @author        liusen
* @date          2017.07.17    
* @brief         ���5���ƺ���
* @param[in]     v_iAngle �Ƕȣ�0~180��
* @param[out]    void
* @retval        void
* @par History   ��
*/
void Servo_J6(int v_iAngle)/*����һ�����庯��������ģ�ⷽʽ����PWMֵ*/
{
	int pulsewidth;    						//�����������

	pulsewidth = (v_iAngle * 11) + 500;			//���Ƕ�ת��Ϊ500-2480 ������ֵ

	GPIO_SetBits(Servo_J6_PORT, Servo_J6_PIN );		//������ӿڵ�ƽ�ø�
	delay_us(pulsewidth);					//��ʱ����ֵ��΢����

	GPIO_ResetBits(Servo_J6_PORT, Servo_J6_PIN );	//������ӿڵ�ƽ�õ�
	delay_ms(20 - pulsewidth/1000);			//��ʱ������ʣ��ʱ��
}

/**
* Function       front_detection
* @author        liusen
* @date          2017.07.17    
* @brief         ��̨�����ǰ
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void front_detection()
{
	int i = 0;
  	//�˴�ѭ���������٣�Ϊ������С�������ϰ���ķ�Ӧ�ٶ�
  	for(i=0; i <= 15; i++) 						//����PWM��������Ч��ʱ�Ա�֤��ת����Ӧ�Ƕ�
  	{
    	Servo_J1(90);						//ģ�����PWM
  	}
}

/**
* Function       left_detection
* @author        liusen
* @date          2017.07.17    
* @brief         ��̨�������
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void left_detection()
{
	int i = 0;
	for(i = 0; i <= 15; i++) 						//����PWM��������Ч��ʱ�Ա�֤��ת����Ӧ�Ƕ�
	{
		Servo_J1(175);					//ģ�����PWM
	}
}

/**
* Function       right_detection
* @author        liusen
* @date          2017.07.17    
* @brief         ��̨�������
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void right_detection()
{
	int i = 0;
	for(i = 0; i <= 15; i++) 						//����PWM��������Ч��ʱ�Ա�֤��ת����Ӧ�Ƕ�
	{
		Servo_J1(5);						//ģ�����PWM
	}
}

