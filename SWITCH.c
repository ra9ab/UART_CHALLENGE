#include "SWITCH.h"

uint8 GET_SWITCH_STATUS(uint8 sw_num,uint8* status)
{uint8 retval = OK;
uint8 val=1;
switch (sw_num)
{


case sw_1:

	DIO_read_pin_value(PORT_C,PIN4,&val)	;
	*status=val;
	break;

case sw_2:


	DIO_read_pin_value(PORT_B,PIN2,&val)	;
	*status=val;
	break;
default :
	retval=NOK;
}
return retval;
}
