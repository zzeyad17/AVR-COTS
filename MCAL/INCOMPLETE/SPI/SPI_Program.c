/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		SPI						************************/
/***************	@TITLE:		SPI_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"
#include "MATH_Interface.h"

#include "SPI_Interface.h"
#include "SPI_Config.h"
#include "SPI_Private.h"
#include "SPI_Register.h"

/**********************************************************
*				    : 	 		  *
**********************************************************/
void SPI_voidInint(u8 Copy_u8Role) {
	/*1- Enable the SPI*/
	SET_BIT(SPI_SPCR, SPCR_SPE);

	if (Copy_u8Role == SPI_u8_MASTER) {
		/*Select master*/
		SET_BIT(SPI_SPCR, SPCR_MSTR);

		/*Select Clock Rate: SCK = FOSC/8*/
		SET_BIT(SPI_SPCR, SPCR_SPR0);
		CLR_BIT(SPI_SPCR, SPCR_SPR1);
		SET_BIT(SPI_SPSR, SPSR_SPI2X);
	}
}

u8 SPI_u8Transeiver(u8 Copy_u8Data) {
	/*Send Data*/
	SPI_SPDR = Copy_u8Data;

	/*Wait (polling) until the transfer is complete*/
	while (GET_BIT(SPI_SPSR, SPSR_SPIF) == 0);

	/*Return the received data (Ignored if the function is used to send data )*/
	return SPI_SPDR;
}

/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/
