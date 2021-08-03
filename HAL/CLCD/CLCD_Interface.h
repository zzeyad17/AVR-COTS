/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		HAL						************************/
/***************	SWC:		CLCD					************************/
/***************	@TITLE:		CLCD_Interface.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
/**********************************************************
*				 CLCD COMMANDS				      		  *
**********************************************************/
#define CLCD_CLEAR_DISPLAY 			0b00000001
#define CLCD_RETURN_HOME			0b00000010
#define CLCD_SHIFT_CURSOR_LEFT		0b00010000
#define CLCD_SHIFT_CURSOR_RIGHT		0b00010100
#define CLCD_SHIFT_DISPLAY_LEFT		0b00011000
#define CLCD_SHIFT_DISPLAY_RIGHT	0b00011100
/**********************************************************
*			CLCD LINE NUMBER		  		    		  *
**********************************************************/
#define CLCD_u8_LINE_ONE	0
#define CLCD_u8_LINE_TWO	1
/**********************************************************
*				 FUNCTIONS DECLARATIONS		      		  *
**********************************************************/

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidInit(void);

u8 CLCD_voidSendString(const char* Copy_pu8CharString);

void CLCD_voidSendNumber(u32 Copy_u32Number);

u8 CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

u8 CLCD_u8WritrSpecialCharacter(u8* Copy_pu8Pattern, u8 Copy_u8PatternNumber, u8 Copy_u8XPos, u8 Copy_u8YPos);

#endif
