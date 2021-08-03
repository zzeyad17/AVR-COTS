/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		EXTI					************************/
/***************	@TITLE:		EXTI_Config.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/**********************************************************
*				 		INT0				      		  *
**********************************************************/
/*Set the required Initial state for the EXTI INT0 pin
options: 1- ENABLED
 	 	 2- DISABLED
*/
#define EXTI_u8_INT0_INIT_STATE		ENABLED
/****************************************************/
/****************************************************/
/*Set the required sense control for the EXTI INT0 pin
options: 1- EXTI_u8_RISING_EDGE
 	 	 2- EXTI_u8_FALLING_EDGE
 	 	 3- EXTI_u8_ON_CHANGE
 	 	 4- EXTI_u8_LOW_LEVEL
*/
#define EXTI_u8_INT0_SENSE		EXTI_u8_FALLING_EDGE
/**********************************************************
*				 		INT1				      		  *
**********************************************************/
/*Set the required Initial state for the EXTI INT1 pin
options: 1- ENABLED
 	 	 2- DISABLED
*/
#define EXTI_u8_INT1_INIT_STATE		ENABLED
/****************************************************/
/****************************************************/
/*Set the required sense control for the EXTI INT1 pin
options: 1- EXTI_u8_RISING_EDGE
 	 	 2- EXTI_u8_FALLING_EDGE
 	 	 3- EXTI_u8_ON_CHANGE
 	 	 4- EXTI_u8_LOW_LEVEL
*/
#define EXTI_u8_INT1_SENSE		EXTI_u8_FALLING_EDGE
/**********************************************************
*				 		INT2				      		  *
**********************************************************/
/*Set the required Initial state for the EXTI INT2 pin
options: 1- ENABLED
 	 	 2- DISABLED
*/
#define EXTI_u8_INT2_INIT_STATE		ENABLED
/****************************************************/
/****************************************************/
/*Set the required sense control for the EXTI INT2 pin
options: 1- EXTI_u8_RISING_EDGE
 	 	 2- EXTI_u8_FALLING_EDGE
*/
#define EXTI_u8_INT2_SENSE		EXTI_u8_FALLING_EDGE


/**********************************************************
*				 	END OF FILE				      		  *
**********************************************************/
#endif /* EXTI_CONFIG_H_ */
