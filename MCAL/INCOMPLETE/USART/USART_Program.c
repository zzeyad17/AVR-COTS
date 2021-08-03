/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		USART					************************/
/***************	@TITLE:		USART_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"

#include "USART_Interface.h"
#include "USART_Config.h"
#include "USART_Private.h"
#include "USART_Register.h"
/**********************************************************
*				    : 	 		  *
**********************************************************/
void USART_voidIntit(void) {
	/*1- Select Asynchronous Mode & no parity & 1 stop bit & 8 char size */
	USART_UCSRC = 0x86;

	/*2- Set the baud rate: 9600 bps*/
	USART_UBRRL = 0x33;

	/*3- Enable USART transmit*/
	SET_BIT(USART_UCSRB, UCSRB_TXEN);

	/*1- Enable USART Receive*/
	SET_BIT(USART_UCSRB, UCSRB_RXEN);

}

u8 USART_voidSendSingleDataSynch(u8 Copy_u8Data) {
	u32 Local_u32Counter = 0;
	u8 Local_u8ErrorState = OK;
	/*1-Wait until data register is empty or timeout passed*/
	while ((GET_BIT(USART_UCSRA, UCSRA_UDRE) == 0) && (Local_u32Counter < USART_U32_TRANSMISSION_TIMEOUT)) {
		Local_u32Counter++;
	}
	if (Local_u32Counter == USART_U32_TRANSMISSION_TIMEOUT) {
		/*Loop is broken because timeout passed and the flag isn't set*/
		Local_u8ErrorState = TIMEOUT_ERR;
	}
	else {
	/*loop is broken because the flag is set*/
	/*2- Write the data to the UDR register*/
		USART_UDR = Copy_u8Data;
	}
	return Local_u8ErrorState;
}

u8 USART_voidReceiveSingleDataSynch(u8* Copy_pu8Data) {
	u8 Local_u8ErrorState = OK;
	u32 Local_u32Counter = 0;

	if (Copy_pu8Data == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else {
		/*1-Wait until new Data is received*/
		while ((GET_BIT(USART_UCSRA, UCSRA_RXC) == 0) && (Local_u32Counter < USART_U32_RECEIVING_TIMEOUT)) {
			Local_u32Counter++
		}
		if (Local_u32Counter == USART_U32_RECEIVING_TIMEOUT) {
			Local_u8ErrorState = TIMEOUT_ERR;
		}
		else {
		/*2- Return the Received data*/
			*Copy_pu8Data = USART_UDR;
		}
	}
	return Local_u8ErrorState;
}

u8 USART_u8SendBufferSynch(const u8* Copy_pu8Buffer, u8 Copy_u8Size) {
	u8 Local_u8ErrorState = OK;
	u8 Local_u8Iterator;
	if (Copy_pu8Buffer != NULL) {
		for (Local_u8Iterator = 0; Local_u8Iterator < Copy_u8Size; ++Local_u8Iterator) {
			Local_u8ErrorState = USART_voidSendSingleDataSynch(Copy_pu8Buffer[Local_u8Iterator]);
			if (Local_u8ErrorState != OK) {
				return Local_u8ErrorState;
			}
		}
	}
	else {
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}





/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/
