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

	bsp_GetLineWalking(&LineL1, &LineL2, &LineR1, &LineR2);

	if( (LineL1 == LOW || LineL2 == LOW) && LineR2 == LOW)
    {
      	Car_SpinLeft(7000, 7000);
		delay_ms(80);
    }
    else if ( LineL1 == LOW && (LineR1 == LOW || LineR2 == LOW))
	{ 
      	Car_SpinRight(7000, 7000);
		delay_ms(80);
    }  
    else if( LineL1 == LOW )
    {  
		Car_SpinLeft(6800, 6800);
		delay_ms(10);
	}
    else if ( LineR2 == LOW)
    {  
		Car_SpinRight(6800, 6800);
		delay_ms(10);
	}
    else if (LineL2 == LOW && LineR1 == HIGH)
    {   
		Car_Left(6500);   
	}
	else if (LineL2 == HIGH && LineR1 == LOW)
    {   
		Car_Right(6500);   
	}
    else if(LineL2 == LOW && LineR1 == LOW) // ���ǰ�ɫ, ֹͣ
    {  
		Car_Run(7200);
	}	
}
