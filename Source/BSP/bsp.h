

#ifndef __BSP_H__
#define __BSP_H__

#include "delay.h"
#include "bsp_gpio.h"
#include "bsp_motor.h"
#include "bsp_servo.h"
#include "bsp_timer.h"
#include "bsp_linewalking.h"
#include "bsp_ultrasonic.h"
#include "bsp_colorful.h"
#include "bsp_iravoid.h"
#include "bsp_lightseeking.h"
#include "usart.h"
#include "bsp_adc.h"
#include "bsp_gs.h"
#include "bsp_fire.h"

void bsp_init(void);


/*��������궨�忪�أ�������Ҫ���Կ���������������*/

/*������Ҫ��ʼ���Ķ���궨�忪��*/
#define USE_SERVO_J1
//#define USE_SERVO_J2
//#define USE_SERVO_J3
//#define USE_SERVO_J4
//#define USE_SERVO_J5
//#define USE_SERVO_J6

/*Ѳ�߿���*/
#define USE_LINE_L1
#define USE_LINE_L2
#define USE_LINE_R1
#define USE_LINE_R2

/*������Ͽ���*/
#define USE_IRAVOID_L1
#define USE_IRAVOID_R1

/*�߲�̽�յ�*/
#define USE_COLOR_RED
#define USE_COLOR_GREEN
#define USE_COLOR_BLUE

/*Ѱ�⴫����*/
#define USE_LIGHTSEEKING_L1
#define USE_LIGHTSEEKING_R1

/*������������*/
#define USE_ULTRASONIC

/*������*/
#define USE_BUZZER

/*���*/
#define USE_FIRE

/*�Ҷȴ�����*/
#define USE_GS


#endif
