/*
 * DIO_cnfg.c
 *
 * Created:  23 , 9 , 2019
 *  Author:
 */
#include "DIO.h"
extern DIO_cnfg_pin DIO_cnfg_arr[NUM_OF_PINS];

DIO_cnfg_pin DIO_cnfg_arr [NUM_OF_PINS] =
{
	{PORT_C,PIN4,INPUT,NA,EXTRES},
	{PORT_B,PIN2,INPUT,NA,EXTRES},
	};
