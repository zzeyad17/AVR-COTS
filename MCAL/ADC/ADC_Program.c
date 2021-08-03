/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	      ************************/
/***************	Layer:		MCAL					              ************************/
/***************	SWC:		  ADC					                ************************/
/***************	@TITLE:		ADC_Program.c			          ************************/
/***************	Version:	V01						               ************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"

#include "ADC_Interface.h"
#include "ADC_Config.h"
#include "ADC_Register.h"
#include "ADC_Private.h"
/********************************************************************
*GLOBAL VARIABLES FOR THE ASYNCH FUNCTION TO HANDLE DATA TO THE ISR *
********************************************************************/

/**********************************************************
*				    GLOBAL VARIABLES		 	 		  *
**********************************************************/
/*Global variables to deliver data to the ISR*/
static u16* ADC_pu16ConversionResult = NULL;
static void (*ADC_pvNotificationFunc)(void) = NULL;

/*Global variable flag to hold the state of the ADC peripheral*/
static u8 ADC_u8BusyFlag = IDLE;
/**********************************************************
*				    ADC INIT				 	 		  *
**********************************************************/
void ADC_voidInit(void) {
	/*Initialize ADMUX & ADCSRA to 0 (Not important)*/
	ADC_ADMUX  = 0;
	ADC_ADCSRA = 0;

	/*1- Set reference voltage AVCC*/
	ADC_ADMUX |= REFS;

	/*2- Set adjust result*/
	ADC_ADMUX |= ADLAR;

	/*3- Setting the prescaler*/
	ADC_ADCSRA |= ADPS;

	/*4- Peripheral Enable*/
	SET_BIT(ADC_ADCSRA, ADCSRA_ADEN);

}
/**********************************************************
*			   ADC START CONVERSION SYNCH	 	 		  *
**********************************************************/
u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16* Copy_pu16Result) {

	u8 Local_u8ErrorState = OK;
	u32 Local_u32Counter = 0;

	if (Copy_pu16Result == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else {

		if (ADC_u8BusyFlag == IDLE) {
			/*1- Make the ADC flag busy*/
			ADC_u8BusyFlag = BUSY;

			/*2- Set the required channel*/
			ADC_ADMUX &= CHANNEL_MASK;
			ADC_ADMUX |= Copy_u8Channel;

			/*3- Start conversion*/
			SET_BIT(ADC_ADCSRA, ADCSRA_ADSC);

			/*4- Wait (Polling with blocking) until the conversion is complete or the timeout period is passed*/
			while((GET_BIT(ADC_ADCSRA, ADCSRA_ADIF) == 0) && (Local_u32Counter < ADC_u8_TIMEOUT_PERIOD)) {
				Local_u32Counter++;
			}
			/*If the timeout period passed*/
			if (Local_u32Counter == ADC_u8_TIMEOUT_PERIOD) {
				/*5- Return timeout error*/
				Local_u8ErrorState = TIMEOUT_ERR;
				/*6- Make the ADC IDLE again*/
				ADC_u8BusyFlag = IDLE;

			}
			else { /*the ADC finished Conversion*/

				/*5- Clear the flag*/
				SET_BIT(ADC_ADCSRA, ADCSRA_ADIF);

				/*6- Return the conversion output*/
				#if ADLAR == LEFT_ADJUST
					*Copy_pu16Result = ADC_ADCH ;	/*The value is 8 bit*/
				#elif ADLAR == RIGHT_ADJUST
					*Copy_pu16Result = ADC_ADC		/*The value is 16 bit*/
				#else
					#error "Wrong ADLAR Configuration option"
				#endif
				/*7- Make the ADC IDLE again*/
				ADC_u8BusyFlag = IDLE;
			}
		}
		else {	/*ADC busy*/
			/*Return busy error*/
			Local_u8ErrorState = BYSY_ERR;
		}
	}
	return Local_u8ErrorState;
}
/**********************************************************
*			   ADC START CONVERSION ASYNCH	 	 		  *
**********************************************************/
u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Result, void (*Copy_pvNotificationFunc)(void)) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_pu16Result == NULL) || (Copy_pvNotificationFunc == NULL)) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else {
		/*1- Check if the peripheral is IDLE*/
		if (ADC_u8BusyFlag == IDLE) {
			/*2- Make ADC busy*/
			ADC_u8BusyFlag = BUSY;
			/*3- Set the required channel*/
			ADC_ADMUX &= CHANNEL_MASK;
			ADC_ADMUX |= Copy_u8Channel;

			/*4- Start conversion*/
			SET_BIT(ADC_ADCSRA, ADCSRA_ADSC);

			/*5- Enable the ADC conversion complete interrupt enable*/
			SET_BIT(ADC_ADCSRA, ADCSRA_ADIF);

			/*6- Send the data to the ISR via the global variables*/
			ADC_pu16ConversionResult = Copy_pu16Result;				/*Send the address of Conversion result variable to the ISR*/
			ADC_pvNotificationFunc   = Copy_pvNotificationFunc;		/*Send the address of the notification func to the ISR*/
		}
		else {		/*ADC is busy*/
			/*Return busy error*/
			Local_u8ErrorState = BYSY_ERR;
		}
	}
	return Local_u8ErrorState;
}
/**********************************
*	ADC Conversion complete ISR	  *
**********************************/
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void) {
	/*1- ADC is now IDLE*/
	ADC_u8BusyFlag = IDLE;

	/*2- Disable the ADC conversion complete interrupt enable*/
	CLR_BIT(ADC_ADCSRA, ADCSRA_ADSC);

	/*3- Read the Conversion result*/
	#if ADLAR == LEFT_ADJUST
		*ADC_pu16ConversionResult = ADC_ADCH;
	#elif ADLAR == RIGHT_ADJUST
		*ADC_pu16ConversionResult = ADC_ADC;
	#endif

	/*4- Invoke the callback notification function*/
	if (ADC_pvNotificationFunc != NULL) {
		ADC_pvNotificationFunc();
	}
	else {
		/*Do nothing*/
	}
}
/**********************************************************
*			   ADC Get  volt				 	 		  *
**********************************************************/
u16 ADC_u16GetMVolt(u8 Copy_u8ChannelNum) {
	u32 Local_u16ConversionResult;
	ADC_u8StartConversionSynch(Copy_u8ChannelNum, &Local_u16ConversionResult);
#if ADLAR == LEFT_ADJUST
	return ((Local_u16ConversionResult * 5000UL) / 256UL);
#elif ADLAR == RIGHT_ADJUST
	return ((Local_u16ConversionResult * 5000UL) / 1024UL);
#endif
}

/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/
