/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:							************************/
/***************	SWC:							************************/
/***************	@TITLE:		_Config.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/**********************************************************
*				Prescaler macros		      		  *
**********************************************************/
#define TIMER1_PWMA_NO_CLOCK			0
#define TIMER1_PWMA_NO_PRESCALER		1
#define TIMER1_PWMA_DIVIDE_BY_8			2
#define TIMER1_PWMA_DIVIDE_BY_64		3
#define TIMER1_PWMA_DIVIDE_BY_256		4
#define TIMER1_PWMA_DIVIDE_BY_1024		5


/**********************************************************
*				Functions Declarations		      		  *
**********************************************************/
void TIMER_voidTimer0Init();
void TIMER_voidTimer1Init(u8 Copy_u8PrescalerValue);
void TIMER_FastPwm1AInit(u8 Copy_u8Prescaler, u16 Copy_u16TopValue);
void TIMER_Pwm1ASetCompareValue(u16 Copy_u16CompareMatchValue );
void TIMER_Pwm1ASetDutyCycle(u8 Copy_u8DutyCycle );
u8 TIMER_u8Timer0SetCallBack(void (*Copy_pvCallBackFunc)(void));
void TIMER_voidTimer0SetPreloadValue(u8 Copy_u8PreloadValue);
void TIMER_FastPwm0Init(u8 Copy_u8PrescalerValue);
void TIMER_Pwm0SetCompareValue(u16 Copy_u16CompareMatchValue );
u16 TIMER_voidTimer1ReadTimerValue(void);
void TIMER_voidTimer1SetTimerValue(u16 Copy_u16TimerValue );

#endif /* TIMER_INTERFACE_H_ */
