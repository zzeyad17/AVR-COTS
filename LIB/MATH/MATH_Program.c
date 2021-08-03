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

/**********************************************************
*				    Mapping Function					  *
**********************************************************/
u32 MATH_s32Mapping(u32 Copy_u32InputMin, u32 Copy_u32InputMax, u32 Copy_u32OutputMin, u32 Copy_u32OutputMax, u32 Copy_u32InputValue) {
	/*1- Constrains on Input*/
	if (Copy_u32InputValue < Copy_u32InputMin) {
		return Copy_u32OutputMin;
	}
	else if (Copy_u32InputValue > Copy_u32InputMax) {
		return Copy_u32OutputMax;
	}
	else {
		/*2- Calculating the Offset*/
		u32 Local_u32Offset = Copy_u32OutputMax - ( ((Copy_u32OutputMax - Copy_u32OutputMin) * Copy_u32InputMax) / (Copy_u32InputMax - Copy_u32InputMin));

		/*3- Return the mapped value*/
		return ((((Copy_u32OutputMax - Copy_u32OutputMin) * Copy_u32InputValue) / (Copy_u32InputMax - Copy_u32InputMin)) + Local_u32Offset );
	}
}
/**********************************************************
*				    Level Function					  *
**********************************************************/
u8 MATH_u8Level(s32 Copy_s32Min, s32 Copy_s32Max, u8 Copy_u8LevelsNumber, s32 Copy_s32Value) {
	u8 Local_u8Step;
	if (Copy_s32Value >= Copy_s32Max) {
		return Copy_u8LevelsNumber;
	}
	else if (Copy_s32Value <= Copy_s32Min) {
		return 1;
	}
	else {
		Local_u8Step = (Copy_s32Max - Copy_s32Min) / Copy_u8LevelsNumber;
		return (((Copy_s32Value - Copy_s32Min ) / Local_u8Step ) + 1);
	}
}
/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/
