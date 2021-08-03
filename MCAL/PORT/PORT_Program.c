/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		PORT					************************/
/***************	@TITLE:		PORT_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"

#include "PORT_Interface.h"
#include "PORT_Config.h"
#include "PORT_Private.h"
#include "PORT_Register.h"

void PORT_voidInit(void) {
	/*Initialize pins directions*/
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;
	/*Initialize pins init values*/
	PORTA = PORTA_INIT_VAL;
	PORTB = PORTB_INIT_VAL;
	PORTC = PORTC_INIT_VAL;
	PORTD = PORTD_INIT_VAL;
}


/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/

