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

#include "TIMER_Interface.h"
#include "TIMER_Config.h"
#include "TIMER_Private.h"
#include "TIMER_Register.h"
/**********************************************************
*				    Global Variables		 	 		  *
**********************************************************/
static void (*TIMER_pvCallBackFunc)(void) = NULL;
static u16 TIMER_u16Pwm1ATopValue;

/**********************************************************
*				    TIMER 0 INIT			 	 		  *
**********************************************************/
void TIMER_voidTimer0Init() {
	/*Normal mode setting*/
	CLR_BIT(TIMER_TCCR0, TCCR0_WGM00);
	CLR_BIT(TIMER_TCCR0, TCCR0_WGM01);

	/*2- Pre-load setting*/
	TIMER_TCNT0 = TIMER0_PRELOAD;

	/*3- Overflow interrupt enable/*/
	SET_BIT(TIMER_TIMSK, TIMSK_TOIE0);

	/*4-Pre-scaler division factor setting*/
	TIMER_TCCR0 &= PRESCALER_MASK;
	TIMER_TCCR0 |= TIMER0_u8_PRESCALER;
}
/**********************************************************
*				   Timer 1 Init				 	 		  *
**********************************************************/
void TIMER_voidTimer1Init(u8 Copy_u8PrescalerValue) {
	/*Normal mode setting*/
	CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TIMER_TCCR1B, TCCR1B_WGM13);

	/*4-Pre-scaler division factor setting*/
	TIMER_TCCR1B &= PRESCALER_MASK;
	TIMER_TCCR0 |= Copy_u8PrescalerValue;
}
/**********************************************************
*				   PWM1 A set Init			 	 		  *
**********************************************************/

void TIMER_FastPwm1AInit(u8 Copy_u8Prescaler, u16 Copy_u16TopValue) {
	/*1- Fast PWM (mode 14) mode setting*/
	CLR_BIT(TIMER_TCCR1A, TCCR1A_WGM10);
	SET_BIT(TIMER_TCCR1A, TCCR1A_WGM11);
	SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);
	SET_BIT(TIMER_TCCR1B, TCCR1B_WGM12);

	/*2- Choose channel A as set on top clear on compare */
	CLR_BIT(TIMER_TCCR1A, TCCR1A_COM1A0);
	SET_BIT(TIMER_TCCR1A, TCCR1A_COM1A1);

	/*3- Pre-scaler division factor setting ()*/
	TIMER_TCCR1B &= PRESCALER_MASK;
	TIMER_TCCR1B |= Copy_u8Prescaler;

	/*4- Set Top value*/
	TIMER_ICR1 = Copy_u16TopValue;

	/*5- Initialize the global Top value */
	TIMER_u16Pwm1ATopValue = Copy_u16TopValue;


}
/**********************************************************
*			PWM1 A set compare match value	 	 		  *
**********************************************************/

void TIMER_Pwm1ASetCompareValue(u16 Copy_u16CompareMatchValue ) {
	TIMER_OCR1A = Copy_u16CompareMatchValue;
}
/**********************************************************
*				   PWM1 A set duty cycle	 	 		  *
**********************************************************/

void TIMER_Pwm1ASetDutyCycle(u8 Copy_u8DutyCycle ) {
	u32 Local_u16CompareMatchValue;
	if (Copy_u8DutyCycle > 100) {
		Copy_u8DutyCycle = 100;
	}
	/*1- Calculate the compare match value from the given duty cycle*/
	Local_u16CompareMatchValue = (((u32)Copy_u8DutyCycle * (u32)(TIMER_u16Pwm1ATopValue + 1UL)) / 100UL ) ;
	/*2- Set the compare match value*/
	TIMER_OCR1A = Local_u16CompareMatchValue;
}

/**********************************************************
*				    TIMER 0 SET CALLBACK	 	 		  *
**********************************************************/
u8 TIMER_u8Timer0SetCallBack(void (*Copy_pvCallBackFunc)(void)) {
	u8 Local_u8ErrorState = OK;
	/*1- Send Address of CallBack function to ISR via Global Variable*/
	if (Copy_pvCallBackFunc == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else {
		TIMER_pvCallBackFunc = Copy_pvCallBackFunc;
	}
	return Local_u8ErrorState;
}
/**********************************************************
*				    TIMER 0 SET PRELOAD VALUE	 		  *
**********************************************************/
void TIMER_voidTimer0SetPreloadValue(u8 Copy_u8PreloadValue) {
	TIMER_TCNT0 = Copy_u8PreloadValue;
}
/**********************************************************
*				    TIMER 0 ISR					 		  *
**********************************************************/

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void) {
	TIMER_pvCallBackFunc();
}
/**********************************************************
*				    PWM0 init					 		  *
**********************************************************/

void TIMER_FastPwm0Init(u8 Copy_u8PrescalerValue) {
	/*1- Fast PWM mode setting*/
	SET_BIT(TIMER_TCCR0, TCCR0_WGM00);
	SET_BIT(TIMER_TCCR0, TCCR0_WGM01);

	/*2-set on top clear on compare */
	CLR_BIT(TIMER_TCCR0, TCCR0_COM00);
	SET_BIT(TIMER_TCCR0, TCCR0_COM01);

	/*3- Pre-scaler division factor setting ()*/
	TIMER_TCCR1B &= PRESCALER_MASK;
	TIMER_TCCR1B |= Copy_u8PrescalerValue;

}
/**********************************************************
*				    Pwm 0 Set compare value		 		  *
**********************************************************/

void TIMER_Pwm0SetCompareValue(u16 Copy_u16CompareMatchValue ) {
	TIMER_OCR0 = Copy_u16CompareMatchValue;
}
/**********************************************************
*				    Timer 1 read timer value			  *
**********************************************************/

u16 TIMER_voidTimer1ReadTimerValue(void) {
	return TIMER_TCNT1;
}
/**********************************************************
*				    Timer 1 Set timer value				  *
**********************************************************/

void TIMER_voidTimer1SetTimerValue(u16 Copy_u16TimerValue ) {
	TIMER_TCNT1 = Copy_u16TimerValue;
}

/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/
