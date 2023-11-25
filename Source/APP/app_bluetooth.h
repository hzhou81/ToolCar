/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_bluetooth.h
* @author       liusen
* @version      V1.0
* @date         2017.08.18
* @brief        蓝牙上位机处理协议业务流程
* @details      
* @par History  见如下说明
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

extern int g_modeSelect;  //0是默认APK上位机状态;  1:红外遥控 2:巡线模式 3:超声波避障 4: 七彩探照 5: 寻光模式 6: 红外跟踪
extern u8 g_Boolfire;	    //在灭火时关闭上报，由于上报数据会使灰度与灭火IO模式冲突。


void app_bluetooth_deal(void);

#endif
