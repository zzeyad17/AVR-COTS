/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		HAL						************************/
/***************	SWC:		KEYPAD					************************/
/***************	@TITLE:		KEYPAD_Program.c		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"

//#define F_CPU 8000000
#include "util/delay.h"

#include "DIO_Interface.h"

#include "KEYPAD_Interface.h"
#include "KEYPAD_Private.h"
#include "KEYPAD_Config.h"
/**********************************************************
*				 KEYPAD GET PRESSED KEY		 	 		  *
**********************************************************/
u8 KEYPAD_u8GetPressedKey(void) {
	u8 Local_u8Pressedkey = KEYPAD_NO_PRESSED_KEY;
	u8 Local_u8RowIndex, Local_u8ColIndex;
	u8 Local_u8PinState = NOT_PRESSED;
	static u8 Local_au8KeyValue[COL_NUMBER][ROW_NUMBER] = KEYPAD_u8_KEY_VAL_ARR;
	static u8 Local_au8ColPins[COL_NUMBER] = COL_PINS_ARR;
	static u8 Local_au8ROWPins[ROW_NUMBER] = ROW_PINS_ARR;


	for (Local_u8ColIndex = 0; Local_u8ColIndex < COL_NUMBER; Local_u8ColIndex++) {
		/*Make the current COL LOW*/
		DIO_u8SetPinValue(kEYPAD_u8_COL_PORT, Local_au8ColPins[Local_u8ColIndex], DIO_u8_PIN_LOW);
		for (Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUMBER; Local_u8RowIndex++) {
			/*Read current row value*/
			DIO_u8ReadPinValue(kEYPAD_u8_ROW_PORT, Local_au8ROWPins[Local_u8RowIndex], &Local_u8PinState);
			/*If key is pressed in the current Row*/
			if (Local_u8PinState == PRESSED) {
				/*Wait until the key is released */
				while(Local_u8PinState == PRESSED) {
					DIO_u8ReadPinValue(kEYPAD_u8_ROW_PORT, Local_au8ROWPins[Local_u8RowIndex], &Local_u8PinState);
				}
				/*Delay to avoid bouncing*/
				_delay_ms(10);
				/*Make the current COL HIGH*/
				DIO_u8SetPinValue(kEYPAD_u8_COL_PORT, Local_au8ColPins[Local_u8ColIndex], DIO_u8_PIN_HIGH);
				/*Return the pressed key*/
				Local_u8Pressedkey = Local_au8KeyValue[Local_u8RowIndex][Local_u8ColIndex];
				return Local_u8Pressedkey;
			}
		}
		/*Make the current COL HIGH*/
		DIO_u8SetPinValue(kEYPAD_u8_COL_PORT, Local_au8ColPins[Local_u8ColIndex], DIO_u8_PIN_HIGH);
	}
	/*If no key pressed, return KEYPAD_NO_PRESSED_KEY*/
	return Local_u8Pressedkey;
}
/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/

