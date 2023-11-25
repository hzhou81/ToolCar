/**
* @par Copyright (C): 2010-2019, Shenzhen Yahboom Tech
* @file         app_ultrasonic.c
* @author       liusen
* @version      V1.0
* @date         2015.01.03
* @brief        蓝牙上位机协议解析业务
* @details      
* @par History  见如下说明
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

int g_modeSelect = 0;  //0是默认APK上位机状态;  1:红外遥控 2:巡线模式 3:超声波避障 4: 七彩探照 5: 寻光模式 6: 红外跟踪
u8 g_Boolfire = 0;	    //在灭火时关闭上报，由于上报数据会使灰度与灭火IO模式冲突。

/**
* Function       serial_data_postback
* @author        Danny
* @date          2017.07.25
* @brief         将采集的传感器数据通过串口传输给上位机显示
* @param[in]     void
* @retval        void
* @par History   无
*/
void serial_data_postback()
{
	//小车超声波传感器采集的信息发给上位机显示
	//打包格式如:
	//    超声波 电压  灰度  巡线  红外避障 寻光
	//$4WD,CSB120,PV8.3,GS214,LF1011,HW11,GM11#
	float csbLen=0.0f, power; 
	u16 gs, lf; 
	u8 hw, gm;
	int L1, R1;
	//超声波
	
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
* @brief         蓝牙或者上位机协议处理
* @param[in]     void
* @param[out]    void
* @retval        void
* @par History   无
*/
void app_bluetooth_deal(void)
{
	if (newLineReceived)
   	{
		Protocol();
	}

	// 切换不同功能模式, 功能模式显示
	switch (g_modeSelect)
	{
		case 1: break; 								//暂时保留
		case 2: app_LineWalking(); break; 			//巡线模式
		case 3: app_ultrasonic_mode();  break;  	//超声波避障模式
		case 4: app_colorMode(); break;  //七彩颜色识别模式
		case 5: app_LightSeeking(); break;  		//寻光模式
		case 6: app_IRFollow(); break;  			//跟随模式
		default:break;
	}
	
	//让小车串口平均每秒发送采集的数据给手机蓝牙apk
	//避免串口打印数据速度过快,造成apk无法正常运行
	if (g_modeSelect == 0 && g_Boolfire == 0)
	{
		if (g_count >= 100000)
		{ 
			g_count = 0;
			serial_data_postback();
		}		
	}

}
