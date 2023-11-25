/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_ultrasonic.c
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        ����������ģʽԴ�ļ�
* @details      
* @par History  ������˵��
*                 
* version:	liusen_20170717
*/

#include "app_ultrasonic.h"
#include "bsp_ultrasonic.h"
#include "bsp_servo.h"
#include "sys.h"
#include "app_motor.h"
#include "delay.h"



/**
* Function       app_ultrasonic_mode
* @author        liusen
* @date          2017.07.20    
* @brief         ����������
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void app_ultrasonic_mode(void)
{
	int Len = 0;

	Len = bsp_getUltrasonicDistance(); 
	
	//printf("CSB:%d", Len);  	

	if(Len < 25)//��ֵΪ�����ϰ���ľ��룬���԰�ʵ���������   
    { 
	  Len = (u16)bsp_getUltrasonicDistance();
      while(Len < 25)//�ٴ��ж��Ƿ����ϰ��������ת������󣬼����ж�
      {    
	  	Car_Stop();//ͣ��   
        Car_SpinRight(3000, 3000);
		delay_ms(300);
        Len = (u16)bsp_getUltrasonicDistance();
      }
    }
    else 
	{
		Car_Run(3000); //���ϰ��ֱ��  		
	}
	
}

/**
* Function       app_ultrasonic_servo_mode
* @author        liusen
* @date          2017.07.20    
* @brief         ����������
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void app_ultrasonic_servo_mode(void)
{
	int Len = 0;
	int LeftDistance = 0, RightDistance = 0;

	Len = (u16)bsp_getUltrasonicDistance();

    if(Len <= 30)//�������ϰ���ʱ
    {

		Car_Stop();//ͣ���������
		
		Angle_J1 = 180;		// ���
		delay_ms(500); //�ȴ������λ
		Len = bsp_getUltrasonicDistance();			
		LeftDistance = Len;	  
	 
		Angle_J1 = 0;		// �ұ�
		delay_ms(500); //�ȴ������λ
		Len = bsp_getUltrasonicDistance();					
		RightDistance = Len;


		Angle_J1 = 90;		//��λ
		delay_ms(500); //�ȴ������λ

		if((LeftDistance < 22 ) &&( RightDistance < 22 ))//��������������ϰ��￿�ñȽϽ�
		{
			Car_SpinRight(3000, 2000);//��ת��ͷ
			delay_ms(500); //�ȴ������λ
		}
		else if(LeftDistance >= RightDistance)//��߱��ұ߿տ�
		{      
			Car_SpinLeft(3000, 2000);//��ת
			delay_ms(500); //�ȴ������λ
		}
		else//�ұ߱���߿տ�
		{
			Car_SpinRight(3000, 2000); //��ת
			delay_ms(500); //�ȴ������λ
		}
    }
    else if(Len > 30)//�������ϰ���ʱ
    {
		Car_Run(3000); 	 //���ϰ��ֱ��     
    }
}
