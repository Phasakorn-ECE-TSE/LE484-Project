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
						Signal_Pass();
						Ctrler_State = THROUGH;
						MIN_GREEN = 0;
						timeout_value = 100;
						printf("State: THROUGH\n"); 
						}
            break;
						
				case THROUGH:
					if ( evt == MODE_CHANGE ) {
						Ctrler_State = OUT_OF_SERVICE;
						printf("OUT OF SERVICE\n");
					}
					if (evt == TIMEOUT) {
						MIN_GREEN = 1;
						printf("Wait for button press\n");
					}
					if (MIN_GREEN) {
						if (evt == BUTTON) {
							Ctrler_State = BLOCKED;
							printf("State: BLOCKED\n");
							Signal_Block();
							timeout_value = 50;
						}
					} else if (evt == BUTTON){
							Ctrler_State = WAIT;
							printf("State: WAIT\n");
							printf("wait a minute\n");
						}
					break;
				
				case BLOCKED:
					if ( evt == MODE_CHANGE ) {
						Ctrler_State = OUT_OF_SERVICE;
						printf("OUT OF SERVICE\n");
					}
					if (evt == TIMEOUT) {
						Ctrler_State = THROUGH;
						Signal_Pass();
						MIN_GREEN = 0;
						timeout_value = 100;
						printf("State: THROUGH\n");
					}
					break;
					
				case WAIT:
					if ( evt == MODE_CHANGE ) {
						Ctrler_State = OUT_OF_SERVICE;
						printf("OUT OF SERVICE\n");
					}
					if (evt == TIMEOUT) {
						Ctrler_State = BLOCKED;
						printf("State: BLOCKED\n");
						Signal_Block();
						timeout_value = 50;
					}
					break;
					
        default:
            Ctrler_State = OUT_OF_SERVICE;
						Signal_Flash();
    }
    return timeout_value;
}
