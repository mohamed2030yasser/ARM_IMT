/*
 * main.c
 *
 *  Created on: May 13, 2022
 *      Author: Diefco
 */

#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA =0b00001111;


	while(1)
	{
		 //port A0 output
		PORTA=0b00000001;
		_delay_ms(500);
		PORTA=0b00000010;
		_delay_ms(500);
		PORTA=0b00000100;
		_delay_ms(500);
		PORTA=0b00001000;
		_delay_ms(500);
	}



}
