/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		EXTI					************************/
/***************	@TITLE:		EXTI_Interface.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
/***********************************************************
*  			EXTERNAL HARDWARE INTERRUPTS				   *
***********************************************************/

#define EXTI_u8_INT0				1
#define EXTI_u8_INT1				2
#define EXTI_u8_INT2				3
/**********************************************************
*  LEVELS OR EDGES ON THE EXTI THAT GENERATE INTERRUPT    *
**********************************************************/
#define EXTI_u8_RISING_EDGE			1
#define EXTI_u8_FALLING_EDGE		2
#define EXTI_u8_ON_CHANGE			3
#define EXTI_u8_LOW_LEVEL			4

/**********************************************************
*				 FUNCTIONS DECLARATIONS		      		  *
**********************************************************/
void EXTI_voidInt0Init (void);
void EXTI_voidInt1Init (void);
void EXTI_voidInt2Init (void);

u8 EXTI_u8SetSenseControl(u8 Copy_u8IntNum, u8 Copy_u8Sense);

u8 EXTI_u8EnableInt(u8 Copy_IntNum);
u8 EXTI_u8DisableInt(u8 Copy_IntNum);

u8 EXTI_u8SetCallBack(void (*Copy_pvCallBack) (void), u8 Copy_u8IntNum);

#endif /* EXTI_INTERFACE_H_ */
