#ifndef __BSP__H__
#define __BSP__H__

#include "main.h"


//-------------------- LEDS GPIO-------------
#define BSP_LED_1                 DO_LED_GPIO_Port, DO_LED_Pin

#define BSP_LED_ON(LED)			HAL_GPIO_WritePin(LED, GPIO_PIN_SET)
#define BSP_LED_OFF(LED)	    HAL_GPIO_WritePin(LED, GPIO_PIN_RESET)
#define BSP_LED_TOGGLE(LED)		HAL_GPIO_TogglePin(LED)
// //-------------------- LEDS GPIO END-------------

// //--------------------- REL GPIO ---------------------
// #define REL1_WORK               O_D_REL1_GPIO_Port, GPIO_PIN_4
// #define REL2_WARNING            O_D_REL2_GPIO_Port, GPIO_PIN_2
// #define REL3_ALARM              O_D_REL3_GPIO_Port, GPIO_PIN_3
// #define SET_REL(REL)            HAL_GPIO_WritePin(REL, GPIO_PIN_SET)
// #define RESET_REL(REL)          HAL_GPIO_WritePin(REL, GPIO_PIN_RESET)
//------------------- REL GPIO END -------------------

// ----------------------------- RS-485 -----------------------------
#define USART2_RX_E                     USART_RX_E_GPIO_Port, USART_RX_E_Pin
#define BSP_USART_RX_E_ON(USARTx)		HAL_GPIO_WritePin(USARTx,GPIO_PIN_SET)
#define BSP_USART_RX_E_OFF(USARTx)	    HAL_GPIO_WritePin(USARTx,GPIO_PIN_RESET)

void bsp_rs485_setPortToModbusRtu(uint8_t portNo, uint8_t *bufRxTX, uint16_t bufSizeByte);

void bsp_rs485_sendBlock(uint8_t portNo, uint8_t *buf, uint8_t bufSizeByte);
void bsp_rs485_sendTestBlock(uint8_t portNo);

void bsp_rs485_callback_rxBlockReady(uint8_t portNo);
void bsp_rs485_callback_rxTimeout(uint8_t portNo);

#define BSP_RS485_1_IRQ_HANDLER 			        USART2_IRQHandler
// #define BSP_RS485_1_IRQ_HANDLER_DMA_RX 			DMA1_Channel3_IRQHandler
// #define BSP_RS485_1_IRQ_HANDLER_DMA_TX 			DMA1_Channel4_IRQHandler

// ----------------------------- RS-485 END-----------------------------

#endif