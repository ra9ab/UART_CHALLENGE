#include "DIO.h"
#include "LCD.h"
#include "registers.h"
#include "uart.h"
#include "SWITCH.h"
#include "timer.h"
#include "avr/interrupt.h"
uint8 INIT_SPEED_CAL( void);
void speed_adjust(void);
void show(void);
#define M2_READY 1
uint8 arr[1];
uint8 x=0;
uint16 time=0;
uint8 ovf=0;
void main (void)
{	LCD_init();
DIO_init ();
init_uart();
Timer_init();
x=INIT_SPEED_CAL();
LCD_displayStringRowColumn(0,0,"speed :");
LCD_displayStringRowColumn(1,0,"time :");
LCD_displayStringRowColumn(0,12,"m/s");
LCD_displayStringRowColumn(1,12,"sec");
SREG=(1<<7);
//Timer_setCallBack(show);

while(1)
{
	speed_adjust();

	_delay_ms(300);

}
}
/**********************************************************************************/
/**********function to calculate initial speed value by keypad*************/
uint8 INIT_SPEED_CAL( void)
{uint8 speed=0,j=0;

arr[0]=KeyPad_getPressedKey();
_delay_ms(500);
arr[1]=KeyPad_getPressedKey();

while (j<2)
{
	speed=speed*10+arr[j];
	j++;
}

return speed;
}

/*************************************************************************************/
/*function to adjust the speed by two switches to increase and decrease speed*/
void speed_adjust(void)
{uint8 status_1=0,status_2=0;
GET_SWITCH_STATUS(sw_1,&status_1);
GET_SWITCH_STATUS(sw_2,&status_2);
if (status_1)
{
	x++;
}
else if (status_2)
{
	x--;
}

}
/*****************************************************************************************/
/******** function to display on screen and send speed by uart ***********/
void show(void)
{
	LCD_intgerToString_goToRowColumn(1,8,time);
}




ISR(TIMER0_OVF_vect) {
	ovf++;
	if (ovf == 30) {

		if (x<10)
		{
			LCD_intgerToString_goToRowColumn(0,8,0);
			LCD_intgerToString_goToRowColumn(0,9,x);
		}
		else
		{LCD_intgerToString_goToRowColumn(0,8,x);}
		LCD_intgerToString_goToRowColumn(1,8,time);

		time++;
		uart_transtmit_data(x);
		ovf = 0;

	}

}

