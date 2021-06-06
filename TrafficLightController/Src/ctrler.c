#include "ctrler.h"
#include "bsp.h"

Ctrler_State_t Ctrler_State = RESTART;

void Ctrler_Init()
{
}
static int MIN_GREEN = 0;
uint32_t Ctrler_Exec(Event_t evt)
{
    uint32_t timeout_value = 0;
    
    switch(Ctrler_State) {
        case RESTART:
					if (evt == TIMEOUT) {
						Ctrler_State = THROUGH;
						printf("State: RESTART\n");
						Signal_Pass();
						MIN_GREEN = 0;
						timeout_value = 100;
						}
            break;
						
				case THROUGH:
					printf("State: THROUGH\n");
					if ( evt == MODE_CHANGE ) {
						Ctrler_State = OUT_OF_SERVICE;
					}
					if (evt == TIMEOUT) {
						MIN_GREEN = 1;
					}
					if (MIN_GREEN) {
						printf("Wait for button press\n");
						if (evt == BUTTON) {
							Ctrler_State = BLOCKED;
							Signal_Block();
							timeout_value = 50;
						}
					} else if (evt == BUTTON){
							Ctrler_State = WAIT;
						}
					break;
				
				case BLOCKED:
					printf("State: BLOCKED\n");
					if ( evt == MODE_CHANGE ) {
						Ctrler_State = OUT_OF_SERVICE;
					}
					if (evt == TIMEOUT) {
						Ctrler_State = THROUGH;
						Signal_Pass();
						MIN_GREEN = 0;
						timeout_value = 100;
					}
					break;
					
				case WAIT:
					printf("State: WAIT\n");
					printf("wait a minute\n");
					if ( evt == MODE_CHANGE ) {
						Ctrler_State = OUT_OF_SERVICE;
					}
					if (evt == TIMEOUT) {
						Ctrler_State = BLOCKED;
						Signal_Block();
						timeout_value = 50;
					}
					break;
					
        default:
            Ctrler_State = OUT_OF_SERVICE;
						printf("OUT OF SERVICE\n");
						Signal_Flash();
    }
    return timeout_value;
}
