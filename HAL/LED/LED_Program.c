/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		HAL						************************/
/***************	SWC:		LED						************************/
/***************	@TITLE:		LED_program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"

#include "DIO_Interface.h"

#include "LED_Interface.h"
/**********************************************************
*				    LED ON 					 	 		  *
**********************************************************/
u8 LED_u8LedOn(LED_t* Copy_pLED_t) {
	u8 Local_u8ErrorState = OK;
	if (Copy_pLED_t == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else if ((Copy_pLED_t->LED_u8Port_m > DIO_u8_PORTD) || (Copy_pLED_t->LED_u8Pin_m > DIO_u8_PIN7)) {
		Local_u8ErrorState = NOK;
	}
	else {
		if (Copy_pLED_t->LED_u8Conn_m == LED_SINK_CONN) {
			DIO_u8SetPinValue(Copy_pLED_t->LED_u8Port_m, Copy_pLED_t->LED_u8Pin_m, DIO_u8_PIN_LOW);
		}
		else if (Copy_pLED_t->LED_u8Conn_m == LED_SRC_CONN) {
			DIO_u8SetPinValue(Copy_pLED_t->LED_u8Port_m, Copy_pLED_t->LED_u8Pin_m, DIO_u8_PIN_HIGH);
		}
		else {
			Local_u8ErrorState = NOK;
		}
	}

	return Local_u8ErrorState;
}
/**********************************************************
*				    LED OFF					 	 		  *
**********************************************************/
u8 LED_u8LedOff(LED_t* Copy_pLED_t) {
	u8 Local_u8ErrorState = OK;
	if (Copy_pLED_t == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else if ((Copy_pLED_t->LED_u8Port_m > DIO_u8_PORTD) || (Copy_pLED_t->LED_u8Pin_m > DIO_u8_PIN7)) {
		Local_u8ErrorState = NOK;
	}

	else {
		if (Copy_pLED_t->LED_u8Conn_m == LED_SINK_CONN) {
			DIO_u8SetPinValue(Copy_pLED_t->LED_u8Port_m, Copy_pLED_t->LED_u8Pin_m, DIO_u8_PIN_HIGH);
		}
		else if (Copy_pLED_t->LED_u8Conn_m == LED_SRC_CONN) {
			DIO_u8SetPinValue(Copy_pLED_t->LED_u8Port_m, Copy_pLED_t->LED_u8Pin_m, DIO_u8_PIN_LOW);
		}
		else {
			Local_u8ErrorState = NOK;
		}
	}

	return Local_u8ErrorState;
}


/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/


