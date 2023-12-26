/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         main.c	
* @author       liusen
* @version      V1.0
* @date         2017.07.17
* @brief        ������
* @details      
* @par History  
*                 
* version:		liusen_20170717
*/
#include "stm32f10x.h"
#include "app_motor.h"
#include "app_bluetooth.h"
#include "app_linewalking.h"
#include "bsp.h"
#include "sys.h"
#include "bsp_lightseeking.h"
#include "bsp_linewalking.h"
#include "bsp_gs.h"
#define CAR_SPEED 2000 //2000(OK) 3000(OK)
#define SPIN_SPEED 3160 //1400(OK) 2000(OK)
#define DELAY_LONG_TIME 500
#define DELAY_TIME 26

int main(void)
{	
	int L1_old=HIGH;
	int L1=HIGH;
	int R1=HIGH;//�����Ԫ�������ҹ���Ԫ�����ı���ֵ
	int isRunning=0;	
	int iGs=0;
	int LineL1 = 1, LineL2 = 1, LineR1 = 1, LineR2 = 1;
	/*�����ʼ��*/
	bsp_init();

	while (1)
	{	
		if(isRunning==1){
			bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);	 //��ú��߼��״̬
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
			else if(LineL1==LOW && LineL2==HIGH && LineR1==HIGH && LineR2==HIGH) //ת����������ڳ��Ӵ����ƫ���ˣ�������ͷ��ת
			{
				Car_Left(CAR_SPEED*1.1f);
			}
			else if(LineL1==HIGH && LineL2==HIGH && LineR1==HIGH && LineR2==LOW) //ת����������ڳ��Ӵ����ƫ���ˣ�������ͷ��ת
			{
				Car_Right(CAR_SPEED*1.1f);
			}
		    else if(LineL2 == LOW && LineR1 == LOW) // ֱ��ǰ��
		    {  
				Car_Run(CAR_SPEED);
			}
		}

		iGs=Get_GS_Value();//�ӻҶȴ�������ȡֵ
		if(iGs<2500){//������ɫ�յ�͵�ͷ
			isRunning=0;
			Car_TurnAround(SPIN_SPEED,SPIN_SPEED);
			//delay_ms(DELAY_LONG_TIME);
		}

		L1_old=L1;
		bsp_GetLightSeeking(&L1, &R1);//���������ȡֵ, �Ұѹ���Ԫ��������������ֻ��L1�ܶ�����ֵ
		if(L1!=L1_old){
			isRunning=1;
			delay_ms(DELAY_TIME);//���߱仯��Ҫ������������
		}
		
		//app_bluetooth_deal();
	}
}
