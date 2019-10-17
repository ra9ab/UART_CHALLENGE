#ifndef SWITCH_H_
#define SWITCH_H_
#include "DIO.h"
#define MAX_SWITCHES 3
extern uint8 GET_SWITCH_STATUS(uint8 sw_num,uint8* status);
#define sw_1 1
#define sw_2 2
#define sw_3 3
#endif
