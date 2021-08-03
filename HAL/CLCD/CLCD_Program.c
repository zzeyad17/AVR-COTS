/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		HAL						************************/
/***************	SWC:		CLCD					************************/
/***************	@TITLE:		CLCD_Program.c.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/


#include "Std_Types.h"
#include "Bit_Math.h"

#include <util/delay.h>

#include "DIO_Interface.h"

#include "CLCD_Interface.h"
#include "CLCD_Private.h"
#include "CLCD_Config.h"

/**********************************************************
*		           CLCD PRIVATE FUNCTIONS         		  *
**********************************************************/
static void SendEnablePulse(void) {
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_E_PIN, DIO_u8_PIN_HIGH);
		_delay_ms(2);
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_E_PIN, DIO_u8_PIN_LOW);
}
#if CLCD_u8_BIT_MODE == FOUR_BIT_MODE
	static void SetHalfDataPort(u8 Copy_u8Data) {
	u8 Local_u8DataBit;

	Local_u8DataBit = GET_BIT(Copy_u8Data, 0);
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT, CLCD_u8_D4_PIN, Local_u8DataBit);

	Local_u8DataBit = GET_BIT(Copy_u8Data, 1);
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT, CLCD_u8_D5_PIN, Local_u8DataBit);

	Local_u8DataBit = GET_BIT(Copy_u8Data, 2);
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT, CLCD_u8_D6_PIN, Local_u8DataBit);

	Local_u8DataBit = GET_BIT(Copy_u8Data, 3);
	DIO_u8SetPinValue(CLCD_u8_DATA_PORT, CLCD_u8_D7_PIN, Local_u8DataBit);
	}
#endif
/**********************************************************
*		                CLCD SEND DATA             		  *
**********************************************************/
void CLCD_voidSendData(u8 Copy_u8Data) {
	/*1- Set RS to Data*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, DIO_u8_PIN_HIGH);

	/*2- Set RW to write*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RW_PIN, DIO_u8_PIN_LOW);


#if CLCD_u8_BIT_MODE == EIGHT_BIT_MODE
	/*3- Send the data*/
	DIO_SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Data);

	/*4- Send enable pulse*/
	SendEnablePulse();
#elif CLCD_u8_BIT_MODE == FOUR_BIT_MODE
	/*3- Send the higher order data bits to lcd data pins*/
	SetHalfDataPort(Copy_u8Data>>4);
	/*4- Send enable pulse*/
	SendEnablePulse();
	/*5- Send the lower order data bits to lcd data pins*/
	SetHalfDataPort(Copy_u8Data);
	/*4- Send enable pulse*/
	SendEnablePulse();
#endif
}
/**********************************************************
*		                CLCD SEND COMMAND        		  *
**********************************************************/
void CLCD_voidSendCommand(u8 Copy_u8Command) {
	/*1- Set RS to Command*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RS_PIN, DIO_u8_PIN_LOW);

	/*2- Set RW to write*/
	DIO_u8SetPinValue(CLCD_u8_CTRL_PORT, CLCD_u8_RW_PIN, DIO_u8_PIN_LOW);

	/*3- Send the data*/
	DIO_SetPortValue(CLCD_u8_DATA_PORT, Copy_u8Command);

	/*4- Send enable pulse*/
	SendEnablePulse();
}
/**********************************************************
*		                CLCD INIT		        		  *
**********************************************************/
void CLCD_voidInit(void) {
	/*1- Wait for more than 30ms*/
	_delay_ms(40);

	/*2- Function set command: 2 lines, Font: 5 * 8*/
	CLCD_voidSendCommand(0b00111000);

	/*3- Wait for more than 39us* (The excution time of send command)/
	 *Note: point 3 is handeled in the delay in CLCD_voidSendCommand.*/

	/*4- Display On/Of control: cursor off, blink cursor off*/
	CLCD_voidSendCommand(0b00001100);

	/*5- Same as (3)*/

	/*6- Display clear*/
	CLCD_voidSendCommand(1);
}
/**********************************************************
*		                CLCD SEND STRING        		  *
**********************************************************/
u8 CLCD_voidSendString(const char* Copy_pu8CharString) {
	u8 Local_u8ErrorState = OK;
	if (Copy_pu8CharString == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else {
		while (*Copy_pu8CharString != '\0') {
			CLCD_voidSendData(*Copy_pu8CharString);
			Copy_pu8CharString++;
		}
	}
	return Local_u8ErrorState;
}
/**********************************************************
*		                CLCD SEND NUMBER        		  *
**********************************************************/
void CLCD_voidSendNumber(u32 Copy_u32Number) {
	u32 Local_u32Reserved = 1;
	if (Copy_u32Number == 0) {
		CLCD_voidSendData('0');
		return;
	}

	/*Reserve the Number*/
	while (Copy_u32Number != 0) {
		/*Get the Right most Digit*/
		Local_u32Reserved = (Local_u32Reserved * 10) + (Copy_u32Number % 10);
		/*Get rid of the Right most Digit*/
		Copy_u32Number /= 10;
	}
	 do {
		/*Display the Right Most digit with converting its value to ascii*/
		CLCD_voidSendData((Local_u32Reserved % 10) + '0');
		/*Git Rid of the right most digit*/
		Local_u32Reserved /= 10;
	}while(Local_u32Reserved != 1);
}
/**********************************************************
*		         CLCD GO TO POSITION X Y	       		  *
**********************************************************/

u8 CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos) {
	u8 Local_u8ErrorState = OK;
	u8 Local_u8DDRAMAdd;
	if ((Copy_u8XPos > COL_MAX_INDEX) || (Copy_u8YPos > ROW_MAX_INDEX)) {
		Local_u8ErrorState = NOK;
	}
	else if(Copy_u8YPos == CLCD_u8_LINE_ONE) {
		Local_u8DDRAMAdd = LINE_ONE_OFFSET + Copy_u8XPos;
	}
	else {
		Local_u8DDRAMAdd = LINE_TWO_OFFSET + Copy_u8XPos;
	}
	/*
	 * The above else if- else can be substituted by the following equation:
	 * 		Local_u8DDRAMAdd = (LINE_TWO_OFFSET * Copy_u8YPos) + Copy_u8XPos ;
	 */
	/*set bit #7 in the address*/
	SET_BIT(Local_u8DDRAMAdd, 7);
	/* Send command to lcd*/
	CLCD_voidSendCommand(Local_u8DDRAMAdd);

	return Local_u8ErrorState;
}
/**********************************************************
*		         CLCD WRITE SPECIAL CHARACTER   		  *
**********************************************************/
u8 CLCD_u8WritrSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos) {
	u8 Local_u8ErrorState = OK;
	u8 Local_u8CGRAMAdd;
	u8 Local_u8LoopCounter = 0;

	if (Copy_pu8Pattern == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else if (Copy_u8PatternNumber > 7) {
		Local_u8ErrorState = NOK;
	}
	else {
		Local_u8CGRAMAdd = Copy_u8PatternNumber * 8;

		/* bit #6-> 1, #7->0,  b0->b5 ---> CGRAM Address*/
		CLR_BIT(Local_u8CGRAMAdd, 7);
		SET_BIT(Local_u8CGRAMAdd, 6);
		/*Send the start address of the pattern number in CGRAM*/
		CLCD_voidSendCommand(Local_u8CGRAMAdd);
		/*Send pattern data to CGRAM*/
		for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++) {
			CLCD_voidSendData(Copy_pu8Pattern[Local_u8LoopCounter]);
		}
		/*Go to XY position in DDRAM*/
		if (CLCD_voidGoToXY(Copy_u8XPos, Copy_u8YPos) == OK) {
			/*Display the content of the Pattern*/
			CLCD_voidSendData(Copy_u8PatternNumber);
		}
		else {
			Local_u8ErrorState = NOK;
		}
	}

	return Local_u8ErrorState;
}


/**********************************************************
*		                END OF FILE		        		  *
**********************************************************/




