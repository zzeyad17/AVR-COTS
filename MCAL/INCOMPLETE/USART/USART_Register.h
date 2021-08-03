/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		USART					************************/
/***************	@TITLE:		USART_Register.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_


/**********************************************************
*				 	USART UBRR				      		  *
**********************************************************/

#define		USART_UBRRL		*( (volatile u8*) 0X29 )

/**********************************************************
*				 	USART UDR				      		  *
**********************************************************/

#define		USART_UDR		*( (volatile u8*) 0X2C )

/**********************************************************
*				 	USART UCSRA				      		  *
**********************************************************/

#define		USART_UCSRA		*( (volatile u8*) 0X2B )		/*USART control and status register A*/

#define		UCSRA_RXC		7							/*USART Receive complete*/
#define		UCSRA_TXC		6							/*USART Transmit complete*/
#define		UCSRA_UDRE		5							/*USART data register empty*/
#define		UCSRA_FE		4							/*Frame error*/
#define		UCSRA_DOR		3							/*Data OverRun*/
#define		UCSRA_PE		2							/*Parity Error*/
#define		UCSRA_U2X		1							/*Double the USART Transmission Speed*/
#define		UCSRA_MPCM		0							/**Multi-processor Communication Mode/

/**********************************************************
*				 	USART UCSRB				      		  *
**********************************************************/

#define		USART_UCSRB		*( (volatile u8*) 0X2A )		/*USART control and status register B*/

#define		UCSRB_RXCIE		7							/*Receive complete Interrupt Enable*/
#define		UCSRB_TXCIE		6							/*Transmit complete Interrupt Enable*/
#define		UCSRB_UDRIE		5							/*USART Data Register Empty Interrupt Enable*/
#define		UCSRB_RXEN		4							/*Receive Enable*/
#define		UCSRB_TXEN		3							/*Transmit Enable*/
#define		UCSRB_UCSZ2		2							/*Character Size*/
#define		UCSRB_RXB8		1							/*Receive Data bit 8*/
#define		UCSRB_TXB8		0							/*Transmit data bit 8*/

/**********************************************************
*				 	USART UCSRC/UBRRH		      		  *
**********************************************************/

#define		USART_UCSRC		*( (volatile u8*) 0X40 )		/*USART control and status register C*/

#define		UCSRC_URSEL		7							/*Register Select (1--->UCSRC // 0---->UBRRH)*/
#define		UCSRC_UMSEL		6							/*USART Mode select*/
#define		UCSRC_UMP1		5							/*Parity Mode bit 1*/
#define		UCSRC_UMP0		4							/*Parity Mode bit 0*/
#define		UCSRC_USBS		3							/*Stop bit Select*/
#define		UCSRC_UCSZ1		2							/*Character Size bit 1*/
#define		UCSRC_UCSZ0		1							/*Character Size bit 0*/
#define		UCSRC_UCPOL		0							/*Clock Polarity (for synchronous mode)*/

/**********************************************************
*				 	END OF FILE				      		  *
**********************************************************/
#endif /* USART_REGISTER_H_ */
