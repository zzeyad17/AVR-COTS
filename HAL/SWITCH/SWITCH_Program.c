/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		HAL						************************/
/***************	SWC:		SWITCH					************************/
/***************	@TITLE:		SWITCH_Program.c		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"

#include "DIO_Interface.h"

#include "SWITCH_Interface.h"
/**********************************************************
*				SWITCH GET STATE			      		  *
**********************************************************/
u8 SWITCH_u8GetState(SWITCH_t* Copy_pSWITCH_t, u8* Copy_pu8State) {
	u8 Local_u8ErrorState = OK;
	u8 Local_u8SwitchVal;
	if (Copy_pSWITCH_t == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else if ((Copy_pSWITCH_t->SWITCH_u8Port_m > DIO_u8_PORTD) || (Copy_pSWITCH_t->SWITCH_u8Pin_m > DIO_u8_PIN7) || (Copy_pSWITCH_t->SWITCH_u8Conn_m > SWITCH_PULLUP)) {
		Local_u8ErrorState = NOK;
	}
	else {
		DIO_u8ReadPinValue(Copy_pSWITCH_t->SWITCH_u8Port_m, Copy_pSWITCH_t->SWITCH_u8Pin_m, &Local_u8SwitchVal);
		if (Copy_pSWITCH_t->SWITCH_u8Conn_m == SWITCH_PULLDOWN) {
			if (0 == Local_u8SwitchVal) {
				*Copy_pu8State = SWITCH_NOT_PRESSED;
			}
			else {
				*Copy_pu8State = SWITCH_PRESSED;
			}
		}
		else {
			if (1 == Local_u8SwitchVal) {
				*Copy_pu8State = SWITCH_NOT_PRESSED;
			}
			else {
				*Copy_pu8State = SWITCH_PRESSED;
			}
		}
	}

	return Local_u8ErrorState;
}

/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/


