/*
IDE Lab2-2 template
Louis J Beato
01/13/2021

All rights reserved.
*/

#include<stdio.h>
#include "msp.h"
#include "uart.h"


#define CHAR_COUNT 255      //change this to modify the max. permissible length of a sentence

int main()
{
	int character_count = 0;
	BYTE ch;
	uart0_init();
	
	// write this string to the UART
	uart0_put("\r\n IDE Lab: Instructed by Prof. Louis Beato");    /*Transmit this through UART*/
	
	while(1)
	{
		if(character_count==0){
			uart0_put("\r\n Enter a sentence (Limit: 255 characters, esc to exit)");
			uart0_putchar('\n');
			uart0_putchar('\r');
		}
			// send carriage return/line feed to uart
		
		while(character_count < CHAR_COUNT)
		{
			// read a character from the UART
			ch = uart0_getchar();
			character_count++;
			if (ch == 27){
				break;
			}

			// write the character to the UART
			uart0_putchar(ch);

			// if "RETURN" character, break
			if (ch == '\r'){
				break;
			
			}


			
		}
		
		while((ch !='\r'))
		{
			ch = uart0_getchar();// read character into ch

		}
		if (ch == 27){
			break;
		}
		character_count = 0;
		// reset character count
	} 
}  
