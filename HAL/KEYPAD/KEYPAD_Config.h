/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		HAL						************************/
/***************	SWC:		KEYPAD					************************/
/***************	@TITLE:		KEYPAD_Config.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_
/********************************************************
*				  CONNECTIOS			 			  	*
********************************************************/
/*PORTS*/
#define kEYPAD_u8_COL_PORT		DIO_u8_PORTD
#define kEYPAD_u8_ROW_PORT		DIO_u8_PORTD
/*ROW PINS*/
#define kEYPAD_u8_ROW_PIN0		DIO_u8_PIN3
#define kEYPAD_u8_ROW_PIN1		DIO_u8_PIN2
#define kEYPAD_u8_ROW_PIN2		DIO_u8_PIN1
#define kEYPAD_u8_ROW_PIN3		DIO_u8_PIN0
/*COL PINS*/
#define kEYPAD_u8_COL_PIN0		DIO_u8_PIN4
#define kEYPAD_u8_COL_PIN1		DIO_u8_PIN5
#define kEYPAD_u8_COL_PIN2		DIO_u8_PIN6
#define kEYPAD_u8_COL_PIN3      DIO_u8_PIN7

/********************************************************
*				  KEY VALUES			 			  	*
********************************************************/
#define  KEYPAD_u8_KEY_VAL_ARR		{{1, 2, 3, 0},{4, 5, 6, 0},{7, 8, 9, 0},{0, 0, 0, 0}}

/**********************************************************
*				    END OF FILE 				 		  *
**********************************************************/
#endif /* KEYPAD_CONFIG_H_ */
