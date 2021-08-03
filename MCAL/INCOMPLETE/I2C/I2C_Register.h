/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:							************************/
/***************	SWC:							************************/
/***************	@TITLE:		_Register.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/
#ifndef I2C_REGISTER_H_
#define I2C_REGISTER_H_

/**********************************************************
*				 	SPSR					      		  *
**********************************************************/
#define		SPI_SPSR		*( (volatile u8*) 0X )			/*SPI Status Register*/

#define 	SPSR_SPIF		7								/*SPIF (SPI Interrupt Flag)*/
#define 	SPSR_WCOL		6								/*WCOL (Write COLLision Flag)*/
#define 	SPSR_SPI2X		0								/*SPIZX (Double SPI Speed)*/
/**********************************************************
*				 	SPCR					      		  *
**********************************************************/
#define		SPI_SPCR		*( (volatile u8*) 0X )			/*SPI Control Register*/

#define 	SPCR_SPIE		7								/*SPI Interrupt Enable*/
#define 	SPCR_SPE		6								/*SPI Enable*/
#define 	SPCR_DORD		5								/*Data Order*/
#define 	SPCR_MSTR		4								/*MasterISlave Select*/
#define 	SPCR_CPOL		3								/*Clock Polarity*/
#define 	SPCR_CPHA		2								/*Clock Phase*/
#define 	SPCR_SPR1		1								/*SPI Clock Rate Select 1*/
#define 	SPCR_SPR0		0								/*SPI Clock Rate Select 0*/

/**********************************************************
*				 	SPDR					      		  *
**********************************************************/
#define		SPI_SPDR		*( (volatile u8*) 0X )			/*SPI Data Register*/



/**********************************************************
*				 	END OF FILE				      		  *
**********************************************************/
#endif /* I2C_REGISTER_H_ */
