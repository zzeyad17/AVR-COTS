/********************************************************************************/
/*  Author        :  Zeyad Mohsen Mohamed                                       */
/*  Date          :	 1 DEC 2020                                                 */
/*  Version       :  V01                                                        */
/********************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_Interface.h"
#include "DIO_Register.h"

/**********************************************************
*                SET PIN DIRECTION                        *
**********************************************************/	
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8Direction) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8PinNum > DIO_u8_PIN7) || (Copy_u8Direction > DIO_u8_PIN_OUTPUT)) {
		Local_u8ErrorState = NOK;
	}
	else {
		if (Copy_u8Direction == DIO_u8_PIN_INPUT) {
			switch (Copy_u8Port) {
			case DIO_u8_PORTA:
								CLR_BIT(DDRA, Copy_u8PinNum);
								break;
			case DIO_u8_PORTB:
								CLR_BIT(DDRB, Copy_u8PinNum);
											break;
			case DIO_u8_PORTC:
								CLR_BIT(DDRC, Copy_u8PinNum);
								break;
			case DIO_u8_PORTD:
								CLR_BIT(DDRD, Copy_u8PinNum);
								break;
			default:
								Local_u8ErrorState = NOK;
								break;
			}
		}
		else if (Copy_u8Direction == DIO_u8_PIN_OUTPUT) {
			switch (Copy_u8Port) {
			case DIO_u8_PORTA:
								SET_BIT(DDRA, Copy_u8PinNum);
								break;
			case DIO_u8_PORTB:
								SET_BIT(DDRB, Copy_u8PinNum);
											break;
			case DIO_u8_PORTC:
								SET_BIT(DDRC, Copy_u8PinNum);
								break;
			case DIO_u8_PORTD:
								SET_BIT(DDRD, Copy_u8PinNum);
								break;
			default:
								Local_u8ErrorState = NOK;
								break;
			}
		}
	}
	return Local_u8ErrorState;
} 
/**********************************************************
*                DIO SET PORT DIRECTION                   *
**********************************************************/	
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {
	u8 Local_u8ErrorState = OK;
	if (Copy_u8Direction > DIO_PORT_OUTPUT) {
		Local_u8ErrorState = NOK;
	}
	else {
		if (Copy_u8Direction == DIO_PORT_INPUT) {
			switch (Copy_u8Port) {
			case DIO_u8_PORTA:
								DDRA = 0;
								break;
			case DIO_u8_PORTB:
								DDRB = 0;
								break;
			case DIO_u8_PORTC:
								DDRC = 0;
								break;
			case DIO_u8_PORTD:
								DDRD = 0;
								break;
			default:
								Local_u8ErrorState = NOK;
								break;
			}
		}
		else if (Copy_u8Direction == DIO_PORT_OUTPUT) {
			switch (Copy_u8Port) {
			case DIO_u8_PORTA:
								DDRA = DIO_PORT_HIGH;
								break;
			case DIO_u8_PORTB:
								DDRB = DIO_PORT_HIGH;
								break;
			case DIO_u8_PORTC:
								DDRC = DIO_PORT_HIGH;
								break;
			case DIO_u8_PORTD:
								DDRD = DIO_PORT_HIGH;
								break;
			default:
								Local_u8ErrorState = NOK;
								break;
			}
		}
	}

	return Local_u8ErrorState;
}
/**********************************************************
*                DIO SET PIN VALUE                        *
**********************************************************/	
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8Value) {
	u8 Local_u8ErrorState = OK;
	if ((Copy_u8PinNum > DIO_u8_PIN7) || (Copy_u8Value > DIO_u8_PIN_HIGH)) {
		Local_u8ErrorState = NOK;
	}
	if (Copy_u8Value == DIO_u8_PIN_LOW) {
		switch (Copy_u8Port) {
		case DIO_u8_PORTA:
							CLR_BIT(PORTA, Copy_u8PinNum);
							break;
		case DIO_u8_PORTB:
							CLR_BIT(PORTB, Copy_u8PinNum);
							break;
		case DIO_u8_PORTC:
							CLR_BIT(PORTC, Copy_u8PinNum);
							break;
		case DIO_u8_PORTD:
							CLR_BIT(PORTD, Copy_u8PinNum);
							break;
		default:
							Local_u8ErrorState = NOK;
							break;
		}
	}
	else if (Copy_u8Value == DIO_u8_PIN_HIGH) {
		switch (Copy_u8Port) {
		case DIO_u8_PORTA:
							SET_BIT(PORTA, Copy_u8PinNum);
							break;
		case DIO_u8_PORTB:
							SET_BIT(PORTB, Copy_u8PinNum);
							break;
		case DIO_u8_PORTC:
							SET_BIT(PORTC, Copy_u8PinNum);
							break;
		case DIO_u8_PORTD:
							SET_BIT(PORTD, Copy_u8PinNum);
							break;
		default:
							Local_u8ErrorState = NOK;
							break;
		}
	}
	return Local_u8ErrorState;
}
/**********************************************************
*                DIO SET PORT VALUE                       *
**********************************************************/	
u8 DIO_SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
						PORTA = Copy_u8Value;
						break;
	case DIO_u8_PORTB:
						PORTB = Copy_u8Value;
						break;
	case DIO_u8_PORTC:
						PORTC = Copy_u8Value;
						break;
	case DIO_u8_PORTD:
						PORTD = Copy_u8Value;
						break;
	default:
						Local_u8ErrorState = NOK;
						break;
	}
	return Local_u8ErrorState;
}
/**********************************************************
*                DIO READ PIN VALUE                       *
**********************************************************/	
u8 DIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8PinNum, u8* Copy_pu8Value) {
	u8 Local_u8ErrorState = OK;
	if (Copy_pu8Value == NULL) {
		Local_u8ErrorState = NULL_POINTER;
	}
	else if (Copy_u8PinNum > DIO_u8_PIN7) {
		Local_u8ErrorState = NOK;
	}
	else {
	switch (Copy_u8Port) {
		case DIO_u8_PORTA:
							*Copy_pu8Value = GET_BIT(PINA, Copy_u8PinNum);
							break;
		case DIO_u8_PORTB:
							*Copy_pu8Value = GET_BIT(PINB, Copy_u8PinNum);
							break;
		case DIO_u8_PORTC:
							*Copy_pu8Value = GET_BIT(PINC, Copy_u8PinNum);
							break;
		case DIO_u8_PORTD:
							*Copy_pu8Value = GET_BIT(PIND, Copy_u8PinNum);
							break;
		default:
							Local_u8ErrorState = NOK;
							break;
		}
	}
	return Local_u8ErrorState;
}
/**********************************************************
*                DIO TOGGLE PIN VALUE                     *
**********************************************************/	
u8 DIO_u8TogglePinVlaue(u8 Copy_u8Port, u8 Copy_u8PinNum) {
	u8 Local_u8ErrorState = OK;
	if (Copy_u8PinNum > DIO_u8_PIN7) {
		Local_u8ErrorState = NOK;
	}
	else {
		switch (Copy_u8Port) {
		case DIO_u8_PORTA:
							TOG_BIT(PORTA, Copy_u8PinNum);
							break;
		case DIO_u8_PORTB:
							TOG_BIT(PORTB, Copy_u8PinNum);
							break;
		case DIO_u8_PORTC:
							TOG_BIT(PORTC, Copy_u8PinNum);
							break;
		case DIO_u8_PORTD:
							TOG_BIT(PORTD, Copy_u8PinNum);
							break;
		default:
							Local_u8ErrorState = NOK;
							break;
		}
	}

	return Local_u8ErrorState;
}

/**********************************************************
*                END OF FILE                              *
**********************************************************/	
