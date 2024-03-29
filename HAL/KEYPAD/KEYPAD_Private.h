/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		HAL						************************/
/***************	SWC:		KEYPAD					************************/
/***************	@TITLE:		KEYPAD_Private.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_


#define ROW_NUMBER		4
#define COL_NUMBER		4

#define COL_PINS_ARR		{kEYPAD_u8_COL_PIN0, kEYPAD_u8_COL_PIN1, kEYPAD_u8_COL_PIN2, kEYPAD_u8_COL_PIN3}

#define ROW_PINS_ARR		{kEYPAD_u8_ROW_PIN0, kEYPAD_u8_ROW_PIN1, kEYPAD_u8_ROW_PIN2, kEYPAD_u8_ROW_PIN3}
/**********************************************************
*				    PIN (PULLUP)STATE		 	 		  *
**********************************************************/

#define PRESSED			0
#define NOT_PRESSED		1

/**********************************************************
*				    END OF FILE 				 		  *
**********************************************************/
#endif /* KEYPAD_PRIVATE_H_ */
