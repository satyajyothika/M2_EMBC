#ifndef LCD_H_                  
#define LCD_H_

#define F_CPU 8000000UL                 
#include <avr/io.h>                     
#include <util/delay.h>                 

#define LCD_Data_Dir DDRB               
#define LCD_Command_Dir DDRC            
#define LCD_Data_Port PORTB             
#define LCD_Command_Port PORTC          
#define EN PC2                          
#define RW PC1                          
#define RS PC0                          

void LCD_Command (char);                
void LCD_Char (char);                   
void LCD_Init (void);                   
void LCD_String (char*);                
void LCD_String_xy (char,char,char*);   
void LCD_Clear(void);                       

#endif