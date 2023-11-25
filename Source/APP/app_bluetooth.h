/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_bluetooth.h
* @author       liusen
* @version      V1.0
* @date         2017.08.18
* @brief        ������λ������Э��ҵ������
* @details      
* @par History  ������˵��
*                 
* version:	liusen_20170717
*/

#ifndef __APP_BLUETOOTH_H__
#define __APP_BLUETOOTH_H__


#include "app_ultrasonic.h"
#include "bsp_ultrasonic.h"
#include "bsp_servo.h"
#include "sys.h"
#include "app_motor.h"
#include "delay.h"

extern int g_modeSelect;  //0��Ĭ��APK��λ��״̬;  1:����ң�� 2:Ѳ��ģʽ 3:���������� 4: �߲�̽�� 5: Ѱ��ģʽ 6: �������
extern u8 g_Boolfire;	    //�����ʱ�ر��ϱ��������ϱ����ݻ�ʹ�Ҷ������IOģʽ��ͻ��


void app_bluetooth_deal(void);

#endif
