/*
    BitzOS (BOS) V0.1.4 - Copyright (C) 2017 Hexabitz
    All rights reserved
		
    File Name     : H01R0.c
    Description   : Header file for module H01R0.
										RGB LED (Cree CLVBA-FKA-CC1F1L1BB7R3R3)
*/
	
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef H01R0_H
#define H01R0_H

/* Includes ------------------------------------------------------------------*/
#include "BOS.h"
#include "H01R0_uart.h"	
#include "H01R0_gpio.h"	
#include "H01R0_dma.h"		
	
/* Exported definitions -------------------------------------------------------*/

#define	modulePN		_H01R0

/* Port-related definitions */
#define	NumOfPorts		6
#define P_PROG 				P2						/* ST factory bootloader UART */

/* Define available ports */
#define _P1 
#define _P2 
#define _P3 
#define _P4 
#define _P5 
#define _P6

/* Define available USARTs */
#define _Usart1 1
#define _Usart2 1
#define _Usart3 1
#define _Usart4 1
#define _Usart5 1
#define _Usart6	1

/* Port-UART mapping */
#define P1uart &huart4	
#define P2uart &huart2
#define P3uart &huart6
#define P4uart &huart3
#define P5uart &huart1
#define P6uart &huart5
	
/* Port Definitions */
#define	USART1_TX_PIN		GPIO_PIN_9
#define	USART1_RX_PIN		GPIO_PIN_10
#define	USART1_TX_PORT	GPIOA
#define	USART1_RX_PORT	GPIOA
#define	USART1_AF				GPIO_AF1_USART1

#define	USART2_TX_PIN		GPIO_PIN_2
#define	USART2_RX_PIN		GPIO_PIN_3
#define	USART2_TX_PORT	GPIOA
#define	USART2_RX_PORT	GPIOA
#define	USART2_AF				GPIO_AF1_USART2

#define	USART3_TX_PIN		GPIO_PIN_10
#define	USART3_RX_PIN		GPIO_PIN_11
#define	USART3_TX_PORT	GPIOB
#define	USART3_RX_PORT	GPIOB
#define	USART3_AF				GPIO_AF4_USART3

#define	USART4_TX_PIN		GPIO_PIN_0
#define	USART4_RX_PIN		GPIO_PIN_1
#define	USART4_TX_PORT	GPIOA
#define	USART4_RX_PORT	GPIOA
#define	USART4_AF				GPIO_AF4_USART4

#define	USART5_TX_PIN		GPIO_PIN_3
#define	USART5_RX_PIN		GPIO_PIN_4
#define	USART5_TX_PORT	GPIOB
#define	USART5_RX_PORT	GPIOB
#define	USART5_AF				GPIO_AF4_USART5

#define	USART6_TX_PIN		GPIO_PIN_4
#define	USART6_RX_PIN		GPIO_PIN_5
#define	USART6_TX_PORT	GPIOA
#define	USART6_RX_PORT	GPIOA
#define	USART6_AF				GPIO_AF5_USART6

/* Module-specific Definitions */
#ifdef H01R0
	#define _RGB_RED_PORT							GPIOA
	#define _RGB_RED_PIN							GPIO_PIN_7
	#define _RGB_RED_TIM_CH						TIM_CHANNEL_2
	#define _RGB_RED_GPIO_CLK()				__GPIOA_CLK_ENABLE();
	#define _RGB_GREEN_PORT						GPIOB
	#define _RGB_GREEN_PIN						GPIO_PIN_0
	#define _RGB_GREEN_TIM_CH					TIM_CHANNEL_3
	#define _RGB_GREEN_GPIO_CLK()			__GPIOB_CLK_ENABLE();
	#define _RGB_BLUE_PORT						GPIOB
	#define _RGB_BLUE_PIN							GPIO_PIN_1
	#define _RGB_BLUE_TIM_CH					TIM_CHANNEL_4
	#define _RGB_BLUE_GPIO_CLK()			__GPIOB_CLK_ENABLE();
	
	#define PWM_TIMER_CLOCK			16000000
	#define RGB_PWM_FREQ				24000
	#define RGB_PWM_PERIOD			((float) (1/RGB_PWM_FREQ) )
#endif

/* Module_Status Type Definition */  
typedef enum 
{
  H01R0_OK = 0,
	H01R0_ERR_UnknownMessage,
  H01R0_ERR_WrongColor,
	H01R0_ERR_WrongIntensity,
	H01R0_ERROR = 255
} Module_Status;

/* Indicator LED */
#define _IND_LED_PORT		GPIOA
#define _IND_LED_PIN		GPIO_PIN_11

/* Color Enumerations */
enum BasicColors{BLACK=1, WHITE, RED, BLUE, YELLOW, CYAN, MAGENTA, GREEN};


/* RGB LED Mode Enumerations */
enum RGBLedMode{RGB_PULSE_RGB=1, RGB_PULSE_COLOR, RGB_SWEEP_BASIC, RGB_SWEEP_FINE, RGB_DIM_UP, RGB_DIM_UP_WAIT, RGB_DIM_DOWN, RGB_DIM_DOWN_WAIT,\
	RGB_DIM_UP_DOWN, RGB_DIM_DOWN_UP, RGB_DIM_UP_DOWN_WAIT, RGB_DIM_DOWN_UP_WAIT};


/* Export UART variables */
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart6;

/* Define UART Init prototypes */
extern void MX_USART1_UART_Init(void);
extern void MX_USART2_UART_Init(void);
extern void MX_USART3_UART_Init(void);
extern void MX_USART4_UART_Init(void);
extern void MX_USART5_UART_Init(void);
extern void MX_USART6_UART_Init(void);

extern TIM_HandleTypeDef htim3;
	
extern uint8_t RGB_LED_State, RGB_LED_Intensity_Old;
extern uint8_t rgbLedMode, rgbRed, rgbGreen, rgbBlue, rgbColor; 
extern uint32_t rgbPeriod, rgbDC; 
extern int16_t rgbCount;

/* -----------------------------------------------------------------------
	|														Message Codes	 														 	|
   ----------------------------------------------------------------------- 
*/

#define	CODE_H01R0_ON							100
#define	CODE_H01R0_OFF						101
#define	CODE_H01R0_TOGGLE					102
#define	CODE_H01R0_COLOR					103
#define	CODE_H01R0_PULSE					104
#define	CODE_H01R0_SWEEP					105
#define	CODE_H01R0_DIM						106

	
/* -----------------------------------------------------------------------
	|																APIs	 																 	|
   ----------------------------------------------------------------------- 
*/

extern Module_Status RGB_LED_on(uint8_t intensity);
extern Module_Status RGB_LED_off(void);
extern Module_Status RGB_LED_toggle(uint8_t intensity);
extern Module_Status RGB_LED_setColor(uint8_t color, uint8_t intensity);
extern Module_Status RGB_LED_setRGB(uint8_t red, uint8_t green, uint8_t blue, uint8_t intensity);
extern Module_Status RGB_LED_pulseRGB(uint8_t red, uint8_t green, uint8_t blue, uint32_t period, uint32_t dc, int32_t repeat);
extern Module_Status RGB_LED_pulseColor(uint8_t color, uint32_t period, uint32_t dc, int32_t repeat);
extern Module_Status RGB_LED_sweep(uint8_t mode, uint32_t period, int32_t repeat);
extern Module_Status RGB_LED_dim(uint8_t color, uint8_t mode, uint32_t period, uint32_t wait, int32_t repeat);

/* -----------------------------------------------------------------------
	|															Commands																 	|
   ----------------------------------------------------------------------- 
*/
extern const CLI_Command_Definition_t onCommandDefinition;
extern const CLI_Command_Definition_t offCommandDefinition;
extern const CLI_Command_Definition_t colorCommandDefinition;
extern const CLI_Command_Definition_t RGBCommandDefinition;
extern const CLI_Command_Definition_t toggleCommandDefinition;
extern const CLI_Command_Definition_t pulseColorCommandDefinition;
extern const CLI_Command_Definition_t pulseRGBCommandDefinition;
extern const CLI_Command_Definition_t sweepCommandDefinition;
extern const CLI_Command_Definition_t dimCommandDefinition;


#endif /* H01R0_H */

/************************ (C) COPYRIGHT HEXABITZ *****END OF FILE****/
