/********************************************************************************/
/*  Author        :  Zeyad Mohsen Mohamed                                       */
/*  Date          :	 1 DEC 2020                                                 */
/*  Version       :  V01                                                        */
/********************************************************************************/
#include "Std_Types.h"
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
/**********************************************************
*		                DIO PORT GROUPS			      	  *
**********************************************************/
#define DIO_u8_PORTA	0
#define DIO_u8_PORTB 	1
#define DIO_u8_PORTC	2
#define DIO_u8_PORTD	3
/**********************************************************
*		                DIO PIN NUMBERS			 									*
**********************************************************/
#define DIO_u8_PIN0		0
#define DIO_u8_PIN1		1
#define DIO_u8_PIN2		2
#define DIO_u8_PIN3		3
#define DIO_u8_PIN4		4
#define DIO_u8_PIN5		5
#define DIO_u8_PIN6		6
#define DIO_u8_PIN7		7
/*********************************************************
*						DIO PIN DIRECTION					*
*********************************************************/
#define DIO_u8_PIN_OUTPUT 1
#define DIO_u8_PIN_INPUT  0 
/**********************************************************
*		                DIO PIN VALUE 			 		*
**********************************************************/
#define DIO_u8_PIN_HIGH 1
#define DIO_u8_PIN_LOW 	0
/**********************************************************
*		                DIO PORT VALU				    	*
**********************************************************/

#define DIO_PORT_HIGH 0xff
#define DIO_PORT_LOW  0
/**********************************************************
*		                DIO PORT DIRECTION										*
**********************************************************/
#define DIO_PORT_OUTPUT 1
#define DIO_PORT_INPUT 0

/**********************************************************
*		             DIO FUNCTIONS DECLARATION    						*
**********************************************************/																														
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8Direction); 

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8Value);

u8 DIO_SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

u8 DIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8PinNum, u8* Copy_pu8Value);

u8 DIO_u8TogglePinVlaue(u8 Copy_u8Port, u8 Copy_u8PinNum);
/**********************************************************
*		                END OF FILE	       	 									*
**********************************************************/
#endif

