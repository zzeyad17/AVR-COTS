/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		TIMER					************************/
/***************	@TITLE:		TIMER_Register.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_
/**********************************************************
*				 	Timer	0				      		  *
**********************************************************/
/***************************************
*			TTCR0					   *
***************************************/
#define		TIMER_TCCR0		*( (volatile u8*) 0X53 )		/*Timer/counter 0 Control register*/

#define 	TCCR0_WGM00		6								/*Wave form generation mode bit 0*/
#define 	TCCR0_WGM01		3								/*Wave form generation mode bit 1*/
/***********************/
#define 	TCCR0_COM00		4								/*Wave form generator Control 0*/
#define 	TCCR0_COM01		5								/*Wave form generator Control 1*/
/***********************/
#define 	TCCR0_CS00		0								/*Wave form generator Control 0*/
#define 	TCCR0_CS01		1								/*Wave form generator Control 1*/
#define 	TCCR0_CS02		2								/*Wave form generator Control 2*/
/***********************/
#define 	TCCR0_FOC0		7								/*Force compare match*/
/***************************************
*			TCNT0					   *
***************************************/
#define		TIMER_TCNT0		*( (volatile u8*) 0X52 )		/*Timer/counter 0 register*/

/***************************************
*			OCR0					   *
***************************************/
#define		TIMER_OCR0		*( (volatile u8*) 0X5C )		/*Timer0 Compare match register*/


/**********************************************************
*				 	Timer	2				      		  *
**********************************************************/
/***************************************
*			TTCR2					   *
***************************************/
#define		TIMER_TCCR2		*( (volatile u8*) 0X45 )		/*Timer/counter 2 Control register*/

#define 	TCCR2_WGM21		3								/*Wave form generation mode bit 0*/
#define 	TCCR2_WGM20		6								/*Wave form generation mode bit 1*/
/***********************/
#define 	TCCR2_COM20		4								/*Wave form generator Control 0*/
#define 	TCCR0_COM21		5								/*Wave form generator Control 1*/
/***********************/
#define 	TCCR2_CS20		0								/*Wave form generator Control 0*/
#define 	TCCR2_CS21		1								/*Wave form generator Control 1*/
#define 	TCCR2_CS22		2								/*Wave form generator Control 2*/
/***********************/
#define 	TCCR0_FOC2		7								/*Force compare match*/

/***************************************
*			TCNT2					   *
***************************************/
#define		TIMER_TCNT2		*( (volatile u8*) 0X44 )		/*Timer/counter 0 register*/
/***************************************
*	Asynchronous status register	   *
***************************************/
#define		TIMER_ASSR		*( (volatile u8*) 0X42 )

#define 	ASSR_TCR2UB		0								/*????*/
#define 	ASSR_OCR2UB		1								/*????*/
#define 	ASSR_TCN2UB		2								/*????*/

#define 	ASSR_AS2		3								/* 0 --> timer 2 clocked from clock i/o
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	*  1 --> timer 2 works as RTC
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	*/
/**********************************************************
*				 	Timer	1				      		  *
**********************************************************/
/***************************************
*			TTCR1A					   *
***************************************/
#define		TIMER_TCCR1A		*( (volatile u8*) 0X4F )		/*Timer/counter 1 Control register A*/

#define 	TCCR1A_COM1A0		6								/*Compare output mode for channel A*/
#define 	TCCR1A_COM1A1		7								/*Compare output mode for channel A*/
/***********************/
#define 	TCCR1A_COM1B0		4								/*Compare output mode for channel B*/
#define 	TCCR1A_COM1B1		5								/*Compare output mode for channel B*/
/***********************/
#define 	TCCR1A_FOC1A		3								/*Force output compare for channel A*/
/***********************/
#define 	TCCR1A_FOC1B		2								/*Force output compare for channel B*/
/***********************/
#define 	TCCR1A_WGM10		0								/*Timer 1 mode bit0*/
#define 	TCCR1A_WGM11		1								/*Timer 1 mode bit1*/

/***************************************
*			TCCR1B					   *
***************************************/
#define		TIMER_TCCR1B		*( (volatile u8*) 0X4E )		/*Timer/counter 1 Control register B*/

#define 	TCCR1B_INC1			7								/*Input capture noise canceler*/
/***********************/
#define 	TCCR1B_ICES1		6								/*Input capture edge select*/
/***********************/
#define 	TCCR1B_WGM12		3								/*Timer 1 mode bit2*/
#define 	TCCR1B_WGM13		4								/*Timer 1 mode bit3*/
/***********************/
#define 	TCCR1B_CS10			0								/*Timer 1 clock selector 0*/
#define 	TCCR1B_CS11			1								/*Timer 1 clock selector 1*/
#define 	TCCR1B_CS12			2								/*Timer 1 clock selector 2*/
/***************************************
*			OCR1A					   *
***************************************/
#define 	TIMER_OCR1A			*( (volatile u16*) 0X4A )		/*Timer 1 output compare register A*/
/***************************************
*			OCR1B					   *
***************************************/
#define 	TIMER_OCR1B			*( (volatile u16*) 0X48 )		/*Timer 1 output compare register A*/

/***************************************
*			ICR1					   *
***************************************/
#define 	TIMER_ICR1			*( (volatile u16*) 0X46 )		/**/

/***************************************
*			TCNT1L					   *
***************************************/
#define		TIMER_TCNT1L		*( (volatile u8*) 0X4C )		/*Timer/counter 1  register low byte*/
/***************************************
*			TCNT1H					   *
***************************************/
#define		TIMER_TCNT1H		*( (volatile u8*) 0X4D )		/*Timer/counter 1  register high byte*/
/***************************************
*	TCNT1 as 16 bit register			*
***************************************/
#define		TIMER_TCNT1			*( (volatile u16*) 0X4C )		/*Timer/counter 1  register*/

/**********************************************************
*		TIMER/Counter interrupt flag register	 		  *
**********************************************************/
#define		TIMER_TIFR		*( (volatile u8*) 0X58 )		/*Timer/Counter interrupt flag register*/

#define 	TIFR_TOV0		0								/*Timer 0 interrupt flag*/
#define 	TIFR_TOV1		2								/*Timer 1 interrupt flag*/
#define 	TIFR_TOV2		6								/*Timer 2 interrupt flag*/
/***********************/
#define 	TIFR_OCF0		1								/*Timer 0 output compare match flag*/
#define 	TIFR_OCF1B		3								/*Timer 1 output compare A match flag*/
#define 	TIFR_OCF1A		4								/*Timer 1 output compare B match flag*/
#define 	TIFR_OCF2		7								/*Timer 2 output compare match flag*/
/***********************/
#define 	TIFR_ICF1		5								/*Input capture flag*/

/**********************************************************
*		TIMER/Counter interrupt mask register	 		  *
**********************************************************/
#define 	TIMER_TIMSK		*( (volatile u8*) 0X59 )		/*Timer mask register*/

#define 	TIMSK_TOIE0		0								/*Timer 0 overflow interrupt enable*/
#define 	TIMSK_T0IE1		2								/*Timer 1 overflow interrupt enable*/
#define 	TIMSK_T0IE2		6								/*Timer 2 overflow interrupt enable*/

#define 	TIMSK_0CIE0		1								/*Timer 0 output compare match interrupt enable*/
#define 	TIMSK_0CIE2		7								/*Timer 2 output compare match interrupt enable*/
#define 	TIMSK_0CIE1A	4								/*Timer 1 output compare match A interrupt enable*/
#define 	TIMSK_0CIE1B	3								/*Timer 1 output compare match B interrupt enable*/

/**********************************************************
*				 	END OF FILE				      		  *
**********************************************************/
#endif /* TIMER_REGISTER_H_ */
