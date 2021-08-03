/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		HAL						************************/
/***************	SWC:		SSD						************************/
/***************	@TITLE:		SSD_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				   Header Files INCLUSIONS        		  *
**********************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_Interface.h"

#include "SSD_Interface.h"
//#include "SSD_Private.h"
#include "SSD_Config.h"
/**********************************************************
*				     CONSTANTS				      		  *
**********************************************************/
static const u8 SSD_au8DisplayValue[] = { 	0b01000000, //0
											0b01001111, //1
											0b00100100, //2
											0b00110000, //3
											0b00011001, //4
											0b00010010, //5
											0b00000010, //6
											0b01111000, //7
											0b00000000, //8
											0b00010000, //9
															};
/**********************************************************
*			FUNCTIONS IMPLEMENTATIONS		      		  *
**********************************************************/

/**********************************************************
*				     SSD SET NUMBER			      		  *
**********************************************************/
u8 SSD_u8SetNumber(u8 Copy_u8Port, u8 Copy_u8Type, u8 Copy_u8Number) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8Port > DIO_u8_PORTD) || (Copy_u8Type > SSD_COM_CATH)) {
		Local_u8ErrorState = NOK;
	}
	else {
		if (Copy_u8Number < 10) {
			if (Copy_u8Type == SSD_COM_ANODE) {
				DIO_SetPortValue(Copy_u8Port, SSD_au8DisplayValue[Copy_u8Number]);
			}
			else if (Copy_u8Type == SSD_COM_CATH) {
				DIO_SetPortValue(Copy_u8Port, ~SSD_au8DisplayValue[Copy_u8Number]);
			}
			else {
				Local_u8ErrorState = NOK;
			}
		}
		else {
			if (Copy_u8Type == SSD_COM_ANODE) {
				DIO_SetPortValue(Copy_u8Port, SSD_au8DisplayValue[0]);
			}
			else if (Copy_u8Type == SSD_COM_CATH) {
				DIO_SetPortValue(Copy_u8Port, ~SSD_au8DisplayValue[0]);
			}
			else {
				Local_u8ErrorState = NOK;
			}
		}
	}
	return Local_u8ErrorState;
}
/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/



