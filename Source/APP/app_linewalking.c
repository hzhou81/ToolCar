/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_linewalking.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        Ѳ��ģʽ�˶�
* @details      
* @par History  ������˵��
*                 
* version:		liusen_20170717
*/

#include "app_linewalking.h"
#include "bsp_linewalking.h"
#include "sys.h"
#include "app_motor.h"
#include "delay.h"

#define CAR_SPEED 3000	  //2000(OK) 3000(OK)
#define SPIN_SPEED 2000   //1400(OK) 2000(OK)
#define DELAY_TIME 10
/**
* Function       app_LineWalking
* @author        liusen
* @date          2017.07.20    
* @brief         Ѳ��ģʽ�˶�
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void app_LineWalking(void)
{
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;

	bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	 //��ú��߼��״̬

	if( (LineL1 == LOW || LineL2 == LOW) && LineR2 == LOW)	  //�����
    {
      	Car_SpinLeft(3500, 3500);
		delay_ms(80);
    }
    else if ( LineL1 == LOW && (LineR1 == LOW || LineR2 == LOW))	 //�Ҵ���
	{ 
      	Car_SpinRight(3500, 3500);
		delay_ms(80);
    }  
    else if( LineL1 == LOW )	   //���������
    {  
		Car_SpinLeft(3000, 3000);
		delay_ms(10);
	}
    else if ( LineR2 == LOW)  	//���������
    {  
		Car_SpinRight(3000, 3000);
		delay_ms(10);
	}
    else if (LineL2 == LOW && LineR1 == HIGH)	  //�м�����ϵĴ�����΢������ת
    {   
		Car_Left(2500);   
	}
	else if (LineL2 == HIGH && LineR1 == LOW)	  //�м�����ϵĴ�����΢������ת
    {   
		Car_Right(2500);   
	}
    else if(LineL2 == LOW && LineR1 == LOW) // ֱ��ǰ��
    {  
		Car_Run(1500);
	}	
}

/**
* Function       app_LineWalking1
* @author        �����
* @date          2023.11.26    
* @brief         Ѳ��ģʽ�˶�(�µ�Ӧ���ڶ��ֳ��������ĵ�ģʽ)
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void app_LineWalking1(void)
{
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;

	bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	 //��ú��߼��״̬
	/*
	if( (LineL1 == LOW || LineL2 == LOW) && LineR2 == LOW)	  //�����
    {
      	Car_SpinLeft(3500, 3500);
		delay_ms(80);
    }
    else if ( LineL1 == LOW && (LineR1 == LOW || LineR2 == LOW))	 //�Ҵ���
	{ 
      	Car_SpinRight(3500, 3500);
		delay_ms(80);
    }  
    else */
	if( LineL1 == LOW && LineL2==LOW && LineR1==LOW && LineR2==HIGH)	   //��ֱ��ת��
    {  
		Car_SpinLeft(SPIN_SPEED, SPIN_SPEED);
		delay_ms(DELAY_TIME);
	}
    else if ( LineR2 == LOW && LineR1==LOW && LineL2==LOW && LineL1==HIGH)  	//��ֱ��ת��
    {  
		Car_SpinRight(SPIN_SPEED, SPIN_SPEED);
		delay_ms(DELAY_TIME);
	}
    else if (LineL2 == LOW && LineR1 == HIGH)	  //�м�����ϵĴ�����΢������ת
    {   
		Car_Left(CAR_SPEED);   
	}
	else if (LineL2 == HIGH && LineR1 == LOW)	  //�м�����ϵĴ�����΢������ת
    {   
		Car_Right(CAR_SPEED);   
	}
    else if(LineL2 == LOW && LineR1 == LOW) // ֱ��ǰ��
    {  
		Car_Run(CAR_SPEED);
	}	
}
