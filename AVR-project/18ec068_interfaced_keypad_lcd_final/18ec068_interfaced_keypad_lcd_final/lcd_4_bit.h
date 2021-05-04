/*
 * lcd_4_bit.h
 *
 * Created: 02-10-2020 20:59:37
 *  Author: Jay
 */ 


#ifndef LCD_4_BIT_H_
#define LCD_4_BIT_H_

#define  F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#define LCD_DPRT PORTB
#define LCD_DDDR DDRB
#define LCD_RS 0
#define LCD_EN 1

void LCD_Command(unsigned char cmnd);
void LCD_Char(unsigned char data);
void LCD_Init();
void LCD_String_xy(unsigned char, unsigned char, char *);
void LCD_String(char *str);
void LCD_Clear();





#endif /* LCD_4_BIT_H_ */