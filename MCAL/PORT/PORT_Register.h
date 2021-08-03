/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		PORT					************************/
/***************	@TITLE:		PORT_Register.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef PORT_REGISTER_H_
#define PORT_REGISTER_H_


#define		PORTA		*( (volatile u8*) 0X3B )
#define		DDRA		*( (volatile u8*) 0X3A )

#define		PORTB		*( (volatile u8*) 0X38 )
#define		DDRB		*( (volatile u8*) 0X37 )

#define		PORTC		*( (volatile u8*) 0X35 )
#define		DDRC		*( (volatile u8*) 0X34 )

#define		PORTD		*( (volatile u8*) 0X32 )
#define		DDRD		*( (volatile u8*) 0X31 )



#endif /* PORT_REGISTER_H_ */
