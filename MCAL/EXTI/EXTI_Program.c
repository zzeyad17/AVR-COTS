/*******************************************************************************/
/*******************************************************************************/
/***************	@Author:	Zeyad Mohsen Mohamed	************************/
/***************	Layer:		MCAL					************************/
/***************	SWC:		EXTI					************************/
/***************	@TITLE:		EXTI_Program.c			************************/
/***************	Version:	V01						************************/
/*******************************************************************************/
/*******************************************************************************/

/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/
#include "Bit_Math.h"
#include "Std_Types.h"

#include "EXTI_Interface.h"
#include "EXTI_Config.h"
#include "EXTI_Private.h"
#include "EXTI_Register.h"
/**********************************************************
*				    Header Files INCLUSIONS 	 		  *
**********************************************************/

static void (*EXTI_apvCallBackFunc[3])(void) = {NULL, NULL, NULL};

/**********************************************************
*				    EXTI INT0 INIT			 	 		  *
**********************************************************/
void EXTI_voidInt0Init (void) {
#if EXTI_u8_INT0_INIT_STATE == ENABLED
	/*Enable INT0*/
	SET_BIT(GICR, GICR_INT0);
	/*Set the initial configurations*/
	#if EXTI_u8_INT0_SENSE == EXTI_u8_LOW_LEVEL
			CLR_BIT(MCUCR, MCUCR_ISC00);
			CLR_BIT(MCUCR, MCUCR_ISC01);
	#elif EXTI_u8_INT0_SENSE == EXTI_u8_ON_CHANGE
			SET_BIT(MCUCR, MCUCR_ISC00);
			CLR_BIT(MCUCR, MCUCR_ISC01);
	#elif EXTI_u8_INT0_SENSE == EXTI_u8_FALLING_EDGE
			CLR_BIT(MCUCR, MCUCR_ISC00);
			SET_BIT(MCUCR, MCUCR_ISC01);
	#elif EXTI_u8_INT0_SENSE == EXTI_u8_RISING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC00);
			SET_BIT(MCUCR, MCUCR_ISC01);
	#else
			#error "Wrong EXTI_u8_INT0_SENSE configuration option"
	#endif

#elif  EXTI_u8_INT0_INIT_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT0);
#else
	#error "Wrong EXTI_u8_INT0_INIT_STATE configuration option"
#endif
}
/**********************************************************
*				    EXTI INT1 INIT			 	 		  *
**********************************************************/
void EXTI_voidInt1Init (void) {
#if EXTI_u8_INT1_INIT_STATE == ENABLED
	/*Enable INT1*/
	SET_BIT(GICR, GICR_INT1);
	/*Set the initial configurations*/
	#if EXTI_u8_INT1_SENSE == EXTI_u8_LOW_LEVEL
			CLR_BIT(MCUCR, MCUCR_ISC10);
			CLR_BIT(MCUCR, MCUCR_ISC11);
	#elif EXTI_u8_INT1_SENSE == EXTI_u8_ON_CHANGE
			SET_BIT(MCUCR, MCUCR_ISC10);
			CLR_BIT(MCUCR, MCUCR_ISC11);
	#elif EXTI_u8_INT1_SENSE == EXTI_u8_FALLING_EDGE
			CLR_BIT(MCUCR, MCUCR_ISC10);
			SET_BIT(MCUCR, MCUCR_ISC11);
	#elif EXTI_u8_INT1_SENSE == EXTI_u8_RISING_EDGE
			SET_BIT(MCUCR, MCUCR_ISC10);
			SET_BIT(MCUCR, MCUCR_ISC11);
	#else
			#error "Wrong EXTI_u8_INT1_SENSE configuration option"
	#endif

#elif  EXTI_u8_INT1_INIT_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT1);
#else
	#error "Wrong EXTI_u8_INT1_INIT_STATE configuration option"
#endif

}
/**********************************************************
*				    EXTI INT2 INIT			 	 		  *
**********************************************************/
void EXTI_voidInt2Init (void) {
#if EXTI_u8_INT2_INIT_STATE == ENABLED
	/*Enable INT2*/
	SET_BIT(GICR, GICR_INT2);
	/*Set the initial configurations*/
	#if EXTI_u8_INT2_SENSE == EXTI_u8_FALLING_EDGE
			CLR_BIT(MCUCSR, MCUCSR_ISC2);
	#elif EXTI_u8_INT2_SENSE == EXTI_u8_RISING_EDGE
			SET_BIT(MCUCSR, MCUCSR_ISC2);
	#else
			#error "Wrong EXTI_u8_INT2_SENSE configuration option"
	#endif

#elif  EXTI_u8_INT2_INIT_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT0);
#else
	#error Wrong EXTI_u8_INT2_INIT_STATE configuration option
#endif
}
/**********************************************************
*				  EXTI SET SENCE CONTROL				  *
**********************************************************/
u8 EXTI_u8SetSenseControl(u8 Copy_u8IntNum, u8 Copy_u8Sense) {
	u8 Local_u8ErrorState = OK;
	switch (Copy_u8IntNum) 						{
	case EXTI_u8_INT0:
						switch (Copy_u8Sense) 	{
						case EXTI_u8_LOW_LEVEL:
												CLR_BIT(MCUCR, MCUCR_ISC00);
												CLR_BIT(MCUCR, MCUCR_ISC01);
												break;
						case EXTI_u8_ON_CHANGE:
												SET_BIT(MCUCR, MCUCR_ISC00);
												CLR_BIT(MCUCR, MCUCR_ISC01);
												break;
						case EXTI_u8_FALLING_EDGE:
												CLR_BIT(MCUCR, MCUCR_ISC00);
												SET_BIT(MCUCR, MCUCR_ISC01);
												break;
						case EXTI_u8_RISING_EDGE:
												SET_BIT(MCUCR, MCUCR_ISC00);
												SET_BIT(MCUCR, MCUCR_ISC01);
												break;
						default:
												Local_u8ErrorState = NOK;
												break;
						}
						break;
	case EXTI_u8_INT1:
						switch (Copy_u8Sense) 	{
						case EXTI_u8_LOW_LEVEL:
												CLR_BIT(MCUCR, MCUCR_ISC10);
												CLR_BIT(MCUCR, MCUCR_ISC11);
												break;
						case EXTI_u8_ON_CHANGE:
												SET_BIT(MCUCR, MCUCR_ISC10);
												CLR_BIT(MCUCR, MCUCR_ISC11);
												break;
						case EXTI_u8_FALLING_EDGE:
												CLR_BIT(MCUCR, MCUCR_ISC10);
												SET_BIT(MCUCR, MCUCR_ISC11);
												break;
						case EXTI_u8_RISING_EDGE:
												SET_BIT(MCUCR, MCUCR_ISC10);
												SET_BIT(MCUCR, MCUCR_ISC11);
												break;
						default:
												Local_u8ErrorState = NOK;
												break;
						}
						break;
	case EXTI_u8_INT2:
						switch (Copy_u8Sense) 	{
						case EXTI_u8_FALLING_EDGE:
												CLR_BIT(MCUCSR, MCUCSR_ISC2);												break;
						case EXTI_u8_RISING_EDGE:
												SET_BIT(MCUCSR, MCUCSR_ISC2);												break;
						default:
												Local_u8ErrorState = NOK;
												break;
						}
						break;
	default:
						Local_u8ErrorState = NOK;
						break;
	}
	return Local_u8ErrorState;
}
/**********************************************************
*				    EXTI ENABLE INTERRUPT	 	 		  *
**********************************************************/
u8 EXTI_u8EnableInt(u8 Copy_IntNum) {
	u8 Local_u8ErrorState = OK;
	switch (Copy_IntNum) {
	case EXTI_u8_INT0:
						SET_BIT(GICR, GICR_INT0);
						break;
	case EXTI_u8_INT1:
						SET_BIT(GICR, GICR_INT1);
						break;
	case EXTI_u8_INT2:
						SET_BIT(GICR, GICR_INT2);
						break;
	default:
						Local_u8ErrorState = NOK;
						break;
	}
	return Local_u8ErrorState;
}
/**********************************************************
*		    EXTI DISABLE INTERRUPT			 	 		  *
**********************************************************/
u8 EXTI_u8DisableInt(u8 Copy_IntNum) {
	u8 Local_u8ErrorState = OK;
	switch (Copy_IntNum) {
	case EXTI_u8_INT0:
						CLR_BIT(GICR, GICR_INT0);
						break;
	case EXTI_u8_INT1:
						CLR_BIT(GICR, GICR_INT1);
						break;
	case EXTI_u8_INT2:
						CLR_BIT(GICR, GICR_INT2);
						break;
	default:
						Local_u8ErrorState = NOK;
						break;
	}
	return Local_u8ErrorState;
}

/**********************************************************
*				     INT0 SET CALLBACK		      		  *
**********************************************************/
u8 EXTI_u8SetCallBack(void (*Copy_pvCallBack)(void), u8 Copy_u8IntNum) {
	u8 Local_u8ErrorState = OK;
	if (Copy_pvCallBack != NULL) {
		EXTI_apvCallBackFunc[(Copy_u8IntNum - 1)] = Copy_pvCallBack;
	}
	else {
		Local_u8ErrorState = NULL_POINTER;
	}
	return Local_u8ErrorState;
}
/**********************************************************
*				     INT0 ISR				      		  *
**********************************************************/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void) {
	if (EXTI_apvCallBackFunc[(EXTI_u8_INT0 - 1)] != NULL) {
		EXTI_apvCallBackFunc[(EXTI_u8_INT0 - 1)]();
	}
	else {
		/*Do nothing*/
	}
}

/**********************************************************
*				     INT1 ISR				      		  *
**********************************************************/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void) {
	if (EXTI_apvCallBackFunc[(EXTI_u8_INT1 - 1)] != NULL) {
		EXTI_apvCallBackFunc[(EXTI_u8_INT1 - 1)]();
	}
	else {
		/*Do nothing*/
	}
}

/**********************************************************
*				     INT2 ISR				      		  *
**********************************************************/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void) {
	if (EXTI_apvCallBackFunc[(EXTI_u8_INT2 - 1)] != NULL) {
		EXTI_apvCallBackFunc[(EXTI_u8_INT2 - 1)]();
	}
	else {
		/*Do nothing*/
	}
}

/**********************************************************
*				     END OF FILE			      		  *
**********************************************************/
