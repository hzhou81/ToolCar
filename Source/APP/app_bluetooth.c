/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_ultrasonic.c
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        ������λ��Э�����ҵ��
* @details      
* @par History  ������˵��
*                 
* version:	liusen_20170717
*/

#include "app_bluetooth.h"
#include "bsp_ultrasonic.h"
#include "bsp_servo.h"
#include "sys.h"
#include "app_motor.h"
#include "delay.h"
#include "protocol.h"
#include "bsp.h"
#include "app_linewalking.h"
#include "app_lightseeking.h"
#include "app_iravoid.h"
#include "app_ultrasonic.h"
#include "app_colormode.h"

int g_modeSelect = 0;  //0��Ĭ��APK��λ��״̬;  1:����ң�� 2:Ѳ��ģʽ 3:���������� 4: �߲�̽�� 5: Ѱ��ģʽ 6: �������
u8 g_Boolfire = 0;	    //�����ʱ�ر��ϱ��������ϱ����ݻ�ʹ�Ҷ������IOģʽ��ͻ��

/**
* Function       serial_data_postback
* @author        Danny
* @date          2017.07.25
* @brief         ���ɼ��Ĵ���������ͨ�����ڴ������λ����ʾ
* @param[in]     void
* @retval        void
* @par History   ��
*/
void serial_data_postback()
{
	//С���������������ɼ�����Ϣ������λ����ʾ
	//�����ʽ��:
	//    ������ ��ѹ  �Ҷ�  Ѳ��  ������� Ѱ��
	//$4WD,CSB120,PV8.3,GS214,LF1011,HW11,GM11#
	float csbLen=0.0f, power; 
	u16 gs, lf; 
	u8 hw, gm;
	int L1, R1;
	//������
	
	csbLen = bsp_getUltrasonicDistance();
	power = Get_Battery_Volotage();
	gs = Get_GS_Value();
	lf = bsp_GetLineWalking_Data();
	hw = bsp_GetIRavoid_Data();
	bsp_GetLightSeeking(&L1, &R1);
	gm = L1 * 10 + R1;
	//printf("hhhh");
	printf("$4WD,CSB%.2f,PV%1.2f,GS%d,LF%04d,HW%02d,GM%02d#",csbLen, power, gs, lf, hw, gm);																				
	return;
}

/**
* Function       app_bluetooth_deal
* @author        liusen
* @date          2017.07.20    
* @brief         ����������λ��Э�鴦��
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   ��
*/
void app_bluetooth_deal(void)
{
	if (newLineReceived)
   	{
		Protocol();
	}

	// �л���ͬ����ģʽ, ����ģʽ��ʾ
	switch (g_modeSelect)
	{
		case 1: break; 								//��ʱ����
		case 2: app_LineWalking(); break; 			//Ѳ��ģʽ
		case 3: app_ultrasonic_mode();  break;  	//����������ģʽ
		case 4: app_colorMode(); break;  //�߲���ɫʶ��ģʽ
		case 5: app_LightSeeking(); break;  		//Ѱ��ģʽ
		case 6: app_IRFollow(); break;  			//����ģʽ
		default:break;
	}
	
	//��С������ƽ��ÿ�뷢�Ͳɼ������ݸ��ֻ�����apk
	//���⴮�ڴ�ӡ�����ٶȹ���,���apk�޷���������
	if (g_modeSelect == 0 && g_Boolfire == 0)
	{
		if (g_count >= 100000)
		{ 
			g_count = 0;
			serial_data_postback();
		}		
	}

}
