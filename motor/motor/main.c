/*
 * motor.c
 *
 * Created: 17/11/2020 00:34:59
 * Author : THENUKA
 */

#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif

#include <avr/io.h>     //standard AVR library
#include <util/delay.h> // delay library
#include <stdio.h>
int addspicy(int spicyspoon1, int spicyspoon2, int spicyspoon3, int spicyspoon4, int spicyspoon5, int spicyspoon6, int spicyspoon7, int spicyspoon8);


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

int main(void) //main starts
{
    DDRC = 0xFF;
    DDRB = 0x00;

    int curryNum = 0, personNum = 0;

    //checking number of person
    while (personNum == 0)
    {
        if (PINB & (1 << 0))
        {
            if (PINB & (1 << 1))
            {
                if (PINB & (1 << 2))
                {
                    personNum = 7;
                }
                else
                {
                    personNum = 3;
                }
            }
            else if (PINB & (1 << 2))

            {
                personNum = 5;
            }
            else if (PINB & (1 << 3))
            {
                personNum = 9;
            }
            else
            {
                personNum = 1;
            }
        }
        else if (PINB & (1 << 1))
        {
            if (PINB & (1 << 2))
            {
                personNum = 6;
            }
            else
            {
                personNum = 2;
            }
        }
        else if (PINB & (1 << 3))
        {
            personNum = 8;
        }
        else if (PINB & (1 << 2))
        {
            personNum = 4;
        }
    }

    //checking curry number
    while (curryNum == 0)
    {
        if (PINB & (1 << 4))
        {
            if (PINB & (1 << 5))
            {
                if (PINB & (1 << 6))
                {
                    curryNum = 7;
                }
                else
                {
                    curryNum = 3;
                }
            }
            else if (PINB & (1 << 6))
            {
                curryNum = 5;
            }
            else if (PINB & (1 << 7))
            {
                curryNum = 9;
            }
            else
            {
                curryNum = 1;
            }
        }
        else if (PINB & (1 << 5))
        {
            if (PINB & (1 << 6))
            {
                curryNum = 6;
            }
            else
            {
                curryNum = 2;
            }
        }
        else if (PINB & (1 << 7))
        {
            curryNum = 8;
        }
        else if (PINB & (1 << 6))
        {
            curryNum = 4;
        }
    }

    //adding spicy according to curry and person number
    switch (curryNum)
    {
    case 1:
        switch (personNum)
        {
        case 1:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            ;
            break;
        case 2:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            ;
            break;
        case 3:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            ;
            break;
        case 4:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            ;
            break;
        case 5:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            ;
            break;
        case 6:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            ;
            break;
        case 7:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            ;
            break;
        case 8:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            ;
            break;
        case 9:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        }
        break;
    case 2:
        switch (personNum)
        {
        case 1:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 2:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 3:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 4:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 5:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 6:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 7:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 8:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 9:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        }
        break;
    case 3:
        switch (personNum)
        {
        case 1:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 2:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 3:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 4:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 5:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 6:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 7:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 8:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 9:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        }
        break;
    case 4:
        switch (personNum)
        {
        case 1:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 2:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 3:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 4:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 5:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 6:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 7:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 8:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 9:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        }
        break;
    case 5:
        switch (personNum)
        {
        case 1:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 2:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 3:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 4:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 5:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 6:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 7:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 8:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 9:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        }
        break;
    case 6:
        switch (personNum)
        {
        case 1:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 2:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 3:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 4:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 5:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 6:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 7:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 8:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 9:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        }
        break;
    case 7:
        switch (personNum)
        {
        case 1:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 2:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 3:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 4:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 5:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 6:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 7:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 8:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 9:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        }
        break;
    case 8:
        switch (personNum)
        {
        case 1:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 2:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 3:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 4:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 5:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 6:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 7:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 8:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 9:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        }
        break;
    case 9:
        switch (personNum)
        {
        case 1:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 2:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 3:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 4:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 5:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 6:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 7:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 8:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        case 9:
            addspicy(2, 1, 2, 3, 4, 2, 1, 2);
            break;
        }
        break;
    }
	
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

int addspicy(int spicyspoon1, int spicyspoon2, int spicyspoon3, int spicyspoon4, int spicyspoon5, int spicyspoon6, int spicyspoon7, int spicyspoon8)
{
    for (int i = 0; i < spicyspoon1; i++)
    {
        PORTC = 0x01;
        _delay_ms(100);
    }
    for (int i = 0; i < spicyspoon2; i++)
    {
        PORTC = 0x02;
        _delay_ms(100);
    }
    for (int i = 0; i < spicyspoon3; i++)
    {
        PORTC = 0x04;
        _delay_ms(100);
    }
    for (int i = 0; i < spicyspoon4; i++)
    {
        PORTC = 0x08;
        _delay_ms(100);
    }
    for (int i = 0; i < spicyspoon5; i++)
    {
        PORTC = 0x10;
        _delay_ms(100);
    }
    for (int i = 0; i < spicyspoon6; i++)
    {
        PORTC = 0x20;
        _delay_ms(100);
    }
    for (int i = 0; i < spicyspoon7; i++)
    {
        PORTC = 0x40;
        _delay_ms(100);
    }
    for (int i = 0; i < spicyspoon8; i++)
    {
        PORTC = 0x80;
        _delay_ms(100);
    }
	PORTC = 0x00;
}
