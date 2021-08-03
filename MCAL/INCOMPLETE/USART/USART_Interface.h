/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		USART					************************/
/***************	@TITLE:		USART_Interface.h		************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_


/**********************************************************
*				Functions Declarations		      		  *
**********************************************************/
void USART_voidIntit(void);

void USART_voidSendSingleDataSynch(u8 Copy_u8Data);
u8 USART_voidReceiveSingleDataSynch(void);

u8 USART_u8SendBufferSynch(const u8* Copy_pu8Buffer, u8 Copy_u8Size);
u8 USART_u8SendBufferAsynch(const u8* Copy_pu8Buffer, u8 Copy_u8Size, void(*Copy_pvNotificationFunc)(void));

u8 USART_u8ReceiveBufferSynch(u8* Copy_pu8Buffer, u8 Copy_u8Size);
u8 USART_u8ReceiveBufferAsynch(u8* Copy_pu8Buffer, u8 Copy_u8Size, void(*Copy_pvNotificationFunc)(void));

/**********************************************************
*				 	END OF FILE				      		  *
**********************************************************/
#endif /* USART_INTERFACE_H_ */
