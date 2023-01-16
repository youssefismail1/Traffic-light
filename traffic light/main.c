/*
 * main.c
 *
 * Created: 1/16/2023 11:58:41 AM
 *  Author: ABOALI
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "LCD.h"
#include "timer.h"
#include "LED.h"

volatile unsigned int counter =0;
signed char time;
int main(void)
{
	LCD_vInit();
	timer_CTC_init_interrupt();
	LED_vInit('D',0);
	LED_vInit('D',1);
	LED_vInit('D',2);
	
    while(1)
    {
	   time=10;
	   LCD_clearscreen();
	   LCD_vSend_string("remaining 10 sec");
	  
       while (time >=0)
       {
		  if(counter >= 100)
		  {
			  time--;
			  counter=0;
			  LCD_movecursor(1,9);
			  LCD_vSend_char(' ');
			  LCD_vSend_char((time%10)+48);
		  }
       }
	   time=5;
	   counter=0;
	   LED_vTurnOff('D',0);
	   LED_vTurnOn('D',1);
	   LCD_clearscreen();
	  LCD_vSend_string("remaining 10 sec");
	   
	   while (time >=0)
	   {
		   if(counter >= 100)
		   {
			   time--;
			   counter=0;
			   LCD_movecursor(1,9);
			   LCD_vSend_char(' ');
			   LCD_vSend_char((time%10)+48);
		   }
	   }
	   time=7;
	   counter=0;
	   LED_vTurnOff('D',1);
	   LED_vTurnOn('D',2);
	   LCD_clearscreen();
	   LCD_vSend_string("remaining 10  sec");
	    
	   while (time >=0)
	   {
		   if(counter >= 100)
		   {
			 time--;
			 counter=0;
			 LCD_movecursor(1,9);
			 LCD_vSend_char(' ');
			 LCD_vSend_char((time%10)+48);   
		   }
	   }
	   LED_vTurnOff('D',2);
    }
}

ISR(TIMER0_COMP_vect)
{
	
	counter++;
}