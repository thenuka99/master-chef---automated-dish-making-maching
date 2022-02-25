/*
 * emergancy.c
 *
 * Created: 17/04/2021 22:53:55
 * Author : THENUKA
 */ 
#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>     //standard AVR library
#include <util/delay.h> // delay library
#include <stdio.h>


#define degree_sysmbol 0xdf



void ADC_Init(){
	DDRA = 0x00;	        /* Make ADC port as input */
	ADCSRA = 0x87;          /* Enable ADC, with freq/128  */
	ADMUX = 0x40;           /* Vref: Avcc, ADC channel: 0 */
}

int ADC_Read(char channel)
{
	ADMUX = 0x40 | (channel & 0x07);   /* set input channel to read */
	ADCSRA |= (1<<ADSC);               /* Start ADC conversion */
	while (!(ADCSRA & (1<<ADIF)));     /* Wait until end of conversion by polling ADC interrupt flag */
	ADCSRA |= (1<<ADIF);               /* Clear interrupt flag */
	_delay_ms(1);                      /* Wait a little bit */
	return ADCW;                       /* Return ADC word */
}
int main(void)
{
    
    //emergancy
    
    DDRD= 0xFF;
    PORTD = 0XFF;
    float celsius;

    ADC_Init();                 /* initialize ADC*/
    
    while(1)
    {
	    celsius = (ADC_Read(0)*4.88);
	    celsius = (celsius/10.00);
	    
	    if(celsius>=100){
		    
		    if(celsius<=105){
			    PORTD = 0x01;
			    
		    }
		    else if(celsius<=110){
			    PORTD = 0x03;;
		    }
		    else if(celsius<=115){
			    PORTD = 0x07;
		    }
		    else PORTD = 0x0F;
		    
	    }
	    else PORTD = 0x00;
	    
    }
    
    
}

