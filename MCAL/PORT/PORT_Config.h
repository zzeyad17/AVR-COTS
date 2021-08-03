/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		PORT					************************/
/***************	@TITLE:		PORT_Config.h			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/


#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_
/**********************************************************
*				 PINS DIRECTIONS			      		  *
**********************************************************/

/*Direction Configuration: Choose 0 for Input, 1 for Output*/

#define PORTA_PIN0_DIR			0 // adc
#define PORTA_PIN1_DIR			1
#define PORTA_PIN2_DIR			1
#define PORTA_PIN3_DIR			1
#define PORTA_PIN4_DIR			1
#define PORTA_PIN5_DIR			1
#define PORTA_PIN6_DIR			1
#define PORTA_PIN7_DIR			1

#define PORTB_PIN0_DIR			1
#define PORTB_PIN1_DIR			1
#define PORTB_PIN2_DIR			1
#define PORTB_PIN3_DIR			1
#define PORTB_PIN4_DIR			1
#define PORTB_PIN5_DIR			1
#define PORTB_PIN6_DIR			1
#define PORTB_PIN7_DIR			1

#define PORTC_PIN0_DIR			1
#define PORTC_PIN1_DIR			1
#define PORTC_PIN2_DIR			1
#define PORTC_PIN3_DIR			1
#define PORTC_PIN4_DIR			1
#define PORTC_PIN5_DIR			1
#define PORTC_PIN6_DIR			1
#define PORTC_PIN7_DIR			1

#define PORTD_PIN0_DIR			0 	/*RXD*/
#define PORTD_PIN1_DIR			1	/*TXD*/
#define PORTD_PIN2_DIR			1
#define PORTD_PIN3_DIR			1
#define PORTD_PIN4_DIR			1
#define PORTD_PIN5_DIR			1
#define PORTD_PIN6_DIR			1
#define PORTD_PIN7_DIR			1


/**********************************************************
*				 PINS INIT VALUES			      		  *
**********************************************************/

/*Direction Configuration:
 * If Output mode is activated : choose 0 for output low, 1 for output high
 * If Input mode is activated  : choose 0 for input floating, 1 for input pullup
 */

#define PORTA_PIN0_INIT_VAL			0
#define PORTA_PIN1_INIT_VAL			0
#define PORTA_PIN2_INIT_VAL			0
#define PORTA_PIN3_INIT_VAL			0
#define PORTA_PIN4_INIT_VAL			0
#define PORTA_PIN5_INIT_VAL			0
#define PORTA_PIN6_INIT_VAL			0
#define PORTA_PIN7_INIT_VAL			0

#define PORTB_PIN0_INIT_VAL			0
#define PORTB_PIN1_INIT_VAL			0
#define PORTB_PIN2_INIT_VAL			0
#define PORTB_PIN3_INIT_VAL			0
#define PORTB_PIN4_INIT_VAL			0
#define PORTB_PIN5_INIT_VAL			0
#define PORTB_PIN6_INIT_VAL			0
#define PORTB_PIN7_INIT_VAL			0

#define PORTC_PIN0_INIT_VAL			0
#define PORTC_PIN1_INIT_VAL			1
#define PORTC_PIN2_INIT_VAL			1
#define PORTC_PIN3_INIT_VAL			1
#define PORTC_PIN4_INIT_VAL			1
#define PORTC_PIN5_INIT_VAL			1
#define PORTC_PIN6_INIT_VAL			1
#define PORTC_PIN7_INIT_VAL			1

#define PORTD_PIN0_INIT_VAL			0
#define PORTD_PIN1_INIT_VAL			1
#define PORTD_PIN2_INIT_VAL			1
#define PORTD_PIN3_INIT_VAL			1
#define PORTD_PIN4_INIT_VAL			1
#define PORTD_PIN5_INIT_VAL			0
#define PORTD_PIN6_INIT_VAL			1
#define PORTD_PIN7_INIT_VAL			1

/**********************************************************
*				 	End of file		  		      		  *
**********************************************************/

#endif /* PORT_CONFIG_H_ */
