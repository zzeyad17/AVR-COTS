/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		EXTI					************************/
/***************	@TITLE:		EXTI_Register.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define		GICR			*( (volatile u8*) 0x5B ) 		/*General interrupt control register*/
#define 	GICR_INT1		7								/*INT1 PIE*/
#define 	GICR_INT0		6								/*INT0 PIE*/
#define 	GICR_INT2		5								/*INT2 PIE*/


#define		MCUCR			*( (volatile u8*) 0x55 )		/*MCU Control Register*/
#define 	MCUCR_ISC11		3								/*INT1 sense control bit1*/
#define 	MCUCR_ISC10		2								/*INT1 sense control bit0*/
#define 	MCUCR_ISC01		1								/*INT0 sense control bit1*/
#define 	MCUCR_ISC00		0								/*INT0 sense control bit0*/


#define		MCUCSR			*( (volatile u8*) 0x54 )		/*MCU Control and status Register*/
#define 	MCUCSR_ISC2		6								/*INT2 sense control bit2*/



#endif /* EXTI_REGISTER_H_ */
