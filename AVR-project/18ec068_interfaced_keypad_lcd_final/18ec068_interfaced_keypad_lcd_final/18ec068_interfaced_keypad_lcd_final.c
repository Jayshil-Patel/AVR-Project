/*
 * _18ec068_interfaced_keypad_lcd_final.c
 *
 * Created: 02-10-2020 20:59:15
 *  Author: Jay
 */ 


#include "lcd_4_bit.h"
#include <avr/io.h>
#include <util/delay.h>


#define KEY_PRT 	PORTA
#define KEY_DDR		DDRA
#define KEY_PIN		PINA

unsigned char keypad[4][4] = {	{'7','8','9','/'},
								{'4','5','6','*'},
								{'1','2','3','-'},
								{' ','0','=','+'}};

unsigned char column, row;


char keyfind()
{
	while(1)
	{
		KEY_DDR = 0xF0;                /* set port direction as input-output */
		KEY_PRT = 0xFF;

		do
		{
			KEY_PRT &= 0x0F;      /* mask PORT for column read only */
			asm("NOP");
			column = (KEY_PIN & 0x0F); /* read status of column */
		}while(column != 0x0F);
		
		 
		 do
	     {
		 _delay_ms(20);             /* 20ms key debounce time */
		 column = (KEY_PIN & 0x0F); /* read status of column */
		 }while(column == 0x0F);        /* check for any key press */
				
				

		

	/* now check for rows */
		KEY_PRT = 0xEF;            /* check for pressed key in 1st row */
		asm("NOP");               
		column = (KEY_PIN & 0x0F);
		if(column != 0x0F)
		{
			row = 0;
			break;
		}

		KEY_PRT = 0xDF;			  /* check for pressed key in 2nd row */
		asm("NOP");
		column = (KEY_PIN & 0x0F);
		if(column != 0x0F)
		{
			row = 1;
			break;
		}
		
		KEY_PRT = 0xBF;			  /* check for pressed key in 3rd row */
		asm("NOP");
		column = (KEY_PIN & 0x0F);
		if(column != 0x0F)
		{
			row = 2;
			break;
		}

		KEY_PRT = 0x7F;			  /* check for pressed key in 4th row */
		asm("NOP");
		column = (KEY_PIN & 0x0F);
		if(column != 0x0F)
		{
			row = 3;
			break;
		}
	}

	if(column == 0x0E)                  // 0E = 0000 1110
		return(keypad[row][0]); 
	else if(column == 0x0D)            //  0D= 0000 1101
		return(keypad[row][1]);
	else if(column == 0x0B)           // 0B = 0000 1011
		return(keypad[row][2]);
	else
		return(keypad[row][3]);     //07= 0000 0111
}

int main(void)
{
	LCD_Init();
	LCD_String_xy(1,0,"Press a key");
    while(1)
	{
		LCD_Command(0xc0);
		LCD_Char(keyfind());             /* Display which key is pressed */
	}
}