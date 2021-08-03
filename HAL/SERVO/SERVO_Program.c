/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		HAL						************************/
/***************	SWC:		SERVO					************************/
/***************	@TITLE:		SERVO_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"


#include "MATH_Interface.h"
#include "SERVO_Interface.h"

#include "TIMER_Interface.h"
#include "CLCD_Interface.h"
#include "SERVO_Config.h"
/**********************************************************
*				    : 	 		  *
**********************************************************/
void SERVO_voidInit (void) {
	TIMER_FastPwm1AInit(TIMER1_PWMA_DIVIDE_BY_8, 20000);
}

u16 SERVO_voidGoToAngle(u8 Copy_u8Angle) {
	u16 Local_u16CompareMatchValue;
	Local_u16CompareMatchValue = MATH_s32Mapping(0, 180, 500, 2500, Copy_u8Angle);
	/*printing compare match value on lcd*/
	CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);
	CLCD_voidGoToXY(0, CLCD_u8_LINE_ONE);
	CLCD_voidSendNumber(Local_u16CompareMatchValue);
	/********/
	TIMER_Pwm1ASetCompareValue(Local_u16CompareMatchValue);

	return Local_u16CompareMatchValue;
}
/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/
