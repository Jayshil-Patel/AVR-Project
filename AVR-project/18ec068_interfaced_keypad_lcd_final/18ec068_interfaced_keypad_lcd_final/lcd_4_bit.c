/*
 * lcd_4_bit.c
 *
 * Created: 02-10-2020 20:59:54
 *  Author: Jay
 */ 
#include "lcd_4_bit.h"
void LCD_Command(unsigned char cmnd)
{
	LCD_DPRT = (LCD_DPRT & 0x0f)|(cmnd & 0xf0);		/* SEND COMMAND TO DATA PORT */
	LCD_DPRT &= ~ (1<<LCD_RS);						/* RS = 0 FOR COMMAND */
	LCD_DPRT |= (1<<LCD_EN);						/* EN = 1 FOR H TO L PULSE */
	_delay_us(1);									/* WAIT FOR MAKE ENABLE WIDE */
	LCD_DPRT &= ~(1<<LCD_EN);						/* EN = 0 FOR H TO L PULSE */
	_delay_us(100);									/* WAIT FOR MAKE ENABLE WIDE */
	
	LCD_DPRT = (LCD_DPRT & 0x0f)|(cmnd << 4);		/* SEND COMMAND TO DATA PORT */
	LCD_DPRT |= (1<<LCD_EN);						/* EN = 1 FOR H TO L PULSE */
	_delay_us(1);									/* WAIT FOR MAKE ENABLE WIDE */
	LCD_DPRT &= ~(1<<LCD_EN);						/* EN = 0 FOR H TO L PULSE */
	_delay_us(2000);								/* WAIT FOR MAKE ENABLE WIDE */
}

void LCD_Char(unsigned char data)
{
	LCD_DPRT = (LCD_DPRT & 0x0f)|(data & 0xf0);		/* SEND DATA TO DATA PORT */
	LCD_DPRT |= (1<<LCD_RS);						/* MAKE RS = 1 FOR DATA */
	LCD_DPRT |= (1<<LCD_EN);						/* EN=0 FOR H TO L PULSE */
	_delay_us(1);									/* WAIT FOR MAKE ENABLE WIDE */
	LCD_DPRT &= ~(1<<LCD_EN);						/* EN = 0 FOR H TO L PULSE */
	_delay_us(100);									/* WAIT FOR MAKE ENABLE WIDE */
	
	LCD_DPRT = (LCD_DPRT & 0x0f)|(data << 4);		/*  */
	LCD_DPRT |= (1<<LCD_EN);						/* EN=0 FOR H TO L PULSE*/
	_delay_us(1);									/* WAIT FOR MAKE ENABLE WIDE*/
	LCD_DPRT &= ~(1<<LCD_EN);						/* EN = 0 FOR H TO L PULSE*/
	_delay_us(2000);								/* WAIT FOR MAKE ENABLE WIDE*/
}

void LCD_Init()
{
	LCD_DDDR = 0xFF;
	_delay_ms(20);									/* WAIT FOR SOME TIME */
	LCD_Command(0x02);								/*CONFIGURE LCD IN 4-BIT MODE*/
	LCD_Command(0x28);								/* INIT. LCD 2 LINE, 5 X 7 MATRIX */
	LCD_Command(0x0C);								/* DISPLAY ON CURSOR ON */
	LCD_Command(0x01);								/* LCD CLEAR */
	LCD_Command(0x82);								/* SHIFT CURSOR TO WRITE */
}

void LCD_String_xy(unsigned char row, unsigned char pos, char *str)
{
	if (row == 1)
	LCD_Command((pos & 0x0F)|0x80);				/* Command of first row and required position */
	else if (row == 2)
	LCD_Command((pos & 0x0F)|0xC0);				/* Command of Second row and required position */
	
	LCD_String(str);								/* Call LCD string function */
}

void LCD_String(char *str)
{
	int i;
	for(i=0;str[i]!=0;i++)							/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);							/* Call LCD data write */
	}
}

void lcd_clear()
{
	LCD_Command(0x01);
	_delay_ms(3);
	LCD_Command(0x80);
}