/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		ADC						************************/
/***************	@TITLE:		ADC_Register.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_
/**********************************************************
*				 ADMUX REGISTER				      		  *
**********************************************************/

#define		ADC_ADMUX		*( (volatile u8*) 0X27 )				/*ADC MULTIPLEXER SELECTION REGISTER*/
/*ANALOG CHANNELS AND GAIN SELECTION BITS*/
#define 	ADMUX_MUX0		0
#define 	ADMUX_MUX1		1
#define 	ADMUX_MUX2		2
#define 	ADMUX_MUX3		3
#define 	ADMUX_MUX4		4
/*ADC LEFT ADJUST RESULT*/
#define 	ADMUX_ADLAR		5
/*REFERENCE SELECTION BITS*/
#define 	ADMUX_REFS0		6
#define 	ADMUX_REFS1		7
/**********************************************************
*				 ADCSRA REGISTER			      		  *
**********************************************************/
#define		ADC_ADCSRA		*( (volatile u8*) 0X26 )				/*ADC CONTROL AND STATUS REGISTER A*/
/*ADC PRESCALER SELECT BITS*/
#define     ADCSRA_ADPS0	0
#define     ADCSRA_ADPS1	1
#define     ADCSRA_ADPS2	2
/*ADC INTERRUPT ENABLE*/
#define     ADCSRA_ADIE		3
/*ADC INTERRUPT FLAG*/
#define     ADCSRA_ADIF		4
/*ADC AUTO TRIGGER ENABLE*/
#define     ADCSRA_ADATE	5
/*ADC START CONVERSION*/
#define     ADCSRA_ADSC		6
/*ADC ENABLE*/
#define     ADCSRA_ADEN		7
/**********************************************************
*				 ADC DATA REGISTERS			      		  *
**********************************************************/

#define		ADC_ADCH		*( (volatile u8*) 0X25 )				/*DATA HIGH REGISTER*/
#define		ADC_ADCL		*( (volatile u8*) 0X24 )				/*DATA LOW REGISTER*/
#define		ADC_ADC			*( (volatile u16*) 0X24 )				/*u16 pointer to fetch 10 bit data*/

/**********************************************************
*				 	END OF FILE				      		  *
**********************************************************/
#endif /* ADC_REGISTER_H_ */
