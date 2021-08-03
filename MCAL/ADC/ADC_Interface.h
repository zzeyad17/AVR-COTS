/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		ADC						************************/
/***************	@TITLE:		ADC_Config.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/**********************************************************
*				Macros						      		  *
**********************************************************/
#define ADC_CHANNEL0	0
#define ADC_CHANNEL1	1
#define ADC_CHANNEL2	2
#define ADC_CHANNEL3	3
#define ADC_CHANNEL4	4
#define ADC_CHANNEL5	5
#define ADC_CHANNEL6	6
#define ADC_CHANNEL7	7
/**********************************************************
*				Functions Declarations		      		  *
**********************************************************/
void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel, u16* Copy_pu16Result);

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel, u16* Copy_pu16Result, void (*Copy_pvNotificationFunc)(void));

u16 ADC_u16GetMVolt(u8 Copy_u8ChannelNum);

/**********************************************************
*				 	END OF FILE				      		  *
**********************************************************/
#endif /* ADC_INTERFACE_H_ */
