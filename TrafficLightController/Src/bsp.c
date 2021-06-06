#include "bsp.h"
#include "timer.h"

// exported global variables
volatile int Button_Status = 0;

/** @brief  Initialize I/O for lamps
    @retval None
*/
void BSP_Init(void)
{
		RED_Toggle();
		YELLOW_Toggle();
		GREEN_Toggle();
		WALK_Toggle();
		Delay(45);
		RED_Toggle();
		YELLOW_Toggle();
		GREEN_Toggle();
		WALK_Toggle();
}

/** @brief  Change lamps to GREEN
    @retval None
*/
void Signal_Pass(void)
{
		DW();
		Delay(20);
		RED_OFF();
		Delay(3);
		GREEN_ON();
		

}

/** @brief  Change lamps to RED
    @retval None
*/
void Signal_Block(void)
{
    GREEN_OFF();
		Delay(3);
		YELLOW_ON();
		Delay(15);
		YELLOW_OFF();
		Delay(3);
		RED_ON();
		Delay(15);
		WALK();

}

/** @brief  Flash YELLOW lamp
    @retval None
*/
void Signal_Flash(void)
{
	RED_OFF();
	GREEN_OFF();
	DW();
	YELLOW_Toggle();
	Delay(10);
}
