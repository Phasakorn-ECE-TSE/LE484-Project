#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "stm32f4xx_hal.h"
#include "main.h"

// exported global variables
extern volatile int Button_Status;

// exported macros
#define RED_ON()        HAL_GPIO_WritePin(RED_LAMP_GPIO_Port, RED_LAMP_Pin, GPIO_PIN_SET)
#define RED_OFF()       HAL_GPIO_WritePin(RED_LAMP_GPIO_Port, RED_LAMP_Pin, GPIO_PIN_RESET)
#define YELLOW_ON()     HAL_GPIO_WritePin(YELLOW_LAMP_GPIO_Port, YELLOW_LAMP_Pin, GPIO_PIN_SET)
#define YELLOW_OFF()    HAL_GPIO_WritePin(YELLOW_LAMP_GPIO_Port, YELLOW_LAMP_Pin, GPIO_PIN_RESET)
#define GREEN_ON()      HAL_GPIO_WritePin(GREEN_LAMP_GPIO_Port, GREEN_LAMP_Pin, GPIO_PIN_SET)
#define GREEN_OFF()     HAL_GPIO_WritePin(GREEN_LAMP_GPIO_Port, GREEN_LAMP_Pin, GPIO_PIN_RESET)
#define WALK()      		HAL_GPIO_WritePin(WALK_SYMBOL_GPIO_Port, WALK_SYMBOL_Pin, GPIO_PIN_SET)
#define DW()         		HAL_GPIO_WritePin(WALK_SYMBOL_GPIO_Port, WALK_SYMBOL_Pin, GPIO_PIN_RESET)
#define RED_Toggle()		HAL_GPIO_TogglePin(RED_LAMP_GPIO_Port, RED_LAMP_Pin)
#define YELLOW_Toggle()	HAL_GPIO_TogglePin(YELLOW_LAMP_GPIO_Port, YELLOW_LAMP_Pin)
#define GREEN_Toggle()	HAL_GPIO_TogglePin(GREEN_LAMP_GPIO_Port, GREEN_LAMP_Pin)
#define WALK_Toggle()		HAL_GPIO_TogglePin(WALK_SYMBOL_GPIO_Port, WALK_SYMBOL_Pin)

#define MODE_READ()     (HAL_GPIO_ReadPin(MODE_SW_GPIO_Port, MODE_SW_Pin) == SET)
    
// Function prototype
void BSP_Init(void);
void Signal_Pass(void);
void Signal_Block(void);
void Signal_Flash(void);

#ifdef __cplusplus
}
#endif

#endif // __BSP_H
