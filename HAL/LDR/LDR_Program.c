/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:							************************/
/***************	SWC:								************************/
/***************	@TITLE:		_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"
#include "MATH_Interface.h"

#include "ADC_Interface.h"

#include "LDR_Interface.h"
#include "LDR_Config.h"
#include "LDR_Private.h"



/**********************************************************
*				    : 	 		  *
**********************************************************/
u8 LDR_u8GetIntensityLevel(u8 Copy_u8LevelsNum) {
	u16 Local_u16AdcReadingMVolt = ADC_u16GetMVolt(LDR_CHANNEL);
#if FULL_LIGHT_MILLI_VOLT < FULL_DARK_MILLI_VOT
	return MATH_u8Level(FULL_LIGHT_MILLI_VOLT, FULL_DARK_MILLI_VOT, Copy_u8LevelsNum, Local_u16AdcReadingMVolt);
#elif FULL_LIGHT_MILLI_VOLT > FULL_DARK_MILLI_VOT
	return MATH_u8Level(FULL_DARK_MILLI_VOT, FULL_LIGHT_MILLI_VOLT, Copy_u8LevelsNum, Local_u16AdcReadingMVolt);
#endif
}
/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/
