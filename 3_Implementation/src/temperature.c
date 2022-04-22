#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include "LCD.h"

#define degree_sysmbol 0xdf

void ADC_Init(){                                        
    DDRC = 0x00;                                   
    ADCSRA = 0x87;                                  
    ADMUX = 0x40;                                   
}

int ADC_Read(char channel)                          
{
    ADMUX = 0x40 | (channel & 0x07);                
    ADCSRA |= (1<<ADSC);                            
    while (!(ADCSRA & (1<<ADIF)));                  
    ADCSRA |= (1<<ADIF);                            
    _delay_ms(1);                                   
    return ADCW;                                    
}

int main()
{
    char Temperature[10];
    float celsius;

    LCD_Init();                 
    ADC_Init();                 
    
    while(1)
    {
        LCD_String_xy(1,0,"Temperature");
        celsius = (ADC_Read(0)*4.88);
        celsius = (celsius/10.00);
        sprintf(Temperature,"%d%cC  ", (int)celsius, degree_sysmbol);              
        LCD_String_xy(2,0,Temperature);                
        _delay_ms(1000);
        memset(Temperature,0,10);
    }
    return 0;
}
